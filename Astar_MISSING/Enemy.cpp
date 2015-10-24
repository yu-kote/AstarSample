#include "Enemy.h"


void Enemy::setup(){
	
}

void Enemy::update(){


}

void Enemy::draw(){
	drawFillBox(enemy_pos.x(), enemy_pos.y(),
				enemy_size.x(), enemy_size.y(),
				Color::red);

}
void Enemy::setStartPos(Vec2i pos){
	enemy_pos = pos;
}

void Enemy::setMovePos(Vec2i pos){
	enemy_pos = pos;
}