TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    button.cpp \
    slot.cpp \
    writecoords.cpp

HEADERS += \
    button.h \
    slot.h \
    writecoords.h
