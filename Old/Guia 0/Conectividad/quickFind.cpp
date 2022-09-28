#include <iostream>
using namespace std;
/* Se quiere implementar un programa que permita determinar si dos elementos, p y q, estan
conectados. */

const int CantidadIngresos = 8;
const int CantidadElementos = 8;

struct Conectividad {
    int vector[CantidadElementos];
};

void Conectar(Conectividad& conectividad, int p, int q); 
bool EstanConectados(Conectividad conectividad, int p, int q);
void Inicializar(Conectividad& conectividad);

int main() {
    
    Conectividad conectividad;
    Inicializar(conectividad);

    for (int numeroIngreso = 0; numeroIngreso < CantidadIngresos; ++numeroIngreso) {
        int p, q;
        cin >> p;
        cin >> q;
        
        if (EstanConectados(conectividad, p, q)) {
            cout << " - " << endl;
        } else {
            Conectar(conectividad, p, q);
            cout << p << " - " << q << endl;
        }
    }

    return 0;
}

// QuickFind
void Conectar(Conectividad& conectividad, int p, int q) {
    int valorP = conectividad.vector[p];
    int valorQ = conectividad.vector[q];

    for (int i = 0; i < CantidadElementos; ++i) {
        if (conectividad.vector[i] == valorP) {
            conectividad.vector[i] = valorQ;
        }
    }
}

bool EstanConectados(Conectividad conectividad, int p, int q) {
    int valorP = conectividad.vector[p];
    int valorQ = conectividad.vector[q];

    return valorP == valorQ;
}

void Inicializar(Conectividad& conectividad) {
    for (int i = 0; i < CantidadElementos; ++i) {
        conectividad.vector[i] = i;
    }
}