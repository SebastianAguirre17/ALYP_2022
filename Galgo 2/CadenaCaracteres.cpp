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
    for (; *texto; ++texto) {
        if (*texto == caracter)
            ++apariciones;
    }
    return apariciones;
}

int CadenaCaracteres::ContarCaracteresCampo(int numeroCampo, const char* texto, char token) {
    int contador = 0, campoActual = 0;
    for (; *texto and campoActual <= numeroCampo; ++texto) {
        if (*texto == token) ++campoActual;
        else if (numeroCampo == campoActual) ++contador;
    }
    return contador;
}