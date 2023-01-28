#include "Wave.h"
#include "Cell.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

vector <Cell> diff{ {0,-1}, {0,1}, {-1, 0}, {1, 0} };
Wave::Wave(string str_path)
{
	fstream file(str_path, ios::in);
	string str;
	int row{};
	vector <Cell> diff;
	while (!file.eof())
	{
		vector<Cell> line;
		int col{};
		int code{};
		getline(file, str);
		while (str[col])
		{
			switch (str[col])
			{
			case ' ':
				code = Celltype::Space; 
				break;
			case 'S':
				code = Celltype::Start;
				start = Cell(row, col);
				break;
			case 'F':
				code = Celltype::Finish; finish = Cell(row, col);
				break;
			case '#':
				code = Celltype::Wall;
				break;
			default: 
				break;
			}
			line.push_back(Cell(row, col, code));
			col++;
		}
		matrix.push_back(line);
		row++;

	}
	file.close();
}

void Wave::print()
{
	for (auto row : matrix)
	{
		for (auto col : row)
		{
			switch ((Celltype)col.Value())
			{
			case Celltype::Space:
				cout << ' ';
				break;
			case Celltype::Start:
				cout << 'S';
				break;
			case Celltype::Wall:
				cout << (char)-78;
				break;
			case Celltype::Finish:
				cout << 'F';
				break;
			default:
				cout << col.Value();
				break;
			}
		}
		cout << "\n";
	}
}

void Wave::create_wave()
{
	vector<Cell>fronts[2];
	bool index_cur_front{ false };
	int numberfronts{};
	fronts[index_cur_front].push_back(start);
	bool is_finish = false;
	while (true)
	{
		for (auto cell : fronts[index_cur_front])
		{
			int row = cell.Row();
			int col = cell.Col();
			for (int i = 0; i < diff.size(); i++)
			{
				int cur_row = row + diff[i].Row();
				int cur_col = col + diff[i].Col();
				//if (matrix[cur_row][cur_col].Value() == Celltype::Finish)
				if (matrix[cur_row][cur_col].Value() == Celltype::Finish)
				{
					is_finish = true;
					break;
				}
				if(matrix[cur_row][cur_col].Value() == Celltype::Finish)
				{
					matrix[cur_row][cur_col].Value() = numberfronts;
					fronts[!index_cur_front]/*[]*/;
				}

			}
		}
	}
}

void Wave::create_path()
{
	if (!is_finish)
	{
		cout << "no path" << "\n";
		return;
	}
	path.push_back(finish);

	int number_wave = steps;
	while (number_wave)
	{
		int row = path.back().Row();
		int col = path.back().Col();
		for (int i = 0; i < diff.size(); i++)
		{
			int drow = row + diff[i].Row();
			int dcol = col + diff[i].Col();
			int cur_value = matrix[drow][dcol].Value();
			if (cur_value == number_wave - 1)
			{
				number_wave--;
				//path.push_back();
			}
		}
	}
}
