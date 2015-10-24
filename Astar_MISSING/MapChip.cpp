#include "MapChip.h"

MapChip::MapChip(){
	map = std::vector<std::vector<MapObject>>(LENGTH, std::vector<MapObject>(WIDE));
	std::vector<std::vector<int>> map_data;
	map_data =
	{
		{ 0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },

		{ 1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  1, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  1, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  1, 0, 0, 0, 0,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  1, 0, 0, 0, 1,  0, 0, 0, 0, 0 },

		{ 1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 0, 1,  1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },

		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 1, 1, 1,  1, 0, 0, 0, 0,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0,  0, 0, 1, 1, 1,  1, 1, 1, 0, 1,  0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1,  0, 0, 0, 0, 0 },
	};


	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDE; x++)
		{
			map[y][x].status = map_data[y][x];
		}
	}
}

void MapChip::setup(){


	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDE; x++)
		{
			map[y][x].size = Vec2f(50, 50);

			map[y][x].pos.x() = -WIDTH / 2 + map[y][x].size.x() * x;
			map[y][x].pos.y() = HEIGHT / 2 - map[y][x].size.y() * y - map[y][x].size.y();

			map[y][x].color = Color::white;
			map[y][x].search = 0;
			map[y][x].cost = 0;
			map[y][x].parent = 0;

		}
	}
}

void MapChip::update(){



}

void MapChip::draw(){

	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDE; x++)
		{
			switch (map[y][x].status)
			{
			case AIR_BLOCK:

				drawBox(map[y][x].pos.x(), map[y][x].pos.y(),
						map[y][x].size.x(), map[y][x].size.y(),
						5, map[y][x].color);
				break;
			case BLOCK:

				drawFillBox(map[y][x].pos.x(), map[y][x].pos.y(),
							map[y][x].size.x(), map[y][x].size.y(),
							map[y][x].color);
				break;

			}
		}
	}
}


