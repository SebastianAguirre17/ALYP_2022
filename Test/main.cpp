#include <iostream>
using namespace std;

struct Nodo {
    int item;
    Nodo* siguiente;
};

struct Lista {
    Nodo* primero;
};

Nodo* CrearNodo(int item);
Lista* CrearListaVacia();
void DestruirNodo(Nodo* nodo);
void DestruirLista(Lista* lista);

void AgregarNodoAlComienzo(Lista* lista, Nodo* nodo);
void AgregarNodoAlFinal(Lista* lista, Nodo* nodo);
void QuitarPrimerNodo(Lista* lista);
void QuitarUltimoNodo(Lista* lista);
int  ObtenerTamanio(Lista* lista);
void MostrarLista(Lista* lista);

int main() {
    Lista* lista = CrearListaVacia();
    MostrarLista(lista); 

    AgregarNodoAlFinal(lista, CrearNodo(10));
    AgregarNodoAlFinal(lista, CrearNodo(15));
    AgregarNodoAlFinal(lista, CrearNodo(20));
    AgregarNodoAlFinal(lista, CrearNodo(30));

    MostrarLista(lista); // 10 -> 15 -> 20 -> 30

    AgregarNodoAlComienzo(lista, CrearNodo(40));
    AgregarNodoAlComienzo(lista, CrearNodo(50));

    MostrarLista(lista); // 50 -> 40 -> 10 -> 15 -> 20 -> 30

 
    QuitarPrimerNodo(lista);
    QuitarUltimoNodo(lista);

    MostrarLista(lista); // 40 -> 10 -> 15 -> 20
    cout << "El tamaño de la lista es " << ObtenerTamanio(lista) << endl;

    QuitarPrimerNodo(lista);
    QuitarUltimoNodo(lista);

    MostrarLista(lista); // 10 -> 15
    cout << "El tamaño de la lista es " << ObtenerTamanio(lista) << endl;

    QuitarPrimerNodo(lista);
    //QuitarUltimoNodo(lista);

    MostrarLista(lista); // 15
    cout << "El tamaño de la lista es " << ObtenerTamanio(lista) << endl;


    //DestruirLista(lista);
    
    cout << endl << endl;
    return 0;
}

Nodo* CrearNodo(int item) {
    Nodo* nodo = new Nodo;
    nodo->item = item;
    nodo->siguiente = NULL;
    return nodo;
}

Lista* CrearListaVacia() {
    Lista* lista = new Lista;
    lista->primero = NULL;
    return lista;
}


void AgregarNodoAlFinal(Lista* lista, Nodo* nuevoNodo) {
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
    }
    else {
        Nodo* nodo = lista->primero;
        while (nodo->siguiente != NULL) {
            nodo = nodo->siguiente;
        }
        nodo->siguiente = nuevoNodo;
    }
}

void MostrarLista(Lista* lista) {
    if (lista->primero == NULL) {
        cout << "La lista esta vacia" << endl;
    }
    else {
        Nodo* nodo = lista->primero;
        while (nodo->siguiente != NULL) {
            cout << nodo->item << " -> ";
            nodo = nodo->siguiente;
        }
        cout << nodo->item << endl;
    }
}

void AgregarNodoAlComienzo(Lista* lista, Nodo* nuevoNodo) {
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
    }
    else {
        nuevoNodo->siguiente = lista->primero;
        lista->primero = nuevoNodo;
    }
}

void QuitarPrimerNodo(Lista* lista) {
    if (lista->primero != NULL) {
        Nodo* primerNodo = lista->primero;
        lista->primero = primerNodo->siguiente;
        delete primerNodo;
    }
}

void QuitarUltimoNodo(Lista* lista) {
    if (lista->primero != NULL) {
        Nodo* anteriorNodo = NULL;
        Nodo* nodo = lista->primero;
        while (nodo->siguiente != NULL) {
            anteriorNodo = nodo;
            nodo = nodo->siguiente;
        }
        if (anteriorNodo == NULL) {
            lista->primero = NULL;
        }
        else {
            anteriorNodo->siguiente = NULL;
        }
        delete nodo;
    }
}

int  ObtenerTamanio(Lista* lista) {
    int cantidadNodos = 0;
    Nodo* nodo = lista->primero;
    while (nodo != NULL) {
        ++cantidadNodos;
        nodo = nodo->siguiente;
    }
    return cantidadNodos;
}