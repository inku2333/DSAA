TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        MergeSort.cpp \
        QuickSort.cpp \
        main.cpp

HEADERS += \
        Heap.h \
        LinkedList.h \
        MergeSort.h \
        QuickSort.h \
        SortInterface.h
