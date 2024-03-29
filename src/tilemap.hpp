#pragma once

#include <vector>
#include "../ext/rapidxml/rapidxml.hpp"
#include "../ext/rapidxml/rapidxml_utils.hpp"
#include "tiny_ecs.hpp"
#include <map>
#include <sstream>
#include <string>
#include "render_system.hpp"
#include "common.hpp"

struct Rect
{
	Rect() : x(0), y(0), width(0), height(0) {}
	Rect(int x, int y, int width, int height)
		: x(x), y(y), width(width), height(height) {}
	int x;
	int y;
	int width;
	int height;
};

struct TileInfo
{
	TileInfo() : tileID(-1)
	{
	}
	TileInfo(int textureID, unsigned int tileID, vec2 textureSize, Rect textureRect)
		: textureID(textureID), tileID(tileID), textureSize(textureSize), textureRect(textureRect) { }
	int tileID;			// GID in Tiled
	int textureID;		// refers to TEXTURE_ASSET_ID enum in components.hpp
	vec2 textureSize;	// size of sprite sheet (image pointed to by textureID)
	Rect textureRect;	// sub-rectangle in sprite sheet
};

struct Tile
{
	vec2 offset = { 0,0 };
	std::shared_ptr<TileInfo> properties;
	int x; // x and y are positions within the tile grid, not screen pixels
	int y;
};

struct TileSheetData
{
	int textureId; // The id of the tile sets texture. 
	vec2 imageSize; // The size of the texture.
	int columns; // How many columns in the tile sheet.
	int rows; // How many rows in the tile sheet.
	vec2 tileSize; // The size of an individual tile.
	int spacing = 0;
	int margin = 0;
	int firstId = 0;
};

struct MapObject
{
	int objectId;
	Rect objectRect;
};

struct SpawnData
{
	std::vector<vec2> playerSpawns;
	std::vector<vec2> enemySpawns;
	std::vector<vec2> itemSpawns;
	int minEnemies = 0;
	int maxEnemies = 0;
	int minItems = 0;
	int maxItems = 0;
};

using Layer = std::vector<std::shared_ptr<Tile>>;
// Stores layer names with layer.
using MapTiles = std::map<std::string, std::shared_ptr<Layer>>;
// Stores the different tile types that can be used.
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;

class TileMapParser
{
public:
	SpawnData Parse(const std::string& file, RenderSystem *renderer, vec2 offset = { 0, 0 });
private:
	std::vector<std::shared_ptr<MapObject>> BuildObjects(rapidxml::xml_node<>* rootNode);
	std::tuple<std::vector<vec2>, int, int> BuildSpawns(rapidxml::xml_node<>* rootNode, std::string layerName, int tileSizeX, int tileSizeY, int scaleFactor, vec2 offset);
	std::shared_ptr<TileSheetData> BuildTileSheetData(rapidxml::xml_node<>* rootNode, RenderSystem *renderer);
	std::shared_ptr<MapTiles> BuildMapTiles(rapidxml::xml_node<>* rootNode, RenderSystem *renderer);
	std::pair<std::string, std::shared_ptr<Layer>>
		BuildLayer(
			rapidxml::xml_node<>* layerNode, std::shared_ptr<TileSheetData> tileSheetData
		);
	Entity TileMapParser::createTileFromData(std::shared_ptr<Tile> tile, int tileSizeX, int tileSizeY, int scaleFactor, float uv_padding, std::string layer_name, vec2 offset = { 0,0 });

	static inline bool IsInteger(const std::string& s)
	{
		if (s.empty()
			|| ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
		{
			return false;
		}
		char* p;
		strtol(s.c_str(), &p, 10);
		return (*p == 0);
	}
};