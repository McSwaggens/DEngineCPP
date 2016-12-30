#pragma once

#include <iostream>
#include <string>
#include "entity.h"
#include "color.h"
#include "vector.h"

// INT
void Log (uint64_t i);
void Log (std::string name, uint64_t i);

void Log (uint32_t i);
void Log (std::string name, uint32_t i);

void Log (int i);
void Log (std::string name, int i);

// CHAR
void Log (std::string message);
void Log (std::string name, const char* data);

//COLOR
void Log (Color color);
void Log (std::string name, Color color);

// VECTOR
void Log (Vector vector);
void Log (std::string name, Vector vector);

// IVECTOR
void Log (IVector vector);
void Log (std::string name, IVector vector);
