#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define SAFE_DELETE(ptr) { if (nullptr != ptr) delete ptr; ptr = NULL; }

#define EXT_KEY			0xffffffe0	//Ȯ��Ű �νİ� 
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50

namespace FOOTBALLGAME
{
	enum GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT };
};

namespace SNAKEGAME
{
	enum COLOR{
		BLACK,      /*  0 : ��� */
		DARK_BLUE,    /*  1 : ��ο� �Ķ� */
		DARK_GREEN,    /*  2 : ��ο� �ʷ� */
		DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
		DARK_RED,    /*  4 : ��ο� ���� */
		DARK_VOILET,  /*  5 : ��ο� ���� */
		DARK_YELLOW,  /*  6 : ��ο� ��� */
		GRAY,      /*  7 : ȸ�� */
		DARK_GRAY,    /*  8 : ��ο� ȸ�� */
		BLUE,      /*  9 : �Ķ� */
		GREEN,      /* 10 : �ʷ� */
		SKY_BLUE,    /* 11 : �ϴ� */
		RED,      /* 12 : ���� */
		VOILET,      /* 13 : ���� */
		YELLOW,      /* 14 : ��� */
		WHITE,      /* 15 : �Ͼ� */
	};

	enum DIRECTION {STOP , UP , LEFT , RIGHT , DOWN };

	const int ABS_X = 2;
	const int ABS_Y = 2;
};



namespace GAME
{
	enum eGAME { FOOTBALL = 1, SNAKEGAME = 2 };
};