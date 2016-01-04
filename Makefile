# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/12 23:33:03 by p                 #+#    #+#              #
#    Updated: 2016/01/01 12:56:20 by qlitzler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gomoku
# Compilation settings
CC = clang++ -std=c++11
CFLAGS = -Werror -Wextra -Wall -O3
GLFW = -Llibs -lglfw3
GLEW = -Llibs -lglew
FRAMEWORK =  $(GLFW) $(GLEW) -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Custom paths
DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCS = -Iincs/ -Iincs/libs/glfw -I/libs/incs/glm -I/incs/libs/GL

#------------------------------------------------------------------------------#

FILES =	main.cpp \
		game/Board.cpp \
		game/Gomoku.cpp \
		game/Intersection.cpp \
		gui/Window.cpp \
		gui/Camera.cpp \
		gui/Model3D.cpp \
		gui/ParserTGA.cpp \
		gui/opengl/GUIOpenGL.cpp \
		gui/opengl/object/GLObject.cpp \
		gui/opengl/object/GLParser.cpp \
		gui/opengl/object/GLBoard.cpp \
		gui/opengl/object/GLStone.cpp \
		gui/opengl/object/GLStoneBlack.cpp \
		gui/opengl/object/GLStoneWhite.cpp \
		gui/opengl/shader/GLShader.cpp \
		gui/opengl/shader/GLShaderStone.cpp \
		gui/opengl/shader/GLShaderBoard.cpp \


#------------------------------------------------------------------------------#

# Apply custom paths
SRCS = $(addprefix $(DIR_SRCS), $(FILES))
OBJS = $(addprefix $(DIR_OBJS), $(FILES:.cpp=.o))

# Colors
RED = \x1b[31;01m
GREEN = \x1b[32;01m
CYAN = \x1b[34;01m
RESET = \x1b[39;49;00m

# Rules
all: $(NAME)
	
$(NAME): $(OBJS)
	@ printf "Linking  "
	@ $(CC) $(OBJS) $(CFLAGS) $(DIR_INCS) $(FRAMEWORK) -o $(NAME)
	@ printf "$(GREEN)DONE$(RESET)\n"
	@ echo "Program $(RED)$(NAME)$(RESET) -> $(GREEN)COMPLETED$(RESET)"

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
	@ echo "Building $(CYAN)$< $(RESET)"
	@ mkdir -p $(DIR_OBJS)
	@ mkdir -p $(DIR_OBJS)gui/
	@ mkdir -p $(DIR_OBJS)gui/opengl/
	@ mkdir -p $(DIR_OBJS)gui/opengl/object/
	@ mkdir -p $(DIR_OBJS)gui/opengl/shader/
	@ mkdir -p $(DIR_OBJS)game/
	@ $(CC) $(CFLAGS) $(DIR_INCS) -c $< -o $@

clean:
	@ rm -f $(OBJS)
	@ rm -rf $(DIR_OBJS)
	@ echo "Clean    $(GREEN)DONE$(RESET)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "Fclean   $(GREEN)DONE$(RESET)"

re: fclean all

.PHONY: all clean fclean re