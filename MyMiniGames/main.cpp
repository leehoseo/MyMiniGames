#include <stdio.h>

#include "GameManager.h"
void main()
{
	int choice = 0;
	printf("1.ǲ�� ����		2.�����\n");
	scanf_s("%d", &choice);

	GameManager::Instance()->SelectGame((eGAME)choice);

	while (GameManager::Instance()->IsEnd() != true)
	{
		GameManager::Instance()->Update();
		GameManager::Instance()->Render();
	}
}