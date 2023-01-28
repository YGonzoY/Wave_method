#include "Cell.h"

Cell::Cell(int _row, int _col, int _value) : row{_row}, col{_col}, value{_value}{}

int Cell::Row()
{
	return row;
}

int Cell::Col()
{
	return col;
}

int& Cell::Value()
{
	return value;
}
