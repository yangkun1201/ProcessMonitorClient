# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

QT += charts
TEMPLATE = app
TARGET = ProcessMonitor
DESTDIR = ../Win32/Debug
QT += core network gui widgets
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB QT_NETWORK_LIB
INCLUDEPATH += ./GeneratedFiles \
    ./GeneratedFiles/$(ConfigurationName) \
    F:\opencv\opencv\build\include
DEPENDPATH += ./GeneratedFiles
MOC_DIR += ./GeneratedFiles/Debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ProcessMonitor.pri)
win32:RC_FILE = ProcessMonitor.rc
LIBS += -luser32 \
        -lF:\opencv\opencv\build\x64\vc14\lib\opencv_world320d





