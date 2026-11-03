#pragma once

#include <iostream>
#include <vector>

#include "Particle.h"

class System
{
	#define POOL_SIZE 1000
	std::vector<Particle> pool;
	int lastIndex = 0;

public:
	
	Color GetRandomColor();

	void Main();
	void Start();
	void Update();
};