CC=g++
CFLAGS= -Wall 
OBJS = makeind.o
INCDIR=./include
LIBDIR=./lib
DIRS = buf index recording var

.PHONY: all clean

all: MakeIndexTest
%.o: %.cpp
	$(CC) -c -I$(INCDIR) $(CFLAGS) -o $@ $<

MakeIndexTest: $(OBJS)
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
	$(CC) -o MakeIndexTest $(OBJS) -L$(LIBDIR) -lmybuffer -lmyindex -lmyrecording -lmyvar
	export LD_LIBRARY_PATH=$(LIBDIR)

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	-rm -rf MakeIndexTest *.dat $(OBJS) 
