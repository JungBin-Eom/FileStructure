OBJS = HW2_Main.o Student.o readstd.o writestd.o
all: main

main: $(OBJS)
	g++ -o hw2 $(OBJS)
%.o: %.cpp
	g++ -c $^

clean:
	rm $(OBJS)
