#include "FootballScreen.h"
#include "Print.h"
#include "Stage.h"
#include <windows.h>
#include <stdio.h>

FootballScreen::FootballScreen()
{
}


FootballScreen::~FootballScreen()
{
}


// ���� ���
void FootballScreen::InitScreen()
{
	PRINT->ScreenPrint(0, 0, "����������������������������������������������");
	PRINT->ScreenPrint(0, 1, "��                                          ��");
	PRINT->ScreenPrint(0, 2, "��             �ব������                   ��");
	PRINT->ScreenPrint(0, 3, "��                                          ��");
	PRINT->ScreenPrint(0, 4, "��                        ///.   ��~~~      ��");
	PRINT->ScreenPrint(0, 5, "��                       (^.^)              ��");
	PRINT->ScreenPrint(0, 6, "��                      ���� ����           ��");
	PRINT->ScreenPrint(0, 7, "��                         ����             ��");
	PRINT->ScreenPrint(0, 8, "��                     ��  ����             ��");
	PRINT->ScreenPrint(0, 9, "��                                          ��");
	PRINT->ScreenPrint(0, 10, "��                                          ��");
	PRINT->ScreenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
	PRINT->ScreenPrint(0, 12, "��                                          ��");
	PRINT->ScreenPrint(0, 13, "��                                          ��");
	PRINT->ScreenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
	PRINT->ScreenPrint(0, 15, "��                                          ��");
	PRINT->ScreenPrint(0, 16, "��                                          ��");
	PRINT->ScreenPrint(0, 17, "��                                          ��");
	PRINT->ScreenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
	PRINT->ScreenPrint(0, 19, "��                                          ��");
	PRINT->ScreenPrint(0, 20, "��                                          ��");
	PRINT->ScreenPrint(0, 21, "��                                          ��");
	PRINT->ScreenPrint(0, 22, "����������������������������������������������");
}


// �غ� ���
void FootballScreen::ReadyScreen(int _stage)
{
	char string[100];

	PRINT->ScreenPrint(0, 0, "����������������������������������������������");
	PRINT->ScreenPrint(0, 1, "�����������������������᦭");
	PRINT->ScreenPrint(0, 2, "�����������������������᦭");
	PRINT->ScreenPrint(0, 3, "�����������������������᦭");
	PRINT->ScreenPrint(0, 4, "�����������������������᦭");
	PRINT->ScreenPrint(0, 5, "�����������������������᦭");
	PRINT->ScreenPrint(0, 6, "�����������������������᦭");
	PRINT->ScreenPrint(0, 7, "�����������������������᦭");
	PRINT->ScreenPrint(0, 8, "�����������������������᦭");
	PRINT->ScreenPrint(0, 9, "�����������������������᦭");
	PRINT->ScreenPrint(0, 10, "��������                    ������᦭");
	sprintf_s(string, "��������     %d   ��������   ������᦭", _stage + 1);
	PRINT->ScreenPrint(0, 11, string);
	PRINT->ScreenPrint(0, 12, "��������                    ������᦭");
	PRINT->ScreenPrint(0, 13, "�����������������������᦭");
	PRINT->ScreenPrint(0, 14, "�����������������������᦭");
	PRINT->ScreenPrint(0, 15, "�����������������������᦭");
	PRINT->ScreenPrint(0, 16, "�����������������������᦭");
	PRINT->ScreenPrint(0, 17, "�����������������������᦭");
	PRINT->ScreenPrint(0, 18, "�����������������������᦭");
	PRINT->ScreenPrint(0, 19, "�����������������������᦭");
	PRINT->ScreenPrint(0, 20, "�����������������������᦭");
	PRINT->ScreenPrint(0, 21, "�����������������������᦭");
	PRINT->ScreenPrint(0, 22, "�����������������������᦭");
	PRINT->ScreenPrint(0, 23, "����������������������������������������������");
}


