#ifndef ENGINE_H
#define ENGINE_H
#include "mazoCartas.h"
#include "jugador.h"
#include<iostream>
using namespace std;

class Engine {
public:
    Engine(string, bool, string, bool);
    //void menuInicial();
    //void tutorial();
    void menuLevantar(); // Escrita, no testeda
    void iniciarMazo();
    bool juegoValido(); // Escrita, no testeda Chequea si la suma da quince
    //void levantarIA();
    void actualizarPozo(); // copia el levante al pozo del jugador 1
    void inicializarLevante(); // Inicia el array a -1
    int getLevante(int); // escrita devuelve un entero como posicion en el arreglo
private:

    Jugador Player1;
    Jugador Player2;
    MazoCartas Escoba;
    MazoCartas *ptrEscoba;
    bool turno;
    int levante[10];
};
Engine::Engine(string nombrePlayer, bool pie, string nombreCompu, bool mano)
    :Player1(nombrePlayer, pie),
     Player2(nombreCompu, mano)
{
    cout << "Constructores por defecto en marcha" << endl;
    ptrEscoba = &Escoba;

}
void Engine::iniciarMazo(){
    Escoba.barajar();
    Escoba.repartir();
    Escoba.imprimirMesa();
    Player1.setMano(ptrEscoba);
    Player2.setMano(ptrEscoba);
}
void Engine::menuLevantar(){
    int cartaElegida = -1, ultima=0;
    bool flag = true;
    while (flag){
        cout << "¿Su Juego? [1][2][3]";
        Player1.imprimirMano(ptrEscoba);
        cin >> cartaElegida;
        levante[ultima]= cartaElegida;
        ultima++;
        cout << "¿Con que carta de la mesa? [Nro] [-1 fin]";
        Escoba.imprimirMesa();
        cin >> cartaElegida;
        while(cartaElegida!=-1){
            levante[ultima] = cartaElegida;
            ultima++;
            cout << Escoba.getCarta(Escoba.getCartaMesa(cartaElegida)) // ATENCION el problema es que get la carta del mazo, no la elegida
                << " seleccionada."
                << endl
                << "¿Alguna mas? [-1 no]";
            cin >> cartaElegida;
        }
        cout << "Su juego ";
        if(juegoValido()){
            cout << " es valido. Espere el siguiente turno. ";
            actualizarPozo();
            flag = false;
        } else {
            cout << " no es valido, debe sumar 15... "
                << endl << " Vuelva a intentar.";
            inicializarLevante();
            ultima =0;
        }
    }

}
void Engine::inicializarLevante(){
    for(int i=0; i<10;i++){
        levante[i]=-1; // inicializa el posible levante en -1 (rellamar cada vez que haya pozo)
    }
}
bool Engine::juegoValido(){
    int suma15 = 0;
    for(int i=0;i<10;i++){
        if (levante[i]!=-1){
            suma15+=Escoba.valorAbsoluto(getLevante(i));
        }
    }
    if(suma15==15) {return true;}
    else {return false;};
}
int Engine::getLevante(int a){
    return levante[a];
}
void Engine::actualizarPozo(){
    for(int i=0;i<10;i++){
        if(levante[i]!=-1){
                Player1.setPozo(levante[i]);
        }
    }
}
#endif // ENGINE_H
