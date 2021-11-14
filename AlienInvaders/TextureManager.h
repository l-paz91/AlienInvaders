// -----------------------------------------------------------------------------
#ifndef TextureManager_H
#define TextureManager_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <string>

using namespace sf;

// -----------------------------------------------------------------------------

class TextureHolder
{
public:
	TextureHolder(const TextureHolder&) = delete;
	void operator=(const TextureHolder&) = delete;

	static Texture& getTexture(const std::string& filename)
	{
		std::map<std::string, Texture>& ref = getInstance().mTextures;
		auto it = ref.find(filename);
		if (it != ref.end())
		{
			return it->second;
		}
		else
		{
			Texture& t = ref[filename];
			t.loadFromFile(filename);
			return t;
		}
	}

private:
	TextureHolder() {}

	static TextureHolder& getInstance()
	{
		static TextureHolder instance;	// guaranteed to be destroyed properly
		return instance;
	}

	std::map<std::string, Texture> mTextures;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !TextureManager_H