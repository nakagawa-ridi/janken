
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
	char JudgResult[JankenResult::RESULT_MAX][RESULT_STRING_MAX] = {
		"引き分け！",
		"プレイヤーの負け！",
		"プレイヤーの勝ち！",
	};

	char SelectHand[JnakenHand::HAND_MAX-1][HAND_SELECT_MAX] = {
		"が出した手は　グー",
		"が出した手は　チョキ",
		"が出した手は　パー",
	};

	//プレイヤーの入力データ
	int PlayerInput = 0;
	//相手の入力データ
	int EnemyInput = 0;

	//勝敗結果判定用
	int Result = 0;

	//勝負の結果をカウント
	int ResultCount[JankenResult::RESULT_MAX] = { 0,0,0 };
};