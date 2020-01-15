#include<iostream>
#include<sstream>
#include<algorithm>
#include <ctime>
#define MAZO 40
#include "mazoCartas.h"
#include "jugador.h"
#include "Engine.h"

using namespace std;

int main() {
    string nombreJugador;
    cout << "Ingrese su nombre: ";
    cin >>nombreJugador;

    Engine Juego(nombreJugador, true, "Computer", false);
    Juego.iniciarMazo();
    Juego.menuLevantar();

   //MazoCartas escoba; //  crea un objeto de tipo MazoCartas llamado escoba

    //Jugador user("Alejandro", true), computer("Compu", false);//, *ptrJugadorA, *ptrJugadorB;
    //ptrJugadorA = &user; // asigno la direccion de user al puntero
    //ptrJugadorB = &computer;
/*
    user.imprimirMano(ptrEscoba);
    computer.imprimirMano(ptrEscoba);
    escoba.barajar();
    escoba.repartir();
    user.setMano(ptrEscoba);
    computer.setMano(ptrEscoba);
    user.imprimirMano(ptrEscoba);
    computer.imprimirMano(ptrEscoba);
    escoba.imprimirMesa();

*/
    return 0;
}

