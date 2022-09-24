#include <iostream>
#include "parseo.h"

using namespace std;



int main() {
	char texto[] = "cinco,name,pep,defender_king";
    const char* pTexto = texto;

    char textoCopiado[10];

    CopiarCampo(2, texto, ',', textoCopiado);

    cout << "Copia: " << textoCopiado << endl;


	return 0;
}


