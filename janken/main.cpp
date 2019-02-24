#include<ctime>
#include<cstdlib>
#include"GameMain.h"

int main()
{
	srand((unsigned int)time(NULL));
	GameMain gamemain;
	gamemain.GameInitialize();
	//無限ループ
	while (1) {
		gamemain.GameInitialize();
		gamemain.GameUpdate();
		gamemain.GameRender();
	}
		return 0;
}