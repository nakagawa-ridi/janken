#include"GameMain.h"


int GameMain::GameEndFlg;


void GameMain::GameInitialize() 
{
	PlayerInput = 0;
	EnemyInput = 0;
	JudgResult = 4;

	GameEndFlg = 0;
}

void GameMain::GameUpdate() 
{
	//プレイヤーにデータ入力要求
	std::cout << "グー、チョキ、パーのいずれかを選択してください\n";
	std::cout << "1:グー　2:チョキ　3:パー\n";
	std::cin >> PlayerInput;

	//乱数で相手の出す手を決定
	EnemyInput = rand() % 3 + 1;

	//勝敗を判定
	Judg(PlayerInput, EnemyInput);
}

void GameMain::GameRender() 
{
	//選択した手を表示
	GameMain::SelectHandShow(PlayerInput, "プレイヤー");
	GameMain::SelectHandShow(EnemyInput, "相手");

	//勝敗を表示
	judgView(JudgResult);

	//勝負結果を表示
	std::cout << WinCount << "勝" << LoseCount << "敗" << DrowCount << "引き分け\n";

	//改行してコンソールの表示を見やすく
	std::cout << "\n\n";
}

void GameMain::SelectHandShow(int InputData, const char *Person)
{
	switch (InputData) {
	case GU:
		std::cout << Person << "が出した手は　グー\n";
		break;
	case CHOKI:
		std::cout << Person << "が出した手は　チョキ\n";
		break;
	case PA:
		std::cout << Person << "が出した手は　パー\n";
		break;
	default:
		break;
	}
}

void GameMain::Judg(int PlayerInputData, int RandumInputData)
{
	//プレイヤーの選択した手を判定
	switch (PlayerInputData) {
		case GU:
			//相手の選択した手を判定し、勝敗を判定
			switch (RandumInputData) {
				case GU:
					JudgResult = DRAW;
					DrowCount++;
					break;
				case CHOKI:
					JudgResult = WIN;
					WinCount++;
					break;
				case PA:
					JudgResult = LOSE;
					LoseCount++;
					break;
				}
			break;
		case CHOKI:
			//相手の選択した手を判定し、勝敗を判定
			switch (RandumInputData) {
				case GU:
					JudgResult = LOSE;
					LoseCount++;
					break;
				case CHOKI:
					JudgResult = DRAW;
					DrowCount++;
					break;
				case PA:
					JudgResult = WIN;
					WinCount++;
					break;
				}
			break;
		case PA:
			//相手の選択した手を判定し、勝敗を判定
			switch (RandumInputData) {
				case GU:
					JudgResult = WIN;
					WinCount++;
					break;
				case CHOKI:
					JudgResult = LOSE;
					LoseCount++;
					break;
				case PA:
					JudgResult = DRAW;
					DrowCount++;
					break;
				}
			break;
		case 100:
			GameEndFlg = 1;
			break;
	}
}

void GameMain::judgView(int Result)
{
	//相手の選択した手を判定し、勝敗を判定
	switch (Result) {
	case WIN:
		std::cout << "プレイヤーの勝ち！\n";
		break;
	case DRAW:
		std::cout << "引き分け！\n";
		break;
	case LOSE:
		std::cout << "プレイヤーの負け！\n";
		break;
	default:
		break;
	}
}


