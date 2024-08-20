######################## SETTINGS ########################

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES =	includes \
			.

######################## SOURCES ########################

IS_CHECKERS =	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isspace.c \
				ft_isabovemid.c \
				ft_isprint.c

PRINTERS =	ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_base.c \
			ft_putarr.c \
			ft_putlst.c \
			ft_printf.c

STRINGS =	ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strcontains.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_splittoi.c \
			ft_countchar.c \
			ft_reachchar.c \
			ft_skipchar.c \
			ft_strmapi.c \
			ft_strcut.c \
			ft_striteri.c

MEMORY =	ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_free.c

CONVERTERS =	ft_itoa.c \
				ft_atoi.c \
				ft_lsttoi.c \
				ft_lsttos.c \
				ft_abs.c \
				ft_toupper.c \
				ft_tolower.c

READ_FILES =	get_next_line.c \
				get_next_line_utils.c \
				get_lines.c

ARRAYS =	remove_index.c \
			ft_arrdup.c \
			ft_arradd.c

LINKED_LISTS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

SRCS_NAMES =	${addprefix is_checkers/, ${IS_CHECKERS}} \
				${addprefix printers/, ${PRINTERS}} \
				${addprefix strings/, ${STRINGS}} \
				${addprefix memory/, ${MEMORY}} \
				${addprefix converters/, ${CONVERTERS}} \
				${addprefix read_files/, ${READ_FILES}} \
				${addprefix arrays/, ${ARRAYS}} \
				${addprefix linked_lists/, ${LINKED_LISTS}}

SRCS_DIR = srcs/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAMES}}

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS_NAMES:.c=.o}}

######################## RULES ########################

all: ${NAME}

${NAME}: ${OBJS_DIR} ${OBJS}
	ar -rc ${NAME} ${OBJS}

${OBJS_DIR}:
	mkdir ${OBJS_DIR}
	mkdir ${OBJS_DIR}is_checkers
	mkdir ${OBJS_DIR}printers
	mkdir ${OBJS_DIR}strings
	mkdir ${OBJS_DIR}memory
	mkdir ${OBJS_DIR}converters
	mkdir ${OBJS_DIR}arrays
	mkdir ${OBJS_DIR}linked_lists
	mkdir ${OBJS_DIR}read_files

${OBJS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${FLAGS} ${foreach include, ${INCLUDES},-I ${include}} -c $< -o $@

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

norm :
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${foreach include, ${INCLUDES}, ${include}/*.h}

re: fclean all