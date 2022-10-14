#include <iostream>

using namespace std;

const char	FinDeCadena = '\0';
const int	TopeCadena = 100;
const int	IndiceComienzo = 0;
const int	IndiceFin = 7;

// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Realiza las siguientes transformaciones en @texto
// 1 - Invierte la cadena @texto
// 2 - Luego modifica cada caracter de la cadena por la suma de
// cada caracter + @clave
// Ejemplo:
// Si invoco Encriptar con texto = "AON" y clave = 1 entonces
// texto quedaria transformado a "MPB" ya que
// - La primer transformacion de AON seria invertirlo -> NOA
// - Como el parametro @clave es uno le suma uno a cada caracter -> "OPB"
void Encriptar(char texto[], unsigned int clave);

// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Cuenta la cantidad de caracteres de @texto
int	 ContarCaracteres(char texto[]);

// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Invierte la cadena @texto
void InvertirPalabra(char texto[]);

// Precondicion: @origen y @destino son cadenas de caracteres y @destino tiene 
// el tamanio suficiente para alojar el contenido de origen
// Postcondicion: Copia el contenido de @origen en @destino
void CopiarCadena(char origen[], char destino[]);

// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Modifica cada caracter de @texto por la suma del caracter + clave
void SumarCaracter(char texto[], unsigned int clave);
void TestEncriptar();

/*
* Precondici�n: @indiceComienzo e @indiceFin son posiciones validas
* dentro de @numeros. @numero es un numero positivo
* Postcondicion: Devuelve la cantidad de numeros en @numeros que son
* multiplos de @numero que se encuentrn desde @indiceComienzo hasta
* @indiceFin en @numeros
*/
int  ContarMultiplos(int numeros[], int numero, int indiceComienzo, int indiceFin);

void MostrarVector(int numeros[], int tope);
void TestContarMultiplos();

int main() {

	TestEncriptar();
	TestContarMultiplos();

	return EXIT_SUCCESS;
}

void TestEncriptar() {
	cout << "Ejercicio 1 - Funcion Encriptar\n\n";

	char texto[] = "AON";
	int clave = 2;
	cout << "Texto:" << texto << " - Clave: " << clave << endl;
	Encriptar(texto, clave);
	cout << "Texto encriptado: " << texto << endl;
}

void Encriptar(char texto[], unsigned int clave) {
	InvertirPalabra(texto);
	SumarCaracter(texto, clave);
}

int ContarCaracteres(char texto[]) {
	int contador = 0;
	for (int i = 0; texto[i] != FinDeCadena; ++i)
		++contador;
	return contador;
}

void InvertirPalabra(char texto[]) {
	int largoTexto = ContarCaracteres(texto);
	char copia[TopeCadena];

	for (int i = 0, j = largoTexto - 1; j >= 0; --j, ++i)
		copia[i] = texto[j];

	copia[largoTexto] = FinDeCadena;
	CopiarCadena(copia, texto);
}

void CopiarCadena(char origen[], char destino[]) {
	int i;
	for (i = 0; origen[i]; ++i)
		destino[i] = origen[i];
	destino[i] = FinDeCadena;
}	

void SumarCaracter(char texto[], unsigned int clave) {
	for (int i = 0; texto[i]; ++i)
		texto[i] = texto[i] + clave;
}

void TestContarMultiplos() {
	cout << "\n------------------------------------------\n\n";
	cout << "Ejercicio 2 - Recursividad\n\n";

	int numeros[] = { 2, 7, 25, 32, 6, 9, 3 };
	int numero = 2;
	cout << "Numeros: ";
	MostrarVector(numeros, IndiceFin);
	cout << "Hay " << ContarMultiplos(numeros, numero, IndiceComienzo, IndiceFin) << " multiplos de " << numero << endl;
}

int ContarMultiplos(int numeros[], int numero, int indiceComienzo, int indiceFin) {
	int multiplos = 0;
	if (indiceComienzo == indiceFin)
		return multiplos;

	if (numeros[indiceComienzo] % numero == 0)
		++multiplos;

	multiplos = multiplos + ContarMultiplos(numeros, numero, indiceComienzo + 1, indiceFin);

	return multiplos;
}

void MostrarVector(int numeros[], int tope) {
	for (int i = 0; i < tope; ++i) {
		cout << numeros[i] << " ";
	}
	cout << endl;
}