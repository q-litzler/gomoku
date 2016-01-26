#version 410 core
in vec2				f_texture;
out vec4			outcolor;

uniform sampler2D	v_material;
uniform vec3		f_color;

void main()
{    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(v_material, f_texture).r);
    outcolor = vec4(f_color, 1.0) * sampled;
}  
