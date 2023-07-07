#include "Camera.hpp"

namespace Engine
{
    void Camera::Init()
    {
        SetTarget({});
        SetOffset({});
        SetRotation();
        SetZoom();
    }

    void Camera::SetTarget(const Vector2& position)
    {
        _camera.target = position;
    }

    void Camera::SetOffset(const Vector2& offset)
    {
        _camera.offset = offset;
    }

    void Camera::SetRotation(float rotation)
    {
        _camera.rotation = rotation;
    }

    void Camera::SetZoom(float zoom)
    {
        _camera.zoom = zoom;
    }

    void Camera::BeginMode()
    {
        BeginMode2D(_camera);
    }

    void Camera::EndMode()
    {
        EndMode2D();
    }
}
