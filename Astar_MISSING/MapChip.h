#pragma once
#include "lib/framework.hpp"
#include "Common.h"
#include <vector>



class MapChip{
private:
public:
	struct MapObject{
		Vec2f pos;
		Vec2f size;
		int status;
		Color color;

		int search;
		int cost; 
		int parent;
	};
	enum BlockNum{
		LENGTH = 20,
		WIDE = 20,
	};
	enum BlockType{
		AIR_BLOCK = 0,
		BLOCK = 1,
		ENEMY_START_POS = 2,
		PLAYER_START_POS = 3,

		//SEARCH_END = 4,
	};


	std::vector<std::vector<MapObject>> map;

	MapChip();

	void setup();
	void update();
	void draw();


};