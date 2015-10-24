#include "AstarBlock.h"


Astar::Astar(Vec2i start_pos, Vec2i goal_pos){
	mapchip.setup();
	enemy.setup();
	enemy.setStartPos(start_pos);

	enemy_pos = start_pos;
	player_pos = goal_pos;



	mapchip.map[player_pos.y()][player_pos.x()].search = CHECK_NOW;
	//ƒRƒXƒg‚ð’²‚×‚é
	mapchip.map[player_pos.y()][player_pos.x()].cost = nowCost(start_pos, goal_pos);




}

void Astar::setup(){

}

void Astar::update(){
	mapchip.update();
	enemy.update();
	algorithm();
}

void Astar::draw(){
	mapchip.draw();
	enemy.draw();

}

int Astar::nowCost(Vec2i start_pos, Vec2i goal_pos){

	return std::abs(goal_pos.x() - start_pos.x()) + std::abs(goal_pos.y() - start_pos.y());
}


void Astar::algorithm(){

	//MapChip::MapObject *map_search = nullptr;
	int cost_min = 1000000;
	Vec2i now_pos = Vec2i::Zero();

	for (int y = 0; y < mapchip.LENGTH; y++)
	{
		for (int x = 0; x < mapchip.WIDE; x++)
		{
			if (mapchip.map[y][x].search == CHECK_NOW && 
				nowCost(Vec2i(y, x), player_pos) < cost_min){
				
				mapchip.map[y][x].cost = nowCost(Vec2i(y, x), player_pos);
				cost_min = nowCost(Vec2i(y, x), player_pos);

				//map_search = &mapchip.map[y][x];

				now_pos = Vec2i(x, y);
			}
		}
	}
	
	

	mapchip.map[now_pos.y()][now_pos.x()].search = CHECK_END;

	for (int i = 0; i < SEARCH_DIRECTION_MAX; i++)
	{
		Vec2i search_start_pos = now_pos;
		
			switch (i){
			case UP:
				search_start_pos.y() += 1;
				break;
			case DOWN:
				search_start_pos.y() -= 1;
				break;
			case LEFT:
				search_start_pos.x() -= 1;
				break;
			case RIGHT:
				search_start_pos.x() += 1;
				break;
			}
		
		if (search_start_pos.y() > 0 && search_start_pos.x() > 0 &&
			search_start_pos.y() < mapchip.LENGTH && search_start_pos.y() < mapchip.WIDE){

			if (mapchip.map[search_start_pos.y()][search_start_pos.x()].search == NOT_CHECK)
			{
				switch (i){
				case UP:
					mapchip.map[search_start_pos.y()][search_start_pos.x()].parent = DOWN;
					break;
				case DOWN:
					mapchip.map[search_start_pos.y()][search_start_pos.x()].parent = UP;
					break;
				case LEFT:
					mapchip.map[search_start_pos.y()][search_start_pos.x()].parent = RIGHT;
					break;
				case RIGHT:
					mapchip.map[search_start_pos.y()][search_start_pos.x()].parent = LEFT;
					break;

				}
				mapchip.map[search_start_pos.y()][search_start_pos.x()].search = CHECK_NOW;

				mapchip.map[search_start_pos.y()][search_start_pos.x()].cost = nowCost(Vec2i(search_start_pos.x(), search_start_pos.y()), player_pos);
			}


		}

		if (now_pos == player_pos)
		{
			return;
		}


	}


	algorithm();


}

void Astar::parentDraw(Vec2i goal_pos){

	if (goal_pos == enemy_pos){
		drawFillBox(goal_pos.x() * 50, goal_pos.y() * 50, 50, 50, Color::blue);
		return;
	}

	switch (mapchip.map[goal_pos.y()][goal_pos.x()].parent)
	{
	case UP:
		parentDraw(Vec2i(goal_pos.x(), goal_pos.y() + 1));
		break;
	case DOWN:
		parentDraw(Vec2i(goal_pos.x(), goal_pos.y() - 1));
		break;
	case LEFT:
		parentDraw(Vec2i(goal_pos.x() - 1, goal_pos.y()));
		break;
	case RIGHT:
		parentDraw(Vec2i(goal_pos.x() + 1, goal_pos.y()));
		break;
	}
}
