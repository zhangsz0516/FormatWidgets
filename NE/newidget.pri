INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

!contains(XCONFIG, xne) {
    XCONFIG += xne
    include(../../Formats/xne.pri)
}

!contains(XCONFIG, formatwidget) {
    XCONFIG += formatwidget
    include(../formatwidget.pri)
}

FORMS += \
    $$PWD/newidget.ui \
    $$PWD/dialogne.ui

HEADERS += \
    $$PWD/newidget.h \
    $$PWD/ne_defs.h \
    $$PWD/dialogne.h

SOURCES += \
    $$PWD/newidget.cpp \
    $$PWD/ne_defs.cpp \
    $$PWD/dialogne.cpp