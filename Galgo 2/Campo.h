#pragma once

namespace CampoCsv {
    struct Campo;

    Campo*  CrearCampo(const char* valorCampo);
    char*   ObtenerValor(const Campo* campo);
    void    Destruir(Campo* campo);
}
