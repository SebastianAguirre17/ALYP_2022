#include <iostream>

using namespace std;

const char SeparadorCampos = ',';
const char SeparadorRegistros = '\n';
const char FinDeCadena = '\0';
const char Win[] = "win";
const char Less[] = "less";
const char Agrupador = '|';

const int Battle_number = 0;
const int Name = 1;
const int Attacker_king = 2;
const int Defender_king = 3;
const int Location = 4;
const int Region = 5;
const int Attacker_outcome = 6;

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

void  Copiar(const char* origen, char* destino);
int   ContarCaracteres(const char* cadena);
char* CrearCopia(const char* texto);
int	  ContarAparicionesCaracter(const char* texto, char caracter);
int   ContarCaracteresCampo(int numeroCampo, const char* texto, char token);
void  CopiarCampo(int numeroCampo, const char* registro, char separadorCampo, char* destinoCopia);
bool  SonIguales(const char* a, const char* b);

Campo* CrearCampo(const char* valorCampo);
Registro* CrearRegistro(char** campos, int cantidadCampos);
ResultadoSeparacion* Separar(const char* texto, char token);
ArchivoCsv* Parsear(const char* textoFormateado);
ArchivoCsv* MergeArchivos(const ArchivoCsv* arch1, const ArchivoCsv* arch2);
Registro* MergeRegistros(const Registro* reg1, const Registro* reg2);

void Mostrar(const Campo* campo);
void Mostrar(const Registro* registro);
void Mostrar(const ArchivoCsv* archivo);
void MostrarInforme(const ArchivoCsv* archivo);
void MostrarGanador(const Registro* registro);
void MostrarPerdedor(const Registro* registro);

void Destruir(Campo* campo);
void Destruir(Registro* registro);
void Destruir(ArchivoCsv* archivo);
void Destruir(ResultadoSeparacion* separacion);

// Precondicion: @batallasCSV1 es una cadena de caracteres en formato CSV con los siguientes campos: battle_number,name,attacker_king,defender_king
// @batallasCSV2 es una cadena de caracteres en formato CSV con los siguientes campos: battle_number,location,region,attacker_outcome
// Postcondicion: Imprime por salida estandard con el siguiente formato
// Ganadores
// 		Batalla [battle_number]-[battle_name] en [location] - [region]
// 			Atacante Ganador: [attacker_king]
//
// Perdedores
// 		Batalla [battle_number] en [location] - [region]
// 			Atacante Perdedor: [attacker_king]
// Es decir primero todas las batallas en las que el rey atacante gano (attacker_outcome tiene el valor win), con el titulo de Ganadores.
// Segundo todas las batallas en las que el rey atacante perdio, con el titulo de perdedores.
void MostrarInformeBatallas(char batallasCSV1[], char batallasCSV2[]);

