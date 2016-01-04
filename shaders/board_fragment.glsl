#version 410 core

in vec3				f_position;
in vec3				f_normal;
in vec2				f_texture;

out vec4			outColor;

uniform sampler2D	v_material;
uniform mat4		model;
uniform vec3		camera;
uniform struct		Light
{
	vec3			position;
	vec3			ambient;
	vec3			diffuse;
	vec3			specular;
	float			coefficient;
	float			attenuation;
	float			shininess;
}					light;


void main()
{
	vec3	normal, position;
	vec3	light_ray, camera_ray;
	vec3	ambient, diffuse, specular;
	vec3	linear_color, gamma;
	vec4	surface_color;
	float	diffuse_coeff, specular_coeff, distance, attenuation;

	surface_color = texture(v_material, f_texture);
	position = vec3(model * vec4(f_position, 1));
	normal = normalize(transpose(inverse(mat3(model))) * f_normal);
	light_ray = normalize(light.position - position);
	camera_ray = normalize(camera - position);

	ambient = light.coefficient * surface_color.rgb * light.ambient;
	diffuse_coeff = max(0.0, dot(normal, light_ray));
	diffuse = diffuse_coeff * surface_color.rgb * light.diffuse;
	specular_coeff = 0.0;
	if(diffuse_coeff > 0.0)
	{
		specular_coeff = pow(
			max(0.0,
			dot(camera_ray, reflect(-light_ray, normal))),
			light.shininess
		);
	}
	specular = specular_coeff * light.specular * light.ambient;

	distance = length(light.position - position);
	attenuation = 1.0 / (1.0 + light.attenuation * pow(distance, 2));

	linear_color = ambient + attenuation*(diffuse + specular);
	gamma = vec3(1.0/2.2);
	outColor = vec4(pow(linear_color, gamma), surface_color.a);
}