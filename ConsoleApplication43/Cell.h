#pragma once
enum Celltype
{
	Space = -1,
	Wall = -2,
	Start = 0,
	Finish = -3
};
class Cell
{
private:
	int row;
	int col;
	int value;
public:
	Cell(int _row = 0, int _col = 0, int _value = Celltype::Space);
	int Row();
	int Col();
	int& Value();
};