// �÷��� ���
void FootballScreen::BackScreen(const Stage& _StageInfo, int _stage, int _ballCount, clock_t _time)
{
	char string[100];

	PRINT->ScreenPrint(0, 0, "����������������������������������������������");
	PRINT->ScreenPrint(0, 1, "��                                          ��");
	PRINT->ScreenPrint(0, 2, "��                                          ��");
	PRINT->ScreenPrint(0, 3, "��                                          ��");
	sprintf_s(string, "��                                          ����������: %d", _stage + 1);
	PRINT->ScreenPrint(0, 4, string);
	PRINT->ScreenPrint(0, 5, "��                                          ��");
	sprintf_s(string, "�������������������������������������������������� �ð�: %d", _StageInfo.GetLimitTime() / 1000);
	PRINT->ScreenPrint(0, 6, string);
	PRINT->ScreenPrint(0, 7, "��                                          ��");
	sprintf_s(string, "��                                          ������ �ð�: %d", (clock() - _time) / 1000);
	PRINT->ScreenPrint(0, 8, string);
	PRINT->ScreenPrint(0, 9, "��                                          ��");
	sprintf_s(string, "��                                          ����ǥ ����: %d ", _StageInfo.GetGoalBall());
	PRINT->ScreenPrint(0, 10, string);
	PRINT->ScreenPrint(0, 11, "��                                          ��");
	sprintf_s(string, "��                                          ������ �� ����: %d ", _ballCount);
	PRINT->ScreenPrint(0, 12, string);

	PRINT->ScreenPrint(0, 13, "��                                          ��");
	sprintf_s(string, "��                                          ��");
	PRINT->ScreenPrint(0, 14, string);
	PRINT->ScreenPrint(0, 15, "��                                          ��");
	sprintf_s(string, "��                                          ��");
	PRINT->ScreenPrint(0, 16, string);
	PRINT->ScreenPrint(0, 17, "��                                          ��");
	PRINT->ScreenPrint(0, 18, "��                                          ��");
	PRINT->ScreenPrint(0, 19, "��                                          ��");
	PRINT->ScreenPrint(0, 20, "��                                          ��");
	PRINT->ScreenPrint(0, 21, "��                                          ��");
	PRINT->ScreenPrint(0, 22, "��                                          ��");
	PRINT->ScreenPrint(0, 23, "����������������������������������������������");
}

// ���� ����Ʈ
void FootballScreen::GoalMessage(int _x, int _y)
{
	PRINT->ScreenPrint(_x, _y, "�� )) ���� (( ��");
	PRINT->ScreenPrint(_x, _y + 1, "��(^^')/ ��(\"*')/");
	PRINT->ScreenPrint(_x, _y + 2, "   ��       ��");
	PRINT->ScreenPrint(_x, _y + 3, "  ����    ����");
}


// Stage ���� ����Ʈ
void FootballScreen::SuccessScreen()
{
	PRINT->ScreenPrint(0, 0, "����������������������������������������������");
	PRINT->ScreenPrint(0, 1, "��                                          ��");
	PRINT->ScreenPrint(0, 2, "��                                          ��");
	PRINT->ScreenPrint(0, 3, "��                                          ��");
	PRINT->ScreenPrint(0, 4, "��                                          ��");
	PRINT->ScreenPrint(0, 5, "��                                          ��");
	PRINT->ScreenPrint(0, 6, "��                ////����                  ��");
	PRINT->ScreenPrint(0, 7, "��               q ��  �� p                 ��");
	PRINT->ScreenPrint(0, 8, "��               (��������)                 ��");
	PRINT->ScreenPrint(0, 9, "��             �� �̼� ���� ��              ��");
	PRINT->ScreenPrint(0, 10, "��                                          ��");
	PRINT->ScreenPrint(0, 11, "��                                          ��");
	PRINT->ScreenPrint(0, 12, "��                                          ��");
	PRINT->ScreenPrint(0, 13, "��                                          ��");
	PRINT->ScreenPrint(0, 14, "��                                          ��");
	PRINT->ScreenPrint(0, 15, "��                                          ��");
	PRINT->ScreenPrint(0, 16, "��                                          ��");
	PRINT->ScreenPrint(0, 17, "��                                          ��");
	PRINT->ScreenPrint(0, 18, "��                                          ��");
	PRINT->ScreenPrint(0, 19, "��                                          ��");
	PRINT->ScreenPrint(0, 20, "��                                          ��");
	PRINT->ScreenPrint(0, 21, "��                                          ��");
	PRINT->ScreenPrint(0, 22, "��                                          ��");
	PRINT->ScreenPrint(0, 23, "����������������������������������������������");
}


