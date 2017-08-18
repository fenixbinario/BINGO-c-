/*
Autor: @fenixbinario
Fecha: 16/08/2017
Nombre: Bingo_play
IDE: QT Creator
*/
#include <QCoreApplication>
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <list>
#include <time.h>
using namespace std;
int digitos[99];
int bombo[60];
int sorteo [30];
int carton[3][5];
int coincidencias[3][5];
int contador;
int contadorBombo;
int digito;
int contadorSorteo;
bool encontrado;
int linea;
int bingo;
void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon,&cci);
}

void pintar_limites()
{
    gotoxy(1,1); printf("BINGO | Juego Programacion c++ | Autor: @fenixbinario | Fecha: 16/08/2017");
    for(int i = 0; i<80 ; i++)
    {
        gotoxy(i,3); printf("%c",205);
        gotoxy(i,14); printf("%c",205);
        gotoxy(i,24); printf("%c",205);
        gotoxy(i,32); printf("%c",205);
        gotoxy(i,46); printf("%c",205);
        gotoxy(i,57); printf("%c",205);
    }
}


int main ()
{
    OcultarCursor();
    gotoxy(5,15);
    printf("BINGO | Juego Programacion c++  \n     Autor: @fenixbinario \n     Fecha: 16/08/2017 \n\n     ");
    printf("Pulsar ENTER para nueva partida.");
  bool stop = false;
  while(!stop)
    {
    if(kbhit() )
      {
        char tecla = getch();

        if(tecla == 13)
          {
            system("cls");
            srand(time(NULL));
            OcultarCursor();
            pintar_limites();

            //bombo
            gotoxy(2,4);
            printf("\n Numeros del BOMBO \n \n");

            for(int i = 0; i<100; i++)
             {
              digitos[i]=i;
             }
            contadorBombo = 0;

            while(contadorBombo <60)
             {
                digito = rand()%99;
                 if(-1 != digitos[digito])
                 {
                   bombo[contadorBombo] = digitos[digito];
                   digitos[digito] = -1;
                   printf(" %d", bombo[contadorBombo]);
                   contadorBombo++;
                 }
                 contador ++;
             }
            printf("\n\nEste BOMBO consta de %d numeros sin repeticion, elegidos al azar y para ello \n ha hecho falta %d iteraciones rand(). \n",contadorBombo, contador);

            //sorteo
            gotoxy(2,15);
            printf("\n Numeros del SORTEO \n \n");
            contadorSorteo = 1;
            contador = 0;
            while(contadorSorteo <31)
            {
                digito = rand()%30;
                 if(-1 != bombo[digito])
                 {
                   sorteo[contadorSorteo] = bombo[digito];
                   bombo[digito] = -1;
                   printf("%d ",sorteo[contadorSorteo]);
                   contadorSorteo++;
                 }
                 contador++;
            }
            printf("\n\n Se han extraido del BOMBO %d numeros para el SORTEO elegidos\n al azar y para ello ha hecho falta %d iteraciones rand(). \n\n", contadorSorteo, contador);

            //carton
            gotoxy(2,25);
            printf("\n CARTON \n \n");
            for(int i = 0; i<100; i++)
             {
              digitos[i]=i;
             }

            for(int x=1; x<4; x++)
            {
             printf("\n ");
                for(int c=1; c<6; c++)
                {
                    encontrado = false;
                    while(!encontrado)
                    {
                        digito = rand()%99;

                        if(-1 != digitos[digito] )
                        {
                            carton[x][c] = digitos[digito];

                            printf(" %d ",carton[x][c]);
                            digitos[digito] = -1;
                            encontrado = true;
                            for (int b = 1; b<31; b++)
                            {
                                if(sorteo[b] == carton[x] [c])
                                {
                                    carton[0][x] ++;
                                }
                            }
                        }

                    }
                }
            }

            //Coincidencias
            gotoxy(2,33);
            printf("\n COINCIDENCIAS \n \n");
            for(int x =1; x<4; x++)
            {
                printf("\n FILA %d:",x);
                for ( int c = 1; c<6; c++)
                {
                    for (int b = 1; b<31; b++)
                    {
                        if(sorteo[b] == carton[x] [c])
                        {
                            printf(" %d",sorteo[b]);
                            coincidencias[x][c] = sorteo[b];
                        }
                    }
                }
            }
            printf("\n\n Total Fila 1: %d", carton[0][1]);
            printf("\n Total Fila 2: %d", carton[0][2]);
            printf("\n Total Fila 3: %d", carton[0][3]);
            bingo=0;
            bingo = carton[0][1] + carton[0][2] + carton[0][3];
            printf("\n Total coincidencias %d: ", bingo);

            //premios
            gotoxy(2,47);
            printf("\n PREMIOS \n \n");
            linea = 0;
          if(bingo==15)
            {
              printf("\n << BINGO >> \n\n");
              printf("\n CREDITOS: 1500 \n \n");
            }
           else
            {
            for(int x =1; x<4; x++)
            {
               if(carton[0][x]==5)
                  {

                    printf("\n Fila %d: LINEA ",x);
                    linea+=10;
                  }
                else
                {
                   printf("\n Fila %d: NADA ",x);
                }
              }
             printf("\n\n CREDITOS: %d",linea);
             }
         for (int i = 0; i< 4; i++) carton[0][i] = 0;
          gotoxy(2,58);
          printf("Pulsar ENTER para nueva partida. | Pulsar cualquier tecla para salir \n\n ");
       }
        else
        {
            stop = true;
        }
    }
  }
  return 0;
}
