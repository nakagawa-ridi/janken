#include<iostream>
#include<ctime>
#include<cstdlib>

class GameMain
{
public:
	//初期化
	void GameInitialize();
	//更新
	void GameUpdate();
	//描画
	void GameRender();

	//選択した手を表示
	void SelectHandShow(int InputData, const char *Person);
	//勝敗決定
	void Judg(int PlayerInputData ,int RandumInputData);

	//勝敗表示
	void judgView(int Result);

	static int GetGameEndFlg() {return GameEndFlg;};

private:
	//じゃんけんの手
	static const int GU = 1;
	static const int CHOKI = 2;
	static const int PA = 3;

	//じゃんけんの結果
	static const int WIN = 0;
	static const int DRAW = 1;
	static const int LOSE = 2;

	//プレイヤーの入力データ
	int PlayerInput = 0;
	//相手の入力データ
	int EnemyInput = 0;

	//勝負の結果を表示用
	int JudgResult = 0;

	//勝負の結果をカウント
	int WinCount = 0;
	int DrowCount = 0;
	int LoseCount = 0;

	static int GameEndFlg;
};