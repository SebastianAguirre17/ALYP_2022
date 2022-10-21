#include "ArchivoCsv.h"
#include "Registro.h"
#include "CadenaCaracteres.h"

using namespace RegistroCsv;
using namespace CadenaCaracteres;

const char SeparadorCampos = ',';
const char SeparadorRegistros = '\n';

struct ResultadoSeparacion {
    char** matriz;
    int cantidadFilas;
};

ResultadoSeparacion* Separar(const char* texto, char token);
void Destruir(ResultadoSeparacion* separacion);

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

ArchivoCSV::ArchivoCsv* ArchivoCSV::CrearArchivoVacio() {
    ArchivoCsv* archivoCsv = new ArchivoCsv;
    archivoCsv->cantidadRegistros = 0;
    return archivoCsv;
}

void ArchivoCSV::AgregarRegistro(ArchivoCsv* archivo, Registro* registro) {
    int nuevoTamanio = archivo->cantidadRegistros + 1;
    Registro** nuevosRegistros = new Registro * [nuevoTamanio];
    for (int i = 0; i < archivo->cantidadRegistros; ++i) {
        nuevosRegistros[i] = archivo->registros[i];
    }
    nuevosRegistros[archivo->cantidadRegistros] = registro;
 
    archivo->registros = nuevosRegistros;
    archivo->cantidadRegistros = nuevoTamanio;
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

ResultadoSeparacion* Separar(const char* texto, char token) {
    ResultadoSeparacion* nuevoResultado = new ResultadoSeparacion;
    nuevoResultado->cantidadFilas = ContarAparicionesCaracter(texto, token) + 1;
    nuevoResultado->matriz = new char* [nuevoResultado->cantidadFilas];
    int tamanio;
    for (int numeroCampo = 0; numeroCampo < nuevoResultado->cantidadFilas; ++numeroCampo) {
        tamanio = CadenaCaracteres::ContarCaracteresCampo(numeroCampo, texto, token) + 1;
        
        nuevoResultado->matriz[numeroCampo] = new char[tamanio];
        CadenaCaracteres::CopiarCampo(numeroCampo, texto, token, nuevoResultado->matriz[numeroCampo]);
    }
    if (tamanio == 1 and token == SeparadorRegistros) nuevoResultado->cantidadFilas--; // TODO
    return nuevoResultado;
}

void Destruir(ResultadoSeparacion* separacion) {
    for (int i = 0; i < separacion->cantidadFilas; ++i) {
        delete[]separacion->matriz[i];
    }
    delete[]separacion->matriz;
    delete separacion;
}

bool EsCSV_Valido(const Registro* registro, int cantidadFilas) {
    return (ObtenerCantidadCampos(registro) == cantidadFilas);
}