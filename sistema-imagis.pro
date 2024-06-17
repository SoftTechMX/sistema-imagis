QT += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += `pkg-config --cflags --libs Qt5Widgets Qt5Sql`
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Config.cpp \
    FormCreateDispositivo.cpp \
    FormCreateModulo.cpp \
    FormCreateRecurso.cpp \
    FormCreateUsuario.cpp \
    FormCreateServidor.cpp \
    FormIndexActulizar.cpp \
    FormIndexConfiguracion.cpp \
    FormIndexDispositivos.cpp \
    FormIndexModulo.cpp \
    FormIndexRecursos.cpp \
    FormIndexServidores.cpp \
    FormIndexUsuarios.cpp \
    FormShowLicencia.cpp \
    FormUpdateLicencia.cpp \
    LoginWindow.cpp \
    MainWindow.cpp \
    main.cpp

HEADERS += \
    Config.h \
    FormCreateDispositivo.h \
    FormCreateModulo.h \
    FormCreateRecurso.h \
    FormCreateUsuario.h \
    FormCreateServidor.h \
    FormIndexActulizar.h \
    FormIndexConfiguracion.h \
    FormIndexDispositivos.h \
    FormIndexModulo.h \
    FormIndexRecursos.h \
    FormIndexServidores.h \
    FormIndexUsuarios.h \
    FormShowLicencia.h \
    FormUpdateLicencia.h \
    LoginWindow.h \
    MainWindow.h

FORMS += \
    FormCreateDispositivo.ui \
    FormCreateModulo.ui \
    FormCreateRecurso.ui \
    FormCreateServidor.ui \
    FormCreateUsuario.ui \
    FormIndexActulizar.ui \
    FormIndexConfiguracion.ui \
    FormIndexDispositivos.ui \
    FormIndexModulos.ui \
    FormIndexRecursos.ui \
    FormIndexServidores.ui \
    FormIndexUsuarios.ui \
    FormShowLicencia.ui \
    FormUpdateLicencia.ui \
    LoginWindow.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    q_side_panel.pri
