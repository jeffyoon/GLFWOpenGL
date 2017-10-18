#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <GL/glew.h>

class Shader
{
public:
    Shader(const std::string& fileName);

    void Bind();

    virtual ~Shader();

private:
    static const unsigned int NUM_SHADERS = 2;
    static const unsigned int NUM_UNIFORMS = 3;

    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, unsigned int type);

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};

#endif  // _SHADER_H_
