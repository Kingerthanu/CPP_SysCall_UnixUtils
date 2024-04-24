CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# List of source files
SRCS = mcat.cpp mgrep.cpp munzip.cpp mzip.cpp

# Generate list of object files by replacing .cpp extension with .o
OBJS = $(SRCS:.cpp=.o)

# Default target
all: mcat mgrep munzip mzip

# Compile each source file into its corresponding object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into executables
mcat: mcat.o
	$(CXX) $(CXXFLAGS) $^ -o $@

mgrep: mgrep.o
	$(CXX) $(CXXFLAGS) $^ -o $@

munzip: munzip.o
	$(CXX) $(CXXFLAGS) $^ -o $@

mzip: mzip.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up intermediate object files and executables
clean:
	rm -f *.o mcat mgrep munzip mzip
