#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
project(qconnectfour)

find_package(Qt4 COMPONENTS QtCore QtGui)

include(${QT_USE_FILE})

set(QCONNECTFOUR_HDRS
	mainwindow.h
	board.h
	boardwidget.h)

set(QCONNECTFOUR_SRCS
	main.cpp
	mainwindow.cpp
	board.cpp
	boardwidget.cpp)

QT4_AUTOMOC(${QCONNECTFOUR_SRCS})

add_executable(qconnectfour ${QCONNECTFOUR_SRCS})

target_link_libraries(qconnectfour ${QT_LIBRARIES})

