CC = g++
CCFLAGS = -Wextra -Wall -Wpedantic

CPP = g++
CPPFLAGS = -Wextra -Wall -Wpedantic

CPPSTD = -std=c++11

src_dir = src
obj_dir = obj
bin_dir = bin
out_dir = out

sources = $(addprefix $(src_dir)/, $(wildcard *.cpp))

# ? there has to be a way to generate this automagically
classes = hash contributor project
objects = $(addprefix $(obj_dir)/, $(addsuffix .o, $(classes)))

target = $(bin_dir)/hash

# Compilation

all: directories hash

obj/%.o : src/%.cpp
	${CPP} $(CPPSTD) ${CPPFLAGS} -c $< -o $@

hash: $(objects)
	$(CPP) $(CPPSTD) ${CPPFLAGS} $(objects) -o $(target)

# Debug

debug: CPPFLAGS += -ggdb
debug: all

# Set up

directories: $(obj_dir) ${bin_dir} ${out_dir}

obj:
	mkdir -p $(obj_dir)

bin:
	mkdir -p $(bin_dir)

# Clean up

clean:
	rm -f $(objects)

# Misc

remake: all

.PHONY: clean
