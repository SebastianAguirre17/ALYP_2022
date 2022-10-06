#include "ArchivoCsv.h"
#include "Registro.h"
#include "CadenaCaracteres.h"

using namespace RegistroCsv;
using namespace CadenaCaracteres;

const char SeparadorCampos = ',';
const char SeparadorRegistros = '\n';


/****   AUXILIARES  *****/
struct ResultadoSeparacion {
    char** matriz;
    int cantidadFilas;
};

ResultadoSeparacion* Separar(const char* texto, char token);
void Destruir(ResultadoSeparacion* separacion);
int ContarCaracteresCampo(int numeroCampo, const char* texto, char token);
void CopiarCampo(int numeroCampo, const char* registro, char separadorCampos, char* destinoCopia);
/****   AUXILIARES  *****/

struct ArchivoCSV::ArchivoCsv {
    Registro** registros;
    int cantidadRegistros;
};

ArchivoCSV::ArchivoCsv* ArchivoCSV::Crear(const char* textoFormateado) {
    ArchivoCsv* archivoCsv = new ArchivoCsv;
    ResultadoSeparacion* registros = Separar(textoFormateado, SeparadorRegistros);
    archivoCsv->cantidadRegistros = registros->cantidadFilas;
    archivoCsv->registros = new Registro * [ObtenerCantidadRegistros(archivoCsv)];
    for (int i = 0; i < archivoCsv->cantidadRegistros; ++i) {
        ResultadoSeparacion* campos = Separar(registros->matriz[i], SeparadorCampos);
        archivoCsv->registros[i] = CrearRegistro(campos->matriz, campos->cantidadFilas);
        Destruir(campos);
    }
    Destruir(registros);
    return archivoCsv;
}

int ArchivoCSV::ObtenerCantidadRegistros(const ArchivoCsv* archivoCsv) {
    return archivoCsv->cantidadRegistros;
}

Registro* ArchivoCSV::ObtenerRegistro(const ArchivoCsv* archivoCsv, int numeroRegistro) {
    return archivoCsv->registros[numeroRegistro];
}

void ArchivoCSV::Destruir(ArchivoCsv* archivo) {
    if (archivo->cantidadRegistros > 0) {
        for (int i = 0; i < archivo->cantidadRegistros; ++i) {
            Destruir(archivo->registros[i]);
        }
        delete[]archivo->registros;
    }
    delete archivo;
}

int ContarCaracteresCampo(int numeroCampo, const char* texto, char token) {
    int contador = 0, campoActual = 0;
    for (; *texto and campoActual <= numeroCampo; ++texto) {
        if (*texto == token) ++campoActual;
        else if (numeroCampo == campoActual) ++contador;
    }
    return contador;
}

void CopiarCampo(int numeroCampo, const char* registro, char separadorCampos, char* destinoCopia) {
    int campoActual = 0;
    for (; *registro and campoActual <= numeroCampo; ++registro) {
        if (*registro == separadorCampos) ++campoActual;
        else if (numeroCampo == campoActual) *destinoCopia++ = *registro;
    }
    *destinoCopia = FinDeCadena;
}

ResultadoSeparacion* Separar(const char* texto, char token) {
    ResultadoSeparacion* nuevoResultado = new ResultadoSeparacion;
    nuevoResultado->cantidadFilas = ContarAparicionesCaracter(texto, token) + 1;
    nuevoResultado->matriz = new char* [nuevoResultado->cantidadFilas];
    for (int numeroCampo = 0; numeroCampo < nuevoResultado->cantidadFilas; ++numeroCampo) {
        int tamanio = ContarCaracteresCampo(numeroCampo, texto, token) + 1;
        nuevoResultado->matriz[numeroCampo] = new char[tamanio];
        CopiarCampo(numeroCampo, texto, token, nuevoResultado->matriz[numeroCampo]);
    }
    return nuevoResultado;
}

void Destruir(ResultadoSeparacion* separacion) {
    for (int i = 0; i < separacion->cantidadFilas; ++i) {
        delete[]separacion->matriz[i];
    }
    delete[]separacion->matriz;
    delete separacion;
}
