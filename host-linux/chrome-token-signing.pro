TEMPLATE = app
CONFIG += console c++11 link_pkgconfig
CONFIG -= app_bundle
QT += widgets network
isEmpty(VERSION):VERSION=1.0.0.0
PKGCONFIG += openssl libpcsclite
INCLUDEPATH += ../host-shared
LIBS += -ldl -L /usr/lib/watchdata/pcsc -l:libpcsclite_wd.so.1.0.0
DEFINES += VERSION=\\\"$$VERSION\\\"
SOURCES += \
    ../host-shared/Labels.cpp \
    ../host-shared/Logger.cpp \
    ../host-shared/BinaryUtils.cpp \
    ../host-shared/AtrFetcher.cpp \
    ../host-shared/PKCS11Path.cpp \
    chrome-host.cpp
HEADERS += *.h ../host-shared/*.h
RESOURCES += chrome-token-signing.qrc
target.path = /usr/bin
hostconf.path = /etc/opt/chrome/native-messaging-hosts
hostconf.files += ee.ria.esteid.json
extension.path = /opt/google/chrome/extensions
extension.files += ../ckjefchnfjhjfedoccjbhjpbncimppeg.json
INSTALLS += target hostconf extension
