INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

!contains(XCONFIG, xlineedithex) {
    XCONFIG += xlineedithex
    include($$PWD/../Controls/xlineedithex.pri)
}

!contains(XCONFIG, xcomboboxex) {
    XCONFIG += xcomboboxex
    include($$PWD/../Controls/xcomboboxex.pri)
}

!contains(XCONFIG, xdatetimeeditx) {
    XCONFIG += xdatetimeeditx
    include($$PWD/../Controls/xdatetimeeditx.pri)
}

!contains(XCONFIG, qhexview) {
    XCONFIG += qhexview
    include($$PWD/../QHexView/qhexview.pri)
}

!contains(XCONFIG, searchstringswidget) {
    XCONFIG += searchstringswidget
    include($$PWD/SearchStrings/searchstringswidget.pri)
}

!contains(XCONFIG, xmemorymapwidget) {
    XCONFIG += xmemorymapwidget
    include($$PWD/../XMemoryMapWidget/xmemorymapwidget.pri)
}

!contains(XCONFIG, xentropywidget) {
    XCONFIG += xentropywidget
    include($$PWD/../XEntropyWidget/xentropywidget.pri)
}

!contains(XCONFIG, xentropywidget) {
    XCONFIG += xentropywidget
    include($$PWD/../StaticScan/formresult.pri)
}

HEADERS += \
    $$PWD/dialogentropy.h \
    $$PWD/dialogprocessdata.h \
    $$PWD/processdata.h \
    $$PWD/formatwidget.h \
    $$PWD/toolswidget.h \
    $$PWD/invwidget.h \
    $$PWD/dialoghex.h \
    $$PWD/formatwidget_def.h \
    $$PWD/dialogsectionheader.h

SOURCES += \
    $$PWD/dialogentropy.cpp \
    $$PWD/dialogprocessdata.cpp \
    $$PWD/processdata.cpp \
    $$PWD/formatwidget.cpp \
    $$PWD/toolswidget.cpp \
    $$PWD/invwidget.cpp \
    $$PWD/dialoghex.cpp \
    $$PWD/dialogsectionheader.cpp

FORMS += \
    $$PWD/dialogentropy.ui \
    $$PWD/dialogprocessdata.ui \
    $$PWD/toolswidget.ui \
    $$PWD/dialoghex.ui \
    $$PWD/dialogsectionheader.ui

