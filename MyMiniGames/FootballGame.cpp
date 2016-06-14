#include "FootballGame.h"
#include "Stage1.h"
#include "Stage2.h"
#include "FootballScreen.h"
#include "GoalPost.h"
#include "Player.h"
#include "Ball.h"
#include "Print.h"
#include <conio.h>
#include <string.h>

FootballGame::FootballGame()
{
	m_pStage = new Stage1();
	m_pStage->Initialize();
	m_pGoalPost = new GoalPost();
	m_pPlayer = new Player();
	m_pBall = new Ball();

	m_pBall->Initialized(m_pPlayer);

	m_eGameState = GAME_STATE::INIT;

	m_LimitTime = 0;
	m_UpdateOldTime = 0;
	m_curTime = 0;
	m_GameStartTime = 0;

	m_nGoalBallCount = 0;
	m_nGoal = 0;
	m_nBallCount = 0;
	m_nCurStage = 0;

	m_IsGoal = false;
}

FootballGame::~FootballGame()
{
	SAFE_DELETE(m_pStage);
	SAFE_DELETE(m_pGoalPost);
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pBall);
}

// GameEntitiy���� �׸���
void FootballGame::Render()
{
	PRINT->ScreenClear();

	RenderScene();

	// Note: ������ �� 
	PRINT->ScreenFlipping();
}

// GameEntity ���� Update��Ų��
void FootballGame::Update()
{
	m_curTime = clock();

	MessageHandler();
	UpdateScene();
}

void FootballGame::MessageHandler()
{
	switch (InputKey())
	{
	case 'y':
	case 'Y':
		if (m_eGameState == GAME_STATE::FAILED)
		{
			Initialize();
			m_eGameState = GAME_STATE::READY;
			//	//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ���� 
			//	//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);
		}
		break;
	case 'n':
	case 'N':
		if (m_eGameState == GAME_STATE::FAILED)
		{
			m_eGameState = GAME_STATE::RESULT;
			//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ����							
		}
		break;

	case ' ':
		if (m_eGameState == GAME_STATE::INIT && m_nCurStage == 0)
		{
			m_eGameState = GAME_STATE::READY;
			//FMOD_Channel_Stop( g_Channel[0] ); // ����� ����
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]); // ready ����
			m_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
		}
		break;
	case 'j':
		m_pPlayer->LMove();
		break;
	case 'l':
		m_pPlayer->RMove();
		break;
	case 'k':
		if (m_eGameState == GAME_STATE::RUNNING)
		{
			m_pBall->Kick();
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // �� ���� �Ҹ� ���
		}
		break;
	}
}

void FootballGame::ChangeStage(Stage * _newStage)
{
	SAFE_DELETE(m_pStage);
	m_pStage = _newStage;
	m_pStage->Initialize();
}

void FootballGame::CollisionCheckBall_GP()
{
	if (m_pBall->GetX() >= m_pGoalPost->GetLineX(0) && m_pBall->GetX() + 1 <= m_pGoalPost->GetLineX(m_pGoalPost->GetMaxLength() - 1) + 1)
	{
		if (m_pBall->GetY() <= m_pGoalPost->GetY())
		{   // �� �ʱ�ȭ
			m_pBall->ResetBall();
			m_nBallCount++;


			if (m_nBallCount == m_nGoalBallCount) // ���� ��ǥ ������ ������ ������ SUCCESS
			{
				m_eGameState = GAME_STATE::STOP;
				m_IsGoal = true;
				return;
			}

			// ȿ�� ���
			if (false == m_IsGoal)
			{
				m_IsGoal = true;
				m_StartTime = m_curTime;
			}

			// ���� ���� ���
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[6], 0, &g_Channel[6]); // ���� ���� �Ϳ�~
		}
		// ��� �浹 
	}
	else if ((m_pBall->GetX() >= m_pGoalPost->GetLineX(0) - 2 && m_pBall->GetX() <= m_pGoalPost->GetLineX(0) - 1) ||
		(m_pBall->GetX() + 1 >= m_pGoalPost->GetLineX(0) - 2 && m_pBall->GetX() + 1 <= m_pGoalPost->GetLineX(0) - 1) ||
		(m_pBall->GetX() >= m_pGoalPost->GetLineX(m_pGoalPost->GetMaxLength() - 1) + 2 && m_pBall->GetX() <= m_pGoalPost->GetLineX(m_pGoalPost->GetMaxLength() - 1) + 3) ||
		(m_pBall->GetX() + 1 >= m_pGoalPost->GetLineX(m_pGoalPost->GetMaxLength() - 1) + 2 && m_pBall->GetX() + 1 <= m_pGoalPost->GetLineX(m_pGoalPost->GetMaxLength() - 1) + 3))
	{
		if (m_pBall->GetY() <= m_pGoalPost->GetY())
		{   // �� �ʱ�ȭ
			m_pBall->ResetBall();
		}
	}
}

