#pragma once

#include "Campo.h"
#include "Registro.h"
#include "ArchivoCsv.h"
#include "CadenaCaracteres.h"

using namespace std;
using namespace CampoCsv;
using namespace RegistroCsv;
using namespace ArchivoCSV;
using namespace CadenaCaracteres;

const char Win[] = "win";
const char Less[] = "loss";

const int Battle_number = 0;
const int Name = 1;
const int Attacker_king = 2;
const int Defender_king = 3;
const int Location = 4;
const int Region = 5;
const int Attacker_outcome = 6;

Registro*   MergeRegistros(Registro* reg1, Registro* reg2);
ArchivoCsv* MergeArchivos(const ArchivoCsv* arch1, const ArchivoCsv* arch2);
void MostrarInforme(const ArchivoCsv* archivo);
void MostrarGanador(const Registro* registro);
void MostrarPerdedor(const Registro* registro);