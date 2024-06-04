# i tried so, so hard to make this nicer
# but i lost all my sanity and i feel like i understand makefiles even less now
# so it will have to remain like this

CC=clang
CFLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-but-set-variable -O2 ${INCLUDE}
DEBUG=-fsanitize=address,undefined -g3

INCLUDE=-Iinclude/

SRC_DIR=src
OBJ_DIR=build
OUT_DIR=lib

SOURCES=$(wildcard ${SRC_DIR}/*.c)

OUTPUT=libengine.a

final: compile move assemble clean
debug: enable-debug final

enable-debug:
	$(eval CFLAGS := ${CFLAGS} ${DEBUG})

compile:
	@echo [compiling...]
	# compile source files
	${CC} -c ${CFLAGS} ${SOURCES}

move:
	@echo [moving files...]
	#create necessary dir if it doesn't exist
	test -d ${OBJ_DIR} || mkdir ${OBJ_DIR}

	# move generated object files to obj_dir
	$(eval objs := $(wildcard *.o))
	mv ${objs} ${OBJ_DIR}

assemble:
	@echo [creating static library...]
	#create necessary dir if it doesn't exist
	test -d ${OUT_DIR} || mkdir ${OUT_DIR}

	# assemble object files into final static library file
	ar rs ${OUT_DIR}/${OUTPUT} $(wildcard ${OBJ_DIR}/*.o)

clean:
	rm $(wildcard ${OBJ_DIR}/*.o)

