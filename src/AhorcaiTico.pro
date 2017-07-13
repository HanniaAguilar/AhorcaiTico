QT += core gui widgets svg # multimedia

TARGET = AhorcaiTico
TEMPLATE = app
CONFIG += c++11

HEADERS += \
    mecanicajuego.h \
    marcador.h \
    controlador.h \
    teclas.h \
    objetoprop.h \
    Vista.h \
    partescuerpo.h

SOURCES += main.cpp \
    mecanicajuego.cpp \
    marcador.cpp \
    controlador.cpp \
    teclas.cpp \
    objetoprop.cpp \
    Vista.cpp \
    partescuerpo.cpp

mac {
        Resources.files = Resources
        Resources.path = Contents/MacOS
        QMAKE_BUNDLE_DATA += Resources
}

RESOURCES += \
    resources.qrc

