#pragma once 
#include "lib/framework.hpp"
#include <iostream>
#include <vector>
#include <string>
#define env App::get()

enum WindowSize{
	WIDTH = 2048,
	HEIGHT = 2048,

};

class App
{

	App(){};
public:

	static AppEnv& get(){
		static AppEnv get(WIDTH, HEIGHT);
		return get;
	}

};