#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "entity.h"

class Camera: Entity
{
public:
    Camera();
    ~Camera();

    void init(float, float, float float);

private:
    glm::mat4 view;
    glm::mat4 projection;
};

#endif /* CAMERA_H */
