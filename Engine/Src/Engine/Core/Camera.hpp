#ifndef _ENGINE_CAMERA_HEADER_
#define _ENGINE_CAMERA_HEADER_

#include "raylib.h"

namespace Engine
{
	class Camera final
	{
	public:
		Camera() = default;
		~Camera() = default;

	public:
		void Init();

		void SetTarget(const Vector2& position);
		void SetOffset(const Vector2& offset);
		void SetRotation(float rotation = 0.f);
		void SetZoom(float zoom = 1.f);

		void BeginMode();
		void EndMode();

	private:
		Camera2D _camera;
	};
}

#endif // _ENGINE_CAMERA_HEADER_
