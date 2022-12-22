SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
MLXPATH = minilibx-linux/
MLX = $(MLXPATH)libmlx.a
######################################################################
SRCS = main.cpp Tup3.cpp Vec3.cpp Point3.cpp Color.cpp Ray.cpp
OBJS = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))
DEPENDS = $(OBJS:.o=.d)
######################################################################
CC = clang++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++20
LINK = -lmlx -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(MLXPATH)
LIBPATH = -L$(MLXPATH)
NAME = RayTracing
VAL = valgrind --leak-check=full ./$(NAME) input.rt
RUN = ./$(NAME) input.rt > img.ppm && eog img.ppm
######################################################################
all: $(NAME)
	$(RUN)

$(NAME): $(OBJDIR) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

-include $(DEPENDS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(MLX):
	make -C $(MLXPATH)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

run:
	$(RUN)

val:
	$(VAL)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	make clean -C $(MLXPATH)
	rm -f $(NAME)

re: fclean $(NAME) run 

.PHONY: all clean fclean re
