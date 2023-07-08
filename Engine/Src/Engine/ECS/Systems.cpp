#include "Systems.hpp"

namespace Engine
{
    void Systems::OnUpdate(Context* context)
    {
        RunSystems(context, SystemType::Update);
    }

    void Systems::OnDraw(Context* context)
    {
        RunSystems(context, SystemType::Draw);
    }

    void Systems::RunSystems(Context* context, SystemType type)
    {
        auto it = _data.find(type);
        if (it != _data.end())
        {
            for (const auto& prioritiesData : it->second)
            {
                for (const auto& system : prioritiesData.second)
                {
                    system->OnRun(context);
                }
            }
        }
    }
}
