######################## SETTINGS ########################

NAME = minishell

CC = cc

FLAGS = #-Wall -Wextra -Werror

LINKFLAGS = -lreadline

LIBS = libft \

INCLUDES =	includes \
			${foreach lib, ${LIBS}, ${lib} ${lib}/includes}

######################## SOURCES ########################

INIT =	init.c \
		signals.c

PARSING =	split.c \
			parser.c \
			vars.c \
			infiles.c \
			cmds.c \
			utils.c

ERRORS =	errors.c

EXEC =	

BUILTIN =	builtin.c \
			echo.c \
			cd.c \
			pwd.c \
			env.c \
			unset.c \
			export.c \
			exit.c

UTILS =	env.c

SRCS_NAMES =	main.c \
				${addprefix init/, ${INIT}} \
				${addprefix parsing/, ${PARSING}} \
				${addprefix errors/, ${ERRORS}} \
				${addprefix exec/, ${EXEC}} \
				${addprefix builtin/, ${BUILTIN}} \
				${addprefix utils/, ${UTILS}} \

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.c=.o}}

######################## BASIC RULES ########################

all : 
	${MAKE} -j ${NAME}

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
	mkdir $@init
	mkdir $@parsing
	mkdir $@errors
	mkdir $@exec
	mkdir $@builtin
	mkdir $@utils

${OBJS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

######################## TEST ########################

test : base

base : all
	./${NAME}

leak : all
	valgrind --suppressions=readline.supp --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./${NAME}