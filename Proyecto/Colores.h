#include<stdio.h>
#include <windows.h>

/* LIBRERIA COLORES 
Colores :
BLACK			0 Negro
BLUE			1 Azul
GREEN			2 Verde
CYAN			3 Cían
RED				4 Rojo
MAGENTA			5 Magenta
BROWN			6 Marrón
LIGHTGRAY		7 Gris Claro
DARKGRAY		8 Gris Oscuro
LIGHTBLUE		9 Azul Claro
LIGHTGREEN		10 Verde Claro
LIGHTCYAN		11 Cían Claro
LIGHTRED		12 Rojo Claro
LIGHTMAGENTA	13 Magenta Claro
YELLOW			14 Amarillo
WHITE			15 Blanco
*/

int color(int b, int f);

int color(int b, int f){
	HANDLE  hConsole;
	WORD    ForeColor = 0;
	WORD    BackColor;
	WORD    wAttributesOld;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

  // **  Open the current console input buffer.
  // **  Abrir la consola actual memoria intermedia de entrada.
  if( ( hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,
                     0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L) )
                 == (HANDLE) -1 ) {
      printf("\nError: Unable to open console.\n");
      return( -1 );
  }

  // **  Get and Save information on the console screen buffer.
  // **  Obtener y guardar información sobre la pantalla de la consola de amortiguación.
	GetConsoleScreenBufferInfo( hConsole, &csbi );
	wAttributesOld = csbi.wAttributes;

	BackColor = b;
	ForeColor= f;
	SetConsoleTextAttribute( hConsole, (WORD) ( (BackColor << 4) | ForeColor) );
	return 0;
}
