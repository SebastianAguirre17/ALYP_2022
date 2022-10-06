#pragma once

#include "Campo.h"
using namespace CampoCsv;

namespace RegistroCsv {
    struct Registro;

    Registro*   CrearRegistro(char** campos, int cantidadCampos);
    Campo*      ObtenerCampo(const Registro* registro, int numeroCampo);
    int         ObtenerCantidadCampos(const Registro* registro);
    void        Destruir(Registro* registro);
}
