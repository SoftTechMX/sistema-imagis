QT += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += `pkg-config --cflags --libs Qt5Widgets Qt5Sql`
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Config.cpp \
    FormCreateProducto.cpp \
    FormCreateUsuario.cpp \
    FormIndexProducto.cpp \
    FormIndexUsuarios.cpp \
    FormShowLicencia.cpp \
    FormUpdateLicencia.cpp \
    FormUpdateUsuario.cpp \
    LoginWindow.cpp \
    MainWindow.cpp \
    main.cpp

HEADERS += \
    Config.h \
    FormCreateProducto.h \
    FormCreateUsuario.h \
    FormIndexProducto.h \
    FormIndexUsuarios.h \
    FormShowLicencia.h \
    FormUpdateLicencia.h \
    FormUpdateUsuario.h \
    LoginWindow.h \
    MainWindow.h

FORMS += \
    FormCreateProducto.ui \
    FormCreateUsuario.ui \
    FormIndexProducto.ui \
    FormIndexUsuarios.ui \
    FormShowLicencia.ui \
    FormUpdateLicencia.ui \
    FormUpdateUsuario.ui \
    LoginWindow.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    q_side_panel.pri
