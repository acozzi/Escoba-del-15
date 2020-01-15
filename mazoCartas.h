#ifndef MAZOCARTAS_H
#define MAZOCARTAS_H

#include <iostream>
#include<sstream>
#include<algorithm>
#include <ctime>

#define MAZO 40

using namespace std;

class MazoCartas {
public:
    MazoCartas(); // Constructor: LLena el mazo con los nombre en orden (1-rey Oro-Bastos)
    void imprimirEnOrden(); // Print Functions
    void imprimirMezclado();
    void imprimirMesa();

    void barajar(); // Set Functions
    void repartir();

    int getCartaMesa(int); // Get Functions
    string getCarta(int);
    int valorAbsoluto(int); // Toma una posicion, devuelve su valor absoluto (como carta)


private:
    string nombresCartas[MAZO]; // Miembros de datos
    int orden[MAZO];
    int mesa[MAZO];
    int ultima;
};
MazoCartas::MazoCartas(){ // llena el arreglo con los nombrs en orden
    int indice = 0;
    ultima = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            switch(j){
                case 0:
                    nombresCartas[indice]= "As ";
                    break;
                case 1:
                    nombresCartas[indice]= "Dos ";
                    break;
                case 2:
                    nombresCartas[indice]= "Tres ";
                    break;
                case 3:
                    nombresCartas[indice]= "Cuatro ";
                    break;
                case 4:
                    nombresCartas[indice]= "Cinco ";
                    break;
                case 5:
                    nombresCartas[indice]= "Seis ";
                    break;
                case 6:
                    nombresCartas[indice]= "Siete ";
                    break;
                case 7:
                    nombresCartas[indice]= "Sota ";
                    break;
                case 8:
                    nombresCartas[indice]= "Caballo ";
                    break;
                case 9:
                    nombresCartas[indice]= "Rey ";
                    break;
                default:
                    cout << "ERROR: No existe el palo" << endl;
            }


            switch(i){
                case 0:
                    nombresCartas[indice] += "de Oros";
                    break;
                case 1:
                    nombresCartas[indice] += "de Copas";
                    break;
                case 2:
                    nombresCartas[indice] += "de Espadas";
                    break;
                case 3:
                    nombresCartas[indice] += "de Bastos";
                    break;

                default:
                    cout << "ERROR: No existe el palo" << endl;
            }

        indice++;
        }
    }
    for(int i=0;i<MAZO;i++){// carga en orden el orden inicial
        orden[i]=i;
    }
    // Inicializar la Mesa
    for(int i=0;i<MAZO;i++){
        mesa[i] = -1; // el indice -1 significa VACIO
    }
}
void MazoCartas::imprimirEnOrden(){ // llama a la funcion que imprime el mazo
    for(int i=0;i<MAZO;i++){ // inprime los nombres en orden
        cout << nombresCartas[i] << endl;
    }
}
void MazoCartas::imprimirMesa(){
    cout << endl << "En la Mesa de Juego" << endl;
    for(int i=6; i<MAZO;i++){
        if(mesa[i]!=-1){
            cout << "[" << i << "] "<< getCarta(getCartaMesa(i)) << endl;
        }
    }
}
void MazoCartas::barajar(){ //mejorar, no está funcionando con el tercer argumento
    random_shuffle(&orden[0],&orden[MAZO]);
}
void MazoCartas::imprimirMezclado(){ // imprime el mazo según el orden del índice
    for(int i=0;i<MAZO;i++){ // inprime los nombres mezclados
        cout << nombresCartas[orden[i]] << endl;
    }
}
string MazoCartas::getCarta(int i){
    return nombresCartas[i];
}
int MazoCartas::valorAbsoluto(int posCarta){
    switch(posCarta){
    case 0:
    case 10:
    case 20:
    case 30:
        return 1;
        break;
    case 1:
    case 11:
    case 21:
    case 31:
        return 2;
        break;
    case 2:
    case 12:
    case 22:
    case 32:
        return 3;
        break;
    case 3:
    case 13:
    case 23:
    case 33:
        return 4;
        break;
    case 4:
    case 14:
    case 24:
    case 34:
        return 5;
        break;
    case 5:
    case 15:
    case 25:
    case 35:
        return 6;
        break;
    case 6:
    case 16:
    case 26:
    case 36:
        return 7;
        break;
    case 7:
    case 17:
    case 27:
    case 37:
        return 8;
        break;
    case 8:
    case 18:
    case 28:
    case 38:
        return 9;
        break;
    case 9:
    case 19:
    case 29:
    case 39:
        return 10;
        break;
    default:
        cout << "Error: la carta solicitada no existe en el mazo.";
        return -1;
    }
}
int MazoCartas::getCartaMesa(int i) {
    return mesa[i];
}

void MazoCartas::repartir(){ // No utiliza un for para ser más legible
    mesa[0] = orden[0]; // Jugador B (Mano) Recibe las Cartas 0 a 2 del Arreglo Mesa
    mesa[1] = orden[2];
    mesa[2] = orden[4];
    mesa[3] = orden[1]; // Jugador A (Pie) Recibe las Cartas 3 a 5 del Arreglo Mesa
    mesa[4] = orden[3];
    mesa[5] = orden[5];
    ultima += 6;
    if(ultima==6){
        mesa[6] = orden[6]; // reparte las primeras 4 cartas en la mesa
        mesa[7] = orden[7];
        mesa[8] = orden[8];
        mesa[9] = orden[9];
    }
}
#endif // MAZOCARTAS_H
