#include "Shader.h"

Shader::Shader()
{

	//create and compile shaders	 
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderChar, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderChar, NULL);
	glCompileShader(fragmentShader);
	this->shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);

		delete[] strInfoLog;
		exit(EXIT_FAILURE);
	}
}

Shader::~Shader()
{
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	//ShaderLoader(vertexFile, fragmentFile, &shaderProgram);
	shaderProgram = loadShader(vertexFile, fragmentFile);
}

void Shader::useShaderProgram(glm::mat4 m, glm::mat4 v, glm::mat4 p)
{
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	GLint idViewTransform = glGetUniformLocation(shaderProgram, "viewMatrix");
	GLint idProjectionTransform = glGetUniformLocation(shaderProgram, "projectionMatrix");

	glUseProgram(shaderProgram);

	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &m[0][0]); //location, count, transpose, *value
	glUniformMatrix4fv(idViewTransform, 1, GL_FALSE, &v[0][0]); //location, count, transpose, *value
	glUniformMatrix4fv(idProjectionTransform, 1, GL_FALSE, &p[0][0]); //location, count, transpose, *value
	
}

