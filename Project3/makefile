COMPILER  = g++

DEBUG  = -g

EXE = app

HDRS = WordData.h\
	WordDataList.h\
	WordVectorList.h\
	WordCList.h\
	CLinkedList.h\
	WordList.h\

OBJS = WordData.o\
	WordDataList.o\
	WordVectorList.o\
	WordCList.o\
	app.o\

SRC = WordData.cpp\
	WordDataList.cpp\
	WordVectorList.cpp\
	WordCList.cpp\
	app.cpp\

##########################################################################
$(EXE): $(OBJS) $(HDRS) $(SRC)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

WordData.o:    WordData.cpp WordData.h
	$(COMPILER)	-c WordData.cpp	$(DEBUG)

WordDataList.o:   WordData.h WordDataList.cpp WordDataList.h WordList.h
	$(COMPILER)	-c WordDataList.cpp $(DEBUG)

WordVectorList.o:	WordData.h WordVectorList.cpp WordVectorList.h WordList.h
	$(COMPILER) -c WordVectorList.cpp $(DEBUG)

WordCList.o:	WordData.h WordCList.cpp WordCList.h WordList.h
	$(COMPILER)	-c WordCList.cpp $(DEBUG)

app.o:	WordDataList.h WordVectorList.h	WordCList.h WordList.h app.cpp
	$(COMPILER)	-c app.cpp $(DEBUG)



clean:
	del *.o $(EXE)