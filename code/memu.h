#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;

#define LINE_SIZE 30
inline void clear() {system("cls");}

class Menu
{
public:
    static string getLine(int x, int y)
    {
        gotoxy(x, y);
        char s[30] = "", c;
        int size = 0;
        while(size < LINE_SIZE && (c = getchar())!='\n')
            s[size++] = c;
        if(c!='\n')while(getchar()!='\n')continue;
        return s;
    }

	static bool isChecking()
	{
        clear();
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%% 广州地铁查询系统 %%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
				"%           是否查询？[y/n]                                            %\n"
				"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
        string order = getLine(27,1);
		gotoxy(0, 3);
        return order[0] == 'y' || order[0] == 'Y';
	}

	static void gotoxy(int x, int y)
	{
		HANDLE hout;
		COORD coord;
		coord.X = x;
		coord.Y = y;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
	}

    static string getOrigin() { return getLine(18,2); }
    static string getDestination() { return getLine(18,3); }

    static void printMenu()
    {
        clear();
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%% 广州地铁查询系统 %%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
                "%                                                                      %\n"
                "%           起点:                                                      %\n"
                "%           终点:                                                      %\n"
			    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    }
};

#endif