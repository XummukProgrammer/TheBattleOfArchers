#ifndef _ENGINE_FILE_SYSTEM_HEADER_
#define _ENGINE_FILE_SYSTEM_HEADER_

#include <string>
#include <map>

namespace Engine
{
	enum class DirType
	{
		Bin,
		Root,
		Assets
	};

	class FileSystem final
	{
	public:
		FileSystem() = default;
		~FileSystem() = default;

	public:
		void Init(char** argv);

		const std::string& GetBinDir() const { return _binDir; }

		std::string BuildPath(DirType dirType, std::string_view path) const;

	private:
		std::string _binDir;
		std::map<DirType, std::string> _dirs;
	};
}

#endif // _ENGINE_FILE_SYSTEM_HEADER_
