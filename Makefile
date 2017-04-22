#
# setup control
#
#DEBUG = TRUE
TOP     := $(shell pwd)/
OBJ     := $(TOP)
BIN     := $(TOP)
SRC     := $(TOP)
INCLUDE  := $(TOP)

ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs)


#	
# set up compilers
#	
CPP     = g++
CPPFLAGS = -O -Wall -fPIC -I$(INCLUDE) $(ROOTCFLAGS)

CPPLIBS = $(ROOTLIBS) $(ROOTGLIBS)

ifeq ($(DEBUG), TRUE)
CPPFLAGS += -g
endif

ifeq ($(PURIFY), TRUE)
LD = purify $(CPP)
else
LD     = $(CPP)
endif

############## Make Executables ####################################
all: dep 

dep   	: $(patsubst $(SRC)%.cxx,$(OBJ)%.o,$(wildcard $(SRC)*.cxx))
	$(LD) $^ $(CPPLIBS) -o $(BIN)$(notdir $@)
	@echo

######################################################
$(OBJ)%.o : 	$(SRC)%.cxx
	$(CPP)  $(CPPFLAGS) -c $(SRC)$(notdir $<) -o $(OBJ)$(notdir $@)
	@echo	

foo:
	@echo

.PHONY: clean
clean:
	rm -f *.o 
	rm -f dep
