PHSP		= 	push_swap
CHCK		=	checker
HDR			= 	push_swap.h
SRC_UTL		= 	utilities.c utilities_list.c utilities_stack.c reverse_rotate.c rotate.c push.c swap.c
SRC_PHSP	= 	push_swap.c  sort.c sort_3.c sort_5.c sort_a.c sort_b.c print.c
SRC_CHCK	=	checker.c checker_commands.c
OBJ_UTL		=	$(patsubst %.c, %.o,$(SRC_UTL))
OBJ_PHSP	=	$(patsubst %.c, %.o,$(SRC_PHSP))
OBJ_CHCK	=	$(patsubst %.c, %.o,$(SRC_CHCK))
FLAGS	= -Wall -Wextra -Werror

all : $(PHSP) $(CHCK)

$(PHSP) : $(OBJ_PHSP) $(OBJ_UTL) $(HDR)
	gcc $(FLAGS) $(OBJ_PHSP) $(OBJ_UTL) -I $(HDR) -o $@

$(CHCK) : $(OBJ_CHCK) $(OBJ_UTL) $(HDR)
	gcc $(FLAGS) $(OBJ_CHCK) $(OBJ_UTL) -I $(HDR) -o $@

%.o : %.c
	gcc $(FLAGS) -I $(HDR) -c $< -o $@

clean :
	@rm -f $(OBJ_PHSP) $(OBJ_CHCK) $(OBJ_UTL)

fclean : clean
	@rm -f $(PHSP) $(CHCK)

re : fclean all

.PHONY : all clean fclean re
