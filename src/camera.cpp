#include "camera.hpp"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::init(float fov, float aspect, float near, float far)
{
    projection = glm::perspective(
        glm::radians(fov),
        aspect,
        near,
        far
    );

    view = glm::lookAt(
        position,
        glm::vec3(0.0f),
        glm::vec3(0,1,0)
    );
}

void Camera::update()
{
    view = glm::lookAt(
        position,
        glm::vec3(0.0f),
        glm::vec3(0,1,0)
    );
}

glm::mat4 Camera::getProjectionMatrix()
{
    return projection;
}

glm::mat4 Camera::getViewMatrix()
{
    return view;
}
