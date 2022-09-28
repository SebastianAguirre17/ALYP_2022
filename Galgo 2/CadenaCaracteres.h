#pragma once

namespace CadenaCaracteres {

void  Copiar(const char* origen, char* destino);
int   ContarCaracteres(const char* cadena);
char* CrearCopia(const char* texto);
int	  ContarAparicionesCaracter(const char* texto, char caracter);
int   ContarCaracteresCampo(int numeroCampo, const char* texto, char token);

}