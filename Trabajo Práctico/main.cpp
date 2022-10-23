#include <iostream>
#include "Particion.h"
#include "Registro.h"

using namespace std;
using namespace UDBParticion;
using namespace UDBRegistro;

void Mostrar(Particion* particion, int comienzo, int fin);
Particion* CrearEstudiantesAlgortimos();

int main()
{
    Particion* estudiantesAlgoritmos = CrearEstudiantesAlgortimos();
    /*ActualizarRegistro(estudiantesAlgoritmos, 1003, "");
    EliminarRegistro(estudiantesAlgoritmos, 1004);
    Mostrar(estudiantesAlgoritmos, 1000, 1003);
    Mostrar(estudiantesAlgoritmos, 1005, 1010);
    Destruir(estudiantesAlgoritmos);*/
}

void Mostrar(Particion* particion, int comienzo, int fin) {
    for (int identificador = comienzo; identificador <= fin; ++identificador) {
        Registro* registro = ObtenerRegistro(particion, identificador);
        cout << ObtenerValor(registro);
    }
}

Particion* CrearEstudiantesAlgortimos() {
    Particion* estudiantes = Crear(1000, 1010);
    AgregarRegistro(estudiantes, "Alejandro Colli");
    AgregarRegistro(estudiantes, "Alex Urquiza");
    AgregarRegistro(estudiantes, "Cesar Vacirca");
    AgregarRegistro(estudiantes, "Danilo Medina");
    AgregarRegistro(estudiantes, "Elisa Araya");
    AgregarRegistro(estudiantes, "Ezequiel Britez");
    AgregarRegistro(estudiantes, "Facundo Lombardo");
    AgregarRegistro(estudiantes, "Federico Aquino");
    AgregarRegistro(estudiantes, "Gerardo Marchetti");
    AgregarRegistro(estudiantes, "Ivan Petrone");

    return estudiantes;
}
