SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
MLXPATH = minilibx-linux/
MLX = $(MLXPATH)libmlx.a
######################################################################
SRCS = main.cpp Tup3.cpp Vec3.cpp Point3.cpp Color.cpp Ray.cpp Sphere.cpp \
	   HittableList.cpp Camera.cpp Lambertian.cpp Metal.cpp Img.cpp MLXRenderer.cpp \
	   Glass.cpp

OBJS = $(addprefix $(OBJDIR),$(SRCS:.cpp=.o))
DEPENDS = $(OBJS:.o=.d)
######################################################################
CC = clang++ -O3
OPTIONALDEFINE = -DCPP_TAG
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++20
LINK = -lmlx -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(MLXPATH)
LIBPATH = -L$(MLXPATH)
NAME = RayTracing
VAL = valgrind --leak-check=full ./$(NAME) input.rt
RUN = ./$(NAME) input.rt #> img2.ppm && eog img2.ppm
######################################################################
all: $(NAME)
	$(RUN)

$(NAME): $(OBJDIR) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

-include $(DEPENDS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -c $(CFLAGS) $(OPTIONALDEFINE) $(INCPATH) $< -o $@

$(MLX):
	make -C $(MLXPATH)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	gencc

run:
	$(RUN)

val:
	$(VAL)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	make clean -C $(MLXPATH)
	rm -f $(NAME)

re: fclean
	make -j 

.PHONY: all clean fclean re
