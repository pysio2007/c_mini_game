
#pragma once
#define N 10
#define M 10
//地图类
class Map
{
public:
	Map();
	~Map();
	void Init();
 
	void ReadMapFile(int map[M][N], int size,const char* filename );
	void WriteMapFile(int map[M][N], int size, const char* filename);
private:
	
