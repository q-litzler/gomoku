# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/12 23:33:03 by p                 #+#    #+#              #
#    Updated: 2016/01/25 11:13:57 by qlitzler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gomoku
# Compilation settings
CC = clang++ -std=c++11
CFLAGS = -Werror -Wextra -Wall -O3
GLFW = -Llibs -lglfw3
GLEW = -Llibs -lglew
FREETYPE = /usr/X11/lib/libfreetype.6.dylib
FRAMEWORK =  $(GLFW) $(GLEW) $(FREETYPE) -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Custom paths
DIR_REPLAY = replay/
DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCS = -Iincs/ -Iincs/libs/glfw -Iincs/libs/glm -Iincs/libs/GL -Iincs/libs/font

#------------------------------------------------------------------------------#

FILES =	main.cpp \
		game/AI.cpp \
		game/Board.cpp \
		game/Gomoku.cpp \
		game/Coord.cpp \
		game/Pattern.cpp \
		game/Replay.cpp \
		game/Intersection.cpp \
		gui/Window.cpp \
		gui/Camera.cpp \
		gui/model/Model.cpp \
		gui/model/Model2D.cpp \
		gui/model/Model3D.cpp \
		gui/ParserTGA.cpp \
		gui/opengl/GUIOpenGL.cpp \
		gui/opengl/Panels.cpp \
		gui/opengl/object/GLFactory.cpp \
		gui/opengl/object/GLFont.cpp \
		gui/opengl/object/GLObject.cpp \
		gui/opengl/object/GLParser.cpp \
		gui/opengl/object/GLBoard.cpp \
		gui/opengl/object/GLStone.cpp \
		gui/opengl/shader/GLSFactory.cpp \
		gui/opengl/shader/GLSBuilder.cpp \
		gui/opengl/shader/GLShader.cpp \
		gui/opengl/shader/GLSFont.cpp \
		gui/opengl/shader/GLSStone.cpp \
		gui/opengl/shader/GLSBoard.cpp \


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
	@ mkdir -p $(DIR_REPLAY)
	@ mkdir -p $(DIR_OBJS)
	@ mkdir -p $(DIR_OBJS)gui/
	@ mkdir -p $(DIR_OBJS)gui/model/
	@ mkdir -p $(DIR_OBJS)gui/opengl/
	@ mkdir -p $(DIR_OBJS)gui/opengl/object/
	@ mkdir -p $(DIR_OBJS)gui/opengl/shader/
	@ mkdir -p $(DIR_OBJS)game/
	@ $(CC) $(CFLAGS) $(DIR_INCS) -c $< -o $@

clean:
	@ rm -f $(OBJS)
	@ rm -rf $(DIR_OBJS)
	@ echo "Clean    $(GREEN)DONE$(RESET)"

replay: fclean
	@ rm -rf $(DIR_REPLAY)

fclean: clean
	@ rm -f $(NAME)
	@ echo "Fclean   $(GREEN)DONE$(RESET)"

re: fclean all

.PHONY: all clean fclean re