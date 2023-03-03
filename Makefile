# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 15:31:10 by estarck           #+#    #+#              #
#    Updated: 2023/03/02 11:19:35 by estarck          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FT_STACK	= ft_container_stack
NAME_FT_MAP		= ft_container_map
NAME_FT_VECTOR	= ft_container_vector
NAME_STD_STACK	= std_container_stack
NAME_STD_MAP	= std_container_map
NAME_STD_VECTOR	= std_container_vector

INCLUDES		=	-I./include/algorithm \
					-I./include/Containers \
					-I./include/iterator \
					-I./include/other \
					-I./include/type_traits \
					-I./include/utility

SDIR			=	./srcs
_SRCS_STK_FT	=	main_stack.cpp
_SRCS_VTR_FT	=	main_vector.cpp
_SRCS_MAP_FT	=	main_map.cpp
SRCS_STK_FT		=	$(patsubst %,$(SDIR)/%,$(_SRCS_STK_FT))
SRCS_VTR_FT		=	$(patsubst %,$(SDIR)/%,$(_SRCS_VTR_FT))
SRCS_MAP_FT		=	$(patsubst %,$(SDIR)/%,$(_SRCS_MAP_FT))
_SRCS_STK_STD	=	main_stack.cpp
_SRCS_VTR_STD	=	main_vector.cpp
_SRCS_MAP_STD	=	main_map.cpp
SRCS_STK_STD	=	$(patsubst %,$(SDIR)/%,$(_SRCS_STK_STD))
SRCS_VTR_STD	=	$(patsubst %,$(SDIR)/%,$(_SRCS_VTR_STD))
SRCS_MAP_STD	=	$(patsubst %,$(SDIR)/%,$(_SRCS_MAP_STD))

ODIR		=	./bin
_OBJS_STK_FT	=	$(_SRCS_STK_FT:.cpp=_ft.o)
_OBJS_VTR_FT	=	$(_SRCS_VTR_FT:.cpp=_ft.o)
_OBJS_MAP_FT	=	$(_SRCS_MAP_FT:.cpp=_ft.o)
OBJS_STK_FT		=	$(patsubst %,$(ODIR)/%,$(_OBJS_STK_FT))
OBJS_VTR_FT		=	$(patsubst %,$(ODIR)/%,$(_OBJS_VTR_FT))
OBJS_MAP_FT		=	$(patsubst %,$(ODIR)/%,$(_OBJS_MAP_FT))
_OBJS_STK_STD	=	$(_SRCS_STK_STD:.cpp=_std.o)
_OBJS_VTR_STD	=	$(_SRCS_VTR_STD:.cpp=_std.o)
_OBJS_MAP_STD	=	$(_SRCS_MAP_STD:.cpp=_std.o)
OBJS_STK_STD		=	$(patsubst %,$(ODIR)/%,$(_OBJS_STK_STD))
OBJS_VTR_STD		=	$(patsubst %,$(ODIR)/%,$(_OBJS_VTR_STD))
OBJS_MAP_STD		=	$(patsubst %,$(ODIR)/%,$(_OBJS_MAP_STD))

# Commands bash
RM			=	rm -rf
MKODIR		=	if [ -d $(ODIR) ]; then :; else mkdir $(ODIR); fi

# Message
DELOBJS		=	printf "$(_YELLOW)Deleting .o files\n$(_END)"
DELNAME_FT_STK	=	printf "$(_RED)$(_BOLD)Remove $(NAME_FT_STACK)\n$(_END)"
DELNAME_FT_VTR	=	printf "$(_RED)$(_BOLD)Remove $(NAME_FT_VECTOR)\n$(_END)"
DELNAME_FT_MAP	=	printf "$(_RED)$(_BOLD)Remove $(NAME_FT_MAP)\n$(_END)"
DELNAME_STD_STK	=	printf "$(_RED)$(_BOLD)Remove $(NAME_STD_STACK)\n$(_END)"
DELNAME_STD_VTR	=	printf "$(_RED)$(_BOLD)Remove $(NAME_STD_VECTOR)\n$(_END)"
DELNAME_STD_MAP	=	printf "$(_RED)$(_BOLD)Remove $(NAME_STD_MAP)\n$(_END)"

# Compilation
CC			=	g++
CFLAGS		=	-std=c++98 -g -O3
CFLAGS		+=	-Wall -Wextra -Werror
STD			=	-DSTD
#ifdef STD
#	CFLAGS += -DSTD
#endif

# Formatting
_RETURN		=	$'\33[2K\r
_END		=	$'\x1b[0m
_BOLD		=	$'\x1b[1m
_UNDER		=	$'\x1b[4m
_REV		=	$'\x1b[7m

# Colors
_GREY		=	$'\x1b[30m
_RED		=	$'\x1b[31m
_GREEN		=	$'\x1b[32m
_YELLOW		=	$'\x1b[33m
_BLUE		=	$'\x1b[34m
_PURPLE		=	$'\x1b[35m
_CYAN		=	$'\x1b[36m
_WHITE		=	$'\x1b[37m

# **************************************************************************** #

all			:	$(NAME_FT_STACK) $(NAME_FT_VECTOR) $(NAME_FT_MAP) $(NAME_STD_STACK) $(NAME_STD_VECTOR) $(NAME_STD_MAP)

$(NAME_FT_STACK)	:	$(OBJS_STK_FT)
				@$(CC) $(CFLAGS) $(OBJS_STK_FT) -o $(NAME_FT_STACK)
				@printf "\n$(_GREEN)$(_BOLD)$(NAME_FT_STACK) is compiled.$(_END)\n"

