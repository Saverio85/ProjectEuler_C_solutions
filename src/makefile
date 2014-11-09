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
CCOMMON = lib/common.o lib/linkedlist.o lib/numerics.o

default: problem23

problem23:  common.o linkedlist.o numerics.o
	$(CC) $(CFLAGS) -o problem23 problem23.c $(CCOMMON) 

common.o:
	$(CC) $(CFLAGS) -c lib/common.c -o lib/common.o

linkedlist.o:
	$(CC) $(CFLAGS) -c lib/linkedlist.c -o lib/linkedlist.o

numerics.o:
	$(CC) $(CFLAGS) -c lib/numerics.c -o lib/numerics.o

clean: 
	$(RM) count *.o *~