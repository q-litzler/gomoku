/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIOpenGL.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:17:19 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:09:23 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/GUIOpenGL.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GUIOpenGL::GUIOpenGL(Window const & window, Gomoku & gomoku):
IGUIModule(window), _gomoku(gomoku)
{
	GLwindow();
	GLcontext();
	glfwGetFramebufferSize(_glWindow, &_width, &_height);
	glfwSetKeyCallback(_glWindow, &GUIOpenGL::inputHandler);
	GUIOpenGL::_GLFW = this;
}

GUIOpenGL::~GUIOpenGL(void)
{
	delete _stones[WHITE];
	delete _stones[BLACK];
	delete _board;
	delete _font[FONT10];
	delete _font[FONT12];
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
	// glfwGetPrimaryMonitor()
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
	glEnable(GL_MULTISAMPLE_ARB);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	glFrontFace(GL_CCW);
}

void		GUIOpenGL::setup(void)
{
	_board = static_cast<GLBoard *>(GLFactory::newInstance(GL_BOARD));
	_stones[WHITE] = static_cast<GLStone *>(GLFactory::newInstance(GL_STONE_WHITE));
	_stones[BLACK] = static_cast<GLStone *>(GLFactory::newInstance(GL_STONE_BLACK));
	_font[FONT10] = static_cast<GLFont *>(GLFactory::newInstance(GL_FONT10));
	_font[FONT12] = static_cast<GLFont *>(GLFactory::newInstance(GL_FONT12));
}

int			GUIOpenGL::render(void)
{
	if (glfwWindowShouldClose(_glWindow))
	{
		return (ESC);
	}
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	clearCalls();

	if (_gomoku.getVictory() == NONE && _gomoku.getMode() != REPLAY) {
		addGhost(_gomoku.getPlayer(), _gomoku.getGhost());
	}
	addStones(_gomoku.getBoard().getBoard());
	drawCalls();

	glfwPollEvents();
	glfwSwapBuffers(_glWindow);
	return (CONTINUE);
}

void		GUIOpenGL::clearCalls(void)
{
	_stones[WHITE]->clear();
	_stones[BLACK]->clear();
}

void		GUIOpenGL::drawCalls(void)
{
	Panels::viewport(0, _width, _height);
	_board->draw();
	_stones[WHITE]->draw();
	_stones[BLACK]->draw();
	Panels::viewport(_width * Panels::_centerPanel, _width, _height);
	Panels::rightPanel(_gomoku, _font);
}

void		GUIOpenGL::addGhost(int const & turn, Intersection const & ghost)
{
	_stones[turn]->add(ghost.coord.x, ghost.coord.y, 0.7f);
}

void		GUIOpenGL::addStones(t_board const & intersections)
{
	t_board::const_iterator		it;

	for (it = intersections.begin(); it != intersections.end(); ++it)
	{
		int stone = (*it).stone;
		if (stone != NONE)
		{
			_stones[stone]->add((*it).coord.x, (*it).coord.y, 1.0f);
		}
	}
}

GUIOpenGL *	GUIOpenGL::_GLFW = nullptr;

void		GUIOpenGL::rotate(GLfloat const & angle)
{
	GUIOpenGL::_GLFW->_board->rotate(angle);
	GUIOpenGL::_GLFW->_stones[BLACK]->rotate(angle);
	GUIOpenGL::_GLFW->_stones[WHITE]->rotate(angle);
}

void		GUIOpenGL::move(glm::vec3 const & position)
{
	GUIOpenGL::_GLFW->_board->move(position);
	GUIOpenGL::_GLFW->_stones[BLACK]->move(position);
	GUIOpenGL::_GLFW->_stones[WHITE]->move(position);
}

void		GUIOpenGL::scale(GLfloat const & delta)
{
	GUIOpenGL::_GLFW->_board->scale(delta);
	GUIOpenGL::_GLFW->_stones[BLACK]->scale(delta);
	GUIOpenGL::_GLFW->_stones[WHITE]->scale(delta);
}

void		GUIOpenGL::reset(void)
{
	GUIOpenGL::_GLFW->_board->reset();
	GUIOpenGL::_GLFW->_stones[BLACK]->reset();
	GUIOpenGL::_GLFW->_stones[WHITE]->reset();
}

void		GUIOpenGL::inputHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static_cast<void>(scancode);
	static_cast<void>(mods);
	if (action != GLFW_PRESS && action != GLFW_REPEAT) {
		return ;
	}
	GLfloat const		angle = 0.10f;
	GLfloat const		scaleUp = 1.1f;
	GLfloat const		scaleDown = 0.9f;
	glm::vec3 const		position = glm::vec3(0.0f, 0.5f, 0.0f);
	glm::vec3 const		negativePosition = glm::vec3(0.0f, -0.5f, 0.0f);

	switch(key) {
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		case GLFW_KEY_LEFT:
			GUIOpenGL::rotate(angle);
			break;
		case GLFW_KEY_RIGHT:
			GUIOpenGL::rotate(-angle);
			break;
		case GLFW_KEY_UP:
			GUIOpenGL::move(position);
			break;
		case GLFW_KEY_DOWN:
			GUIOpenGL::move(negativePosition);
			break;
		case GLFW_KEY_KP_ADD:
		case GLFW_KEY_EQUAL:
			GUIOpenGL::scale(scaleUp);
			break;
		case GLFW_KEY_KP_SUBTRACT:
		case GLFW_KEY_MINUS:
			GUIOpenGL::scale(scaleDown);
			break;
		case GLFW_KEY_W:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(Coord(0, -1));
			break;
		case GLFW_KEY_A:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(Coord(-1, 0));
			break;
		case GLFW_KEY_S:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(Coord(0, 1));
			break;
		case GLFW_KEY_D:
			GUIOpenGL::_GLFW->_gomoku.moveGhost(Coord(1, 0));
			break;
		case GLFW_KEY_ENTER:
			GUIOpenGL::_GLFW->_gomoku.turn();
			break;
		case GLFW_KEY_C:
			GUIOpenGL::_GLFW->_gomoku.reset();
			break;
		case GLFW_KEY_R:
			GUIOpenGL::reset();
			break;
		case GLFW_KEY_X:
			GUIOpenGL::_GLFW->_gomoku.save();
			break;
	}
}