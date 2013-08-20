load(qt_build_config)

TARGET = QtModeling
QT = core core-private

QMAKE_DOCS = $$PWD/doc/qtmodeling.qdocconf

load(qt_module)

PUBLIC_HEADERS += \
    qtmodelingglobal.h \
    qwrappedobject.h \
    qguardedlist.h \
    qguardedset.h \
    qsignaledpointer.h

PRIVATE_HEADERS +=

SOURCES += \
    qwrappedobject.cpp

HEADERS += $$PUBLIC_HEADERS $$PRIVATE_HEADERS
