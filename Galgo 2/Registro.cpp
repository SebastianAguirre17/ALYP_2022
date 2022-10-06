#include "Registro.h"
#include "Campo.h"

using namespace CampoCsv;

struct RegistroCsv::Registro {
    int cantidadCampos;
    Campo** campos;
};

RegistroCsv::Registro* RegistroCsv::CrearRegistro(char** campos, int cantidadCampos) {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->campos = new Campo * [cantidadCampos];
    for (int i = 0; i < cantidadCampos; ++i)
        nuevoRegistro->campos[i] = CrearCampo(campos[i]);

    nuevoRegistro->cantidadCampos = cantidadCampos;
    return nuevoRegistro;
}

void RegistroCsv::Destruir(Registro* registro) {
    if (registro->cantidadCampos > 0) {
        for (int i = 0; i < registro->cantidadCampos; ++i) {
            Destruir(registro->campos[i]);
        }
        delete[]registro->campos;
    }
    delete registro;
}

int RegistroCsv::ObtenerCantidadCampos(const Registro* registro) {
    return registro->cantidadCampos;
}

Campo* RegistroCsv::ObtenerCampo(const Registro* registro, int numeroCampo) {
    return registro->campos[numeroCampo];
}
