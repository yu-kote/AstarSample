#include "Astar.h"

Astar::Astar(Vec2f player_pos, Vec2f enemy_pos){
	setup(player_pos, enemy_pos);

	for (int y = 0; y < FieldSize::LENGTH; y++)
	{
		for (int x = 0; x < FieldSize::WIDE; x++)
		{
			map[y][x].pos.x() = map[y][x].pos.x() + map[y][x].size.x() * x;
			map[y][x].pos.y() = map[y][x].pos.y() - map[y][x].size.y() * y;
		}
	}
}



void Astar::setup(Vec2f player_pos, Vec2f enemy_pos){



	int map_chip[FieldSize::LENGTH][FieldSize::WIDE] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

		{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	for (int y = 0; y < FieldSize::LENGTH; y++)
	{
		for (int x = 0; x < FieldSize::WIDE; x++)
		{
			map[y][x].status = map_chip[y][x];
			map[y][x].search = NONE;
			map[y][x].parent = 5;
		}
	}

	_player_pos = Vec2i((float)player_pos.x(), (float)player_pos.y());
	_enemy_pos = Vec2i((float)enemy_pos.x(), (float)enemy_pos.y());

	map[_enemy_pos.y()][_enemy_pos.x()].search = OPEN;


}


int Astar::nowCost(Vec2i _enemy_pos){
	return std::abs(_player_pos.x() - _enemy_pos.x()) + std::abs(_player_pos.y() - _enemy_pos.y());
}

void Astar::algorithm(){

	int cost_min = 100000000;
	Vec2i once_pos = Vec2i::Zero();

	if (_enemy_pos == _player_pos)
	{
		return;
	}

	//std::cout << "enemy " << _enemy_pos << std::endl;
	//std::cout << "player " << _player_pos << std::endl;
	for (int y = 0; y < FieldSize::LENGTH; y++)
	{
		for (int x = 0; x < FieldSize::WIDE; x++)
		{
			if (map[y][x].search == OPEN)
			{
				if (nowCost(Vec2i(x, y)) <= cost_min)
				{
					if (map[y][x].status != BLOCK)
					{
						once_pos = Vec2i(x, y);
						cost_min = nowCost(once_pos);
					}
				}
			}

		}
	}

	map[once_pos.y()][once_pos.x()].search = CLOSE;

	for (int direction = 0; direction < Direction::DIRECTION_MAX; direction++)
	{
		Vec2i search_pos = once_pos;

		switch (direction)
		{
		case Direction::UP:
			search_pos.y() -= 1;
			break;
		case Direction::DOWN:
			search_pos.y() += 1;
			break;
		case Direction::LEFT:
			search_pos.x() -= 1;
			break;
		case Direction::RIGHT:
			search_pos.x() += 1;
			break;
		}

		if (search_pos.x() >= 0 && search_pos.y() >= 0)
		{
			if (search_pos.x() < WIDE && search_pos.y() < LENGTH)
			{
				if (map[search_pos.y()][search_pos.x()].search == NONE)
				{
					if (map[search_pos.y()][search_pos.x()].status != BLOCK){
						switch (direction)
						{
						case Direction::UP:
							map[search_pos.y()][search_pos.x()].parent = DOWN;
							break;
						case Direction::DOWN:
							map[search_pos.y()][search_pos.x()].parent = UP;
							break;
						case Direction::LEFT:
							map[search_pos.y()][search_pos.x()].parent = RIGHT;
							break;
						case Direction::RIGHT:
							map[search_pos.y()][search_pos.x()].parent = LEFT;
							break;
						}
						map[search_pos.y()][search_pos.x()].search = OPEN;
					}
				}
			}
		}

	}

	if (map[_player_pos.y()][_player_pos.x()].search != OPEN){
		algorithm();
	}
}

void Astar::parentUpdate(){
	if (_player_pos == _enemy_pos)
	{
		return;
	}

	switch (map[_player_pos.y()][_player_pos.x()].parent)
	{
	case Direction::UP:
		_player_pos.y() -= 1;
		//_enemy_pos.y() -= 1;
		font.draw("ª", Vec2f((float)map[_player_pos.y()][_player_pos.x()].pos.x(), (float)map[_player_pos.y()][_player_pos.x()].pos.y()), Color::cyan);
		parentUpdate();
		break;
	case Direction::DOWN:
		_player_pos.y() += 1;
		//_enemy_pos.y() += 1;
		font.draw("«", Vec2f((float)map[_player_pos.y()][_player_pos.x()].pos.x(), (float)map[_player_pos.y()][_player_pos.x()].pos.y()), Color::cyan);
		parentUpdate();
		break;
	case Direction::LEFT:
		_player_pos.x() -= 1;
		//_enemy_pos.x() -= 1;
		font.draw("©", Vec2f((float)map[_player_pos.y()][_player_pos.x()].pos.x(), (float)map[_player_pos.y()][_player_pos.x()].pos.y()), Color::cyan);
		parentUpdate();
		break;
	case Direction::RIGHT:
		_player_pos.x() += 1;
		//_enemy_pos.x() += 1;
		font.draw("¨", Vec2f((float)map[_player_pos.y()][_player_pos.x()].pos.x(), (float)map[_player_pos.y()][_player_pos.x()].pos.y()), Color::cyan);
		parentUpdate();
		break;
	}

}


void Astar::parentDraw(){
	font.size(50);

	for (int y = 0; y < FieldSize::LENGTH; y++)
	{
		for (int x = 0; x < FieldSize::WIDE; x++)
		{
#if(0)
			switch (map[y][x].parent)
			{
			case UP:
				font.draw("ª", Vec2f((float)map[y][x].pos.x(), (float)map[y][x].pos.y()), Color::yellow);
				break;
			case DOWN:
				font.draw("«", Vec2f((float)map[y][x].pos.x(), (float)map[y][x].pos.y()), Color::yellow);
				break;
			case LEFT:
				font.draw("©", Vec2f((float)map[y][x].pos.x(), (float)map[y][x].pos.y()), Color::yellow);
				break;
			case RIGHT:
				font.draw("¨", Vec2f((float)map[y][x].pos.x(), (float)map[y][x].pos.y()), Color::yellow);
				break;
			}

#endif
#if(1)
			switch (map[y][x].search)
			{
			case OPEN:
				font.draw("o", Vec2f((float)map[y][x].pos.x(), (float)map[y][x].pos.y()), Color::yellow);
				break;
			case CLOSE:
				font.draw("c", Vec2f((float)map[y][x].pos.x(), (float)map[y][x].pos.y()), Color::yellow);
				break;
			}
#endif
		}
	}
}

void Astar::mapDraw(){

	for (int y = 0; y < FieldSize::LENGTH; y++)
	{
		for (int x = 0; x < FieldSize::WIDE; x++)
		{
			switch (map[y][x].status){
			case AIR_BLOCK:
				drawBox(map[y][x].pos.x(), map[y][x].pos.y(),
						map[y][x].size.x(), map[y][x].size.y(),
						2, Color::white);
				break;
			case BLOCK:
				drawBox(map[y][x].pos.x(), map[y][x].pos.y(),
						map[y][x].size.x(), map[y][x].size.y(),
						2, Color::blue);
				break;
			}
		}
	}

	drawFillBox(map[_player_pos.y()][_player_pos.x()].pos.x(), map[_player_pos.y()][_player_pos.x()].pos.y(),
				map[_player_pos.y()][_player_pos.x()].size.x(), map[_player_pos.y()][_player_pos.x()].size.y(),
				Color::green);
	drawFillBox(map[_enemy_pos.y()][_enemy_pos.x()].pos.x(), map[_enemy_pos.y()][_enemy_pos.x()].pos.y(),
				map[_enemy_pos.y()][_enemy_pos.x()].size.x(), map[_enemy_pos.y()][_enemy_pos.x()].size.y(),
				Color::red);


}

void Astar::draw(){
	mapDraw();
	parentDraw();
}


void Astar::update(){

	for (int y = 0; y < FieldSize::LENGTH; y++)
	{
		for (int x = 0; x < FieldSize::WIDE; x++)
		{
			//map[_enemy_pos.y()][_enemy_pos.x()].search = OPEN;
		}
	}
	//map[_enemy_pos.y()][_enemy_pos.x()].search = OPEN;


	parentUpdate();
	c++;
	std::cout << c << std::endl;

	if (c % 1 == 0){
		algorithm();
	}

}


void Astar::setPlayerPos(Vec2f player_pos){
	_player_pos = Vec2i((float)player_pos.x(), (float)player_pos.y());
}
void Astar::setEnemyPos(Vec2f enemy_pos){
	_enemy_pos = Vec2i((float)enemy_pos.x(), (float)enemy_pos.y());
}
