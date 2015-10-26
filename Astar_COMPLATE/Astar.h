#pragma once
#include "lib/framework.hpp"
#include "MapChip.h"
#include "Common.h"


class Astar
{
private:

	Font font = Font("res/meiryob.ttc");

	enum FieldSize{
		WIDE = 30,
		LENGTH = 30,

	};
	MapChip map[LENGTH][WIDE];
	enum Block{
		AIR_BLOCK,
		BLOCK,
	};
	enum Search{
		NONE,	//’²‚×‚Ä‚¢‚È‚¢ó‘Ô
		OPEN,	//’²‚×‚Ä‚¢‚éó‘Ô
		CLOSE,	//’²‚×I‚í‚Á‚½ó‘Ô
	};
	enum Direction{
		UP,
		DOWN,
		LEFT,
		RIGHT,

		DIRECTION_MAX,
	};

	int nowCost(Vec2i _enemy_pos);
	void algorithm();
	void mapDraw();
	void parentUpdate();
	void parentDraw();

	int c = 0;
	

	Vec2i _player_pos;
	Vec2i _enemy_pos;
	Vec2i now_pos = Vec2i::Zero();

public:
	Astar(Vec2f player_pos, Vec2f enemy_pos);

	void setup(Vec2f player_pos, Vec2f enemy_pos);
	void update();

	void draw();


	void setPlayerPos(Vec2f player_pos);
	void setEnemyPos(Vec2f enemy_pos);
};


