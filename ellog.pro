TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    easylogging++.cc \
    ellog.cpp

HEADERS += \
    easylogging++.h \
    ellog.h

INCLUDEPATH += .

DISTFILES += \
    config.conf
