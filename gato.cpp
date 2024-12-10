#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void mostrarTablero (int tablero[3][3]);
bool verificarWin (int jugador, int tablero[3][3]);
int minMax(int tableroMinMax[3][3], int profundidad, bool esMax, int alfa, int beta);
bool estaElTableroLleno(int tablero[3][3]);
bool mejorMovimiento(int tablero[3][3]);
void limpiarTablero(int tablero[3][3]);
bool continuar();


int main(){

    int tablero[3][3] = {0};  
    int jugador1 = 1;         
    int jugador2 = 2;         
    int pos1, pos2;           

    bool juegoTerminado = false;

    while (!juegoTerminado) {

        mostrarTablero(tablero);

        bool entradaValida = false;
        while(!entradaValida){
            cout << "Jugador 1 (X), ingrese la posicion a jugar separada de espacios (fila columna): ";
            cin >> pos1 >> pos2;

            pos1--;
            pos2--;

            if (cin.fail()) { 
                cin.clear();   
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Entrada no valida. Por favor ingrese numeros enteros entre 1 y 3." << endl;
            }else if (pos1 < 0 || pos1 >= 3 || pos2 < 0 || pos2 >= 3 || tablero[pos1][pos2] != 0) {
            cout << "Posicion invalida. Intente de nuevo." << endl;

            }else{
                entradaValida  = true;
            }
        }

        tablero[pos1][pos2] = jugador1;

        if (verificarWin(jugador1, tablero)) {
            mostrarTablero(tablero);
            cout << "GANA EL JUGADOR 1!" << endl;
            limpiarTablero(tablero);
            juegoTerminado = continuar();
            
        }

        if (!estaElTableroLleno(tablero)) {
            mostrarTablero(tablero);
            cout << "EMPATE! El tablero esta lleno" << endl;
            limpiarTablero(tablero);
            juegoTerminado = continuar();
            
        }

        cout << "Turno de la IA (O)..." << endl;
        mejorMovimiento(tablero);

        if (verificarWin(jugador2, tablero)) {
            mostrarTablero(tablero);
            cout << "GANA LA IA!" << endl;
            limpiarTablero(tablero);
            juegoTerminado = continuar();
            
        }

        if (!estaElTableroLleno(tablero)) {
            mostrarTablero(tablero);
            cout << "EMPATE! El tablero esta lleno." << endl;
            limpiarTablero(tablero);
            juegoTerminado = continuar();
            
        }

        
    }

    return 0;
}

void mostrarTablero(int tablero[3][3]) {
    cout << endl;
    cout<< "               /)   "<<endl;
    cout<< "    /\\ _ /\\   ((   "<<endl;
    cout<<" _\\( o . o )/_ ))"<<endl;
    cout<<"_(,,,)____(,,,)_"<<endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(tablero[i][j]==0){
                cout << "|   |";
            }else if(tablero[i][j]==1){
                cout << "| X |";
            }else{
                cout << "| O |";
            }
        }
        cout << endl;
    }
    cout <<"================"<< endl;
    cout <<endl;


}

void limpiarTablero(int tablero[3][3]){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            tablero[i][j] = 0;
        }
    }
}

bool continuar(){
    char opcion;

    while (true) {
        cout << "Desea continuar? Y o N: ";
        cin >> opcion;

        opcion = toupper(opcion);

        if (opcion == 'N') {
            return true;
        } else if (opcion == 'Y') {
            return false;
        } else {
            cout << "Ingrese un valor válido (Y o N)." << endl;
        }
    }

}

bool estaElTableroLleno(int tablero[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(tablero[i][j]==0){
                return true;
            }
        }  
    }
    return false;
}

bool verificarWin(int jugador, int tablero[3][3]) {

    for(int fila = 0; fila < 3;fila++){
        if(tablero[fila][0] == jugador && tablero[fila][1] == jugador && tablero[fila][2] == jugador ){
            return true;
        }
    }
 
    for(int colum = 0; colum < 3;colum++){
        if(tablero[0][colum] == jugador && tablero[1][colum] == jugador && tablero[2][colum] == jugador ){
            return true;
        }
    }  

    if(tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador ){
        return true;
    }

    if(tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador ){
        return true;
    }    

    return false;         
}

int minMax(int tableroMinMax[3][3], int profundidad, bool esMax, int alfa, int beta) {
    if (verificarWin(2, tableroMinMax)) {  
        return 10 - profundidad;  
    }
    if (verificarWin(1, tableroMinMax)) {  
        return profundidad - 10;  
    }
    if (!estaElTableroLleno(tableroMinMax)) {  
        return 0;
    }

    if (esMax) {
        int mejorPuntaje = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tableroMinMax[i][j] == 0) {  
                    tableroMinMax[i][j] = 2;  
                    int puntaje = minMax(tableroMinMax, profundidad + 1, false, alfa, beta);
                    tableroMinMax[i][j] = 0;  
                    mejorPuntaje = max(mejorPuntaje, puntaje);
                    alfa = max(alfa, mejorPuntaje);
                    if (beta <= alfa) {
                        return mejorPuntaje;  
                    }
                }
            }
        }
        return mejorPuntaje;
    } else {
        int mejorPuntaje = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tableroMinMax[i][j] == 0) {  
                    tableroMinMax[i][j] = 1;  
                    int puntaje = minMax(tableroMinMax, profundidad + 1, true, alfa, beta);
                    tableroMinMax[i][j] = 0;  
                    mejorPuntaje = min(mejorPuntaje, puntaje);
                    beta = min(beta, mejorPuntaje);
                    if (beta <= alfa) {
                        return mejorPuntaje; 
                    }
                }
            }
        }
        return mejorPuntaje;
    }
}

bool mejorMovimiento(int tablero[3][3]){
    int mejorPuntaje = -1000;
    int movimiento[2] = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == 0) {  
                tablero[i][j] = 2;  
                int puntaje = minMax(tablero, 0, false, -1000, 1000);
                tablero[i][j] = 0;  

                if (puntaje > mejorPuntaje) {
                    mejorPuntaje = puntaje;
                    movimiento[0] = i;
                    movimiento[1] = j;
                }
            }
        }
    }

    if (movimiento[0] != -1 && movimiento[1] != -1) {
        tablero[movimiento[0]][movimiento[1]] = 2;
        return true;
    }
    return false;
}