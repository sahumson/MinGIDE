# Auto generated make file  using Mingw visual studio
SRC=jackson.cpp	jackson.h	main.cpp	
OBJ=$(SRC:.cxx=.o) # replaces the .cpp from SRC with .o
EXE=FirstVersion.exe

CC=gcc
CFLAGS=-Wall -O3
LDFLAGS=-mwindows
RM=rm

%.o: %.cxx         # combined w/ next line will compile recently changed .c files
	 $(CXX) $(CXXFLAGS) -g -o $@ -c $<

.PHONY : all     # .PHONY ignores files named all
all: $(EXE)      # all is dependent on $(EXE) to be complete

$(EXE): $(OBJ)   # $(EXE) is dependent on all of the files in $(OBJ) to exist
	 $(CXX) $(OBJ) $(LDFLAGS) -g -o $@

.PHONY : clean   # .PHONY ignores files named clean
clean:
	-$(RM) $(OBJ) core    # '-' causes errors not to exit the proces
