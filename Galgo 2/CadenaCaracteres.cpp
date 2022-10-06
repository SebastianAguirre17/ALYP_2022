#include "CadenaCaracteres.h"

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
        if (*texto == caracter) ++apariciones;
    }
    return apariciones;
}

bool CadenaCaracteres::SonIguales(const char* a, const char* b) {
    while (*a and *b and *a++ == *b++);
    return *a == FinDeCadena and *b == FinDeCadena;
}

bool CadenaCaracteres::EstaVacio(const char* texto) {
    return texto[PosInicioDeCadena] == FinDeCadena;
}