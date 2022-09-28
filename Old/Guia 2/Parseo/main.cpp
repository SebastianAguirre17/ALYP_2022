#include <iostream>
using namespace std;

#define SEPARADOR_REGISTRO '\n'
#define SEPARADOR_CAMPO ','
​
struct Campo {
    char* valor;
};

struct Registro {
    int cantidadCampos;
    Campo** campos;
};

struct ArchivoCsv {
    Registro** registros;
    int cantidadRegistros;
};

// Ejercicio de parseo
ArchivoCsv* Parsear(const char* textoFormatoCsv);
void Destruir(ArchivoCsv* archivoCsv);
​
// Funciones de los tipo de dato Campo y Registro
Campo* CrearCampo(const char* valorCampo);
Registro* CrearRegistroVacio();
void AgregarCampo(Registro* registro, Campo* campo);
Registro* CrearRegistro(char** campos, int cantidadCampos);
void Mostrar(const Campo* campo);
void Mostrar(const Registro* registro);
void Mostrar(const ArchivoCsv* archivoCsv);
int ContarRegistros(const char* textoFormatoCsv);
​
// Funciones auxiliares de cadena de caracteres
char* CrearCopia(const char* texto);
void Copiar(const char* origen, char* destino);
int ContarCaracteres(const char* cadena);
bool Estavacio(const char* texto);
bool ContarAparicionCaracter(const char* texto, char caracter);
​
// Funciones auxiliares de un algoritmo de separacion / SPLIT
struct ResultadoSeparacion {
    char** matriz;
    int cantidadFilas;
};
​
// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Devuelve una instancia valida de ResultadoSeparacion
// donde en cada fila de matriz hay una cadena de caracteres que representa la
// particion de @texto por el caracter @oken
ResultadoSeparacion* Separar(const char* texto, char token);
void Destruir(ResultadoSeparacion* separacion);
​
int main()
{
    ArchivoCsv* autos = Parsear("Fun,Susuki,Negro,IBP567\nRanger,Ford,Blanco,POP887");
    ArchivoCsv* cartas = Parsear("4,Copa\n1,Oro\n2,Copa");
    Mostrar(autos);
    Mostrar(cartas);
    Destruir(autos);
    Destruir(cartas);
}
​
ResultadoSeparacion* Separar(const char* texto, char token) {
    //TODO implementar esto
    return NULL;
}
​
void Destruir(ArchivoCsv* archivoCsv) {
    //TODO implementar esto
}
​
ArchivoCsv* Parsear(const char* textoFormatoCsv) {
    ArchivoCsv* archivoCsv = new ArchivoCsv;
    ResultadoSeparacion* registros = Separar(textoFormatoCsv, SEPARADOR_REGISTRO);
    archivoCsv->cantidadRegistros = registros->cantidadFilas;
    archivoCsv->registros = new Registro * [archivoCsv->cantidadRegistros];
    for (int i = 0; i < archivoCsv->cantidadRegistros;++i) {
        ResultadoSeparacion* campos = Separar(registros->matriz[i], SEPARADOR_CAMPO);
        archivoCsv->registros[i] = CrearRegistro(campos->matriz, campos->cantidadFilas);
        Destruir(campos);
    }
    Destruir(registros);
​
    return archivoCsv;
}
​
bool Estavacio(const char* texto) {
    return texto[0] == '\0';
}
​
bool ContarAparicionCaracter(const char* texto, char caracter) {
    int apariciones = 0;
    for (int i = 0; texto[i] != '\0'; ++i) {
        if (texto[i] == caracter) {
            ++apariciones;
        }
    }
​
    return apariciones;
}
​
int ContarRegistros(const char* textoFormatoCsv) {
    if (Estavacio(textoFormatoCsv)) return 0;
    return ContarAparicionCaracter(textoFormatoCsv, SEPARADOR_REGISTRO) + 1;
}
​
void Destruir(ResultadoSeparacion* separacion) {
    for (int i = 0; i < separacion->cantidadFilas;++i) {
        delete[]separacion->matriz[i];
    }
    delete[]separacion->matriz;
    delete separacion;
}
​
Campo* CrearCampo(const char* valorCampo) {
    Campo* nuevoCampo = new Campo;
    nuevoCampo->valor = CrearCopia(valorCampo);
​
    return nuevoCampo;
}
​
char* CrearCopia(const char* texto) {
    char* nuevoTexo = new char[ContarCaracteres(texto) + 1];
    Copiar(texto, nuevoTexo);
​
    return nuevoTexo;
}
​
void Copiar(const char* origen, char* destino) {
    while (*destino++ = *origen++);// Precedencia de Operadores, Sentencia devuelve un valor
}
​
int ContarCaracteres(const char* cadena) {
    const char* comienzoCadena = cadena;
    while (*(++cadena) != '\0');
    const char* finalCadena = cadena;
    return (finalCadena - comienzoCadena) - 1;
}
​
Registro* CrearRegistroVacio() {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->cantidadCampos = 0;
​
    return nuevoRegistro;
}
​
void AgregarCampo(Registro* registro, Campo* campo) {
    // 1 Crear un nuevo vector con el nuevo tamanio
    // 2 Copiar los campos que estan en registro en ese nuevo vector
    // 3 Agregar en la ultima posicion el nuevo campo
    // 4 Liberar del stack solo el vector
    // 5 Asignar en registro los nuevos campos 
    int nuevoTamanio = registro->cantidadCampos + 1;
    Campo** nuevosCampos = new Campo*[nuevoTamanio];
    for (int i = 0; i < registro->cantidadCampos;++i) {
        nuevosCampos[i] = registro->campos[i];
    }
    nuevosCampos[registro->cantidadCampos] = campo;
    delete []registro->campos;
    registro->campos = nuevosCampos;
    registro->cantidadCampos = nuevoTamanio;
}
​
Registro* CrearRegistro(char** campos, int cantidadCampos) {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->campos = new Campo * [cantidadCampos];
    for (int i = 0; i < cantidadCampos; ++i) {
        nuevoRegistro->campos[i] = CrearCampo(campos[i]);
    }
    nuevoRegistro->cantidadCampos = cantidadCampos;
​
    return nuevoRegistro;
}
​
void Mostrar(const Campo* campo) {
    cout << campo->valor;
}
​
void Mostrar(const Registro* registro) {
    for (int i = 0; i < registro->cantidadCampos; ++i) {
        Mostrar(registro->campos[i]);
        if(i< registro->cantidadCampos - 1)
            cout<<",";
    }
}
​
void Mostrar(const ArchivoCsv* archivoCsv) {
    for (int i = 0; i < archivoCsv->cantidadRegistros;++i) {
        Mostrar(archivoCsv->registros[i]);
        cout << endl;
    }
}