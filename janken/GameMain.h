#pragma once

class GameMain
{
public:
	//ゲーム起動時にすべての変数を初期化
	void FirstInitialize();
	//初期化
	void GameInitialize();
	//更新
	void GameUpdate();
	//描画
	void GameRender();

	//選択した手を表示
	void SelectHandShow(int InputData, const char *Person);

private:
	//じゃんけんの手
	enum JnakenHand {
		NONE = 0,
		GU,
		CHOKI,
		PA,
		HAND_MAX,
	};

	//じゃんけんの結果
	enum JankenResult{
		DRAW = 0,
		LOSE,
		WIN,
		RESULT_MAX,
	};
	
	static const int RESULT_STRING_MAX = 19;
	static const int HAND_SELECT_MAX = 21;

	//勝負の結果を表示用
	const char *JudgResult[JankenResult::RESULT_MAX] = {
		"引き分け！",
		"プレイヤーの負け！",
		"プレイヤーの勝ち！",
	};

	const char *SelectHand[JnakenHand::HAND_MAX-1] = {
		"が出した手は　グー",
		"が出した手は　チョキ",
		"が出した手は　パー",
	};

	//勝敗結果判定用
	const int Result[JnakenHand::HAND_MAX - 1][JnakenHand::HAND_MAX - 1] = {
		{JankenResult::DRAW, JankenResult::LOSE, JankenResult::WIN},
		{JankenResult::WIN, JankenResult::DRAW, JankenResult::LOSE},
		{JankenResult::LOSE, JankenResult::WIN, JankenResult::DRAW},
	};

	//プレイヤーの入力データ
	int PlayerInput;
	//相手の入力データ
	int EnemyInput;

	//勝負の結果をカウント
	int ResultCount[JankenResult::RESULT_MAX];
};