#pragma once

#include "Registro.h"
using namespace RegistroCsv;

namespace ArchivoCSV {
	struct ArchivoCsv;

	ArchivoCsv* Crear(const char* textoFormatoCsv);
	Registro*	ObtenerRegistro(const ArchivoCsv* archivoCsv, int numeroRegistro);
	void		Destruir(ArchivoCsv* archivoCsv);
	int			ObtenerCantidadRegistros(const ArchivoCsv* archivoCsv);
}