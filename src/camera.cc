#include "camera.h"

Camera::Camera(): Entity()
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
        far,
    );


}
