#-------------------------------------------------
#
# Project created by QtCreator 2017-06-12T18:15:09
#
#-------------------------------------------------

TEMPLATE = app
TARGET   = ProgettoP2
QT       += core gui
QT       += xml
QT       += widgets
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = resources.qrc

SOURCES += model/main.cpp\
        view/mainwindow.cpp \
    model/product.cpp \
    model/videogame.cpp \
    model/base.cpp \
    model/limited.cpp \
    model/console.cpp \
    model/retroconsole.cpp \
    model/newgeneration.cpp \
    model/user.cpp \
    model/user_base.cpp \
    model/user_admin.cpp \
    model/user_premium.cpp \
    model/user_database.cpp \
    model/product_database.cpp \
    view/loginwindow.cpp \
    view/searchwindow.cpp \
    view/usersettings.cpp \
    view/productsettings.cpp \
    view/list.cpp \
    controller/mainwindow_controller.cpp \
    controller/product_controller.cpp \
    controller/user_controller.cpp \
    view/viewproduct.cpp

HEADERS  += view/mainwindow.h \
    model/product.h \
    model/videogame.h \
    model/base.h \
    model/limited.h \
    model/console.h \
    model/retroconsole.h \
    model/newgeneration.h \
    model/user.h \
    model/user_base.h \
    model/user_admin.h \
    model/user_premium.h \
    model/user_database.h \
    model/product_database.h \
    view/loginwindow.h \
    view/searchwindow.h \
    view/usersettings.h \
    view/productsettings.h \
    view/list.h \
    controller/mainwindow_controller.h \
    controller/product_controller.h \
    controller/user_controller.h \
    view/viewproduct.h

