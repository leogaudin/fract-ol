GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
OBJ			=	ft_isalnum.o ft_itoa.o ft_memset.o ft_split.o ft_strlcat.o ft_strnstr.o ft_toupper.o ft_isalpha.o ft_memchr.o ft_putchar_fd.o ft_strchr.o ft_strlcpy.o ft_strrchr.o ft_atoi.o ft_isascii.o ft_memcmp.o ft_putendl_fd.o ft_strdup.o ft_strlen.o ft_strtrim.o ft_bzero.o ft_isdigit.o ft_memcpy.o ft_putnbr_fd.o ft_striteri.o ft_strmapi.o ft_substr.o ft_calloc.o ft_isprint.o ft_memmove.o ft_putstr_fd.o ft_strjoin.o ft_strncmp.o ft_tolower.o ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o ft_intlen.o get_next_line.o get_next_line_utils.o ft_parse_width.o ft_print_padding.o ft_print_char.o ft_print_string.o ft_print_pointer.o ft_print_int.o ft_print_unsigned.o ft_print_hexa.o ft_print_percent.o ft_printf.o
HEADERS	=	libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $<
	@echo "$(NAME): $(GREEN)$@ was created$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean $(NAME)
