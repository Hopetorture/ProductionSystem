#-------------------------------------------------
#
# Project created by QtCreator 2015-10-20T13:53:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProductionSystem
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    abstractobject.cpp \
    property.cpp \
    isa.cpp \
    link.cpp \
    objectpool.cpp \
    propertypool.cpp \
    xmlparser.cpp \
    quads.cpp \
    forms.cpp \
    consistsof.cpp \
    partof.cpp \
    linkfactory.cpp \
    logical.cpp \
    rand.cpp \
    debug_link.cpp \
    calc.cpp \

HEADERS  += mainwindow.h \
    abstractobject.h \
    property.h \
    isa.h \
    link.h \
    objectpool.h \
    propertypool.h \
    xmlparser.h \
    quads.h \
    forms.h \
    consistsof.h \
    partof.h \
    linkfactory.h \
    logical.h \
    rand.h \
    debug_link.h \
    calc.h \

FORMS    += mainwindow.ui
