#pragma once

#include "Campo.h"
using namespace CampoCsv;

namespace RegistroCsv {
    struct Registro;

    Registro*   CrearRegistro(char** campos, int cantidadCampos);
    Registro*   CrearRegistroVacio();
    Campo*      ObtenerCampo(const Registro* registro, int numeroCampo);
    void        AgregarCampo(Registro* registro, Campo* campo);
    int         ObtenerCantidadCampos(const Registro* registro);
    void        Destruir(Registro* registro);
}
