#ifndef _ENGINE_TRANSFORM_COMPONENT_HEADER_
#define _ENGINE_TRANSFORM_COMPONENT_HEADER_

namespace Engine
{
	struct TransformComponent
	{
		float positionX = 0.f;
		float positionY = 0.f;

		TransformComponent(float posX, float posY);
	};
}

#endif // _ENGINE_TRANSFORM_COMPONENT_HEADER_
