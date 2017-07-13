QT += core gui widgets svg # multimedia

TARGET = AhorcaiTico
TEMPLATE = app
CONFIG += c++11

HEADERS += \
    mecanicajuego.h \
    marcador.h \
    Controlador.h \
    Teclas.h \
    objetoprop.h \
    Vista.h \
    PartesCuerpo.h

SOURCES += main.cpp \
    mecanicajuego.cpp \
    marcador.cpp \
    Controlador.cpp \
    Teclas.cpp \
    objetoprop.cpp \
    Vista.cpp \
    PartesCuerpo.cpp

mac {
        Resources.files = Resources
        Resources.path = Contents/MacOS
        QMAKE_BUNDLE_DATA += Resources
}

RESOURCES += \
    resources.qrc

