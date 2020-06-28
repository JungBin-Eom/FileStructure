CC=g++
CFLAGS= -Wall 
OBJS = testIdxFile.o
INCDIR=./include
LIBDIR=./lib
DIRS = buf fixed index recording var

.PHONY: all clean

all: testIdxFile
%.o: %.cpp
	$(CC) -c -I$(INCDIR) $(CFLAGS) -o $@ $<

testIdxFile: $(OBJS)
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
	$(CC) -o testIdxFile $(OBJS) -L$(LIBDIR) -lmybuffer -lmyfixed -lmyindex -lmyrecording -lmyvar
	export LD_LIBRARY_PATH=$(LIBDIR)

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	-rm -rf testIdxFile recording.dat recording.ind $(OBJS) 
