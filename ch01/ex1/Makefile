CFLAGS= -Wall 
OBJS = Person.o PersonTest.o
all: ptest
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
ptest: $(OBJS)
	g++ -o ptest $(OBJS)
clean:
	rm ptest $(OBJS)