int main() {
	char batallas1[] = "battle_number,name,attacker_king,defender_king\n1,Battle of the Golden Tooth,Joffrey/Tommen Baratheon,Robb Stark\n2,Battle at the Mummer\'s Ford,Joffrey/Tommen Baratheon,Robb Stark\n3,Battle of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n4,Battle of the Green Fork,Robb Stark,Joffrey/Tommen Baratheon\n5,Battle of the Whispering Wood,Robb Stark,Joffrey/Tommen Baratheon\n6,Battle of the Camps,Robb Stark,Joffrey/Tommen Baratheon\n7,Sack of Darry,Joffrey/Tommen Baratheon,Robb Stark\n8,Battle of Moat Cailin,Balon/Euron Greyjoy,Robb Stark\n9,Battle of Deepwood Motte,Balon/Euron Greyjoy,Robb Stark\n10,Battle of the Stony Shore,Balon/Euron Greyjoy,Robb Stark\n11,Battle of Torrhen\'s Square,Robb Stark,Balon/Euron Greyjoy\n12,Battle of Winterfell,Balon/Euron Greyjoy,Robb Stark\n13,Sack of Torrhen\'s Square,Balon/Euron Greyjoy,Balon/Euron Greyjoy\n14,Sack of Winterfell,Joffrey/Tommen Baratheon,Robb Stark\n15,Battle of Oxcross,Robb Stark,Joffrey/Tommen Baratheon\n16,Siege of Storm\'s End,Stannis Baratheon,Renly Baratheon\n17,Battle of the Fords,Joffrey/Tommen Baratheon,Robb Stark\n18,Sack of Harrenhal,Robb Stark,Joffrey/Tommen Baratheon\n19,Battle of the Crag,Robb Stark,Joffrey/Tommen Baratheon\n20,Battle of the Blackwater,Stannis Baratheon,Joffrey/Tommen Baratheon\n21,Siege of Darry,Robb Stark,Joffrey/Tommen Baratheon\n22,Battle of Duskendale,Robb Stark,Joffrey/Tommen Baratheon\n23,Battle of the Burning Septry,,\n24,Battle of the Ruby Ford,Joffrey/Tommen Baratheon,Robb Stark\n25,Retaking of Harrenhal,Joffrey/Tommen Baratheon,\n26,The Red Wedding,Joffrey/Tommen Baratheon,Robb Stark\n27,Siege of Seagard,Robb Stark,Joffrey/Tommen Baratheon\n28,Battle of Castle Black,Stannis Baratheon,Mance Rayder\n29,Fall of Moat Cailin,Joffrey/Tommen Baratheon,Balon/Euron Greyjoy\n30,Sack of Saltpans,,\n31,Retaking of Deepwood Motte,Stannis Baratheon,Balon/Euron Greyjoy\n32,Battle of the Shield Islands,Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n33,|Invasion of Ryamsport, Vinetown, and Starfish Harbor|,Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n34,Second Seige of Storm\'s End,Joffrey/Tommen Baratheon,Stannis Baratheon\n35,Siege of Dragonstone,Joffrey/Tommen Baratheon,Stannis Baratheon\n36,Siege of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n37,Siege of Raventree,Joffrey/Tommen Baratheon,Robb Stark\n38,Siege of Winterfell,Stannis Baratheon,Joffrey/Tommen Baratheon\n";
	char batallas2[] = "battle_number,location,region,attacker_outcome\n1,Golden Tooth,The Westerlands,win\n2,Mummer\'s Ford,The Riverlands,win\n3,Riverrun,The Riverlands,win\n4,Green Fork,The Riverlands,loss\n5,Whispering Wood,The Riverlands,win\n6,Riverrun,The Riverlands,win\n7,Darry,The Riverlands,win\n8,Moat Cailin,The North,win\n9,Deepwood Motte,The North,win\n10,Stony Shore,The North,win\n11,Torrhen\'s Square,The North,win\n12,Winterfell,The North,win\n13,Torrhen\'s Square,The North,win\n14,Winterfell,The North,win\n15,Oxcross,The Westerlands,win\n16,Storm\'s End,The Stormlands,win\n17,Red Fork,The Riverlands,loss\n18,Harrenhal,The Riverlands,win\n19,Crag,The Westerlands,win\n20,King\'s Landing,The Crownlands,loss\n21,Darry,The Riverlands,win\n22,Duskendale,The Crownlands,loss\n23,,The Riverlands,win\n24,Ruby Ford,The Riverlands,win\n25,Harrenhal,The Riverlands,win\n26,The Twins,The Riverlands,win\n27,Seagard,The Riverlands,win\n28,Castle Black,Beyond the Wall,loss\n29,Moat Cailin,The North,win\n30,Saltpans,The Riverlands,win\n31,Deepwood Motte,The North,win\n32,Shield Islands,The Reach,win\n33,|Ryamsport, Vinetown, Starfish Harbor|,The Reach,win\n34,Storm\'s End,The Stormlands,win\n35,Dragonstone,The Stormlands,win\n36,Riverrun,The Riverlands,win\n37,Raventree,The Riverlands,win\n38,Winterfell,The North,\n";

	MostrarInformeBatallas(batallas1, batallas2);

    //ResultadoSeparacion* campos = Separar("33,|Ryamsport, Vinetown, Starfish Harbor|,The Reach,win", SeparadorCampos);
    //cout << campos->cantidadFilas;

	return 0;
}

void MostrarInformeBatallas(char batallasCSV1[], char batallasCSV2[]) {
	ArchivoCsv* batallas1 = Parsear(batallasCSV1);
	// ArchivoCsv* batallas2 = Parsear(batallasCSV2);
    
    // ArchivoCsv* mergeBatallas = MergeArchivos(batallas1, batallas2);
	// Mostrar(batallas1);
}

void Copiar(const char* origen, char* destino) {
    while (*destino++ = *origen++);
}

int ContarCaracteres(const char* cadena) {
    const char* comienzoCadena = cadena;
    while (*cadena++);
    const char* finalCadena = cadena;
    return (finalCadena - comienzoCadena) - 1;
}

