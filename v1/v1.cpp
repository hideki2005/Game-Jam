#include "pch.h"
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


using namespace System;

int corazones = 3;
int vidas = 3;
int n = 5;

int x = 7;
int y = 7;

int asteroides[15][2];
int bala[1][2];

void gotoxy(int x, int y) {

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);

}


void OcultarCursor() {

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci; //cambiar configuracion del cursor

	cci.dwSize = 2; //cambiando el size del cursor, tiene que ser un valor eentero entre 1 y 100
	cci.bVisible = false; //Mostrar o no mostrar el cursor en pantalla


	SetConsoleCursorInfo(hCon, &cci);

}

void pintar_limites() {

	for (int i = 2; i < 91; i++) {
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 33); printf("%c", 205);
	}

	for (int i = 4; i < 33; i++) {
		gotoxy(2, i); printf("%c", 186);
		gotoxy(90, i); printf("%c", 186);
	}

	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 33); printf("%c", 200);
	gotoxy(90, 3); printf("%c", 187);
	gotoxy(90, 33); printf("%c", 188);



}

void configura_consola() {

	Console::SetWindowSize(100, 50);

}


void pintar(int x, int y) {

	gotoxy(x, y); printf("  %c", 30);
	gotoxy(x, y + 1); printf(" %c%c%c", 40, 207, 41);
	gotoxy(x, y + 2); printf("%c%c %c%c", 30, 190, 190, 30);



}



void borrar(int x, int y) {

	gotoxy(x, y); printf("        ");
	gotoxy(x, y + 1); printf("       ");
	gotoxy(x, y + 2); printf("       ");

}




void pintar_corazones(int vidas, int corazones) {

	gotoxy(50, 2); printf("VIDAS %d", vidas);

	gotoxy(64, 2); printf("Salud");
	gotoxy(70, 2); printf("      ");

	for (int i = 0; i < corazones; i++) {

		gotoxy(70 + i, 2); printf("%c", 3);

	}


}


void morir(int x, int y, int vidas, int corazones) {

	if (corazones == 0) {

		borrar(x, y);
		gotoxy(x, y); printf("   **  ");
		gotoxy(x, y + 1); printf("  ****  ");
		gotoxy(x, y + 2); printf("   **   ");

		Sleep(200);

		borrar(x, y);
		gotoxy(x, y); printf("  * ** *  ");
		gotoxy(x, y + 1); printf("  *****  ");
		gotoxy(x, y + 2); printf(" * ** * ");

		Sleep(200);

		borrar(x, y);

		vidas--;
		corazones = 3;

		pintar_corazones(vidas, corazones);
		pintar(x, y);
	}
}


void movimiento() {

	if (kbhit()) {

		char tecla = _getch();

		borrar(x, y);

		if (tecla == IZQUIERDA && x > 3) x--;
		if (tecla == DERECHA && x + 6 < 90) x++;
		if (tecla == ARRIBA && y > 4) y--;
		if (tecla == ABAJO && y + 3 < 33) y++;
		if (tecla == 'a') {

			gotoxy(bala[1][0], bala[1][1]); printf(" ");

			/*bala[1][0] == 0;
			bala[1][1] == 0;*/

			bala[1][0] = x + 2;
			bala[1][1] = y - 1;

		}

		pintar(x, y);

	}
}


void sin_corazones() {

	if (corazones == 0) {

		borrar(x, y);
		gotoxy(x, y); printf("   **  ");
		gotoxy(x, y + 1); printf("  ****  ");
		gotoxy(x, y + 2); printf("   **   ");

		Sleep(200);

		borrar(x, y);
		gotoxy(x, y); printf("  * ** *  ");
		gotoxy(x, y + 1); printf("  *****  ");
		gotoxy(x, y + 2); printf(" * ** * ");

		Sleep(200);

		borrar(x, y);

		vidas--;
		corazones = 3;

		pintar_corazones(vidas, corazones);
		pintar(x, y);


	}

}


void pos_ast() {

	for (int i = 0; i < 15; i++) {

		asteroides[i][0] = rand() % 86 + 4;
		asteroides[i][1] = rand() % 8;
	}
}

//void crear_bala() {
//awsqdfasd
//	bala[1][0] = x;
//	bala[1][1] = y - 1;
//}


int main() {


	OcultarCursor();
	pintar_limites();
	configura_consola();
	pintar(x, y);

	pos_ast();

	
	bool game_over = false;

	while (!game_over) {

		for (int i = 0; i < n; i++) {

			gotoxy(asteroides[i][0], asteroides[i][1]); printf(" ");
			asteroides[i][1] += 1;
		}

		for (int i = 0; i < n; i++) {

			if (asteroides[i][1] > 32) {

				asteroides[i][0] = rand() % 86 + 4;
				asteroides[i][1] = rand() % 8;
			}
		}

		for (int i = 0; i < n; i++) {

			if (asteroides[i][1] > 4) {

				gotoxy(asteroides[i][0], asteroides[i][1]); printf("%c", 184);

			}


		}

		for (int i = 0; i < n; i++)
		{


			if (asteroides[i][0] >= x && asteroides[i][0] < x + 6 && asteroides[i][1] >= y && asteroides[i][1] <= y + 2) {

				corazones--;
				borrar(x, y);
				pintar(x, y);
				pintar_corazones(vidas, corazones);

				asteroides[i][0] = rand() % 86 + 4;
				asteroides[i][1] = rand() % 8;
			}

		}




		gotoxy(bala[1][0], bala[1][1]); printf(" ");


		/*gotoxy(bala[1][0], bala[1][1]); printf("*");*/



		if (bala[1][1] > 4) {

			bala[1][1] -= 1;
			gotoxy(bala[1][0], bala[1][1]); printf("*");

		}

		for (int i = 0; i < n; i++)
		{

			if (bala[1][0] == asteroides[i][0] && bala[1][1] == asteroides[i][1]) {

				bala[1][0] == 0;
				bala[1][1] == 0;

				gotoxy(bala[1][0], bala[1][1]); printf(" ");
				bala[1][0] == 0;
				bala[1][1] == 0;
				asteroides[i][0] = rand() % 86 + 4;
				asteroides[i][1] = rand() % 8;
				n--;
			}
		}






		movimiento();
		movimiento();

		sin_corazones();

		pintar_corazones(vidas, corazones);
		pintar_limites();
		Sleep(30);

	}

	system("pause>0");
	return 0;
}