CFLAGS= -Wall 
OBJS = Person.o Deltext.o Lentext.o Fixtext.o testBuffer.o
all: testBuffer
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
testBuffer: $(OBJS)
	g++ -o testBuffer $(OBJS)
clean:
	-rm -f testBuffer $(OBJS) 
