# File: Makefile
# Author: dgrubb
# Date: 24/05/2020

# Aliases
CC  = gcc
CPP = g++
RM  = rm -rf

CPPFLAGS = -O3 \
		   -g \
		   -pedantic \
		   -Wall \
		   -Werror \
		   # Going to walk on the wild side
		   -std=c++2a

# Include directories
INC = -I./ \
	  -I./util \
	  -I./include \
	  -I./components

# Source files
SRCS = VKEngine.cc \
	components/Window.cc \
	util/Log.cc \
	util/Video.cc

OBJS=$(subst .cc,.o,$(SRCS))

LDFLAGS=-lconfig \
		-lrt \
		-lpthread \
		-lSDL2 \
		-lSDL2_image

####################
# Cleanup directives
####################

all: VKEngine

VKEngine: $(OBJS)
	$(CPP) $(INC) -o VKEngine $(OBJS) $(LDFLAGS)

%.o: %.cc
	$(CPP) $(CPPFLAGS) $(INC) -c $< -o $@

check:
	cppcheck -v --std=c++20 --language=c++ --enable=all ./

clean: clean-objects

dist-clean: clean-objects
	$(RM) VKEngine

clean-objects:
	for i in $(OBJS); \
		do (if test -e "$$i"; then ($(RM) $$i ); fi ); done
