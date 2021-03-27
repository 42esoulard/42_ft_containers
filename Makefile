##################### CONTAINER FILES #######################
INC_CONT	= List.hpp Vector.hpp Stack.hpp Queue.hpp Map.hpp
INC_CDIR	= includes/containers/
INC_CONT 	:= $(addprefix ${INC_CDIR}, ${INC_CONT})
#############################################################

########################### UTILS ###########################
INC_UTILS	= ft_containers.h ListNode.hpp 
INC_UDIR	= includes/utils/
INC_UTILS	:= $(addprefix ${INC_UDIR},${INC_UTILS})
#############################################################

######################### TEST FILES ########################
SRC_TEST	= main.cpp List_tests.cpp Vector_tests.cpp \
				Stack_tests.cpp Queue_tests.cpp Map_tests.cpp
SRC_TDIR	= tests/
SRC_TEST 	:= $(addprefix ${SRC_TDIR}, ${SRC_TEST})

INC_TEST 	= tests.hpp
INC_TDIR	= tests/
INC_TEST	:= $(addprefix ${INC_TDIR}, ${INC_TEST})
#############################################################

################# GROUPING ALL SRCS/INCLUDES ################
SRCS 			+= ${SRC_TEST}
OBJS			= ${SRCS:.cpp=.o}
INCLUDES		= ${INC_CONT} ${INC_UTILS} ${INC_TEST}
INC_DIRS 		= $(addprefix -I,${INC_UDIR} ${INC_TDIR} ${INC_CDIR})
#############################################################

CPP			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -fno-omit-frame-pointer 
NAME		= ft_containers


.cpp.o:		${SRCS} ${INCLUDES}
			${CPP} ${CFLAGS} ${INC_DIRS} -c $^ -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJS} ${INCLUDES}
			${CPP} ${CFLAGS} ${INC_DIRS} -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME} 

re :		fclean all
