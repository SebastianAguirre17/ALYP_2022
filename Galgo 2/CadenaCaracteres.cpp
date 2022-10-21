#include "CadenaCaracteres.h"

bool agrupado = false;

bool CadenaCaracteres::EstaAgrupado(const char* texto) {
    agrupado = (*texto == Agrupador) ? not agrupado : agrupado;
    return (*texto == Agrupador) ? not agrupado : agrupado;
}

void CadenaCaracteres::Copiar(const char* origen, char* destino) {
    while (*destino++ = *origen++);
}

int CadenaCaracteres::ContarCaracteres(const char* cadena) {
    const char* comienzoCadena = cadena;
    while (*cadena++);
    const char* finalCadena = cadena;
    return (finalCadena - comienzoCadena) - 1;
}

char* CadenaCaracteres::CrearCopia(const char* texto) {
    char* nuevoTexto = new char[ContarCaracteres(texto + 1)];
    Copiar(texto, nuevoTexto);
    return nuevoTexto;
}

int CadenaCaracteres::ContarAparicionesCaracter(const char* texto, char caracter) {
    int apariciones = 0;
    for (; *texto; ++texto) {
        if (not EstaAgrupado(texto) and *texto == caracter) ++apariciones;
    }
    agrupado = false;// Default
    return apariciones;
}

bool CadenaCaracteres::SonIguales(const char* a, const char* b) {
    while (*a and *b and *a++ == *b++);
    return *a == FinDeCadena and *b == FinDeCadena;
}

bool CadenaCaracteres::EstaVacio(const char* texto) {
    return texto[PosInicioDeCadena] == FinDeCadena;
}

int CadenaCaracteres::ContarCaracteresCampo(int numeroCampo, const char* texto, char token) {
    int contador = 0, campoActual = 0;

    for (; *texto and campoActual <= numeroCampo; ++texto) {
        if (not EstaAgrupado(texto) and *texto == token) ++campoActual;
        else if (numeroCampo == campoActual) ++contador;
    }
    agrupado = false;// Default
    return contador;
}


void CadenaCaracteres::CopiarCampo(int numeroCampo, const char* registro, char separadorCampos, char* destinoCopia) {
    int campoActual = 0;
    for (; *registro and campoActual <= numeroCampo; ++registro) {
        if (not EstaAgrupado(registro) and *registro == separadorCampos) ++campoActual;
        else if (numeroCampo == campoActual) *destinoCopia++ = *registro;
    }
    agrupado = false;// Default
    *destinoCopia = FinDeCadena;
}