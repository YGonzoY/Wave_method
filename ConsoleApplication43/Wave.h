#pragma once
#include <vector>
#include "Cell.h"
#include <string>

using namespace std;

class Wave
{
private:
#include "Cell.h"
	vector<vector<Cell>> matrix;
	Cell start;
	Cell finish;
	bool is_finish;
	vector<Cell> path;
	int steps;
	//vector<Cell> path;
public:
	Wave(string str_path);
	void print();
	void create_wave();
	void create_path();
};

