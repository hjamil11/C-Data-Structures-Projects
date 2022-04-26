DebugFlag = -g
TemplateFlag =

p1: main.o WordData.o
# Create executable named p1 via -o option
	g++ -o p1 main.o WordData.o $(DebugFlag) $(TemplateFlag)

WordData.o: WordData.h WordData.cpp
# Make object code for the application
	g++ -c WordData.cpp $(TemplateFlag) $(DebugFlag)

main.o: WordData.h main.cpp
# Make object code for the class; explicit instantiation in test.cpp required
	g++ -c main.cpp $(TemplateFlag) $(DebugFlag)

clean:
# Remove all but source code & makefile
	/rm -f * .o