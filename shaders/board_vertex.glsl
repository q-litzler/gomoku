#version 410 core

in vec3		v_position;
in vec3		v_normal;
in vec2 	v_texture;

out vec3		f_position;
out vec3		f_normal;
out vec2		f_texture;

uniform mat4	model;
uniform mat4	view;
uniform mat4	projection;

void main()
{
	gl_Position = projection * view * model * vec4(v_position, 1.0);
	f_position = v_position;
	f_normal = v_normal;
	f_texture = v_texture;
}