#include "shader.hpp"

Shader::Shader()
{

}

Shader::~Shader()
{

}

void Shader::use() {
    glUseProgram(program);
}

GLuint Shader::getProgram()
{
    return program;
}

GLuint Shader::getUniformLocation(const std::string& name)
{
    if (uniforms.find(name) != uniforms.end())
    {
        return uniforms[name];
    }
    return GL_FALSE;
}

void Shader::findUniform(const std::string& name)
{
    GLint loc = glGetUniformLocation(program, name.c_str());
    if (loc != -1)
    {
        uniforms.insert(std::pair<std::string, GLuint>(name,loc));
    }
    else
    {
        printf("could not find uniform");
    }
}

void Shader::load(const char* vertex_fn, const char* fragment_fn)
{
    GLuint vsid = glCreateShader(GL_VERTEX_SHADER);
    GLuint fsid = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vscode;
    std::ifstream vsstream(vertex_fn, std::ios::in);
    if (vsstream.is_open())
    {
        std::stringstream sstr;
        sstr << vsstream.rdbuf();
        vscode = sstr.str();
        vsstream.close();
    }
    else
    {
        printf("cannot open %s\n", vertex_fn);
        return;
    }

    std::string fscode;
    std::ifstream fsstream(fragment_fn, std::ios::in);
    if (fsstream.is_open())
    {
        std::stringstream sstr;
        sstr << fsstream.rdbuf();
        fscode = sstr.str();
        fsstream.close();
    }
    else
    {
        printf("cannot open %s\n", fragment_fn);
        return;
    }

    GLint result = GL_FALSE;
    int infologlength;

    const char* vspointer = vscode.c_str();
    glShaderSource(vsid, 1, &vspointer, NULL);
    glCompileShader(vsid);

    glGetShaderiv(vsid, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vsid, GL_INFO_LOG_LENGTH, &infologlength);
    if (infologlength > 0)
    {
        std::vector<char> vserror(infologlength+1);
        glGetShaderInfoLog(vsid, infologlength, NULL, &vserror[0]);
        printf("%s\n", &vserror[0]);
    }

    const char* fspointer = fscode.c_str();
    glShaderSource(fsid, 1, &fspointer, NULL);
    glCompileShader(fsid);

    glGetShaderiv(fsid, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fsid, GL_INFO_LOG_LENGTH, &infologlength);
    if (infologlength > 0)
    {
        std::vector<char> fserror(infologlength+1);
        glGetShaderInfoLog(fsid, infologlength, NULL, &fserror[0]);
        printf("%s\n", &fserror[0]);
    }

    program = glCreateProgram();
    glAttachShader(program, vsid);
    glAttachShader(program, fsid);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infologlength);
    if (infologlength > 0)
    {
        std::vector<char> perror(infologlength+1);
        glGetProgramInfoLog(program, infologlength, NULL, &perror[0]);
        printf("%s\n", &perror[0]);
    }

    glDetachShader(program, vsid);
    glDetachShader(program, fsid);

    glDeleteShader(vsid);
    glDeleteShader(fsid);
}
