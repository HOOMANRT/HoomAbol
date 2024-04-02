QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainpage.cpp \
    register.cpp \
    setprofile.cpp \
    splash.cpp \
    verificationcode.cpp

HEADERS += \
    login.h \
    mainpage.h \
    register.h \
    setprofile.h \
    splash.h \
    verificationcode.h

FORMS += \
    login.ui \
    mainpage.ui \
    register.ui \
    setprofile.ui \
    splash.ui \
    verificationcode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images/images.qrc
