#include <iostream>
using namespace std;

// Precondicion: 
// Postcondicion:Devuelve la sumatoria
int obtenerSumatoria(int desde, int hasta);

void TestSumatoriaDeCeroEsCero();
void TestSumatoriaModulosIgualesEsCero();
void TestSumatoriaCienElementosNegativos();
void TestSumatoriaCienElementosPositivos();
void TestSumatoriaCienElementosPositivosAPartirDelCien();
void TestSumatoriaDesdeNegativoAUnPositivo();
void TestIncioSumatoriaEsMayorFinSumatoria();
void TestSumatoriaUnSoloElemento();
void TestSumatoriaConBordesPrimos();
void TestSumatoriaImpares();
void EjecutarTestSuite();

int main(int argc, char const *argv[]) {
    EjecutarTestSuite();
    return 0;
}

/*
int obtenerSumatoria(int desde, int hasta) {
    if(desde > hasta) return 0;
    return ((desde + hasta) * (hasta - desde + 1) / 2);
}

int obtenerSumatoria(int desde, int hasta) {
    int sumatoria =0;
    if(desde <= hasta) {
        sumatoria = ((desde + hasta) * (hasta - desde + 1) / 2);
    }

    return sumatoria;
}

 A ? B : C;
*/

// [2,4] = 2 + 3 + 4
// [3,4] = 3 + 4
int obtenerSumatoria(int desde, int hasta) {
    int sumaExtremos = desde + hasta;
    int cantidadElementos = hasta - desde + 1;
    return (desde <= hasta) ? (((sumaExtremos) * (cantidadElementos)) /2 ) : 0;
}

void EjecutarTestSuite(){
    TestSumatoriaDeCeroEsCero();
    TestSumatoriaCienElementosNegativos();
    TestSumatoriaCienElementosPositivos();
    TestSumatoriaCienElementosPositivosAPartirDelCien();
    TestSumatoriaModulosIgualesEsCero();
    TestSumatoriaDesdeNegativoAUnPositivo();
    TestIncioSumatoriaEsMayorFinSumatoria();
    TestSumatoriaUnSoloElemento();
    TestSumatoriaConBordesPrimos();
    TestSumatoriaImpares();
}

void TestSumatoriaImpares(){
    int resultadoEsperado = 309;
    int desde = 102;
    int hasta = 104;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaImpares: OK"<<endl;
    }else{
        cout<<"TestSumatoriaImpares: Fallo"<<endl;
    }
}

void TestIncioSumatoriaEsMayorFinSumatoria(){
    int resultadoEsperado = 0;
    int desde = 50;
    int hasta = 1;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestIncioSumatoriaEsMayorFinSumatoria: OK"<<endl;
    }else{
        cout<<"TestIncioSumatoriaEsMayorFinSumatoria: Fallo"<<endl;
    }
}

void TestSumatoriaDesdeNegativoAUnPositivo(){
    int resultadoEsperado = (-1)*(101 * 50) + (51 * 25) ;
    int desde = -100;
    int hasta = 50;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaDesdeNegativoAUnPositivo: OK"<<endl;
    }else{
        cout<<"TestSumatoriaDesdeNegativoAUnPositivo: Fallo"<<endl;
    }
}

void TestSumatoriaModulosIgualesEsCero(){
    int resultadoEsperado = 0;
    int desde = -89000;
    int hasta = desde * -1;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaModulosIgualesEsCero: OK"<<endl;
    }else{
        cout<<"TestSumatoriaModulosIgualesEsCero: Fallo"<<endl;
    }
}

void TestSumatoriaCienElementosPositivosAPartirDelCien(){
    int resultadoEsperado = (101 + 200) * 50;
    int desde = 101;
    int hasta = 200;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaCienElementosPositivosAPartirDelCien: OK"<<endl;
    }else{
        cout<<"TestSumatoriaCienElementosPositivosAPartirDelCien: Fallo se esperaba: "<<resultadoEsperado<<"se obtuvo: "<<resultadoObtenido<<endl;
    }
}

void TestSumatoriaCienElementosPositivos(){
    int resultadoEsperado = 5050;
    int desde = 1;
    int hasta = 100;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaCienElementosPositivos: OK"<<endl;
    }else{
        cout<<"TestSumatoriaCienElementosPositivos: Fallo"<<endl;
    }
}

void TestSumatoriaCienElementosNegativos(){
    int resultadoEsperado = -5050;
    int desde = -100;
    int hasta = -1;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaPruebaUnitariaElementosNegativos: OK"<<endl;
    }else{
        cout<<"TestSumatoriaPruebaUnitariaElementosNegativos: Fallo"<<endl;
    }
}

void TestSumatoriaDeCeroEsCero(){
    //Incializa el contexto de la prueba
    int resultadoEsperado = 0;
    int desde = 0;
    int hasta =0;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TesSumatoriaDeCeroEsCero: OK"<<endl;
    }else{
        cout<<"TesSumatoriaDeCeroEsCero: Fallo"<<endl;
    }
}

void TestSumatoriaConBordesPrimos(){
        //Incializa el contexto de la prueba
    int resultadoEsperado = 45;
    int desde = 7;
    int hasta =11;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaConBordesPrimos: OK"<<endl;
    }else{
        cout<<"TestSumatoriaConBordesPrimos: Fallo"<<endl;
    }
}

void TestSumatoriaUnSoloElemento(){
    int resultadoEsperado = 66;
    int desde = 66;
    int hasta =66;

    // Ejecutar la prueba
    int resultadoObtenido = obtenerSumatoria(desde, hasta);

    //Oraculo
    if(resultadoEsperado == resultadoObtenido){
        cout<<"TestSumatoriaUnSoloElemento: OK"<<endl;
    }else{
        cout<<"TestSumatoriaUnSoloElemento: Fallo"<<endl;
    }
}