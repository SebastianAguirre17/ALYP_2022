#include "Parser.h"

Campo* CrearCampo(const char* valorCampo) {
    Campo* nuevoCampo = new Campo;
    nuevoCampo->valor = CadenaCaracteres::CrearCopia(valorCampo);
    return nuevoCampo;
}

Registro* CrearRegistro(char** campos, int cantidadCampos) {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->campos = new Campo * [cantidadCampos];
    for (int i = 0; i < cantidadCampos; ++i)
        nuevoRegistro->campos[i] = CrearCampo(campos[i]);

    nuevoRegistro->cantidadCampos = cantidadCampos;
    return nuevoRegistro;
}

ResultadoSeparacion* Separar(const char* texto, char token) {
    ResultadoSeparacion* resultado = new ResultadoSeparacion;
    resultado->cantidadFilas = CadenaCaracteres::ContarAparicionesCaracter(texto, token) + 1;
    resultado->matriz = new char* [resultado->cantidadFilas];
    for (int numeroCampo = 0; numeroCampo < resultado->cantidadFilas; ++numeroCampo) {
        // En cada fila reservar tamanio
        int tamanio = CadenaCaracteres::ContarCaracteresCampo(numeroCampo, texto, token) + 1;
        resultado->matriz[numeroCampo] = new char[tamanio];
        // Copiar en esa fila la cadena correspondiente
        CadenaCaracteres::CopiarCampo(numeroCampo, texto, token, resultado->matriz[numeroCampo]);
    }

    return resultado;
}

ArchivoCsv* Parsear(const char* textoFormateado) {
    ArchivoCsv* archivoCsv = new ArchivoCsv;
    ResultadoSeparacion* registros = Separar(textoFormateado, SeparadorRegistros);
    archivoCsv->cantidadRegistros = registros->cantidadFilas - 1; // TODO: Se está cargando una fila de mas 
    archivoCsv->registros = new Registro * [archivoCsv->cantidadRegistros - 1];
    for (int i = 0; i < archivoCsv->cantidadRegistros; ++i) {
        ResultadoSeparacion* campos = Separar(registros->matriz[i], SeparadorCampos);
        archivoCsv->registros[i] = CrearRegistro(campos->matriz, campos->cantidadFilas);
        Destruir(campos);
    }
    Destruir(registros);
    return archivoCsv;
}

Registro* MergeRegistros(const Registro* reg1, const Registro* reg2) {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->cantidadCampos = reg1->cantidadCampos + reg2->cantidadCampos - 1;
    nuevoRegistro->campos = new Campo * [nuevoRegistro->cantidadCampos];
    for (int i = 0, j = reg1->cantidadCampos; i < reg1->cantidadCampos; ++i, ++j) {
        nuevoRegistro->campos[i] = reg1->campos[i];
        nuevoRegistro->campos[j] = reg2->campos[i + 1];
    }

    return nuevoRegistro;
}

ArchivoCsv* MergeArchivos(const ArchivoCsv* arch1, const ArchivoCsv* arch2) {
    ArchivoCsv* merge = new ArchivoCsv;
    merge->cantidadRegistros = arch1->cantidadRegistros;
    merge->registros = new Registro * [arch1->cantidadRegistros];

    for (int i = 0; i < merge->cantidadRegistros; ++i) 
        merge->registros[i] = MergeRegistros(arch1->registros[i], arch2->registros[i]);
    
    return merge;
}

void Mostrar(const Campo* campo) {
    cout << campo->valor;
}

void Mostrar(const Registro* registro) {
    for (int i = 0; i < registro->cantidadCampos; ++i) {
        Mostrar(registro->campos[i]);
        if (i < registro->cantidadCampos - 1)
            cout << " - ";
    }
}

void Mostrar(const ArchivoCsv* archivo) {
    for (int i = 0; i < archivo->cantidadRegistros; ++i) {
        Mostrar(archivo->registros[i]);
        cout << endl;
    }
}

void MostrarInforme(const ArchivoCsv* archivo) {
    cout << "Ganadores" << endl;
    for (int i = 1; i < archivo->cantidadRegistros; ++i) {
        if (CadenaCaracteres::SonIguales(archivo->registros[i]->campos[Attacker_outcome]->valor, Win))
            MostrarGanador(archivo->registros[i]);
    }
    cout << endl << "Perdedores" << endl;
    for (int i = 1; i < archivo->cantidadRegistros; ++i) {
        if (not CadenaCaracteres::SonIguales(archivo->registros[i]->campos[Attacker_outcome]->valor, Win))
            MostrarPerdedor(archivo->registros[i]);
    }

}

void MostrarGanador(const Registro* registro) {
    cout << "\tBatalla [" << registro->campos[Battle_number]->valor << "] - [" << registro->campos[Name]->valor << "]";
    cout << " en [" << registro->campos[Location]->valor << "] - [" << registro->campos[Region]->valor << "]" << endl;
    cout << "\t\tAtancante Ganador: " << registro->campos[Attacker_king]->valor << endl;
}

void MostrarPerdedor(const Registro* registro) {
    cout << "\tBatalla [" << registro->campos[Battle_number]->valor << "] en [" << registro->campos[Location]->valor << "] - [" << registro->campos[Region]->valor << "]" << endl;
    cout << "\t\tAtancante Perdedor: " << registro->campos[Attacker_king]->valor << endl;
}

void Destruir(Campo* campo) {
    delete[]campo->valor;
    delete campo;
}

void Destruir(Registro* registro) {
    if (registro->cantidadCampos > 0) {
        for (int i = 0; i < registro->cantidadCampos; ++i) {
            Destruir(registro->campos[i]);
        }
        delete[]registro->campos;
    }
}

void Destruir(ArchivoCsv* archivo) {
    if (archivo->cantidadRegistros > 0) {
        for (int i = 0; i < archivo->cantidadRegistros; ++i) {
            Destruir(archivo->registros[i]);
        }
        delete[]archivo->registros;
    }
}

void Destruir(ResultadoSeparacion* separacion) {
    for (int i = 0; i < separacion->cantidadFilas; ++i)
        delete[]separacion->matriz[i];

    delete[]separacion->matriz;
    delete separacion;
}