COMP=clang
OPTIONS=-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-but-set-variable -O2
DEBUG=-fsanitize=address,undefined -g3

SOURCES=src/*
OUTPUT=engine-test
INCLUDE=-Iinclude/

final:
	${COMP} ${OPTIONS} ${SOURCES} ${INCLUDE} -o ${OUTPUT}

debug:
	${COMP} ${OPTIONS} ${DEBUG} ${SOURCES} ${INCLUDE} -o ${OUTPUT}
