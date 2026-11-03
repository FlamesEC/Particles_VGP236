#pragma once

#include <raylib.h>
#include <raymath.h>

struct Particle
{
	Vector2 center = Vector2{ 0,0 };
	float radius = 0;
	Color color = BLACK;
	Vector2 speed = Vector2{ 0, 0 };
	float gravity = 0.981f/2;
	float subtractor = 0;

	bool active = false;

	void Activate(Vector2 center, float radius, Color color, Vector2 speed, float subtractor);

	void Draw();
	void Update();
};