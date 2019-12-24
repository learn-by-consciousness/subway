#ifndef MEMU_H
#define MEMU_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;

#define LINE_SIZE 30
inline void clear() {system("cls");}

class Memu
{
public:
    string getLine(int x, int y)
    {
        gotoxy(x, y);
        char s[30] = "", c;
        int size = 0;
        while(size < LINE_SIZE && (c = getchar())!='\n')
            s[size++] = c;
        if(c!='\n')while(getchar()!='\n')continue;
        return s;
    }

	bool isChecking()
	{
        clear();
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%% 广州地铁查询系统 %%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
            <<  "%           是否查询？[y/n]                                            %\n";
        string order = getLine(27,1);
        return order[0] == 'y' || order[0] == 'Y';
	}

	void gotoxy(int x, int y)
	{
		HANDLE hout;
		COORD coord;
		coord.X = x;
		coord.Y = y;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, coord);
	}

    string getOrigin() { return getLine(18,2); }
    string getDestination() { return getLine(18,3); }

    void printMemu()
    {
        clear();
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%% 广州地铁查询系统 %%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
            <<  "%                                                                      %\n"
            <<  "%           起点:                                                      %\n"
            <<  "%           终点:                                                      %\n";

    }
};

#endif