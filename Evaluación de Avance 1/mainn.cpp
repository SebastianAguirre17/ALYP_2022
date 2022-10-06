#include <iostream>

using namespace std;

const int PosInicioDeCadena = 0;
const int FinDeCadena = '\0';

/* 
 * Consigna: Implementar la función “ContenidaEnSaltos” que cumpla con la post-condición descrita.
 * Precondicion: @texto y @textoABuscar son cadena de caracteres.
 * Postcondicion: Devuelve true si @textoABuscar se encuentra
 * en texto de manera consecutiva o de a saltos regulares.
 * Varios ejemplos de @texto donde el textoABuscar es "coro"
 * "acoros" -> Lo contiene, el tamano del salto es 0 (comenzando en el indice 1)
 * "caomrgols" -> Lo contiene, el tamano del salto es 1 (comenzando en el indice 0)
 * "ca12olaoraloo" -> Lo contiene, el tamano del salto es 3 (comenzando en el indice 0)
 * "corao" -> No lo contiene, el salto debe ser regular (siempre 0 o siempre 1, es decir: siempre n)
 */
bool ContenidaEnSaltos(char texto[], char textoABuscar[]);

int ContarCaracteres(char texto[]);

/* 
 * Consigna: Implementar la función recursiva “ContieneElemento” que cumpla con la post-condición dada.
 * Precondición: @indiceComienzo e @indiceFin son índices válidos en
 * @elementos
 * Postcondicion: Si @elementoBuscado se encuentra entre la posicion
 * @indiceComienzo e @indiceFin de @elementos devuelve true. Caso
 * contrario devuelve false
 */
bool ContieneElemento(int elementos[], int elementoBuscado, int indiceComienzo, int indiceFin);

int main() {
    cout << "Evaluacion de Avance 2 - Recursividad" << endl << endl;
    
    int v[] = { 0,1,2,3,2,5,4,6 };
    // ContieneElemento(v, 3, 1, 3) ? cout << "Contiene" << endl : cout << "No contiene" << endl;

    cout << "Evaluacion de Avance 2 - Descomposicion Funcional" << endl << endl;

    char buscado[] = "coro";
    char cad1[] = "acoros";
    char cad2[] = "caomrgols";
    char cad3[] = "ca12olaoraloo";
    char cad4[] = "corao";

    ContenidaEnSaltos(cad1, buscado) ? cout << "Encontrado" << endl : cout << "No Encontrado" << endl;
    ContenidaEnSaltos(cad2, buscado) ? cout << "Encontrado" << endl : cout << "No Encontrado" << endl;
    ContenidaEnSaltos(cad3, buscado) ? cout << "Encontrado" << endl : cout << "No Encontrado" << endl;
    ContenidaEnSaltos(cad4, buscado) ? cout << "Encontrado" << endl : cout << "No Encontrado" << endl;


	return EXIT_SUCCESS;
}

bool ContenidaEnSaltos(char texto[], char textoABuscar[]) {
    int lenTexto = ContarCaracteres(texto);
    int lenTextoABuscar = ContarCaracteres(textoABuscar);
    bool result =  lenTexto >= lenTextoABuscar;
    if (result) {
        result = CompararPorSalto(texto, textoABuscar, 0, lenTexto);
    }
    return result;
}

bool CompararPorSalto(char texto[], char textoABuscar[], int salto, int tope) {
    bool result = true;
    for (int i = 0; i < tope and result; ++i) {
        if (texto[i] == textoABuscar[PosInicioDeCadena]) {
            for (int j = i, pos = 0; i < tope and result and texto[j] != FinDeCadena; j += salto, ++pos) {
                if (texto[j] != textoABuscar[pos])
                    result = false;
            }
        }
    }
    return result;
}

bool ContieneElemento(int elementos[], int elementoBuscado, int indiceComienzo, int indiceFin) {
	bool contiene = elementos[indiceComienzo] == elementoBuscado;

    if (not contiene)
        contiene = indiceComienzo == indiceFin ? false : ContieneElemento(elementos, elementoBuscado, indiceComienzo + 1, indiceFin);

	return contiene;
}