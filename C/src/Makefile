IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=

_LDEPS = list.h
LDEPS = $(patsubst %,$(IDIR)/%,$(_LDEPS))

_SDEPS = list.h stack.h
SDEPS = $(patsubst %,$(IDIR)/%,$(_SDEPS))

_LOBJ = list.o list_test.o
LOBJ = $(patsubst %,$(ODIR)/%,$(_LOBJ))

_SOBJ = list.o stack.o stack_test.o
SOBJ = $(patsubst %,$(ODIR)/%,$(_SOBJ))

$(ODIR)/%.o: %.c $(LDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.c $(SDEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: list_test stack_test

list_test: $(LOBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

stack_test: $(SOBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
