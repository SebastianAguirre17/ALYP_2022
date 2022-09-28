#include <iostream>
using namespace std;

// Convenciones de nombramiento
// 1 - Pascal camel case
//   A) lowerCase -> cuboMagico
//   B) UpperCase -> CuboMagico
// 2 - Notacion hungara
   // change_number, release_number

// Nombrar structuras, Constantes, Funciones: Pascal UpperCamelCase
// Nombrar Variables, parametros de funcionees: Pascal lowerCamelCase

struct Version
{
	int versionNumber;
	int releaseNumber;
	int changeNumber;
};

// Precondiciones:
// Postcondiciones:
void Inicializar(Version& version);

//Pre-condici�n: -
//Post-condici�n: incrementa en uno el versionNumber de la version
void Commit(Version& version);

//Pre-condici�n: -
//Post-condici�n: incrementa en uno el release_number del artefacto
void Release(Version& version);

//Pre-condici�n: -
//Post-condici�n: incrementa en uno el version_number del artefacto
void NewVersion(Version& version);

int main() {
	Version versionUnProducto;
	Inicializar(versionUnProducto);
}

void Inicializar(Version& version) {
	version.changeNumber = 0;
	version.releaseNumber = 0;
	version.versionNumber = 0;
}

//Pre-condici�n: -
//Post-condici�n: incrementa en uno el change_number del artefacto
void Commit(Version& version) {
	version.changeNumber++;
}

//Pre-condici�n: -
//Post-condici�n: incrementa en uno el release_number del artefacto
void Release(Version& version) {
	version.releaseNumber++;
}

//Pre-condici�n: -
//Post-condici�n: incrementa en uno el version_number del artefacto
void NewVersion(Version& version) {
	version.versionNumber++;
}
