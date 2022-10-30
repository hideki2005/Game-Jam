#include "pch.h"
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<list>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

using namespace System;
using namespace std;


void color(int c)
{
    switch (c)
    {
    case 1: Console::ForegroundColor = ConsoleColor::Black; break;
    case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
    case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
    case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
    case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
    case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
    case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
    case 10: Console::ForegroundColor = ConsoleColor::Green; break;
    case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
    case 12: Console::ForegroundColor = ConsoleColor::Red; break;
    case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
    case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
    case 15: Console::ForegroundColor = ConsoleColor::White; break;
    }
}

void cursor(int x, int y) {

    Console::SetCursorPosition(x, y);

}


void OcultarCursor() {

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci; //cambiar configuracion del cursor

    cci.dwSize = 2; //cambiando el size del cursor, tiene que ser un valor eentero entre 1 y 100
    cci.bVisible = false; //Mostrar o no mostrar el cursor en pantalla


    SetConsoleCursorInfo(hCon, &cci);

}

void configura_consola() {

    Console::SetWindowSize(100, 40);

}


void configura_consola() {

    Console::SetWindowSize(80, 42);
    Console::CursorVisible = false;

}

void imprimir_limits() {

    //lineas horizontales
   /* for (int i = 2; i < 91; i++) {
        cursor(i, 3); printf("%c", 196);
        cursor(i, 33); printf("%c", 196);
    }*/

    //lineas verticales
    for (int i = 4; i < 34; i++) {
        cursor(2, i); printf("%c", 219);
        cursor(90, i); printf("%c", 219);
    }

    cursor(2, 3); printf("%c", 219);
    cursor(2, 33); printf("%c", 219);
    cursor(90, 3); printf("%c", 219);
    cursor(90, 33); printf("%c", 219);
}

void bienvenida() {



}

int main() {


    //configura_consola();
    imprimir_limits();






    system("pause>0");
    return 0;
}