# source, object and header files
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=obj/%.o)
HEADER := $(wildcard include/*.h)
# preprocessor flags
CPPFLAGS := -Iinclude
# compiler flags
CXXFLAGS := -Wall -O2
# additional linked libraries
LDLIBS := -lsndfile -lSDL2

all : main

main : $(OBJ)
	$(CXX) $(LDLIBS) -o $@ $^

obj/%.o : src/%.cpp $(HEADER) | obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

obj :
	mkdir $@

clean : 
	$(RM) -r obj

.PHONY : clean all

