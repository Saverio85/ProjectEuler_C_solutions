#  -g    adds debug info
#  -Wall enable comiler warning
CC = gcc
CFLAGS  = -g -O -Wall -Weffc++ -pedantic  \
    -pedantic-errors -Wextra -Waggregate-return -Wcast-align \
    -Wcast-qual  -Wchar-subscripts  -Wcomment -Wconversion \
    -Wdisabled-optimization \
    -Werror -Wfloat-equal  -Wformat  -Wformat=2 \
    -Wformat-nonliteral -Wformat-security  \
    -Wformat-y2k \
    -Wimplicit  -Wimport  -Winit-self  -Winline \
    -Winvalid-pch   \
    -Wlong-long -Wmissing-braces \
    -Wmissing-field-initializers -Wmissing-format-attribute   \
    -Wmissing-include-dirs -Wmissing-noreturn \
    -Wpacked  -Wpadded -Wparentheses  -Wpointer-arith \
    -Wredundant-decls -Wreturn-type \
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default \
    -Wswitch-enum -Wtrigraphs  -Wuninitialized \
    -Wunknown-pragmas  -Wunreachable-code -Wunused \
    -Wunused-function  -Wunused-label  -Wunused-parameter \
    -Wunused-value  -Wunused-variable  -Wvariadic-macros \
    -Wvolatile-register-var  -Wwrite-strings
CCOMMON = lib/common.o lib/linkedlist.o

default: problem1 problem2 problem3 problem4 problem5 problem6 problem7 problem8

problem1:  common.o linkedlist.o
	$(CC) $(CFLAGS) -o problem1 problem1.c $(CCOMMON) 

problem2:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem2 problem2.c $(CCOMMON)

problem3:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem3 problem3.c $(CCOMMON)

problem4:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem4 problem4.c $(CCOMMON)

problem5:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem5 problem5.c $(CCOMMON)

problem6:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem6 problem6.c $(CCOMMON)

problem7:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem7 problem7.c $(CCOMMON)

problem8:  common.o linkedlist.o 
	$(CC) $(CFLAGS) -o problem8 problem8.c $(CCOMMON)

common.o:
	$(CC) $(CFLAGS) -c lib/common.c -o lib/common.o

linkedlist.o:
	$(CC) $(CFLAGS) -c lib/linkedlist.c -o lib/linkedlist.o

clean: 
	$(RM) count *.o *~