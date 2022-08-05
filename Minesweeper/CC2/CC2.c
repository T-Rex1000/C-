#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>

int X = 20, Y = 10;
int win = 0, fail = 0;

int nextcount = 0;
int x = 0;
int y = 0;

int boom_count = 0;
int maps[40][40] = { {0} };
struct BOOM
{
	int x;
	int y;
}boom[40];

int gotoxy(int, int);
void map();
void booms();
void mem();
void game();

void map()
{
	int x, y;
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			maps[i][j] = 0;
		}
	}
	gotoxy(0, 0);
	for (int j = 0; j < 40; j += 1)
	{
		for (int i = 0; i < 90; i += 2)
		{
			printf("  ");
		}
		printf("\n");
	}
	gotoxy(0, 0);
	for (y = 0; y < Y; y += 1)
	{
		for (x = 0; x < X; x += 2)
		{
			printf("■");
		}
		printf("\n");
	}
	booms();
}
void booms()
{
	int i, x, y;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 2 * Y; i++)
	{
		x = rand() % X / 2;
		y = rand() % Y;
		if (maps[x][y] == 0)
		{
			maps[x][y] = -10;
			boom[i].x = x * 2;
			boom[i].y = y;
			boom_count++;
		}
		else
			i--;
	}
	gotoxy(X + 2, 1);
	printf("×：%d", boom_count);
	mem();
	game();
}
void mem()
{
	int b = 0;
	int o = -10;
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (maps[x][y] != o)
			{
				if (y - 1 >= 0 && maps[x][y - 1] == o)
					b++;
				if (y + 1 < 20 && maps[x][y + 1] == o)
					b++;
				if (x - 1 >= 0 && maps[x - 1][y] == o)
					b++;
				if (x + 1 < 20 && maps[x + 1][y] == o)
					b++;
				if (x - 1 >= 0 && y - 1 >= 0 && maps[x - 1][y - 1] == o)
					b++;
				if (x + 1 < 20 && y - 1 >= 0 && maps[x + 1][y - 1] == o)
					b++;
				if (x - 1 >= 0 && y + 1 < 20 && maps[x - 1][y + 1] == o)
					b++;
				if (x + 1 < 20 && y + 1 < 20 && maps[x + 1][y + 1] == o)
					b++;
				b++;
				maps[x][y] = b * -1;
				//printf("%d,%d", maps[x][y], maps[19][18]);
				//gotoxy(5, 5);
				//printf("%d", b);
				b = 0;
			}
		}
	}

}

int gotoxy(int x, int y)
{
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//将输入光标移动到指定位置（x,y）
}

