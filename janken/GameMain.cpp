﻿#include"GameMain.h"
#include<iostream>
#include<cstdlib>

void GameMain::FirstInitialize() 
{
	PlayerInput = 0;
	EnemyInput = 0;
	for (int i = 0; i < JankenResult::RESULT_MAX; i++) {
		ResultCount[i] = 0;
	}
}

void GameMain::GameInitialize() 
{
	PlayerInput = 0;
	EnemyInput = 0;
}

void GameMain::GameUpdate() 
{
	//プレイヤーにデータ入力要求
	std::cout << "グー、チョキ、パーのいずれかを選択してください\n";
	std::cout << "1:グー　2:チョキ　3:パー\n";
	std::cin >> PlayerInput;

	//乱数で相手の出す手を決定
	EnemyInput = rand() % (JnakenHand::HAND_MAX - 1) + 1;

	//勝敗を判定
	ResultCount[Result[EnemyInput-1][PlayerInput - 1]]++;
}

void GameMain::GameRender() 
{
	//選択した手を表示
	this->SelectHandShow(PlayerInput, "プレイヤー");
	this->SelectHandShow(EnemyInput, "相手");

	//勝敗を表示
	//相手の選択した手を判定し、勝敗を判定
	int JudgResultLength = strlen(JudgResult[Result[EnemyInput - 1][PlayerInput - 1]]);
	for (int i = 0; i < JudgResultLength; i++) {
		std::cout << JudgResult[Result[EnemyInput-1][PlayerInput - 1]][i];
	}
	//表示した勝敗判定の改行処理
	std::cout << "\n";

	//勝負結果を表示
	std::cout << ResultCount[JankenResult::WIN] << "勝" << ResultCount[JankenResult::LOSE] << "敗" << ResultCount[JankenResult::DRAW] << "引き分け\n";

	//改行してコンソールの表示を見やすく
	std::cout << "\n\n";
}

void GameMain::SelectHandShow(int InputData, const char *Person)
{
	std::cout << Person;
	int SelectHandLength = strlen(SelectHand[InputData - 1]);
	for (int i = 0; i < SelectHandLength; i++) {
		std::cout << SelectHand[InputData - 1][i];
	}
	//表示した手の改行処理
	std::cout << "\n";
}