#include <iostream>
#include <stdio.h>
#include "engine.h"
#include "entity.h"
#include "render.h"
#include <math.h>

#define PI 3.14159265


using namespace std;

enum NODE_STATUS
{
	FREE,
	USED,
	SOLID
}

#define SIZE 32

struct Node : public Actor
{
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
		this->status = FREE;
		this->position = this->i_position * 32;
		
	}
	
	void Render ()
	{
		Render::DrawFilledRectangle(position, size, Color (0, 0, 0, 255));
		Render::DrawRectangle(position, size, Color (0, 0, 0, 255));
	}
};

Node* grid[SIZE][SIZE];

void InitializeGrid ()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			Node* node = new Node (Vector(x, y));
			grid[x][y] = node;
			
			node->status = FREE;
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
