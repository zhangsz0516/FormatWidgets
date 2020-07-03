INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

FORMS += \
    $$PWD/nesectionheaderwidget.ui \
    $$PWD/newidget.ui \
    $$PWD/dialogne.ui

HEADERS += \
    $$PWD/neprocessdata.h \
    $$PWD/nesectionheaderwidget.h \
    $$PWD/newidget.h \
    $$PWD/ne_defs.h \
    $$PWD/dialogne.h

SOURCES += \
    $$PWD/neprocessdata.cpp \
    $$PWD/nesectionheaderwidget.cpp \
    $$PWD/newidget.cpp \
    $$PWD/ne_defs.cpp \
    $$PWD/dialogne.cpp

!contains(XCONFIG, formatwidget) {
    XCONFIG += formatwidget
    include($$PWD/../formatwidget.pri)
}
