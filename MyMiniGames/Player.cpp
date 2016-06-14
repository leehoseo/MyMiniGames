#include "Player.h"
#include <windows.h>
#include "Print.h"

Player::Player()
{
	m_strPlayer = "�����ܦ���";
	Initialize();
}


Player::~Player()
{
}

void Player::Initialize()
{
	m_nCenterX = 4;
	m_nCenterY = 0;

	m_nMoveX = 20;
	m_nMoveY = 22;

	m_nX = m_nMoveX - m_nCenterX;

	m_nLength = strlen(m_strPlayer);
}

void Player::Render()
{
	char string[100] = { 0, };
	if (m_nX < 2)  //  ���� Ŭ���� ó��  g_nLength : Player
		PRINT->ScreenPrint(2, m_nMoveY, &m_strPlayer[(m_nX - 2)*-1]);	 // ��ǥ�� �迭 �ε��� 
	else if (m_nMoveX + (m_nLength - m_nCenterX + 1) > 43) // ������ Ŭ���� ó��
	{
		strncat_s(string, m_strPlayer, m_nLength - ((m_nMoveX + m_nCenterX + 1) - 43));
		PRINT->ScreenPrint(m_nX, m_nMoveY, string);
	}
	else { // 1 �÷��� �̵�
		PRINT->ScreenPrint(m_nX, m_nMoveY, m_strPlayer);
	}
}

void Player::LMove()
{
	int nRemain = 0;
	if (m_nMoveX > 2) // ���� �浹 ��� ��ǥ üũ
	{
		m_nMoveX--;
		nRemain = m_nLength - m_nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
											  // Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
		if (m_nMoveX - m_nCenterX < 2 || m_nMoveX + nRemain > 43)
			m_nMoveX--;

		m_nX = m_nMoveX - m_nCenterX;
	}
}

void Player::RMove()
{
	int nRemain = 0;

	if (m_nMoveX + 1 < 43) // ������ �浹 ��� ��ǥ üũ
	{
		m_nMoveX++;
		nRemain = m_nLength - m_nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
											  // Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
		if (m_nMoveX + nRemain > 43 || (m_nMoveX - m_nCenterX < 2))
			m_nMoveX++;

		m_nX = m_nMoveX - m_nCenterX;
	}
}
