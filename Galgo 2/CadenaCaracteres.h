#pragma once

const int FinDeCadena = '\0';
const char Agrupador = '|';

namespace CadenaCaracteres {

void  Copiar(const char* origen, char* destino);
int   ContarCaracteres(const char* cadena);
char* CrearCopia(const char* texto);
int	  ContarAparicionesCaracter(const char* texto, char caracter);
int   ContarCaracteresCampo(int numeroCampo, const char* texto, char token);
void  CopiarCampo(int numeroCampo, const char* registro, char separadorCampo, char* destinoCopia);
bool  SonIguales(const char* a, const char* b);
}