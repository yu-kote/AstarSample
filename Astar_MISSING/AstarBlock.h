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
		NOT_CHECK,	//�`�F�b�N���Ă��Ȃ�
		CHECK_NOW,	//�`�F�b�N��
		CHECK_END,	//�`�F�b�N�I���
	};
	enum SearchDirection{
		UP,		//������T�[�`
		DOWN,	//�������T�[�`
		LEFT,	//�������T�[�`
		RIGHT,	//�E�����T�[�`

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