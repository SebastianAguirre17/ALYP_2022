#pragma once

const int	FinDeCadena = '\0';
const int	PosInicioDeCadena = 0;
const char  Agrupador = '|';

namespace CadenaCaracteres {
	void  Copiar(const char* origen, char* destino);
	int   ContarCaracteres(const char* cadena);
	char* CrearCopia(const char* texto);
	int	  ContarAparicionesCaracter(const char* texto, char caracter);
	bool  SonIguales(const char* a, const char* b);
	bool  EstaVacio(const char* texto);
	bool  EstaAgrupado(const char* texto);
	void  CopiarCampo(int numeroCampo, const char* registro, char separadorCampos, char* destinoCopia);
	int   ContarCaracteresCampo(int numeroCampo, const char* texto, char token);
}