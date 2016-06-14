#pragma once

class Print
{
private:
	Print();

	void* m_hscreen[2];
	int m_nscreenIndex;

public:
	static Print* Instance();
	~Print();

	void ScreenPrint(int _x, int _y, char* _string);
	// Screen �ʱ�ȭ
	void ScreenInit();
	// m_hscreen ���� �ٲ���(Flipping)
	void ScreenFlipping();
	// Screen�� ����ش�
	void ScreenClear();
	// m_hscreen �� �����ش�
	void ScreenRelease();

	// ������
	void SetColor(int color);
};


#define PRINT Print::Instance()
