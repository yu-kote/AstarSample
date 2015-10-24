#include "lib/framework.hpp"
#include <iostream>
#include "Common.h"
#include "AstarBlock.h"

 





int main() {
  
  
	AppEnv env(WindowSize::WIDTH, WindowSize::HEIGHT);

	Vec2i start_pos = Vec2i(0, 0);
	Vec2i goal_pos = Vec2i(10, 10);


	Astar Astarblock(start_pos, goal_pos);
	Astarblock.setup();
	Astarblock.update();
  while (env.isOpen()) {
	  if (env.isPushKey('E')){
		  return 0;
	  }
	

    env.begin();

	//Astarblock.parentDraw(goal_pos);
	Astarblock.draw();

	env.end();
  }
}
