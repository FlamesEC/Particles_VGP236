#include "Particle.h"

void Particle::Activate(Vector2 center, float radius, Color color, Vector2 speed, float subtractor)
{
	this->center = center;
	this->radius = radius;
	this->color = color;
	this->speed = speed;
	this->subtractor = subtractor;

	active = true;
}

void Particle::Draw()
{
	if (!active)
		return;

	DrawCircleV(center, radius, color);
}

void Particle::Update()
{
	if (!active)
		return;

	center += speed;
	speed.y += gravity;

	float alpha = color.a - subtractor;
	color.a = alpha;

	if (alpha <= 0)
		active = false;
}