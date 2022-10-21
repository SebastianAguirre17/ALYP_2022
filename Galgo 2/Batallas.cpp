#include <iostream>
#include "Batallas.h"

Registro* MergeRegistros(Registro* reg1, Registro* reg2) {
	Registro* nuevoRegistro = CrearRegistroVacio();

	for (int i = 0; i < ObtenerCantidadCampos(reg1); ++i) 
		AgregarCampo(nuevoRegistro, ObtenerCampo(reg1, i));
	
	for (int j = 1; j < ObtenerCantidadCampos(reg2); ++j)
		AgregarCampo(nuevoRegistro, ObtenerCampo(reg2, j));
	
	return nuevoRegistro;
}

ArchivoCsv* MergeArchivos(const ArchivoCsv* arch1, const ArchivoCsv* arch2) {
	ArchivoCsv* merge = CrearArchivoVacio();

	for (int i = 0; i < ObtenerCantidadRegistros(arch1); ++i)
		AgregarRegistro(merge, MergeRegistros(ObtenerRegistro(arch1, i), ObtenerRegistro(arch2, i)));

	return merge;
}

void MostrarInforme(const ArchivoCsv* archivo) {
	cout << "Ganadores" << endl;
	
	for (int i = 1; i < ObtenerCantidadRegistros(archivo); ++i) {
		if (SonIguales(ObtenerValor(ObtenerCampo(ObtenerRegistro(archivo, i), Attacker_outcome)), Win))
			MostrarGanador(ObtenerRegistro(archivo, i));
	}
	cout << endl << "Perdedores" << endl;
	for (int j = 1; j < ObtenerCantidadRegistros(archivo); ++j) {
		if (SonIguales(ObtenerValor(ObtenerCampo(ObtenerRegistro(archivo, j), Attacker_outcome)), Less))
			MostrarPerdedor(ObtenerRegistro(archivo, j));
	}
}

void MostrarGanador(const Registro* registro) {
	cout << "\tBatalla [" << ObtenerValor(ObtenerCampo(registro, Battle_number)) << "] - [" << ObtenerValor(ObtenerCampo(registro, Name)) << "]";
	cout << " en [" << ObtenerValor(ObtenerCampo(registro, Location)) << "] - [" << ObtenerValor(ObtenerCampo(registro, Region)) << "]" << endl;
	cout << "\t\tAtancante Ganador: " << ObtenerValor(ObtenerCampo(registro, Attacker_king)) << endl;
}

void MostrarPerdedor(const Registro* registro) {
	cout << "\tBatalla [" << ObtenerValor(ObtenerCampo(registro, Battle_number)) << "] en [" << ObtenerValor(ObtenerCampo(registro, Location));
	cout << "] - [" << ObtenerValor(ObtenerCampo(registro, Region)) << "]" << endl;
	cout << "\t\tAtancante Perdedor: " << ObtenerValor(ObtenerCampo(registro, Attacker_king)) << endl;
}