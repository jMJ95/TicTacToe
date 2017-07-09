// se incluyen las librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//se indica el uso del std
using namespace std;

//se declara algunas variables
char tablero [3][3];
char jugadorActual = 'X';

//se crea el metodo inicializar
void inicializar(){

    //se crea un bucle anidado pata crear el tablero
    for(int i=0;  i< 3; i++){
        for(int j=0; j<3; j++ ){
            tablero[i][j] = '_';
        }
    }
}

//se crea un elemento booleano
bool HayGanador(){

    //para ganador horizontal
    char jugadorEncontrado = tablero[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[i][j] == '_' && jugadorEncontrado == tablero[i][j]){
                break;
            }
            if(j == 2){
                printf("Ha ganado el jugador %c", jugadorEncontrado);
                return true;
            }
        }
    }
    //para ganador vertical

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[j][i] == '_' && jugadorEncontrado == tablero[j][i]){
               break;
            }
            if(j == 2){
                printf("Ha ganado el jugador %c", jugadorEncontrado);
                return true;
        }
        jugadorEncontrado = tablero[j][i];
        }
    }
    //para ganador diagonal izquierda derecha
    for(int i = 0; i<3 ; i++){
        if(tablero[i][i] == '_' && jugadorEncontrado == tablero[i][i]){
                break;
            }

        jugadorEncontrado = tablero[i][i];
        if(i == 2){
            printf("Ha ganado el jugador %c", jugadorEncontrado);
            return true;
        }
        jugadorEncontrado = tablero[i][i];
    }
    //para ganador diagonal derecha izquierda
    for(int i = 2; i>=0; i--){
        if(tablero[2-i][i] == '_' && jugadorEncontrado == tablero[2-i][i]){
            break;
            }

        jugadorEncontrado = tablero[2-i][i];
        if(i == 2){
            printf("Ha ganado el jugador %c", jugadorEncontrado);
            return true;
        }
        jugadorEncontrado = tablero[2-i][i];
    }
    return false;
}

//se crea el metodo que muestra el tablero
void DesplegarTablero(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%c\t", tablero[i][j]);
        }
        printf("\n");
    }
}

// este es el funcion principal
int main(){
    inicializar();
    while(!HayGanador()){
       DesplegarTablero();
       int fila = 0;
       int columna = 0;
       printf("en que fila quiere jugar %c", jugadorActual);
       scanf("%d", &fila);
       printf("en que columna quiere jugar %c", jugadorActual);
       scanf("%d", &columna);

       tablero[fila][columna] = jugadorActual;

       if(jugadorActual == 'X'){
            jugadorActual = '0';
       }else{
            jugadorActual = 'X';
       }
       printf("\n");
       DesplegarTablero();
       printf("\n");
       system("pause");
   }
}