bool FootballGame::IsEnd()
{
	if (m_eGameState == GAME_STATE::FAILED)
		return true;
	else
		return false;
}

void FootballGame::RenderScene()
{
	switch (m_eGameState)
	{
	case GAME_STATE::INIT:
		//if (g_nStage == 0)
		m_pScreen.InitScreen();
		break;
	case GAME_STATE::READY:
		m_pScreen.ReadyScreen(m_nCurStage);
		break;
	case GAME_STATE::RUNNING:
		m_pScreen.BackScreen(*m_pStage, m_nCurStage, m_nBallCount, m_GameStartTime);
		m_pGoalPost->Render();

		// Note: ȿ�� ���  	
		if (m_IsGoal == true)
		{
			m_pScreen.GoalMessage(10, 10);
		}

		// Note: 2 �÷��� Ŭ���� 
		m_pPlayer->Render();
		m_pBall->Render();
		break;
	case GAME_STATE::SUCCESS:
		m_pScreen.SuccessScreen();
		break;
	case GAME_STATE::FAILED:
		m_pScreen.FailureScreen();
		break;
	case GAME_STATE::RESULT:
		m_pScreen.ResultScreen(m_nCurStage);
		break;
	}
}

void FootballGame::UpdateScene()
{
	switch (m_eGameState)
	{
	case GAME_STATE::READY:
		if (m_curTime - m_UpdateOldTime > 2000)  // 2��
		{
			m_eGameState = GAME_STATE::RUNNING;
			m_GameStartTime = m_curTime;

			//FMOD_Channel_Stop( g_Channel[3] );  // ready ���� ����
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[1], 0, &g_Channel[1]); // running �����
		}
		break;
	case GAME_STATE::RUNNING:
		if (m_curTime - m_GameStartTime > m_LimitTime) // Note: ���� �ð�
		{
			m_eGameState = GAME_STATE::STOP;
			return;
		}
		else {
			//Note: ���
			m_pGoalPost->MoveGoalPost(m_curTime);
			m_pGoalPost->Update();

			if (false == m_pBall->GetReady()) // �̵� ���� �� 
			{	// �̵� �ð� ���ݿ� ���� �̵�
				if ((m_curTime - m_pBall->GetOldTime()) > m_pBall->GetMoveTime())
				{
					if (m_pBall->GetY() - 1 > 0)
					{
						m_pBall->Update(m_curTime);
						// ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����

						// ��� ���� �浹
						CollisionCheckBall_GP();
					}
					else { // �� �ʱ�ȭ
						m_pBall->ResetBall();
					}
				}
			}
			else
			{
				m_pBall->SetX(m_pPlayer->GetMoveX());
			}

			// ȿ�� 
			if (true == m_IsGoal)
			{
				if (m_curTime - m_StartTime > m_StayTime)
					m_IsGoal = false;
			}
		}
		break;
	case GAME_STATE::STOP:
		if (m_nBallCount == m_nGoalBallCount)
		{
			m_eGameState = GAME_STATE::SUCCESS;
			m_UpdateOldTime = m_curTime;
			//FMOD_Channel_Stop( g_Channel[1] );  // running ���� ����
			//FMOD_Channel_Stop( g_Channel[1] );  // running ���� ����

			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4]); // �̼� ���� ����
		}
		else {
			m_eGameState = GAME_STATE::FAILED;
			//FMOD_Channel_Stop( g_Channel[1] );  // running ���� ����
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // �̼� ���� ����
		}
		break;
	case GAME_STATE::SUCCESS:
		if (m_curTime - m_UpdateOldTime > 3000)
		{
			m_UpdateOldTime = m_curTime;

			ChangeStage(new Stage2());
			m_nCurStage++;
			Initialize();	// Stage ���� �κ�
			m_eGameState = GAME_STATE::READY;
			//FMOD_Channel_Stop( g_Channel[4] );  // �̼� ���� ���� ��� ����					
			//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]); //READY ���� 
		}
		break;
	}
}

int FootballGame::InputKey()
{
	int nKey = 0;

	if (_kbhit())
	{
		if (m_eGameState == GAME_STATE::RESULT)
			return 0;

		nKey = _getch();

		return nKey;
	}
}

// Game ó���� Stage �ٲ� �� ���� , Player , Ball , GoalPost �ʱ�ȭ�� �ֱ�
void FootballGame::Initialize()
{
	m_nGoalBallCount = m_pStage->GetGoalBall();
	m_LimitTime = m_pStage->GetLimitTime();
	m_StayTime = 2000;
	m_nGoal = 0;
	m_nBallCount = 0;
	m_UpdateOldTime = clock();
	m_IsGoal = false;
	m_pGoalPost->Initialize(*m_pStage);
}
