#include "FileSystem.hpp"

#include <filesystem>

namespace Engine
{
    void FileSystem::Init(char** argv)
    {
        _binDir = std::filesystem::path(argv[0]).remove_filename().generic_u8string();

        _dirs[DirType::Bin] = _binDir;
        _dirs[DirType::Root] = _dirs[DirType::Bin] + "../";
        _dirs[DirType::Assets] = _dirs[DirType::Root] + "Assets/";
    }

    std::string FileSystem::BuildPath(DirType dirType, std::string_view path) const
    {
        return _dirs.at(dirType) + std::string{ path };
    }
}
