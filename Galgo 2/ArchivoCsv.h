#pragma once

#include "Registro.h"
using namespace RegistroCsv;

namespace ArchivoCSV {
	struct ArchivoCsv;

	ArchivoCsv* Crear(const char* textoFormatoCsv);
	ArchivoCsv* CrearArchivoVacio();
	Registro*	ObtenerRegistro(const ArchivoCsv* archivoCsv, int numeroRegistro);
	void		AgregarRegistro(ArchivoCsv* archivo, Registro* registro);
	void		Destruir(ArchivoCsv* archivoCsv);
	int			ObtenerCantidadRegistros(const ArchivoCsv* archivoCsv);
}