char* CrearCopia(const char* texto) {
    char* nuevoTexto = new char[ContarCaracteres(texto + 1)];
    Copiar(texto, nuevoTexto);
    return nuevoTexto;
}

int ContarAparicionesCaracter(const char* texto, char caracter) {
    int apariciones = 0;
    bool flag = false;
    for (; *texto; ++texto) {
        if (*texto == caracter and not flag) ++apariciones;
        else if (*texto == Agrupador) flag = not flag;
    }
    return apariciones;
}

int ContarCaracteresCampo(int numeroCampo, const char* texto, char token) {
    int contador = 0, campoActual = 0;
    bool flag = false;
    for (; *texto and campoActual <= numeroCampo; ++texto) {
        if (*texto == token and not flag) ++campoActual;
        else if (*texto == Agrupador) flag = not flag;
        else if (numeroCampo == campoActual) ++contador;
    }
    return contador;
}

void CopiarCampo(int numeroCampo, const char* registro, char token, char* destinoCopia) {
    int campoActual = 0;
    bool flag = false;
    for (; *registro and campoActual <= numeroCampo; ++registro) {
        if (*registro == token and not flag) ++campoActual;
        else if (*registro == Agrupador) flag = not flag;
        else if (numeroCampo == campoActual) *destinoCopia++ = *registro;
    }
    *destinoCopia = FinDeCadena;
}

bool SonIguales(const char* a, const char* b) {
    while (*a and *b and *a++ == *b++);
    return *a == FinDeCadena and *b == FinDeCadena;
}


Campo* CrearCampo(const char* valorCampo) {
    Campo* nuevoCampo = new Campo;
    nuevoCampo->valor = CrearCopia(valorCampo);
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
    resultado->cantidadFilas = ContarAparicionesCaracter(texto, token) + 1;
    resultado->matriz = new char* [resultado->cantidadFilas];
    for (int numeroCampo = 0; numeroCampo < resultado->cantidadFilas; ++numeroCampo) {
        int tamanio = ContarCaracteresCampo(numeroCampo, texto, token) + 1;
        resultado->matriz[numeroCampo] = new char[tamanio];
        CopiarCampo(numeroCampo, texto, token, resultado->matriz[numeroCampo]);
    }
    return resultado;
}

ArchivoCsv* Parsear(const char* textoFormateado) {
    ArchivoCsv* archivoCsv = new ArchivoCsv;
    ResultadoSeparacion* registros = Separar(textoFormateado, SeparadorRegistros);
    archivoCsv->cantidadRegistros = registros->cantidadFilas - 1; // TODO: Se está cargando una fila de mas 
    archivoCsv->registros = new Registro * [archivoCsv->cantidadRegistros];
    for (int i = 0; i < archivoCsv->cantidadRegistros; ++i) {
        ResultadoSeparacion* campos = Separar(registros->matriz[i], SeparadorCampos);
        archivoCsv->registros[i] = CrearRegistro(campos->matriz, campos->cantidadFilas);
        if (i == 33) {
            cout << "Registro: " << registros->matriz[i] << endl;
            Mostrar(archivoCsv->registros[i]);
            cout << "Campo filas: " << campos->cantidadFilas << endl;
            cout << "Matriz campo: " << campos->matriz[1] << endl;
        }
        Destruir(campos);
    }
    Destruir(registros);
    return archivoCsv;
}

Registro* MergeRegistros(Registro* reg1, Registro* reg2) {
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
        if (SonIguales(archivo->registros[i]->campos[Attacker_outcome]->valor, Win))
            MostrarGanador(archivo->registros[i]);
    }
    cout << endl << "Perdedores" << endl;
    for (int i = 1; i < archivo->cantidadRegistros; ++i) {
        if (SonIguales(archivo->registros[i]->campos[Attacker_outcome]->valor, Less))
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
    delete registro;
}

void Destruir(ArchivoCsv* archivo) {
    if (archivo->cantidadRegistros > 0) {
        for (int i = 0; i < archivo->cantidadRegistros; ++i) {
            Destruir(archivo->registros[i]);
        }
        delete[]archivo->registros;
    }
    delete archivo;
}

void Destruir(ResultadoSeparacion* separacion) {
    for (int i = 0; i < separacion->cantidadFilas; ++i)
        delete[]separacion->matriz[i];

    delete[]separacion->matriz;
    delete separacion;
}