#ifndef MODEL_H
#define MODEL_H

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

private:
    glm::mat4 modelmatrix;
};

#endif /* MODEL_H */
