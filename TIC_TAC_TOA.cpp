#include"tao_game.h"
#include<thread>
#include<mmsystem.h>
#include<random>
#include<sstream>
#define MAX 100
bool isPlaying = true;
using namespace std;
void dem(char&);
void tic();
void tac();
void toe();
void ve();
void menunu();
void sound(bool k)
{
	if (k)
	{
		PlaySound(TEXT(".\\a.wav"), NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
	}
	else
	{
		PlaySound(NULL, NULL, 0);
	}
}
void NEWGAME();
void MUTE();
void HUONGDAN();
void THOAT();
void menu();
//Phan biet
void pb(bool k)
{
	if (k)
		memset(xuli, ' ', sizeof(xuli));
}
//start game
void start(bool k)
{
	int dem_nuoc = 0;
	tbao();
	int x, y;
	char nguoi;
	dem(nguoi);
	int kt;
	kt = 2;
	x = 42; y = 13;
	int i = 0;
	pb(k);
	while (true)
	{
		hien_thi(x, y, 1);
		kt = xet_thang_thua(x, y);
		if (kt != 2)
		{
			memset(xuli, ' ', sizeof(xuli));
			hien_thi(x, y, 0);
			clrscr();
			if (kt == 0)
			{
				Bling('O',i);
			}
			else if (kt == 1)
			{
				Bling('X',i);
			}
			else
			{
				Bling('Z',i);
			}
			if (i)
			{
				clrscr();
				menu();
			}
		}
		loop1:
		int check = dieu_khien(x, y, nguoi, dem_nuoc);
		if (!check)
		{
			goto loop1;
		}
		else if(check == 2)
		{
			hien_thi(x, y, 0);
			clrscr();
			menu();
		}
		gotoXY(16, xx + 1);
		TextColor(15);
		cout << dem_nuoc;
	}
}
int main()
{
	sound(1);
	menu();
	return 0 ;
}
void NEWGAME()
{
	clrscr();
	start(1);
	system("pause");
	clrscr();
	menu();
}
bool check()
{
	for (int i = 0; i < doc; i++)
	{
		for (int j = 0; j < ngang; j++)
		{
			if (xuli[i][j] =='X')
				return 1;
		}
	}
	return 0;
}
void CONTINUE()
{
	if (!check())
	{
		clrscr();
		gotoXY(47, 13);
		cout << "KHONG CO DU LIEU CU!!!";
		while (!_kbhit())
		{
			gotoXY(45, 15);
			TextColor(Color_BLACK);
			cout << "NHAN PHIM BAT KI DE TIEP TUC...";
			Sleep(400);
			gotoXY(45, 15);
			TextColor(11);
			cout << "NHAN PHIM BAT KI DE TIEP TUC...";
			Sleep(400);
		}
		_getch();
		clrscr();
		menu();
	}
	else
	{
		start(0);
	}
}
void MUTE()
{
	isPlaying = !isPlaying;
	sound(isPlaying);
	menu();
}
void HUONGDAN(short k)
{
	clrscr();
	string str = "DUNG CAC PHIM DIEU KHIEN DE DI CHUYEN, DUNG PHIM ENTER DE DANH";
	int cnt=30;
	for (int i = 0; i < str.length(); ++i)
	{
		gotoXY(cnt, 11);
		cout << str[i];
		++cnt;
		Sleep(10);
	}
	string strr = "CHUC CAC BAN CHOI GAME VUI VE";
	 cnt = 45;
	for (int i = 0; i < strr.length(); ++i)
	{
		gotoXY(cnt, 13);
		cout << strr[i];
		++cnt;
		Sleep(10);
	}
	while (!_kbhit())
	{
		gotoXY(45, 15);
		TextColor(Color_BLACK);
		cout << "NHAN PHIM BAT KI DE TIEP TUC...";
		Sleep(400);
		gotoXY(45, 15);
		TextColor(11);
		cout << "NHAN PHIM BAT KI DE TIEP TUC...";
		Sleep(400);
	}
	clrscr();
	menu();
}
void THOAT()
{
	gotoXY(0, 13);
	TextColor(7);
	clrscr();
	ExitProcess(0);

}
void menu()
{
	ve();
	menunu();
}
void ve()
{

	ShowCur(0);
	bool b = 0;
	/*while (1)
	{
		b = !b;
		if (b)
		{
			TextColor(Color_Green);
			tic();
			Sleep(1000);
			tac();
			Sleep(1000);
			toe();
			Sleep(200);
		}
		else 
		TextColor(Color_BLACK);
		tic();
		Sleep(150);
		tac();
		Sleep(150);
		toe();
		Sleep(150);
	
	}*/
	TextColor(Color_Cyan);
	tic();
	tac();
	toe();
}
void tic()
{
	int x = 10;
	int y = 1;
	int xxx = 10;
	{
		//chu T
		gotoXY(x, y + 1);
		cout << "|";
		gotoXY(x, y);
		for (int i = 0; i < 7; i++)
		{
			cout << " " << char(196);
			x += 2;
		}
		++y;
		gotoXY(x, y);
		cout << "|"; ++y;

		gotoXY(xxx, y);
		for (int i = 0; i < 2; i++)
		{
			cout << " " << char(196);
			xxx += 2;
		}
		xxx += 6;
		gotoXY(xxx, y);
		for (int i = 0; i < 2; i++)
		{
			cout << " " << char(196);
			xxx += 2;
		}
		x = 14;
		y = 4;
		xxx = 20;
		for (int i = 0; i < 4; ++i)
		{
			gotoXY(x, y); cout << "|";
			gotoXY(xxx, y); cout << "|";
			++y;
		}
		gotoXY(x, y); cout << "\\";
		gotoXY(xxx, y); cout << "/";
		++x;
		++y;
		for (int i = 0; i < 2; i++)
		{

			gotoXY(x, y);
			cout << " " << char(196);
			x += 2;
		}
		//Chu I
		gotoXY(24, 2);
		cout << "(";
		gotoXY(25, 1);
		cout << "__";
		gotoXY(25, 2);
		cout << char(95) << char(95);
		gotoXY(27, 2);
		cout << ")";
		y = 4;
		x = 25;
		gotoXY(x, y);
		cout << char(196) << char(196);
		while (y < 8)
		{
			++y;
			gotoXY(24, y);
			cout << "|";
			gotoXY(27, y);
			cout << "|";
		}
		x = 25;
		y++;
		gotoXY(x, y);
		cout << char(196) << char(196);
		//Chu C
		y = 4;
		x = 29;
		gotoXY(x, y);
		cout << " _ _";
		y++;
		gotoXY(28, y);
		cout << "/";
		y += 3;
		gotoXY(28, y);
		cout << "\\";
		++y;
		x = 29;
		gotoXY(x, y);
		cout << " " << char(196) << " " << char(196);
		gotoXY(34, 5);
		cout << "|";
		gotoXY(34, 8);
		cout << "|";
		x = 31;
		gotoXY(x, 6);
		cout << "- -";
		gotoXY(x, 7);
		cout << "_ _";
		--x;
	}
	//T
} 
void tac()
{
	int x = 10;
	int y = 1;
	int xxx = 10;
	x = 40;
	y = 1;
	gotoXY(x, y + 1);
	cout << "|";
	gotoXY(x, y);
	for (int i = 0; i < 7; i++)
	{
		cout << " " << char(196);
		x += 2;
	}
	++y;
	gotoXY(x, y);
	cout << "|"; ++y;
	xxx = 40;
	gotoXY(xxx, y);
	for (int i = 0; i < 2; i++)
	{
		cout << " " << char(196);
		xxx += 2;
	}
	xxx += 6;
	gotoXY(xxx, y);
	for (int i = 0; i < 2; i++)
	{
		cout << " " << char(196);
		xxx += 2;
	}
	x = 44;
	y = 4;
	xxx = 50;
	for (int i = 0; i < 4; ++i)
	{
		gotoXY(x, y); cout << "|";
		gotoXY(xxx, y); cout << "|";
		++y;
	}
	gotoXY(x, y); cout << "\\";
	gotoXY(xxx, y); cout << "/";
	++x;
	++y;
	for (int i = 0; i < 2; i++)
	{

		gotoXY(x, y);
		cout << " " << char(196);
		x += 2;
	}
	//a
	x = 55, y = 4;
	gotoXY(x, y);
	cout << " ___";
	y++;
	x--;
	gotoXY(x, y);
	cout << "/";
	gotoXY(x - 1, y + 1);
	cout << "| ";
	y += 2;
	gotoXY(x - 1, y);
	cout << "| ";
	++y;
	gotoXY(x, y);
	cout << "\\";
	y++;
	gotoXY(x, y);
	cout << " " << char(196) << char(196) << char(196);
	gotoXY(60, 5);
	cout << "`";
	x = 62;
	gotoXY(x, 4);
	cout << "_";
	x += 2;
	y = 4;
	while (y < 8)
	{
		++y;
		gotoXY(x, y);
		cout << "|";
	}
	x -= 4; ++y;
	while (x < 63)
	{
		++x;
		gotoXY(x, y);
		cout << char(196);
	}
	gotoXY(59, y);
	cout << "^";
	x = 56; y = 6;
	gotoXY(x, y);
	cout << " " << char(196) << char(196);
	y++;
	x--;
	gotoXY(x, y);
	cout << "|";
	x = 56; y++;
	gotoXY(x, y);
	cout << " " << char(196) << char(196);
	x += 4;
	y -= 1;
	gotoXY(x, y);
	cout << "|";
	//x = 60
	//Chu C
	y = 4;
	x = 67;//29
	gotoXY(x, y);
	cout << " _ _";
	y++;
	gotoXY(65, y);
	cout << "/";//k
	y += 3;
	gotoXY(65, y);//k
	cout << "\\";
	++y;
	x = 67;
	gotoXY(x, y);
	cout << " " << char(196) << " " << char(196);
	gotoXY(72, 5);
	cout << "|";
	gotoXY(72, 8);
	cout << "|";
	x = 69;
	gotoXY(x, 6);
	cout << "- -";
	gotoXY(x, 7);
	cout << "_ _";
	--x;
}
void toe()
{
	int x = 75;
	int y = 1;
	int xxx = x;
		//chu T
		gotoXY(x, y + 1);
		cout << "|";
		gotoXY(x, y);
		for (int i = 0; i < 7; i++)
		{
			cout << " " << char(196);
			x += 2;
		}
		++y;
		gotoXY(x, y);
		cout << "|"; ++y;

		gotoXY(xxx, y);
		for (int i = 0; i < 2; i++)
		{
			cout << " " << char(196);
			xxx += 2;
		}
		xxx += 6;
		gotoXY(xxx, y);
		for (int i = 0; i < 2; i++)
		{
			cout << " " << char(196);
			xxx += 2;
		}
		x = 79;
		y = 4;
		xxx = x+6;
		for (int i = 0; i < 4; ++i)
		{
			gotoXY(x, y); cout << "|";
			gotoXY(xxx, y); cout << "|";
			++y;
		}
		gotoXY(x, y); cout << "\\";
		gotoXY(xxx, y); cout << "/";
		++x;
		++y;
		for (int i = 0; i < 2; i++)
		{

			gotoXY(x, y);
			cout << " " << char(196);
			x += 2;
		}
	//x 89
		x = 87;
		gotoXY(x, 4);
		cout << " " << char(196) << " " << char(196) << " " << char(196);
		y = 5; --x;
		gotoXY(x, y);
		cout << "/";
		y+=3;
		gotoXY(x, y);
		cout << "\\";
		++x; ++y;
		gotoXY(x, y);
		cout << " " << char(196) << " " << char(196) << " " << char(196);
		x += 7;
		--y;
		gotoXY(x, y);
		cout << "/";
		y -= 1;
		gotoXY(x+1, y);
		cout << "|";
		y -= 1;
		gotoXY(x+1, y);
		cout << "|";
		y--;
		gotoXY(x, y);
		cout << "\\";
		x = 89;
		y = 5;
		gotoXY(x, y);
		cout << char(196)<< char(196)<< char(196);
		gotoXY(x, y+3);
		cout << char(196) << char(196) << char(196);
		int i = 2;
		while (i--)
		{
			y++;
			gotoXY(x - 1, y);
			cout << "|";
			gotoXY(x + 3, y);
			cout << "|";
		}
		//E 100
		x = 98;
		y = 4;
		i = 3;
		while (i--)
		{
			gotoXY(x, y);
			cout << char(196)<<" ";
			gotoXY(x, y + 2);
			cout << "_" << " ";
			gotoXY(x, y + 5);
			cout << char(196) << " ";
			x+=2;
		}
		gotoXY(x - 6, 2+y);
		cout << " ";
		gotoXY(x - 5, y+1);
		cout << char(196)<< char(196)<< char(196);
		gotoXY(x, y+1);
		cout << "\\";
		gotoXY(x, y + 2);
		cout << "/";
		x = 96;
		y++;
		gotoXY(x, y);
		cout << "/";
		y += 3;
		gotoXY(x, y);
		cout << "\\";
		x += 7;
		gotoXY(x, y);
		cout << "|";
		y--; x -= 5;
		gotoXY(x, y);
		cout << "  " << char(196) << " " << char(196) ;
}
void menunu()
{
	ShowCur(0);
	int x = 55;
	int y = 15;
	int xp = x;
	int yp = y;
	int vitri = -1;
	bool kt = true;
	while (true)
	{
		gotoXY(56, 15);
		TextColor(15);
		cout << "CHOI MOI";
		gotoXY(56, 17);
		TextColor(15);
		cout << "TIEP TUC";
		gotoXY(56, 19);
		TextColor(15);
		if (isPlaying)
		{
			cout << "TAT NHAC";
		}
		else
		{
			cout << "BAT NHAC";
		}
		gotoXY(53, 21);
		TextColor(15);
		cout << "HUONG DAN CHOI";
		gotoXY(57, 23);
		TextColor(15);
		cout << "THOAT";
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				
				c = _getch();
				if (c == 72)
				{
					yp -= 2;
					
				}
				else if (c == 80)
				{
					yp += 2;
					
				}

			}
			else if (c == 13)
			{
				vitri = (yp - y) / 2;
			}

		}
		if (yp < 15)
			yp = 23;
		else if (yp > 23)
			yp = 15;
		if (yp == 15)
		{
			gotoXY(56, 15);
			SetColor(11);
			cout << "CHOI MOI";
		}
		else if (yp == 17)
		{
			gotoXY(56, 17);
			SetColor(11);
			cout << "TIEP TUC";
		}
		else if (yp == 19)
		{
			gotoXY(56, 19);
			SetColor(11);
			if (isPlaying)
			{
				cout << "TAT NHAC";
			}
			else
			{
				cout << "BAT NHAC";
			}
		}
		else if (yp == 21)
		{
			gotoXY(53, 21);
			SetColor(11);
			cout << "HUONG DAN CHOI";
		}
		else if (yp == 23)
		{
			gotoXY(57, 23);
			SetColor(11);
			cout << "THOAT";
		}
		if (vitri == 0) {
			
			NEWGAME();
		}
		else if (vitri == 1)
		{
			
			CONTINUE();
		}
		else if (vitri == 2)
		{

			MUTE();
		}
		else if (vitri == 3)
		{
			
			HUONGDAN(1);
		}
		else if (vitri == 4)
		{
			
			THOAT();
		}
		Sleep(100);
		
	}

}
void dem(char &k)
{
	int cntX = 0, cntO = 0;
	for (int i = 0; i < doc; i++)
	{
		for (int j = 0; j < ngang; j++)
		{
			if (xuli[i][j] == 'X')
				++cntX;
			else if (xuli[i][j] == 'O')
				++cntO;
		}
	}
	if (cntX == cntO)
		k = 'X';
	else if (cntX > cntO)
		k = 'O';
}