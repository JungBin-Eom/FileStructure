CFLAGS= -Wall -g
OBJS1 = Person.o Readper.o Writestr.o ex4_1Main.o
OBJS2 = Person.o Readdel.o Writedel.o ex4_2Main.o
OBJS3 = Person.o Readvar.o Writevar.o ex4_3Main.o
TARGET = ex4_1 ex4_2 ex4_3
all: $(TARGET)
%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<
ex4_1: $(OBJS1)
	g++ -o $@ $(OBJS1)
ex4_2: $(OBJS2)
	g++ -o $@ $(OBJS2)
ex4_3: $(OBJS3)
	g++ -o $@ $(OBJS3)
clean:
	-rm -rf $(TARGET) $(OBJS1) $(OBJS2) $(OBJS3)
