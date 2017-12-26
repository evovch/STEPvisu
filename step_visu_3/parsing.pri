# Thx http://hipersayanx.blogspot.de/2013/03/using-flex-and-bison-with-qt.html

FLEXSOURCE = ../step_visu_2/parsing/parser.l
BISONSOURCE = ../step_visu_2/parsing/parser.y

OTHER_FILES += $$FLEXSOURCE \
               $$BISONSOURCE

flexsource.input = FLEXSOURCE
flexsource.output = parser.flex.cpp
flexsource.commands = flex --header-file=parser.flex.h -o parser.flex.cpp ${QMAKE_FILE_IN}
flexsource.variable_out = SOURCES
flexsource.name = Flex Source ${QMAKE_FILE_IN}
flexsource.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += flexsource

flexheader.input = FLEXSOURCE
flexheader.output = parser.flex.h
flexheader.commands = @true
flexheader.variable_out = HEADERS
flexheader.name = Flex Header ${QMAKE_FILE_IN}
flexheader.CONFIG += target_predeps no_link

QMAKE_EXTRA_COMPILERS += flexheader

bisonsource.input = BISONSOURCE
bisonsource.output = parser.tab.cpp
bisonsource.commands = bison -d --defines=parser.tab.h -o parser.tab.cpp ${QMAKE_FILE_IN}
bisonsource.variable_out = SOURCES
bisonsource.name = Bison Source ${QMAKE_FILE_IN}
bisonsource.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += bisonsource

bisonheader.input = BISONSOURCE
bisonheader.output = parser.tab.h
bisonheader.commands = @true
bisonheader.variable_out = HEADERS
bisonheader.name = Bison Header ${QMAKE_FILE_IN}
bisonheader.CONFIG += target_predeps no_link

QMAKE_EXTRA_COMPILERS += bisonheader

LIBS += -lfl -ly
