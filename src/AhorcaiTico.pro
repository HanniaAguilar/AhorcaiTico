QT += core gui widgets svg # multimedia

TARGET = AhorcaiTico
TEMPLATE = app
CONFIG += c++11

HEADERS += \
    marcador.h \
    Controlador.h \
    Teclas.h \
    objetoprop.h \
    Vista.h \
    PartesCuerpo.h \
    Diccionario.h \
    Raya.h \
    Aviso.h \
    Pista.h

SOURCES += main.cpp \
    marcador.cpp \
    Controlador.cpp \
    Teclas.cpp \
    Vista.cpp \
    PartesCuerpo.cpp \
    Diccionario.cpp \
    Objetoprop.cpp \
    Raya.cpp \
    Aviso.cpp \
    Pista.cpp

mac {
        Resources.files = Resources
        Resources.path = Contents/MacOS
        QMAKE_BUNDLE_DATA += Resources
}

RESOURCES += \
    resources.qrc

