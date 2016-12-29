#include <iostream>
#include <stdio.h>
#include "engine.h"
#include "entity.h"
#include "render.h"
#include "logger.h"
#include <math.h>

#define PI 3.14159265


using namespace std;

#define SIZE 32

enum NODE_STATUS
{
	FREE,
	USED,
	SOLID
};


class Node : public Actor
{
public:
	NODE_STATUS status;
	
	IVector i_position;
	
	int g_cost;
	int h_cost;
	
	int GetFCost ()
	{
		return g_cost + h_cost;
	}
	
	Node (IVector i_position)
	{
		this->i_position = i_position;
		this->position = (this->i_position * 32).ToVector();
		this->size = Vector (32, 32);
		Log (this->position);
		status = FREE;
	}
	
	void Render ()
	{
		Render::DrawFilledRectangle(position, size, Colors::white);
		Render::DrawRectangle(position, size, Colors::black);
	}
};

Node* grid[SIZE][SIZE];

void InitializeGrid ()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			Node* node = new Node (IVector(x, y));
			grid[x][y] = node;
		}
	}
}

int main ()
{
	Engine::Initialize ();
	Engine::SetSize (Vector(SIZE*32, SIZE*32));
	
	InitializeGrid();
	
	
	
	
	Engine::Start ();
	
	return 0;
}
