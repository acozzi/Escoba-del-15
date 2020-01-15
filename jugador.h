#ifndef JUGADOR_H
#define JUGADOR_H
#include<iostream>


#define MAZO 40
using namespace std;
class MazoCartas;

class Jugador {
public:
    Jugador(string, bool);
    string getname();
    void imprimirMano(MazoCartas *);
    void setMano(MazoCartas *);
    void setPozo(int);



private:
    string nombre;
    int mano[3];
    int pozo[MAZO];
    int ultimaPozo;
    bool esPie;

};
Jugador::Jugador(string n, bool flag) { // Constructor: Toma como argumento el nombre del jugador
    nombre = n;
    for(int i=0;i<3;i++){ // Inicializa la mano a -1
        mano[i] = -1;
    }
    for(int i=0;i<MAZO;i++){ // inicializa el pozo a -1
        pozo[i] = -1;
    }
    esPie = flag;
    ultimaPozo=0;

}
string Jugador::getname(){
    return nombre;
}

void Jugador::imprimirMano(MazoCartas *ptrEscoba){
    cout << "Jugador: "<< getname() << endl;
    for(int i=0;i<3;i++){
        if(mano[i]!=-1){
            cout << "[" << i << "] "<< ptrEscoba->getCarta(mano[i]) << endl; //  string getCarta(int);
        } else {
            cout << "Slot " << i+1 << " Vacio" << endl;
        }
    }
}

void Jugador::setMano(MazoCartas *ptrEscoba){ // a,b y c < 40
    if(esPie){
        for(int i=0;i<3;i++){
            mano[i] = ptrEscoba->getCartaMesa(i);
        }
    } else {
        for(int i=0;i<3;i++){
            mano[i] = ptrEscoba->getCartaMesa(i+3);
        }
    }
}
void Jugador::setPozo(int sumaAlPozo){
    pozo[ultimaPozo] = sumaAlPozo;
    ultimaPozo++;
}
#endif // JUGADOR_H
