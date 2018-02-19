#include "model.h"

Model::Model()
{
    parent = nullptr;
    position = glm::vec3(0.0f);
    rotation = glm::vec3(0.0f);
    scale = glm::vec3(1.0f);
    modelmatrix = glm::mat4(1.0f);
}

Model::~Model()
{

}

void Model::update()
{
    glm::mat4 tmat = glm::translate(glm::mat4(), position);
    glm::quat quaternion = glm::quat(rotation);
    glm::mat4 rmat = glm::toMat4(quaternion);
    glm::mat4 smat = glm::scale(scale);

    modelmatrix = tmat * rmat * smat;
}

glm::mat4 Model::getModelMatrix()
{
    return modelmatrix;
}
