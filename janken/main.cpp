#include"GameMain.h"

int main()
{
	srand((unsigned int)time(NULL));
	GameMain gamemain;
	while (GameMain::GetGameEndFlg() == 0) {
		gamemain.GameInitialize();
		gamemain.GameUpdate();
		gamemain.GameRender();
	}
		return 0;
}