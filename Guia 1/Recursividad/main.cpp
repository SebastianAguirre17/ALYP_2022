#include <iostream>

using namespace std;

int ObtenerFibonacci(int n);
int ObtenerFactorial(int n);
void MostrarReversa(char cadena[], int indiceComienzo);
bool PuedoLlegarAPlantaBaja(int boton1, int boton2, int piso);
int ObtenerFibonacciGeneralizado(int primerValor, int segundoValor, int n);

int main() {

    std::cout << "----------------------------------\n"; 
    std::cout << "\tRECURSIVIDAD\n"; 
    std::cout << "----------------------------------\n\n"; 

    cout << "Fibonacci de 3: " << ObtenerFibonacci(3) << endl;
    cout << "Fibonacci de 4: " << ObtenerFibonacci(4) << endl;
    cout << "Fibonacci de 5: " << ObtenerFibonacci(5) << endl;

    std::cout << "\n-------------------------\n\n"; 

    cout << "Factorial de 3: " << ObtenerFactorial(3) << endl;
    cout << "Factorial de 4: " << ObtenerFactorial(4) << endl;
    cout << "Factorial de 5: " << ObtenerFactorial(5) << endl;

    std::cout << "\n-------------------------\n\n"; 

    char cadena[] = "Hola Mundo!";
    MostrarReversa(cadena, 0);

    std::cout << "\n\n-------------------------\n\n"; 
    
    cout << "Puedo bajar del 10: ";
    PuedoLlegarAPlantaBaja(3, 4, 10) ? cout << "True" : cout << "False";
    cout << "\nPuedo bajar del 2: ";
    PuedoLlegarAPlantaBaja(3, 4, 2) ? cout << "True" : cout << "False";
    cout << "\nPuedo bajar del 5: ";
    PuedoLlegarAPlantaBaja(3, 4, 5) ? cout << "True" : cout << "False";
    cout << "\nPuedo bajar del 6: ";
    PuedoLlegarAPlantaBaja(3, 4, 6) ? cout << "True" : cout << "False";

    std::cout << "\n\n-------------------------\n\n"; 


    return EXIT_SUCCESS;
}

int ObtenerFibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return ObtenerFibonacci(n - 1) + ObtenerFibonacci(n - 2);
}

int ObtenerFactorial(int n) {
    if (n == 1)
        return 1;
    return n * ObtenerFactorial(n - 1);
}

void MostrarReversa(char cadena[], int indiceComienzo) {
    if (cadena[indiceComienzo] != '\0') {
        MostrarReversa(cadena, indiceComienzo + 1);
        cout << cadena[indiceComienzo];
    }
}

bool PuedoLlegarAPlantaBaja(int boton1, int boton2, int piso) {
    if (piso == 0)
        return true;
    
    bool opcion1, opcion2;
    opcion1 = opcion2 = false;

    if (boton1 <= piso)
        opcion1 = PuedoLlegarAPlantaBaja(boton1, boton2, piso - boton1);

    if (boton2 <= piso)
        opcion2 = PuedoLlegarAPlantaBaja(boton1, boton2, piso - boton2);

    return opcion1 or opcion2;
}

int ObtenerFibonacciGeneralizado(int primerValor, int segundoValor, int n) {
	if (n == 0)
		return primerValor;
	if (n == 1)
		return segundoValor;
        
	return ObtenerFibonacciGeneralizado(primerValor, segundoValor, n-1) + ObtenerFibonacciGeneralizado(primerValor, segundoValor, n-2);
}

