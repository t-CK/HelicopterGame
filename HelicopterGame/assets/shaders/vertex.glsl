#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vertColor;
out vec2 texCoord;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	vertColor = aColor;
	texCoord = aTexCoord;
	gl_Position = u_Model * u_View * u_Projection * vec4(aPos, 1.0f);
}