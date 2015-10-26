#pragma once
#include "lib/framework.hpp"


class MapChip
{
private:


public:

	int status = 0;
	int search = 0;
	int cost = 0;
	int parent = 0;
	Vec2i pos = Vec2i(0, 0);
	Vec2i size = Vec2i(50, 50);
	MapChip();
	

};


