#include <iostream>
using namespace std;

// Precondicion: @desde debe ser menor igual que @hasta
// Postcondicion:Devuelve la sumatoria
int obtenerSumatoria(int desde, int hasta);

void TesSumatoriaDeCeroEsCero();

int main(int argc, char const *argv[]) {
    int resultado = obtenerSumatoria(1, 7);
    cout<<resultado<<endl;
    return 0;
}

void TesSumatoriaDeCeroEsCero(){
    //Incializa el contexto de la prueba
    int resultadoEsperado = 0;
    int desde = 0;
    int hasta =0;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"OK"<<endl;
    }else{
        cout<<"Fallo"<<endl;
    }
}

int obtenerSumatoria(int desde, int hasta) {
    return ((desde + hasta) * (hasta - desde + 1) / 2);
}