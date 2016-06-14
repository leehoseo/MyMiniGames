#pragma once
#include <time.h>

class Stage;

class FootballScreen
{
public:
	FootballScreen();
	~FootballScreen();

	// ���� ���
	void InitScreen();
	// �غ� ���
	void ReadyScreen(int _stage);
	// �÷��� ���
	void BackScreen(const Stage& _StageInfo, int _stage, int _ballCount, clock_t _time);
	// ���� ����Ʈ
	void GoalMessage(int _x, int _y);
	// Stage ���� ����Ʈ
	void SuccessScreen();
	// Stage ���� ����Ʈ
	void FailureScreen();
	// ��� ���
	void ResultScreen(int _stage);
};

