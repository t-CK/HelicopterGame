#version 330 core

out vec4 fragColor;
in vec3 vertColor;
in vec2 texCoord;

uniform sampler2D tex;

void main()
{
//	fragColor = vec4(1.0f, 0.5f, 1.0f, 1.0f);
	fragColor = vec4(vertColor, 1.0f);
	fragColor = texture(tex, texCoord);
}