$(NAME_FT_VECTOR)	:	$(OBJS_VTR_FT)
				@$(CC) $(CFLAGS) $(OBJS_VTR_FT) -o $(NAME_FT_VECTOR)
				@printf "\n$(_GREEN)$(_BOLD)$(NAME_FT_VECTOR) is compiled.$(_END)\n"

$(NAME_FT_MAP)	:	$(OBJS_MAP_FT)
				@$(CC) $(CFLAGS) $(OBJS_MAP_FT) -o $(NAME_FT_MAP)
				@printf "\n$(_GREEN)$(_BOLD)$(NAME_FT_MAP) is compiled.$(_END)\n"

$(ODIR)/main_s%_ft.o	:	$(SDIR)/$(_SRCS_STK_FT)
				@$(MKODIR)
				@printf "$(_RETURN)$(_BLUE)Compiling $(NAME_FT_STACK) in progress... $< $(_END)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ODIR)/main_v%_ft.o	:	$(SDIR)/$(_SRCS_VTR_FT)
				@$(MKODIR)
				@printf "$(_RETURN)$(_BLUE)Compiling $(NAME_FT_VECTOR) in progress... $< $(_END)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ODIR)/main_m%_ft.o	:	$(SDIR)/$(_SRCS_MAP_FT)
				@$(MKODIR)
				@printf "$(_RETURN)$(_BLUE)Compiling $(NAME_FT_MAP) in progress... $< $(_END)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME_STD_STACK)	:	$(OBJS_STK_STD)
				@$(CC) $(CFLAGS) $(STD) $(OBJS_STK_STD) -o $(NAME_STD_STACK)
				@printf "\n$(_GREEN)$(_BOLD)$(NAME_STD_STACK) is compiled.$(_END)\n"

$(NAME_STD_VECTOR)	:	$(OBJS_VTR_STD)
				@$(CC) $(CFLAGS) $(STD) $(OBJS_VTR_STD) -o $(NAME_STD_VECTOR)
				@printf "\n$(_GREEN)$(_BOLD)$(NAME_STD_VECTOR) is compiled.$(_END)\n"

$(NAME_STD_MAP)	:	$(OBJS_MAP_STD)
				@$(CC) $(CFLAGS) $(STD) $(OBJS_MAP_STD) -o $(NAME_STD_MAP)
				@printf "\n$(_GREEN)$(_BOLD)$(NAME_STD_MAP) is compiled.$(_END)\n"

$(ODIR)/main_s%_std.o	:	$(SDIR)/$(_SRCS_STK_STD)
				@$(MKODIR)
				@printf "$(_RETURN)$(_BLUE)Compiling $(NAME_STD_STACK) in progress... $< $(_END)"
				@$(CC) $(CFLAGS) $(STD) $(INCLUDES) -c $< -o $@

$(ODIR)/main_v%_std.o	:	$(SDIR)/$(_SRCS_VTR_STD)
				@$(MKODIR)
				@printf "$(_RETURN)$(_BLUE)Compiling $(NAME_STD_VECTOR) in progress... $< $(_END)"
				@$(CC) $(CFLAGS) $(STD) $(INCLUDES) -c $< -o $@

$(ODIR)/main_m%_std.o	:	$(SDIR)/$(_SRCS_MAP_STD)
				@$(MKODIR)
				@printf "$(_RETURN)$(_BLUE)Compiling $(NAME_STD_MAP) in progress... $< $(_END)"
				@$(CC) $(CFLAGS) $(STD) $(INCLUDES) -c $< -o $@

stack		:	$(NAME_FT_STACK) $(NAME_STD_STACK)

map			:	$(NAME_FT_MAP) $(NAME_STD_MAP)

vector		:	$(NAME_FT_VECTOR) $(NAME_STD_VECTOR)

clean		:
				@if [ -d $(ODIR) ]; \
					then $(RM) $(ODIR) && $(DELOBJS); \
					else printf "$(_GREEN)Already clean .o files\n$(_END)"; \
				fi

fclean		:	clean
				@if [ -f $(NAME_FT_STACK) ]; \
					then $(RM) $(NAME_FT_STACK) && $(DELNAME_FT_STK); \
					else printf "$(_GREEN)Already remove $(NAME_FT_STACK)$(_END)\n"; \
				fi
				@if [ -f $(NAME_STD_STACK) ]; \
					then $(RM) $(NAME_STD_STACK) && $(DELNAME_STD_STK); \
					else printf "$(_GREEN)Already remove $(NAME_STD_STACK)$(_END)\n"; \
				fi
				@if [ -f $(NAME_FT_VECTOR) ]; \
					then $(RM) $(NAME_FT_VECTOR) && $(DELNAME_FT_VTR); \
					else printf "$(_GREEN)Already remove $(NAME_FT_VECTOR)$(_END)\n"; \
				fi
				@if [ -f $(NAME_STD_VECTOR) ]; \
					then $(RM) $(NAME_STD_VECTOR) && $(DELNAME_STD_VTR); \
					else printf "$(_GREEN)Already remove $(NAME_STD_VECTOR)$(_END)\n"; \
				fi
				@if [ -f $(NAME_FT_MAP) ]; \
					then $(RM) $(NAME_FT_MAP) && $(DELNAME_FT_MAP); \
					else printf "$(_GREEN)Already remove $(NAME_FT_MAP)$(_END)\n"; \
				fi
				@if [ -f $(NAME_STD_MAP) ]; \
					then $(RM) $(NAME_STD_MAP) && $(DELNAME_STD_MAP); \
					else printf "$(_GREEN)Already remove $(NAME_STD_MAP)$(_END)\n"; \
				fi

re			: fclean all

.PHONY		: all clean fclean re stack map vector