# Set compiler.
CXX=g++

# Set flags.
CXXFLAGS=-Wall -O3 -std=c++17 -fopenmp
CXXFLAGS+=-MD -MP # Autogenerate dependencies. MUST NOT BE DELETED.

# Directories.
BUILDDIR=build
SRCDIR=src
OBJDIR=$(BUILDDIR)/obj

# Files.
SRCS:=$(shell find $(SRCDIR) -name "*.cpp")
OBJS:=$(subst $(SRCDIR),$(OBJDIR),$(SRCS:%.cpp=%.o))
DEPS:=$(subst $(SRCDIR),$(OBJDIR),$(SRCS:%.cpp=%.d))

#
# Executables.
#
MAIN=$(BUILDDIR)/main
MAIN_OBJS=$(OBJDIR)/main.o

.PHONY: all
all: main

main: $(MAIN)

#
# Generate executables
#
$(MAIN): $(MAIN_OBJS)
	$(CXX) $^ -o $@

#
# Generate objects.
#
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependencies.
-include $(DEPS)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/*
	rm -rf $(INCLUDEDIR)/*