// Stage ���� ����Ʈ
void FootballScreen::FailureScreen()
{
	PRINT->ScreenPrint(0, 0, "����������������������������������������������");
	PRINT->ScreenPrint(0, 1, "��                                          ��");
	PRINT->ScreenPrint(0, 2, "��                                          ��");
	PRINT->ScreenPrint(0, 3, "��                                          ��");
	PRINT->ScreenPrint(0, 4, "��                                          ��");
	PRINT->ScreenPrint(0, 5, "��                                          ��");
	PRINT->ScreenPrint(0, 6, "��                                          ��");
	PRINT->ScreenPrint(0, 7, "��                                          ��");
	PRINT->ScreenPrint(0, 8, "��                                          ��");
	PRINT->ScreenPrint(0, 9, "��                                          ��");
	PRINT->ScreenPrint(0, 10, "��                                          ��");
	PRINT->ScreenPrint(0, 11, "��                    �̼� ���� !!!!        ��");
	PRINT->ScreenPrint(0, 12, "��                                          ��");
	PRINT->ScreenPrint(0, 13, "��                                          ��");
	PRINT->ScreenPrint(0, 14, "��                 �ܦ�����                 ��");
	PRINT->ScreenPrint(0, 15, "��                   ��  ��                 ��");
	PRINT->ScreenPrint(0, 16, "��                  �����                ��");
	PRINT->ScreenPrint(0, 17, "��                                          ��");
	PRINT->ScreenPrint(0, 18, "��        �ٽ� �Ͻðڽ��ϱ�? (y/n)          ��");
	PRINT->ScreenPrint(0, 19, "��                                          ��");
	PRINT->ScreenPrint(0, 20, "��                                          ��");
	PRINT->ScreenPrint(0, 21, "��                                          ��");
	PRINT->ScreenPrint(0, 22, "����������������������������������������������");
}


// ��� ���
void FootballScreen::ResultScreen(int _stage)
{
	char string[100];
	PRINT->ScreenPrint(0, 0, "����������������������������������������������");
	PRINT->ScreenPrint(0, 1, "��                                          ��");
	PRINT->ScreenPrint(0, 2, "��                                          ��");
	PRINT->ScreenPrint(0, 3, "��             �ব������                   ��");
	PRINT->ScreenPrint(0, 4, "��                                          ��");
	PRINT->ScreenPrint(0, 5, "��                                          ��");
	PRINT->ScreenPrint(0, 6, "��                                          ��");
	PRINT->ScreenPrint(0, 7, "��                                          ��");
	sprintf_s(string, "��      ������ �������� :  %2d               ��", _stage + 1);
	PRINT->ScreenPrint(0, 8, string);
	PRINT->ScreenPrint(0, 9, "��                                          ��");
	PRINT->ScreenPrint(0, 10, "��                                          ��");
	PRINT->ScreenPrint(0, 11, "��   ___�ƢƢ�___                           ��");
	PRINT->ScreenPrint(0, 12, "��     (*^  ^*)                             ��");
	PRINT->ScreenPrint(0, 13, "�� =====��==��=====                         ��");
	PRINT->ScreenPrint(0, 14, "��                                          ��");
	PRINT->ScreenPrint(0, 15, "��                                          ��");
	PRINT->ScreenPrint(0, 16, "��                                          ��");
	PRINT->ScreenPrint(0, 17, "��                                          ��");
	PRINT->ScreenPrint(0, 18, "��                      ���ܦ�              ��");
	PRINT->ScreenPrint(0, 19, "��                                          ��");
	PRINT->ScreenPrint(0, 20, "��                                          ��");
	PRINT->ScreenPrint(0, 21, "��                                          ��");
	PRINT->ScreenPrint(0, 22, "����������������������������������������������");
}
