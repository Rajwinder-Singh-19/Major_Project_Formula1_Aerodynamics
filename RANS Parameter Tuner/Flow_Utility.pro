QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    air_calc.cpp \
    boundary_calc.cpp \
    main.cpp \
    mainwindow.cpp \
    turbulence_calc.cpp

HEADERS += \
    air_calc.h \
    air_constants_isa.h \
    boundary_calc.h \
    mainwindow.h \
    turbulence_calc.h \
    turbulence_constants_SI.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
