#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
COORD GetPosition(HANDLE handle){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD cursorPosition = csbi.dwCursorPosition;
    return cursorPosition;
}
void SetPosition(HANDLE hConsole,COORD pos){
	SetConsoleCursorPosition(hConsole, pos);
}

void printScreenRange(HANDLE hConsole,int Wight,int Height,char tran='|',char vert='-'){
	for (int i=0;i<Height;i++){
		SetConsoleCursorPosition(hConsole,{Wight,i});
		printf("%c",tran);
	}
	SetConsoleCursorPosition(hConsole,{0,Height});
	for (int i=0;i<Wight;i++){
		printf("%c",vert);
	}
}

void fullRange(HANDLE hConsole,int from_x,int from_y,int to_x,int to_y){
	SetConsoleCursorPosition(hConsole,{from_x,from_y});
	for (int x=from_x;x<=to_x;x++){
		for (int y=from_y;y<=to_y;y++){
			SetConsoleCursorPosition(hConsole,{x,y});
			std::cout<<" "<<std::flush;
		}
	}
} 

void DisableConsoleStop(HANDLE hConsole){
    // 获取控制台模式
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    // 禁用鼠标输入模式  
	SetConsoleMode(hConsole, mode & ~(ENABLE_PROCESSED_INPUT|ENABLE_QUICK_EDIT_MODE));
}
#endif
