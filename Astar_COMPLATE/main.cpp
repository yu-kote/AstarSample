#include "lib/framework.hpp"
#include "Common.h"
#include "Astar.h"


int main() {
	env;

	Vec2f player_pos = Vec2f(15, 15);
	Vec2f enemy_pos = Vec2f(0, 25);

	Astar astar(player_pos, enemy_pos);


	while (env.isOpen()) {


		if (env.isPushKey('W')){ enemy_pos.y() -= 1; }
		if (env.isPushKey('S')){ enemy_pos.y() += 1; }
		if (env.isPushKey('A')){ enemy_pos.x() -= 1; }
		if (env.isPushKey('D')){ enemy_pos.x() += 1; }
		if (env.isPushKey('W') || env.isPushKey('S') || env.isPushKey('A') || env.isPushKey('D')){
			astar.setup(player_pos, enemy_pos);
		}
		if (env.isPushKey(GLFW_KEY_UP)){ player_pos.y() -= 1; }
		if (env.isPushKey(GLFW_KEY_DOWN)){ player_pos.y() += 1; }
		if (env.isPushKey(GLFW_KEY_LEFT)){ player_pos.x() -= 1; }
		if (env.isPushKey(GLFW_KEY_RIGHT)){ player_pos.x() += 1; }
		if (env.isPushKey(GLFW_KEY_UP) || env.isPushKey(GLFW_KEY_DOWN) || env.isPushKey(GLFW_KEY_LEFT) || env.isPushKey(GLFW_KEY_RIGHT)){
			astar.setup(player_pos, enemy_pos);
		}


		astar.setPlayerPos(player_pos);
		astar.setEnemyPos(enemy_pos);


		env.begin();
		glPushMatrix();
		glTranslated(-WIDTH / 3, HEIGHT / 3, 0);
		astar.update();

		astar.draw();

		glPopMatrix();

		env.end();
	}
}
