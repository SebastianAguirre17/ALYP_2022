#include "Particion.h"
#include <iostream>

struct UDBParticion::Particion {
	int inicioRango;
	int finRango;
};

UDBParticion::Particion* UDBParticion::Crear(int inicioRango, int finRango) {
	if (inicioRango < 0 or finRango < inicioRango)
		return NULL;

	Particion* nuevaParticion = new Particion;
	nuevaParticion->inicioRango = inicioRango;
	nuevaParticion->finRango = finRango;
	return nuevaParticion;
}

Registro* UDBParticion::ObtenerRegistro(Particion* particion, int identificador) {
	return NULL;
}

void UDBParticion::AgregarRegistro(Particion* particion, string valor) {

}

void UDBParticion::ActualizarRegistro(Particion* particion, int identificador, string valor) {

}

void UDBParticion::EliminarRegistro(Particion* particion, int identificador) {

}

void UDBParticion::Destruir(Particion* particion) {

}