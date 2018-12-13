TARGET = Panel
TEMPLATE = app
QT += core gui

MOC_DIR += ./.build
OBJECTS_DIR += ./.build
UI_DIR += ./.build

LIBS += -lX11

SOURCES += main.cpp \
           Panel.cpp

HEADERS += Panel.h

FORMS += Panel.ui
