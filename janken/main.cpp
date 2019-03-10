#include"GameMain.h"
#include<ctime>
#include<cstdlib>

int main()
{
	srand((unsigned int)time(NULL));
	GameMain gamemain;
	gamemain.FirstInitialize();
	//無限ループ
	while (1) {
		gamemain.GameInitialize();
		gamemain.GameUpdate();
		gamemain.GameRender();
	}
		return 0;
}