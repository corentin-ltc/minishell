######################## SETTINGS ########################

NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBS = libft \

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}

######################## SOURCES ########################

SRCS_NAMES =	main.c \
				init.c \
				parsing.c \
				pipex.c \
				exit.c

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.c=.o}}

######################## BASIC RULES ########################

all : ${NAME}

re : fclean
	${MAKE} all

clean :
	${foreach lib, ${LIBS}, ${MAKE} clean -C ${lib}}
	rm -rf ${OBJS_DIR}

fclean : clean
	${foreach lib, ${LIBS}, ${MAKE} fclean -C ${lib}}
	rm -f ${NAME}

norm :
	${foreach lib, ${LIBS}, ${MAKE} norm -C ${lib}}
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCLUDES}

######################## COMPILATION ########################

${NAME} : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o $@ ${LINKFLAGS}

debug : ${OBJS_DIR} ${OBJS}
	${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
	${CC} ${FLAGS} -g3 -fsanitize=address ${OBJS} ${foreach lib, ${LIBS},${lib}/${lib}.a} -o ${NAME} ${LINKFLAGS}

${OBJS_DIR} :
	mkdir $@

${OBJS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@
	
######################## TEST ########################

test : all
	./${NAME} infile "ls -l" "wc -l" /dev/stdout

here : all
	./${NAME} here_doc EOF "cat" "wc -l" /dev/stdout

leak : all
	valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./${NAME} infile "echo premier" "echo bye" outfile