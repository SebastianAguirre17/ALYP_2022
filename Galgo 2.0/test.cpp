#include <iostream>
#include "parseo.h"

using namespace std;



int main() {
	ArchivoCsv* autos = Parsear("Fun,Susuki,Negro,IQZ754\nRanger,Ford,Blanco,JVT776");
    Mostrar(autos);

	return 0;
}

