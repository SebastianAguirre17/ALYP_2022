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
int ObtenerRaiz(Conectividad& conectividad, int p, int q);

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

int ObtenerRaiz(Conectividad& conectividad, int p, int q) {
    while (conectividad[e] != e)
        e = conectividad[e];  
    return e;
}

// QuickUnion
void Conectar(Conectividad& conectividad, int p, int q) {
    int raizQ = ObtenerRaiz(conectividad, q);
    conectividad.vector[q] = raizQ;
}

bool EstanConectados(Conectividad conectividad, int p, int q) {
    conectividad[q] = ObtenerRaiz(conectividad, p); 
}

void Inicializar(Conectividad& conectividad) {
    for (int i = 0; i < CantidadElementos; ++i) {
        conectividad.vector[i] = i;
    }
}