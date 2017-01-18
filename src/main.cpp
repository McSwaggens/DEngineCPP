#include <iostream>
#include <stdio.h>
#include <vector>
#include "engine.h"
#include "entity.h"
#include "render.h"
#include "logger.h"
#include "font.h"
#include <math.h>

#define PI 3.14159265


using namespace std;

FONT font;

#define SIZE 32
#define NODE_SIZE_PX 64

enum NODE_STATUS
{
	FREE,
	USED,
	SOLID,
	START,
	TARGET
};

class Node;

Node* start_node = nullptr;
Node* target_node = nullptr;
Node* grid[SIZE][SIZE];

class Node : public Entity, public Actor
{
public:
	NODE_STATUS status;
	
	IVector i_position;
	
	Node* parent = nullptr;
	int g_cost;
	int h_cost;
	
	int GetFCost ()
	{
		return g_cost + h_cost;
	}
	
	Node (IVector i_position)
	{
		this->i_position = i_position;
		this->position = (this->i_position * NODE_SIZE_PX).ToVector();
		this->size = Vector (NODE_SIZE_PX, NODE_SIZE_PX);
		status = FREE;
		Listen ();
	}
	
	void Tick ()
	{
	}
	
	vector<Node*> GetNeighbouringNodes ()
	{
		std::vector<Node*> nodes;
		
		for (int y = -1; y <= 1; ++y)
		{
			for (int x = -1; x <= 1; ++x)
			{
				if (x == 0 && y == 0) continue;
				if (this->i_position.x + x >= SIZE || this->i_position.y + y >= SIZE) continue;
				
				Node* node = grid[this->i_position.x + x][this->i_position.y + y];
				
				nodes.push_back (node);
			}
		}
		
		return nodes;
	}
	
	void OnEventCalled (Event event)
	{
		int x = event.button.x;
		int y = event.button.y;
		
		if (x > this->position.x && x < this->position.x + this->size.x && y > this->position.y && y < this->position.y + this->size.y)
		{
			
			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				Log ("clicked", i_position);
				status = SOLID;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT)
			{
				Log ("clicked", i_position);
				static bool flip = false;
				flip = !flip;
				
				if (flip)
				{
					status = START;
					
					if (start_node != nullptr)
						start_node->status = FREE;
					
					start_node = this;
				}
				else
				{
					status = TARGET;
					
					if (target_node != nullptr)
						target_node->status = FREE;
					
					target_node = this;
				}
			}
		}
	}
	
	Color GetFillColor ()
	{
		switch (status)
		{
			case FREE:
				return Colors::white;
			case SOLID:
			return Colors::black;
			case USED:
				return Colors::red;
			case START:
				return Color (210, 210, 0, 255);
			case TARGET:
				return Colors::green;
		}
	}
	
	void Render ()
	{
		Render::DrawFilledRectangle(position, size, GetFillColor());
		Render::DrawRectangle(position, size, Colors::black);
		
	}
};


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

std::vector<Node*> GetPath ()
{
	
}

int main ()
{
	Engine::Initialize ();
	Engine::SetSize (Vector(SIZE*NODE_SIZE_PX, SIZE*NODE_SIZE_PX));
	
	font = Font::CreateFont ("DejaVuSansMono", 22);
	
	InitializeGrid();
	
	start_node = grid[16][0];
	target_node = grid[16][31];
	
	start_node->status = START;
	target_node->status = TARGET;
	
	for (int i = 0; i < 16; i++)
	{
		Node* node = grid[(32/4)+i][16];
		node->status = SOLID;
	}
	
	Engine::Start ();
	
	return 0;
}
