TEMPLATE = app
TARGET = twitter

CONFIG += qt warn_on debug_and_release
QT     += declarative script svg sql network
LIBS   += -lbb -lQtCascades -lheimdall ${QNX_TARGET}/../target-override/armle-v7/usr/lib/libQtCascades_main.a

INCLUDEPATH += ../src
SOURCES += ../src/*.cpp ../src/oauth/*.cpp
HEADERS += ../src/*.hpp ../src/*.h ../src/oauth/*.hpp ../src/oauth/*.h

device {
	CONFIG(release, debug|release) {		
		DESTDIR = o.le-v7		
	} 
	CONFIG(debug, debug|release) {
		DESTDIR = o.le-v7-g
	}
}

simulator {
	CONFIG(release, debug|release) {
		DESTDIR = o
	} 
	CONFIG(debug, debug|release) {
		DESTDIR = o-g
	}
}

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.moc
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR = $${DESTDIR}/.ui

