QT += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += `pkg-config --cflags --libs Qt5Widgets Qt5Sql`
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    fadministrador.cpp \
    fespecialista.cpp \
    flogin.cpp \
    main.cpp

HEADERS += \
    MainWindow.h \
    fadministrador.h \
    fespecialista.h \
    flogin.h

FORMS += \
    MainWindow.ui \
    flogin.ui \
    fadministrador.ui \
    fespecialista.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
