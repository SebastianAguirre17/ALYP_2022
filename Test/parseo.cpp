#include <iostream>

using namespace std;


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

int ContarCaracteres(const char *cadena); 
void Copiar(const char *origen, char *destino);
char * CrearCopia(const char* texto);

void MostrarCampo(const Campo* campo);
void MostrarRegistro(const Registro* registro); 
Campo* CrearCampo(const char* valorCampo);
Registro* CrearRegistroVacio(); 
void AgregarRegistro(Registro* registro, Campo* campo);

ArchivoCsv* Parsear(const char* texto);

int main() {
    cout << "\tPRACTICA PARSEO\n\n";

    char batallas1[] = "battle_number,name,attacker_king,defender_king\n1,Battle of the Golden Tooth,Joffrey/Tommen Baratheon,Robb Stark\n2,Battle at the Mummer\'s Ford,Joffrey/Tommen Baratheon,Robb Stark\n3,Battle of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n4,Battle of the Green Fork,Robb Stark,Joffrey/Tommen Baratheon\n";

    

    ArchivoCsv* archivo = Parsear(batallas1);

    
    return EXIT_SUCCESS;
}

ArchivoCsv* Parsear(const char* texto) {
    ArchivoCsv* nuevoArchivo = new ArchivoCsv;


    return nuevoArchivo;
}

Campo* CrearCampo(const char* valorCampo) {
    Campo* nuevoCampo = new Campo;
    nuevoCampo->valor = CrearCopia(valorCampo);
    return nuevoCampo;
}

Registro* CrearRegistroVacio() {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->cantidadCampos = 0;
    return nuevoRegistro;
}

void Copiar(const char *origen, char *destino) {
    while (*destino++ = *origen++);
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

void AgregarRegistro(Registro* registro, Campo* campo) {
    int cantidadCampos = registro->cantidadCampos + 1;
    Campo** nuevosCampos = new Campo*[cantidadCampos];
    for (int i = 0; i < registro->cantidadCampos; ++i) {
        nuevosCampos[i] = registro->campos[i];
    }
    nuevosCampos[registro->cantidadCampos] = campo;
    delete []registro->campos;
    registro->campos = nuevosCampos;
    registro->cantidadCampos++;
}

Registro* CrearRegistro(char** campos, int cantidadDeCampos) {
    Registro* nuevoRegistro = new Registro;
    nuevoRegistro->campos = new Campo*[cantidadDeCampos];
    for (int i = 0; i < cantidadDeCampos; ++i) {
        nuevoRegistro->campos[i] = CrearCampo(campos[i]);
    }
    nuevoRegistro->cantidadCampos = cantidadDeCampos;
    return nuevoRegistro;
}

void MostrarCampo(const Campo* campo) {
    cout << campo->valor << " ";
}

void MostrarRegistro(const Registro* registro) {
    for (int i = 0; i < registro->cantidadCampos; ++i) {
        MostrarCampo(registro->campos[i]);
    }
}   



int ContarRegistros(const char* texto) {

}