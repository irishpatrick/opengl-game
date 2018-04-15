#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera();
    ~Camera();

    void init(float, float, float, float);
    void update();

    glm::mat4 getProjectionMatrix();
    glm::mat4 getViewMatrix();

    glm::vec3 position;
    glm::vec3 rotation;

private:
    glm::mat4 view;
    glm::mat4 projection;
};

#endif /* CAMERA_H */
