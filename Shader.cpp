#include "Shader.h"

Shader::Shader()
{
	shaderProgram = loadShader("shaders/VertexColor.txt", "shaders/FragmentColor.txt"); //default shaders
	viewMatrix = glm::mat4(1.0f);
	projectionMatrix = glm::mat4(1.0f);
	/*
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
	*/

}


Shader::~Shader()
{
}

void Shader::update(glm::mat4 vMatrix, glm::mat4 pMatrix, glm::vec3 cameraPos)
{
	viewMatrix = vMatrix;
	projectionMatrix = pMatrix;
	cameraEyePosition = cameraPos;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	//ShaderLoader(vertexFile, fragmentFile, &shaderProgram);
	shaderProgram = loadShader(vertexFile, fragmentFile);
	viewMatrix = glm::mat4(1.0f);
	projectionMatrix = glm::mat4(1.0f);
}

void Shader::useShaderProgram(glm::mat4 modelMatrix, glm::vec3 color)
{
	GLint idModelTransform = glGetUniformLocation(shaderProgram, "modelMatrix");
	GLint idViewTransform = glGetUniformLocation(shaderProgram, "viewMatrix");
	GLint idProjectionTransform = glGetUniformLocation(shaderProgram, "projectionMatrix");

	GLint idCameraPosition = glGetUniformLocation(shaderProgram, "cameraPos");
	GLint idColor = glGetUniformLocation(shaderProgram, "uniformColor");

	if (idModelTransform == -1)
		printf("Model Matrix not found!!!\n");

	if (idViewTransform == -1)
		printf("View Matrix not found!!!\n");

	if (idProjectionTransform == -1)
		printf("Projection Matrix not found!!!\n");

	//printf("Matrices are okay...\n");

	glUseProgram(shaderProgram);

	glUniformMatrix4fv(idModelTransform, 1, GL_FALSE, &modelMatrix[0][0]); //location, count, transpose, *value
	glUniformMatrix4fv(idViewTransform, 1, GL_FALSE, &viewMatrix[0][0]); //location, count, transpose, *value
	glUniformMatrix4fv(idProjectionTransform, 1, GL_FALSE, &projectionMatrix[0][0]); //location, count, transpose, *value

	if (idCameraPosition != -1)
	{
		glUniform3fv(idCameraPosition, 1, &cameraEyePosition[0]);
		printf("Camera %f %f %f\n", cameraEyePosition.x, cameraEyePosition.y, cameraEyePosition.z);
	}

	if (idColor != -1)
	{
			glUniform3fv(idColor, 1, &color[0]);
			printf("Color\n");
	}

}

