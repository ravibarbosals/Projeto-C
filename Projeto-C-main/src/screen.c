/**
 * screen.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include "screen.h"
#include <wchar.h>
#include <locale.h>


void screenDrawBorders() 
{
    setlocale(LC_ALL, "");

    const char *hbc = "═";
    const char *vbc = "║";
    #define BOX_UPLEFT     0x6C  // caractere gráfico da tabela CP437
    #define BOX_UPRIGHT    0x6B
    #define BOX_DWNLEFT    0x6D
    #define BOX_DWNRIGHT   0x6A
    #define BOX_HORIZ      0xCD
    #define BOX_VERT       0xBA


    screenClear();
    screenBoxEnable();
    
    screenGotoxy(MINX, MINY);
    printf("%c", BOX_UPLEFT); // Updated to use %s for BOX_UPLEFT

    for (int i=MINX+1; i<MAXX; i++)
    {
        screenGotoxy(i, MINY);
        printf("%s", hbc);
    }
    screenGotoxy(MAXX, MINY);
    printf("%c", BOX_UPRIGHT);

    for (int i=MINY+1; i<MAXY; i++)
    {
        screenGotoxy(MINX, i);
        printf("%s", vbc);
        screenGotoxy(MAXX, i);
        printf("%s", vbc);
    }

    screenGotoxy(MINX, MAXY);
    printf("%c", BOX_DWNLEFT); // Updated to use %s for BOX_DWNLEFT
    for (int i=MINX+1; i<MAXX; i++)
    {
        screenGotoxy(i, MAXY);
        printf("%s", hbc);
    }
    screenGotoxy(MAXX, MAXY);
    printf("%c", BOX_DWNRIGHT); // Updated to use %s for BOX_DWNRIGHT

    screenBoxDisable();
    
}

void screenInit(int drawBorders)
{
    screenClear();
    if (drawBorders) screenDrawBorders();
    screenHomeCursor();
    screenHideCursor();
}

void screenDestroy()
{
    printf("%s[0;39;49m", ESC); // Reset colors
    screenSetNormal();
    screenClear();
    screenHomeCursor();
    screenShowCursor();
}

void screenGotoxy(int x, int y)
{
    x = ( x<0 ? 0 : x>=MAXX ? MAXX-1 : x);
    y = ( y<0 ? 0 : y>MAXY ? MAXY : y);
    
    printf("%s[f%s[%dB%s[%dC", ESC, ESC, y, ESC, x);
}

void screenSetColor( screenColor fg, screenColor bg)
{
    char atr[] = "[1;";

    if ( fg > RED )
    {
        atr[1] = '1';
		fg -= 8;
    }

    printf("%s%s%d;%dm", ESC, atr, fg+30, bg+40);
}
