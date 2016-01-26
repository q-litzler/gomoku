#version 410 core
in vec4			v_position;
out vec2		f_texture;

uniform mat4	projection;

void main()
{
    gl_Position = projection * vec4(v_position.xy, 0.0, 1.0);
    f_texture = v_position.zw;
}  