#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


class Model
{
public:
    Model();
    ~Model();

    void update();
    glm::mat4 getModelMatrix();

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

protected:
    glm::mat4 modelmatrix;
    Model* parent;
    std::vector<Model*> children;
};

#endif /* MODEL_H */
