#include <iostream>

using namespace std;

const char FinDeCadena = '\0';

// Precondicion: @textoPrincipal y @textoAEvaluar son 
// cadena de caracteres.
// Postcondicion: Devuelve true si @textoAEvaluar es una 
// rotacion ciclica de @textoPrincipal
bool EsRotacionCiclica(char textoPrincipal[], char textoAEvaluar[]);

int ContarCaracteres(char texto[]);

int main() {
	cout << "Evaluacion de Avance" << endl;

	char amigo[] = "amigo";
	char rot1[] = "goami";
	char rot2[] = "oamig";
	char rot3[] = "igoam";
	char rot4[] = "migoa";
	char rot5[] = "amigo";
	char rot6[] = "amigos";

	EsRotacionCiclica(amigo, rot1) ? cout << "OK" << endl : cout << "ERROR" << endl;
	EsRotacionCiclica(amigo, rot2) ? cout << "OK" << endl : cout << "ERROR" << endl;
	EsRotacionCiclica(amigo, rot3) ? cout << "OK" << endl : cout << "ERROR" << endl;
	EsRotacionCiclica(amigo, rot4) ? cout << "OK" << endl : cout << "ERROR" << endl;
	EsRotacionCiclica(amigo, rot5) ? cout << "OK" << endl : cout << "ERROR" << endl;
	EsRotacionCiclica(amigo, rot6) ? cout << "OK" << endl : cout << "ERROR" << endl;

	return EXIT_SUCCESS;
}

bool EsRotacionCiclica(char textoPrincipal[], char textoAEvaluar[]) {
	bool result = ContarCaracteres(textoPrincipal) == ContarCaracteres(textoAEvaluar);
	if (result) {

	}
	return result;
}

int ContarCaracteres(char texto[]) {
	int contador = 0;
	for (int i = 0; texto[i] != FinDeCadena; ++i)
		++contador;
	return contador;
}

