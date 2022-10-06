#pragma once

const int	FinDeCadena = '\0';
const int	PosInicioDeCadena = 0;

namespace CadenaCaracteres {
	void  Copiar(const char* origen, char* destino);
	int   ContarCaracteres(const char* cadena);
	char* CrearCopia(const char* texto);
	int	  ContarAparicionesCaracter(const char* texto, char caracter);
	bool  SonIguales(const char* a, const char* b);
	bool  EstaVacio(const char* texto);
}