TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    button.h \
    character.h \
    gmapcategory.h \
    gmapobject.h \
    gmapslot.h \
    keycodes.h \
    main.h \
    timer.h \
    gmap.h \
    label.h \
    rands.h \
    font.h \
    fonts.h \
    scene.h \
    text.h \
    scenes.h \
    screen.h \
    mydebug.h \
    pushmessage.h \
    ncursesall.h \
    systems.h \
    ctrlpointers.h

SOURCES += main.cpp \
    button.cpp \
    character.cpp \
    gmapcategory.cpp \
    gmapobject.cpp \
    gmapslot.cpp \
    timer.cpp \
    gmap.cpp \
    message.cpp \
    label.cpp \
    rands.cpp \
    font.cpp \
    scene.cpp \
    text.cpp \
    screen.cpp

# NCurses libs install:
# Linux: sudo apt-get install libncursesw5-dev
# Windows: Download PDCurses (from https://sourceforge.net/projects/pdcurses/files/pdcurses/3.4/pdcurs34.zip/download)
#                Extract zip
#                In cmd: path = "path to MinGW Compiler (C:/Qt/5.6/mingw49_32/bin)"
#                In cmd: cd "path to zip + /win32"
#                In cmd: mingw32-make -f mingwin32.mak
#                Copy / Paste panel.a and ncurses.a to "path to MinGW Compiler" + /lib
#                Copy / Paste curses.h to "path to MinGW Compiler" + /include

win32 {
    INCLUDEPATH += C:/Qt/5.6/mingw49_32/include
    LIBS += C:/Qt/5.6/mingw49_32/lib/pdcurses.a
}

unix:!macx {
    LIBS += -lncursesw
}
