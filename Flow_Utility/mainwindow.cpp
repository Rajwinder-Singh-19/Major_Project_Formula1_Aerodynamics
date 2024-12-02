#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "air_calc.h"
#include "boundary_calc.h"
#include "turbulence_calc.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>
#include <QString>
#include <QDesktopServices>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
double circuit_altitude = 0;
double characteristic_len = 1;
double flow_velocity = 1;
double temperature = 1;
double pressure = 1;
double rho = 1;
double visc = 1;
double reynolds = 1;
double skinFric = 1;
double wallShear = 1;
double fricVelocity = 1;
double yPlus = 1;
double cellHeight = 1;
   int noLayers = 1;
double layerHeight = 1;
double expRatio = 1;
double boundary_layer = 1;
double blockSize = 1;
   int refineLevel = 1;
double turbInt = 1;
double turbKE = 1;
double turbOmega = 1;
double turbEpsilon=1;
void MainWindow::on_ReynCalc_clicked()
{
    if(ui->Char_Len->text().isEmpty() || ui->circuit_altitude->text().isEmpty()){
        QMessageBox::warning(this, "Error" ,"Enter both circuit altitude and characteristic length to proceed");
        on_Clear_clicked();
        return;
    }
    circuit_altitude = ui->circuit_altitude->text().toDouble();
    characteristic_len = ui->Char_Len->text().toDouble();
    rho = calcAirRho(circuit_altitude);
    ui->Density->setText(QString::number(rho));
    visc = calcAirVisc(circuit_altitude);
    ui->Viscosity->setText(QString::number(visc));
    temperature = calcAirTemperature(circuit_altitude);
    ui->Temperature->setText(QString::number(temperature));
    pressure = calcAirPressure(circuit_altitude);
    ui->Pressure->setText(QString::number(pressure));

    if(ui->ReynoldsNo->text().isEmpty() && ui->Flow_Velocity->text().isEmpty()){
        QMessageBox::warning(this, "Error" ,"Either enter Reynolds Number or Inlet Velocity to proceed. Both cannot be empty.");
        on_Clear_clicked();
        return;
    }

    if(ui->Flow_Velocity->text().isEmpty()){
        reynolds = ui->ReynoldsNo->text().toDouble();
        flow_velocity = reynolds*visc/characteristic_len;
        ui->Flow_Velocity->setText(QString::number(flow_velocity));
    }

    if(ui->ReynoldsNo->text().isEmpty()){
        flow_velocity = ui->Flow_Velocity->text().toDouble();
        reynolds = flow_velocity*characteristic_len/visc;
        ui->ReynoldsNo->setText(QString::number(reynolds));
    }

    skinFric = calcSkinFriction(reynolds);
    ui->skinFriction->setText(QString::number(skinFric));
    wallShear = calcShearStress(rho, flow_velocity, skinFric);
    ui->shearStress->setText(QString::number(wallShear));
    fricVelocity = calcFricVelocity(wallShear, rho);

    if(ui->yPlus->text().isEmpty() && ui->cellHeight->text().isEmpty()){
        QMessageBox::warning(this, "Error" ,"Either enter y+ or cell height to proceed. Both cannot be empty.");
        on_Clear_clicked();
        return;
    }

    if(ui->noLayers->text().isEmpty() || ui->expRatio->text().isEmpty()){
        QMessageBox::warning(this, "Error" ,"Enter both No. of layers and expansion ratio to proceed");
        on_Clear_clicked();
        return;
    }

    if(ui->yPlus->text().isEmpty()){
        cellHeight = ui->cellHeight->text().toDouble();
        yPlus = 0.5*cellHeight*fricVelocity/visc;
        ui->yPlus->setText(QString::number(yPlus));
    }

    if(ui->cellHeight->text().isEmpty()){
        yPlus = ui->yPlus->text().toDouble();
        cellHeight = 2*yPlus*visc/fricVelocity;
        ui->cellHeight->setText(QString::number(cellHeight));
    }
    noLayers = ui->noLayers->text().toInt();
    expRatio = ui->expRatio->text().toDouble();
    layerHeight = cellHeight*(ceil(noLayers)*expRatio);
    ui->layerHeight->setText(QString::number(layerHeight));
    boundary_layer = calcLayerThickness(reynolds, characteristic_len);
    ui->BLayerHeight->setText(QString::number(boundary_layer));

    if(ui->blockSize->text().isEmpty()){
        QMessageBox::warning(this, "Error" ,"Enter background cell size to proceed.");
        on_Clear_clicked();
        return;
    }

    blockSize = ui->blockSize->text().toDouble();
    refineLevel = ceil(log10(blockSize/layerHeight)/log10(2));
    ui->refineLevel->setText(QString::number(refineLevel));

    if(ui->turbIntensity->text().isEmpty()){
        QMessageBox::warning(this, "Error" ,"Enter turbulence intensity to proceed.");
        on_Clear_clicked();
        return;
    }

    turbInt = ui->turbIntensity->text().toDouble()/100;
    turbKE = calcKE(turbInt, flow_velocity);
    turbOmega = calcOmega(turbInt, flow_velocity, characteristic_len);
    turbEpsilon = calcEpsilon(turbInt, flow_velocity, characteristic_len);
    turbInt = ui->turbIntensity->text().toDouble();
    ui->turbKE->setText(QString::number(turbKE));
    ui->turbOmega->setText(QString::number(turbOmega));
    ui->turbEpsilon->setText(QString::number(turbEpsilon));

}
void MainWindow::on_Clear_clicked()
{
    ui->circuit_altitude->clear();
    ui->Char_Len->clear();
    ui->Density->clear();
    ui->Viscosity->clear();
    ui->Temperature->clear();
    ui->Pressure->clear();
    ui->Flow_Velocity->clear();
    ui->ReynoldsNo->clear();
    ui->skinFriction->clear();
    ui->shearStress->clear();
    ui->yPlus->clear();
    ui->cellHeight->clear();
    ui->noLayers->clear();
    ui->expRatio->clear();
    ui->layerHeight->clear();
    ui->BLayerHeight->clear();
    ui->blockSize->clear();
    ui->refineLevel->clear();
    ui->turbIntensity->clear();
    ui->turbKE->clear();
    ui->turbOmega->clear();
    ui->turbEpsilon->clear();
}
QString dataFileName;
QString fullPath;
unsigned int dataCount;
void MainWindow::on_NewFile_clicked()
{
    dataFileName = ui->fileName->text().trimmed();
    if (dataFileName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a file name.");
        return;
    }
    QDir subDir(QDir::currentPath() + "/Data/");
    if(!subDir.exists()){
        if (!subDir.mkdir(subDir.absolutePath())){
            QMessageBox::warning(this, "Error", "Data subdirectory could not be created");
            return;
        }
    }
    fullPath = subDir.absoluteFilePath(dataFileName);
    QFile file(fullPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(this, "Success", dataFileName + " created successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Could not create file.");
    }

    QTextStream out(&file);
    out << "Circuit Altitude (ft), "
           "Characteristic Length (m), "
           "Flow Velocity (m/s), "
           "Temperature (K), "
           "Pressure (Pa), "
           "Density (kg per cubic m), "
           "Kinematic Viscosity (m square per s), "
           "Reynolds Number, "
           "yPlus, "
           "No. of Layers, "
           "B.L. Expansion Ratio, "
           "Cell Height (m), "
           "Layer Height (m), "
           "B.L. Thickness (m), "
           "Background Cell Size (m), "
           "Mesh Refinement Level, "
           "Wall Skin Friction Coefficient, "
           "Wall Shear Stress (Pa), "
           "Turbulence Intensity (%), "
           "Turbulent K.E. (m square per s square), "
           "Omega (per s), "
           "Epsilon (m square per s cube)\n";
    file.close();
    dataCount = 0;
}


