QT       += core gui \
         testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AlgoSorting.cpp \
    AlgoSortingInsertion.cpp \
    BarGraphButton.cpp \
    algosortingbubble.cpp \
    algosortingheap.cpp \
    algosortingmerge.cpp \
    algosortingquick.cpp \
    algosortingselection.cpp \
    barvaluedouble.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    algosorting.h \
    algosortingbubble.h \
    algosortingheap.h \
    algosortinginsertion.h \
    algosortingmerge.h \
    algosortingquick.h \
    algosortingselection.h \
    bargraphbutton.h \
    barvaluedouble.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
