#include "System.h"

void System::Main()
{
	InitWindow(500, 500, "Particles");
	SetTargetFPS(60);

	Start();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		
		BeginBlendMode(BLEND_ADDITIVE);
		Update();
		EndBlendMode();
		
		EndDrawing();
	}
}

void System::Start()
{
	pool.reserve(POOL_SIZE);

	for (int i = 0; i < POOL_SIZE; i++)
		pool.push_back(Particle());
}

void System::Update()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		int rate = GetRandomValue(3, 20);

		for (int r = 0; r < rate; r++)
		{
			for (int i = 0; i < pool.size(); i++)
			{
				int index = (i + lastIndex) % pool.size();

				if (pool[index].active) continue;
				pool[index].Activate(
					GetMousePosition(), 
					GetRandomValue(5, 50), 
					GetRandomColor(), 
					{(GetRandomValue(-500, 500) / 100.0f), (GetRandomValue(-100, -500) / 100.0f)},
					GetRandomValue(4,7));
				lastIndex = index;
				break;
			}
		}
	}

	for (int i = 0; i < pool.size(); i++)
	{
		pool[i].Update();
		pool[i].Draw();
	}
}

Color System::GetRandomColor()
{
	return Color{ (unsigned char)GetRandomValue(0, 255) , (unsigned char)GetRandomValue(0, 255) , (unsigned char)GetRandomValue(0, 255) , 255 };
}