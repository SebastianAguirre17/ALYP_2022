#include <iostream>

using namespace std;

const char SeparadorCampos = ',';
const char SeparadorRegistros = '\n';
const char FinDeCadena = '\0';
const char FinDeLinea = '\n';

struct Campo {
    char* valor;
};

struct Registro {
    int cantidadCampos;
    Campo** campos;
};

struct ArchivoCsv {
    int cantidadRegistros;
    Registro** registros;
};

struct ResultadoSeparacion {
    char** matriz;
    int cantidadFilas;
};


void Copiar(const char *origen, char *destino) {
    while (*destino++ = *origen++);
}

void CopiarHataSeparador(const char *origen, char *destino, char separador) {
    while ((*destino++ = *origen++) and (*origen != separador));
}

int ContarCaracteres(const char *cadena) {
    const char* inicio = cadena;
	while (*cadena++);
	return cadena - inicio - 1;
}

char * CrearCopia(const char* texto) {
    char* nuevoTexto = new char[ContarCaracteres(texto + 1)];
    Copiar(texto, nuevoTexto);
    return nuevoTexto;
}

int ContarAparicionesCaracter(const char* texto, char caracter) {
    int apariciones = 0;
    for (; *texto; ++texto) {
        if (*texto == caracter)
            ++apariciones;
    }
    return apariciones;
}

int ContarCaracteresCampo(int numeroCampo, const char* texto, char token) {
    int contador = 0, campoActual = 0;
    for (; *texto and campoActual <= numeroCampo; ++texto) {
        if (*texto == token) ++campoActual;
        else if (numeroCampo == campoActual) ++contador;
    }
    return contador;
}

void CopiarCampo(int numeroCampo, const char* registro, char separadorCampo, char* destinoCopia) {
    int campoActual = 0;
    for (; *registro and campoActual <= numeroCampo; ++registro) {
        if (*registro == separadorCampo) ++campoActual;
        else if (numeroCampo == campoActual) {
            *destinoCopia++ = *registro;
        }
    }
    *destinoCopia = FinDeCadena;
}

void Destruir(Campo* campo) {
    delete []campo->valor;
    delete campo;
}

void Destruir(Registro* registro) {
    if (registro->cantidadCampos > 0) {
        for (int i = 0; i < registro->cantidadCampos; ++i) {
            Destruir(registro->campos[i]);
        }
        delete []registro->campos;
    }
}

void Destruir(ArchivoCsv* archivo) {
    if (archivo->cantidadRegistros > 0) {
        for (int i = 0; i < archivo->cantidadRegistros; ++i) {
            Destruir(archivo->registros[i]);
        }
        delete []archivo->registros;
    }
}

void Destruir(ResultadoSeparacion* separacion) {
    for (int i = 0; i < separacion->cantidadFilas; ++i) 
        delete []separacion->matriz[i];

    delete []separacion->matriz;
    delete separacion;
}

Campo* CrearCampo(const char * valorCampo) {
    Campo* nuevoCampo = new Campo;
    nuevoCampo->valor = CrearCopia(valorCampo);
    return nuevoCampo;
}

Registro* CrearRegistro(char** campos, int cantidadCampos) {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->campos = new Campo*[cantidadCampos];
    for (int i = 0; i < cantidadCampos; ++i) 
        nuevoRegistro->campos[i] = CrearCampo(campos[i]);
    
    nuevoRegistro->cantidadCampos = cantidadCampos;
    return nuevoRegistro;
}

ResultadoSeparacion* Separar(const char* texto, char token) {
    ResultadoSeparacion* resultado = new ResultadoSeparacion;
    resultado->cantidadFilas = ContarAparicionesCaracter(texto, FinDeLinea) + 1;
    resultado->matriz = new char*[resultado->cantidadFilas];
    for (int numeroCampo = 0; numeroCampo < resultado->cantidadFilas; ++numeroCampo) {
        // En cada fila reservar tamanio
        int tamanio = ContarCaracteresCampo(numeroCampo, texto, token) + 1;
        resultado->matriz[numeroCampo] = new char[tamanio];
        // Copiar en esa fila la cadena correspondiente
        CopiarCampo(numeroCampo, texto, token, resultado->matriz[numeroCampo]);
    }

    return resultado;
}

ArchivoCsv* Parsear(const char* textoFormateado) {
    ArchivoCsv* archivoCsv = new ArchivoCsv;
    ResultadoSeparacion* registros = Separar(textoFormateado, SeparadorRegistros);
    archivoCsv->cantidadRegistros = registros->cantidadFilas;
    archivoCsv->registros = new Registro*[archivoCsv->cantidadRegistros];
    for (int i = 0; i < archivoCsv->cantidadRegistros; ++i) {
        ResultadoSeparacion* campos = Separar(registros->matriz[i], SeparadorCampos);
        archivoCsv->registros[i] = CrearRegistro(campos->matriz, campos->cantidadFilas);
        Destruir(campos);
    }
    Destruir(registros);
    return archivoCsv;
}

void Mostrar(const Campo* campo) {
    cout << campo->valor;
}

void Mostrar(const Registro* registro) {
    for (int i = 0; i < registro->cantidadCampos; ++i) {
        Mostrar(registro->campos[i]);
        if (i < registro->cantidadCampos - 1)
            cout << ",";
    }
}

void Mostrar(const ArchivoCsv* archivo) {
    for (int i = 0; i < archivo->cantidadRegistros; ++i) {
        Mostrar(archivo->registros[i]);
        cout << endl;
    }
}