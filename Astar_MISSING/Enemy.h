#pragma once
#include "lib/framework.hpp"
#include "Common.h"



class Enemy{
private:

public:

	Vec2i enemy_pos;
	Vec2i enemy_size = Vec2i(50, 50);
	void setup();
	void update();
	void draw();

	void setStartPos(Vec2i pos);
	void setMovePos(Vec2i pos);
};