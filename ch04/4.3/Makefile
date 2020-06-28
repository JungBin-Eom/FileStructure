CFLAGS= -Wall 
OBJS = person.o iobuffer.o delim.o fixfld.o fixlen.o varlen.o length.o BufClassTest.o
all: BufClassTest
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
BufClassTest: $(OBJS)
	g++ -o BufClassTest $(OBJS)
clean:
	-rm -rf BufClassTest $(OBJS) *.dat
