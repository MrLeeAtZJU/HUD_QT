######################################################################
# Automatically generated by qmake (2.01a) Fri Oct 27 10:13:23 2017
######################################################################

TEMPLATE = app
TARGET = target
QT += network
DEPENDPATH += .
INCLUDEPATH += $$PWD/include
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS +=					\
	include/widget.h		\
    include/dialog1.h		\
    include/data_types.h	\
    include/setwidget.h		\
    include/dialog2.h		\
    include/dialog3.h		\
    include/dialog4.h

FORMS +=			\ 
	ui/widget.ui	\
    ui/dialog1.ui	\
    ui/dialog2.ui	\
    ui/dialog3.ui	\
    ui/dialog4.ui

SOURCES +=			\ 
	src/main.cpp	\
	src/widget.cpp	\
    src/dialog1.cpp \
    src/dialog2.cpp \
    src/dialog3.cpp \
    src/dialog4.cpp

DISTFILES +=

RESOURCES += \
    image.qrc
