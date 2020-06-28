CFLAGS= -Wall 
OBJS = strclass.o strlist.o coseq.o testcoseq.o
all: MakeListTest
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
MakeListTest: $(OBJS)
	g++ -o MakeListTest $(OBJS)
clean:
	-rm MakeListTest $(OBJS) 
