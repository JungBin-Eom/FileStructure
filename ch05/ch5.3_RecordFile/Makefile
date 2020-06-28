CFLAGS= -Wall 
OBJS = iobuffer.o delim.o varlen.o buffile.o recording.o recfile.o makerec.o
all: MakeRecTest
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
MakeRecTest: $(OBJS)
	g++ -o MakeRecTest $(OBJS)
clean:
	-rm MakeRecTest $(OBJS) 
