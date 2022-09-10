#include <iostream>

using namespace std;

int ObtenerMaximo(int vector[], int indiceComienzo, int indiceFin);

int main() {

    std::cout << "----------------------------------\n"; 
    std::cout << "\tRECURSIVIDAD 2\n"; 
    std::cout << "----------------------------------\n\n"; 

    int numeros[] = {2, 6, 5, 4, 9, 6, 8, 7};
    cout << "Obtener Maximo: " << ObtenerMaximo(numeros, 0, 7) << endl;
    
    std::cout << "\n----------------------------------\n"; 


    return EXIT_SUCCESS;
}

int ObtenerMaximo(int vector[], int indiceComienzo, int indiceFin) {
    if (indiceComienzo == indiceFin)
        return vector[indiceComienzo];

    int maximo = vector[indiceComienzo];
    int proximo = ObtenerMaximo(vector, indiceComienzo + 1, indiceFin);

    return proximo > maximo ? proximo : maximo;
}