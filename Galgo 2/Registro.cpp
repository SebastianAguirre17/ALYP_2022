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

RegistroCsv::Registro* RegistroCsv::CrearRegistroVacio() {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->cantidadCampos = 0;
    return nuevoRegistro;
}

void RegistroCsv::AgregarCampo(Registro* registro, Campo* campo) {
    int nuevoTamanio = registro->cantidadCampos + 1;
    Campo** nuevosCampos = new Campo * [nuevoTamanio];
    for (int i = 0; i < registro->cantidadCampos; ++i) {
        nuevosCampos[i] = registro->campos[i];
    }
    nuevosCampos[registro->cantidadCampos] = CrearCampo(ObtenerValor(campo));

    registro->campos = nuevosCampos;
    registro->cantidadCampos = nuevoTamanio;
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
