#include "CadenaCaracteres.h"

void CadenaCaracteres::Copiar(const char* origen, char* destino) {
    while (*destino++ = *origen++);
}

int CadenaCaracteres::ContarCaracteres(const char* cadena) {
    const char* inicio = cadena;
    while (*cadena++);
    return cadena - inicio - 1;
}

char* CadenaCaracteres::CrearCopia(const char* texto) {
    char* nuevoTexto = new char[ContarCaracteres(texto + 1)];
    Copiar(texto, nuevoTexto);
    return nuevoTexto;
}

int CadenaCaracteres::ContarAparicionesCaracter(const char* texto, char caracter) {
    int apariciones = 0;
    bool agrupar = false;
    for (; *texto; ++texto) {
        if (*texto == caracter and not agrupar) ++apariciones;
        if (*texto == Agrupador) agrupar = not agrupar;
    }
    return apariciones;
}

int CadenaCaracteres::ContarCaracteresCampo(int numeroCampo, const char* texto, char token) {
    int contador = 0, campoActual = 0;
    bool agrupar = false;
    for (; *texto and campoActual <= numeroCampo; ++texto) {
        if (*texto == token) ++campoActual;
        else if (*texto == Agrupador) agrupar = not agrupar;
        else if (numeroCampo == campoActual) ++contador;
    }
    return contador;
}

void CadenaCaracteres::CopiarCampo(int numeroCampo, const char* registro, char token, char* destinoCopia) {
    int campoActual = 0;
    bool agrupar = false;
    for (; *registro and campoActual <= numeroCampo; ++registro) {
        if (*registro == token and not agrupar) ++campoActual;
        else if (*registro == Agrupador) agrupar = not agrupar;
        else if (numeroCampo == campoActual) *destinoCopia++ = *registro;
    }
    *destinoCopia = FinDeCadena;
}

bool CadenaCaracteres::SonIguales(const char* a, const char* b) {
    while (*a and *b and *a++ == *b++);
    return *a == FinDeCadena and *b == FinDeCadena;
}
