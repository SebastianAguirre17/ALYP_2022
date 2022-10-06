#include "Campo.h"
#include "CadenaCaracteres.h"

using namespace CadenaCaracteres;

struct CampoCsv::Campo {
    char* valor;
};

CampoCsv::Campo* CampoCsv::CrearCampo(const char* valorCampo) {
    Campo* nuevoCampo = new Campo;
    nuevoCampo->valor = CrearCopia(valorCampo);
    return nuevoCampo;
}

char* CampoCsv::ObtenerValor(const Campo* campo) {
    return campo->valor;
}

void CampoCsv::Destruir(Campo* campo) {
    delete[]campo->valor;
    delete campo;
}