void MainWindow::on_RecordData1_clicked()
{
    QFile file(fullPath);
    QTextStream out(&file);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        out << QString::number(circuit_altitude)<<",";
        out << QString::number(characteristic_len)<<",";
        out << QString::number(flow_velocity)<<",";
        out << QString::number(temperature)<<",";
        out << QString::number(pressure)<<",";
        out << QString::number(rho)<<",";
        out << QString::number(visc)<<",";
        out << QString::number(reynolds)<<",";
        out << QString::number(yPlus)<<",";
        out << QString::number(noLayers)<<",";
        out << QString::number(expRatio)<<",";
        out << QString::number(cellHeight)<<",";
        out << QString::number(layerHeight)<<",";
        out << QString::number(boundary_layer)<<",";
        out << QString::number(blockSize)<<",";
        out << QString::number(refineLevel)<<",";
        out << QString::number(skinFric)<<",";
        out << QString::number(wallShear)<<",";
        out << QString::number(turbInt)<<",";
        out << QString::number(turbKE)<<",";
        out << QString::number(turbOmega)<<",";
        out << QString::number(turbEpsilon)<<"\n";
        dataCount++;
    } else {
        QMessageBox::warning(this, "Error", "Could not record data");
    }
    file.close();
    ui->count->setText(QString::number(dataCount));
}


void MainWindow::on_SaveFile_clicked()
{
    if (!fullPath.isEmpty()) {
        // Open the file in the default text editor
        bool success = QDesktopServices::openUrl(QUrl::fromLocalFile(fullPath));
        if (!success) {
            QMessageBox::warning(this, "Error", "Could not open file");
        }
    }
}



