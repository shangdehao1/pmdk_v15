#
# examples/libpmemobj/string_store/Makefile -- build the intro 1 example
#
PROGS = writer reader

LIBS = -lpmemobj -lpmem -pthread

include ../../Makefile.inc

writer: writer.o
reader: reader.o
clean :
	rm writer reader
