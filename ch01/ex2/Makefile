CFLAGS= -Wall -g
OBJS = Strclass.o StrMain.o
all: strTest
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
strTest: $(OBJS)
	g++ -o strTest $(OBJS)
clean:
	rm strTest $(OBJS)
