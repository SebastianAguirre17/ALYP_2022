#pragma once

#include <iostream>
#include "CadenaCaracteres.h"

using namespace std;
using namespace CadenaCaracteres;

const char SeparadorCampos = ',';
const char SeparadorRegistros = '\n';
const char Win[] = "win";
const int Battle_number = 0;
const int Name = 1;
const int Attacker_king = 2;
const int Defender_king = 3;
const int Location = 4;
const int Region = 5;
const int Attacker_outcome = 6;

struct Campo {
    char* valor;
};

struct Registro {
    int cantidadCampos;
    Campo** campos;
};

struct ArchivoCsv {
    int cantidadRegistros;
    Registro** registros;
};

struct ResultadoSeparacion {
    char** matriz;
    int cantidadFilas;
};

Campo* CrearCampo(const char* valorCampo);
Registro* CrearRegistro(char** campos, int cantidadCampos);
ResultadoSeparacion* Separar(const char* texto, char token);
ArchivoCsv* Parsear(const char* textoFormateado);
ArchivoCsv* MergeArchivos(const ArchivoCsv* arch1, const ArchivoCsv* arch2);
Registro* MergeRegistros(const Registro* reg1, const Registro* reg2);

void Mostrar(const Campo* campo);
void Mostrar(const Registro* registro);
void Mostrar(const ArchivoCsv* archivo);
void MostrarInforme(const ArchivoCsv* archivo);
void MostrarGanador(const Registro* registro);
void MostrarPerdedor(const Registro* registro);

void Destruir(Campo* campo);
void Destruir(Registro* registro);
void Destruir(ArchivoCsv* archivo);
void Destruir(ResultadoSeparacion* separacion);


