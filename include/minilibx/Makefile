GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ) > /dev/null
	@ranlib $(NOM) > /dev/null
	@echo "$(NOM): $(GREEN)$(NOM) was created$(RESET)"

clean:
	@rm -f $(NOM) $(OBJ) *~ > /dev/null
	@rm -f mlx_app > /dev/null
	@echo "$(NOM): $(RED)$(NOM) was deleted$(RESET)"

re: clean all
