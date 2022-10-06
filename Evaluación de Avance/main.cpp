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
	char goami[] = "goami";

	char caracas[] = "caracas";
	char caracasCopy[] = "racasapa";

	EsRotacionCiclica(amigo, goami) ? cout << "OK" << endl : cout << "ERROR" << endl;
	EsRotacionCiclica(caracas, caracasCopy) ? cout << "OK" << endl : cout << "ERROR" << endl;

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