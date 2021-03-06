
#include<iostream>
#include<string.h>
using namespace std;
#pragma warning (disable:4996)
#define M 10
#define N 10
 
//定义一个10*10地图,1表示墙,0表示空地,2表示人
//3表示箱子,4表示成功点
//1.人物可以站到成功点中,显示人
//2.箱子推入成功点后,可以推出来
//3.记录步数,显示在控制台上
//4.界面:提示(■代表墙....)/游戏开始界面
//5.最终提示全部推入,提示成功
//周围都是墙,中间都是空地
#include"Map.h"
#include"Game.h"
int main()
{
	Map _map;
	//_map.Init();
	int map[M][N];
	char filename[] = "map/map_0";
	int custom = 2;
	while (custom <= 5)
	{
		char buffer[80];
		sprintf(buffer, "%s%d", filename, custom);         //连接filename和custom,以字符串保存到buffer中
		strcat(buffer, ".txt");                            //字符串连接
		_map.ReadMapFile(map, N, buffer);
		Game game;
		int step = 0;
		while (game.juide(map))                           //游戏胜利，跳出循环
		{
			system("cls");
			game.Drop(map, custom);
			char ch = _getch();                           //按键输入
			step = game.Move(map, ch);
			system("cls");
		}
		custom++;                            //关卡+1
		cout << "你赢了!" << endl;
		cout << "共走：" << step << "步" << endl;;
		system("pause");
		
	}
	
	
	return 0;
}