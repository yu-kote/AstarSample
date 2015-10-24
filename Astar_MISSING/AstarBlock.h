#pragma once
#include "lib/framework.hpp"
#include "Common.h"
#include "MapChip.h"
#include "Enemy.h"

class Astar{
private:
	MapChip mapchip;
	Enemy enemy;

	enum SearchType{
		NOT_CHECK,	//チェックしていない
		CHECK_NOW,	//チェック中
		CHECK_END,	//チェック終わり
	};
	enum SearchDirection{
		UP,		//上方向サーチ
		DOWN,	//下方向サーチ
		LEFT,	//左方向サーチ
		RIGHT,	//右方向サーチ

		SEARCH_DIRECTION_MAX,
	};
	SearchDirection direction;

	

	void algorithm();



	int nowCost(Vec2i start_pos, Vec2i goal_pos);

	Vec2i enemy_pos;
	Vec2i player_pos;

public:

	Astar(Vec2i start_pos, Vec2i goal_pos);
	void parentDraw(Vec2i goal_pos);

	void setup();
	void update();
	void draw();

};