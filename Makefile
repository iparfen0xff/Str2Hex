CC = gcc
OBJDIR = ./build
OBJS = $(OBJDIR)/main.o
OBJS += $(OBJDIR)/converter.o

# Set project defines
CDEFS = 
#CDEFS += -DUT
#CDEFS += -DWINDOWS_VERSION 

# Set warning options used Compiler Flags
CFLAGS = -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

# Linker Flags
#LDFLAGS


# App_name (w/o extension)
APP = task

.PHONY: all rebuild clean

all:${OBJS}
	${CC} ${OBJS} ${CDEFS} ${CFLAGS} -o $(OBJDIR)/${APP}

$(OBJDIR)/converter.o: converter.c converter.h
	${CC} ${CDEFS} ${CFLAGS} -c converter.c
	mv -f converter.o $(OBJDIR)/converter.o

$(OBJDIR)/main.o: main.c converter.h
	${CC} ${CDEFS} -c main.c
	mv -f main.o $(OBJDIR)/main.o

rebuild: clean all

clean:
	rm -rf $(OBJDIR)/${APP} $(OBJDIR)/*.o