void game(void)
{
	x = 0; y = 0;
	int key = 0, k = 1, prex = 0, prey = 0, flag = 0, empty = 0;
	FILE* write;
	gotoxy(X + 2, 2);
	printf("√：%d  ", flag);
	while (1)
	{


		gotoxy(prex * 2, prey);
		if (maps[prex][prey] <= 0)
			printf("■");
		else if (maps[prex][prey] > 0 && maps[prex][prey] < 10)
			printf(" %d", maps[prex][prey] - 1);
		else if (maps[prex][prey] >= 10 && maps[prex][prey] <= 19)
			printf("√");

		if (k)
		{
			gotoxy(x, y);
			printf("◎");
		}
		else
			k = 1;
		gotoxy(X + 2, 3);
		printf("◎：%d,%d ", x / 2 + 1, y + 1);
		key = getch();
		switch (key)
		{
			//大写WASD
		case 87:
			if (y != 0)
			{
				prex = x / 2;
				prey = y;
				y -= 1;
			}
			break;
		case 83:
			if (y != Y - 1)
			{
				prex = x / 2;
				prey = y;
				y += 1;
			}
			break;
		case 65:
			if (x != 0)
			{
				prex = x / 2;
				prey = y;
				x -= 2;
			}
			break;
		case 68:
			if (x != X - 2)
			{
				prex = x / 2;
				prey = y;
				x += 2;
			}
			break;
			//小写wasd
		case 119:
			if (y != 0)
			{
				prex = x / 2;
				prey = y;
				y -= 1;
			}
			break;
		case 115:
			if (y != Y - 1)
			{
				prex = x / 2;
				prey = y;
				y += 1;
			}
			break;
		case 97:
			if (x != 0)
			{
				prex = x / 2;
				prey = y;
				x -= 2;
			}
			break;
		case 100:
			if (x != X - 2)
			{
				prex = x / 2;
				prey = y;
				x += 2;
			}
			break;
			//方向键
		case 72:
			if (y != 0)
			{
				prex = x / 2;
				prey = y;
				y -= 1;
			}
			break;
		case 80:
			if (y != Y - 1)
			{
				prex = x / 2;
				prey = y;
				y += 1;
			}
			break;
		case 75:
			if (x != 0)
			{
				prex = x / 2;
				prey = y;
				x -= 2;
			}
			break;
		case 77:
			if (x != X - 2)
			{
				prex = x / 2;
				prey = y;
				x += 2;
			}
			break;
		case 13:

			if (maps[x / 2][y] < 0)
			{
				if (maps[x / 2][y] == -10)
				{
					for (int i = 0; i < Y * 2; i++)
					{
						gotoxy(boom[i].x, boom[i].y);
						printf("×");
						if (i == 2 * Y - 1)
						{
							fail++;
							write = fopen("count.txt", "w");
							fprintf(write, "%d\n%d", win, fail);
							gotoxy(2, Y + 2);
							printf("胜场：%d  败场：%d  胜率：%0.2f%%", win, fail, ((float)win / (win + fail)) * 100);
							fclose(write);
							gotoxy(2, Y + 3);
							printf("游戏失败！按下ENTER键重新开始");
							if (getch() == 13)
								map();
							else
								exit(1);
						}
					}
				}
				else if (maps[x / 2][y] > -10)
				{
					k = 0;
					maps[x / 2][y] *= -1;
					gotoxy(x, y);
					printf(" %d", maps[x / 2][y] - 1);

					empty++;
					if (empty == Y * Y - 2 * Y)
					{
						win++;
						write = fopen("count.txt", "w");
						fprintf(write, "%d\n%d", win, fail);
						gotoxy(2, Y + 2);
						printf("胜场：%d  败场：%d  胜率：%0.2f%%", win, fail, ((float)win / (win + fail)) * 100.0);
						fclose(write);
						gotoxy(2, Y + 3);
						printf("恭喜，通过成功");
						gotoxy(2, Y + 4);
						printf("按下ENTER键开始新游戏");
						int next;
						next = getch();

						if (next == 13)
						{
							Y += 5;
							X += 10;
							nextcount++;
							map();
						}
						else
						{
							exit(1);
						}
						if (Y == 40 && nextcount == 2)
						{
							gotoxy(20, Y + 5);
							printf("恭喜，通过全部关卡");
							Sleep(5000);
							exit(1);
						}
					}
				}
			}
			break;
		case 32:
			if (maps[x / 2][y] < 0 && flag < X)
			{
				gotoxy(x, y);
				printf("√");
				maps[x / 2][y] += 20;
				flag++;
			}
			else if (maps[x / 2][y] >= 10)
			{
				gotoxy(x, y);
				printf("■");
				maps[x / 2][y] -= 20;
				flag--;
			}
			k = 0;
			gotoxy(X + 2, 2);
			printf("√：%d  ", flag);
			break;
		}
	}
}

void main()
{
	char select;
	gotoxy(0, 0);
	FILE* read;
	if ((read = fopen("count.txt", "r")) != NULL)
	{
		fscanf(read, "%d%d", &win, &fail);
		fclose(read);
	}
	gotoxy(0, 0);
A:	printf("请选择难度：1.简单  2.一般  3.困难\n");
	select = getchar();
	if (select == '\n')
	{
		goto A;
	}
	while (getchar() != '\n')
	{
		continue;
	}
	switch (select)
	{
	case '1':
		Y = 10;
		X = 20;
		break;
	case '2':
		Y = 15;
		X = 30;
		break;
	case '3':
		Y = 20;
		X = 40;
		break;
	default:goto A;
	}
	map();
}