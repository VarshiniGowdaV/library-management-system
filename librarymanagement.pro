QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        admin.c \
        book.c \
        borrowedbook.c \
        department.c \
        fileopration.c \
        library.c \
        main.c \
        main1.c \
        returnedbook.c \
        sortbyauthor.c \
        sortbybookname.c \
        staff.c \
        studend.c

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    admin.h \
    books.h \
    borrowedbook.h \
    department.h \
    enum.h \
    fileoperation.h \
    library.h \
    main1.h \
    returnedbook.h \
    sortbyauthor.h \
    sortbybookname.h \
    staff.h \
    student.h
