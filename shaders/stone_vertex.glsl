#version 410 core

in vec3		v_position;
in vec3		v_normal;
in vec3		v_instance;
in vec4		v_color;

out vec3		f_position;
out vec3		f_normal;
out vec4		f_color;

uniform mat4	model;
uniform mat4	view;
uniform mat4	projection;

void main()
{
	gl_Position = projection * view * model * vec4(v_position + v_instance, 1.0);
	f_position = v_position;
	f_normal = v_normal;
	f_color = v_color;
}