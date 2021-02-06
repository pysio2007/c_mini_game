
#include "Map.h"
#include<iostream>
#include<fstream>
using namespace std;
 
 
Map::Map()
{
	
}
//地图初始化方法
void Map::Init()
{
	int Map[10][10] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 4, 3, 0, 1, 1, 1, 1 },
		{ 1, 0, 4, 3, 4, 3, 0, 0, 1, 1 },
		{ 1, 7, 3, 4, 3, 4, 2, 0, 1, 1 },
		{ 1, 0, 4, 3, 4, 3, 0, 1, 1, 1 },
		{ 1, 0, 0, 4, 3, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	WriteMapFile(Map, 10, "map/map_05.txt");
 
}
//读取地图文件
void Map::ReadMapFile(int map[M][N], int size, const char* filename)
{
	FILE* pfile = nullptr;
	fopen_s(&pfile, filename, "rb");
	fread(map, 10 * size * 4, 1, pfile);
	fclose(pfile);
}
//写入地图文件
void Map::WriteMapFile(int map[M][N], int size, const char* filename)
{
	FILE* pfile = nullptr;
	fopen_s(&pfile, filename, "wb");
	fwrite(map, 10 * size * 4, 1, pfile);
	fclose(pfile);
}
Map::~Map()
{
 
}