/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIOpenGL.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:17:19 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 21:57:58 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/GUIOpenGL.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GUIOpenGL::GUIOpenGL(Window const & window, Model3D & model3D, Camera & camera, Gomoku & gomoku):
IGUIModule(window), _model3D(model3D), _camera(camera), _gomoku(gomoku)
{
	GLwindow();
	GLcontext();
	glfwSetKeyCallback(_glWindow, &GUIOpenGL::inputHandler);
	GUIOpenGL::_GLFW = this;
}

GUIOpenGL::~GUIOpenGL(void)
{

}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void		GUIOpenGL::GLwindow(void)
{
	if (!glfwInit())
	{
		throw std::exception();
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	_glWindow = glfwCreateWindow(_window.width, _window.height, _window.name.c_str(), nullptr, nullptr);
	if (!_glWindow)
	{
		glfwTerminate();
		throw std::exception();
	}
}

void		GUIOpenGL::GLcontext(void)
{
	glfwMakeContextCurrent(_glWindow);
	glewExperimental = GL_TRUE;
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		throw std::exception();
	}
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	glFrontFace(GL_CCW); 
	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void		GUIOpenGL::setup(void)
{
	_board = new GLBoard(_model3D, _camera, new GLShaderBoard());
	_stones[WHITE] = new GLStoneWhite(_model3D, _camera, new GLShaderStone());
	_stones[BLACK] = new GLStoneBlack(_model3D, _camera, new GLShaderStone());
}

int			GUIOpenGL::render(void)
{
	if (glfwWindowShouldClose(_glWindow))
	{
		return (ESC);
	}
	clearCalls();
	glClearColor(0.01f, 0.01f, 0.01f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (_gomoku.getVictory() == NONE) {
		addGhost(_gomoku.getPlayer(), _gomoku.getGhost());
	}
	addStones(_gomoku.getBoard().getIntersections());
	drawCalls();


	glfwSwapBuffers(_glWindow);
	glfwPollEvents();
	return (CONTINUE);
}

void		GUIOpenGL::clearCalls(void)
{
	_stones[WHITE]->clear();
	_stones[BLACK]->clear();
}

void		GUIOpenGL::drawCalls(void)
{
	_board->draw();
	glEnable(GL_BLEND);
	_stones[WHITE]->draw();
	_stones[BLACK]->draw();
	glDisable(GL_BLEND);
}

void		GUIOpenGL::addGhost(int const & turn, Intersection const & ghost)
{
	_stones[turn]->add(ghost.x, ghost.y, 0.7f);
}

void		GUIOpenGL::addStones(std::vector<Intersection> const & intersections)
{
	std::vector<Intersection>::const_iterator	it;

	for (it = intersections.begin(); it != intersections.end(); ++it)
	{
		int stone = (*it).stone;
		if (stone != NONE)
		{
			_stones[stone]->add((*it).x, (*it).y, 1.0f);
		}
	}
}

GUIOpenGL *	GUIOpenGL::_GLFW = nullptr;

void		GUIOpenGL::inputHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static_cast<void>(scancode);
	static_cast<void>(mods);
	if (action != GLFW_PRESS && action != GLFW_REPEAT) {
		return ;
	}
	switch(key) {
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		case GLFW_KEY_LEFT:
			GUIOpenGL::_GLFW->_model3D.setRotation(-0.10f);
			break;
		case GLFW_KEY_RIGHT:
			GUIOpenGL::_GLFW->_model3D.setRotation(0.10f);
			break;
		case GLFW_KEY_UP:
			GUIOpenGL::_GLFW->_camera.move(glm::vec3(0.0f, 0.5f, 0.0f));
			break;
		case GLFW_KEY_DOWN:
			GUIOpenGL::_GLFW->_camera.move(glm::vec3(0.0f, -0.5f, 0.0f));
			break;
		case GLFW_KEY_KP_ADD:
		case GLFW_KEY_EQUAL:
			GUIOpenGL::_GLFW->_model3D.setScale(1.1f);
			break;
		case GLFW_KEY_KP_SUBTRACT:
		case GLFW_KEY_MINUS:
			GUIOpenGL::_GLFW->_model3D.setScale(0.9f);
			break;
		case GLFW_KEY_W:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(0, -1);
			break;
		case GLFW_KEY_A:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(-1, 0);
			break;
		case GLFW_KEY_S:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(0, 1);
			break;
		case GLFW_KEY_D:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(1, 0);
			break;
		case GLFW_KEY_ENTER:
			GUIOpenGL::_GLFW->_gomoku.addStone();
			break;
		case GLFW_KEY_R:
			GUIOpenGL::_GLFW->_gomoku.reset();
			break;
	}
}