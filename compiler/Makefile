CC	=	g++ 
CFLAGS	=	-std=c++11 -ggdb3 -Wall -Woverloaded-virtual -pedantic -pie
GCFLAGS =	-std=c++11 -g -Wall -Wno-unused-function -Wno-unused-variable
DPFLAGS =	-MM

BASESRC =	symbol.cc symtab.cc ./parser/ast.cc ./semantics/semantic.cc ./codegen/quads.cc ./codegen/codegen.cc error.cc main.cc
SOURCES =	$(BASESRC) ./parser/parser.cc scanner.cc
BASEHDR =	symtab.hh error.hh ./parser/ast.hh ./semantics/semantic.hh ./codegen/quads.hh ./codegen/codegen.hh
HEADERS =	$(BASEHDR) ./parser/parser.hh
OBJECTS =	$(SOURCES:%.cc=%.o)
OUTFILE =	compiler

DPFILE  =	Makefile.dependencies

PATH := ../flex/bin/:../bison/bin:$(PATH)

all : $(OUTFILE) coff_rts.o

.flex :
	$(MAKE) -C ../flex
	touch $@

.bison :
	$(MAKE) -C ../bison
	touch $@

$(OUTFILE) : $(OBJECTS)
	$(CC) -o $(OUTFILE) $(OBJECTS)

foo : foo.cc
	$(CC) $(CFLAGS) -o foo

./parser/parser.cc ./parser/parser.hh : ./parser/parser.y Makefile .bison
	bison --defines --output-file=./parser/parser.cc ./parser/parser.y

scanner.cc : scanner.l .flex
	flex scanner.l

scanner.o : scanner.cc
	$(CC) $(GCFLAGS) -c $<

./semantics/semantic.o : ./semantics/semantic.cc
	$(CC) $(GCFLAGS) -c -o ./semantics/semantic.o ./semantics/semantic.cc

./parser/parser.o : ./parser/parser.cc
	$(CC) $(GCFLAGS) -c -o ./parser/parser.o ./parser/parser.cc

./parser/ast.o: ./parser/ast.cc
	$(CC) $(GCFLAGS) -c -o ./parser/ast.o ./parser/ast.cc

./codegen/quads.o: ./codegen/quads.cc
	$(CC) $(GCFLAGS) -c -o ./codegen/quads.o ./codegen/quads.cc

./codegen/codegen.o: ./codegen/codegen.cc
	$(CC) $(GCFLAGS) -c -o ./codegen/codegen.o ./codegen/codegen.cc

.cc.o: $(DPFILE)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJECTS) $(OUTFILE) core *~ scanner.cc ./parser/parser.cc ./parser/parser.hh ./parser/parser.cc.output $(DPFILE)
	touch $(DPFILE)

$(DPFILE) depend : $(BASESRC) $(HEADERS) $(SOURCES)
	$(CC) $(DPFLAGS) $(CFLAGS) $(BASESRC) > $(DPFILE)

include $(DPFILE)