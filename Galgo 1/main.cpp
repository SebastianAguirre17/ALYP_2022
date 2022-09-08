#include <iostream>
#include "langford.h"
using namespace std;

/*
 * Precondicion: @secuenciaNumeros es un array de tama�o igual al doble del parametro @n
 * Postcondicion: Devuelve true si @secuenciaNumeros es un patron de Langford caso contrario devuelve false.
 * Es decir que debe validar las doscondiciones del patron de Langford: los elementos presentes (que sean los determinados por 2N) y la posicion en donde se encuentran
 * Ejemplo 1:
 * Al invocarse con EsSecuenciaLangford([2,1,1,3], 2)
 * No cumple las validaciones respecto de los elementos presentes en @secuenciaNumeros. Para que cumpla esta validacion se esperaria que en lugar del 3 este el 2.
 * Por lo tanto devuelve false.
 *
 * Ejemplo 2:
 * Al invocarse con EsSecuenciaLangford([2,1,1,2], 2)
 * Cumple con las validaciones respecto de los elementos presentes en @secuenciaNumeros (hay dos de cada uno).
 * No cumple con la validacion respecto del orden de la secuencia.
 *
 * Ejemplo 3:
 * Al invocarse con EsSecuenciaLangford([2 3 1 2 1 3], 3)
 * Cumple con todas las validaciones
 *
 */
bool EsSecuenciaLangford(int secuenciaNumeros[], unsigned int n);

/* Pruebas unitarias */
void EjecutarPruebasUnitarias();
void TestEjemplo1();
void TestEjemplo2();
void TestEjemplo3();
void TestLangford7A();
void TestLangford7B();
void TestLangford8A();
void TestLangford8B();
void TestLangford16();

/* Funciones auxiliares de las pruebas unitarias*/
void Mostrar(bool value);
void MostrarResultado(bool valorObtenido, bool valorEsperado, char nombreFuncion[]);

int main() {
	EjecutarPruebasUnitarias();
	return 0;
}

bool EsSecuenciaLangford(int secuenciaNumeros[], int n) {

}

void Mostrar(bool value){
	if(value){
		cout<<"[True]";
	}
	else{
		cout<<"[False]";
	}

}

void MostrarResultado(bool valorObtenido, bool valorEsperado, char nombreFuncion[])
{
	if(valorObtenido == valorEsperado)
	{
		cout<<nombreFuncion<<": OK."<<endl;
	}
	else
	{
		cout<<nombreFuncion<<": Error. Se esperaba obtener ";
		Mostrar(valorEsperado);
		cout<<" se obtuvo ";
		Mostrar(valorObtenido);
		cout<<endl;
	}
}

void TestEjemplo1()
{
	int n = 2;
	int secuencia[]={2,1,1,3};
	bool valorEsperado = false;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo1");
}

void TestEjemplo2()
{
	int n = 2;
	int secuencia[]={2,1,1,2};
	bool valorEsperado = false;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo2");
}

void TestEjemplo3()
{
	int n = 3;
	int secuencia[]={2,3,1,2,1,3};
	bool valorEsperado = true;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestEjemplo3");
}

void TestLangford7A()
{
	int n = 7;
	int secuencia[]={2,6,3,2,7,4,3,5,6,1,4,1,7,5};
	bool valorEsperado = true;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestLangford7A");
}

void TestLangford7B()
{
	int n = 7;
	int secuencia[]={5,2,6,4,2,7,5,3,4,6,1,3,1,7};
	bool valorEsperado = true;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestLangford7B");
}

void TestLangford8A()
{
	int n = 8;
	int secuencia[]={1,5,1,7,3,8,6,5,3,2,4,7,2,6,8,4};
	bool valorEsperado = true;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestLangford8A");
}

void TestLangford8B()
{
	int n = 8;
	int secuencia[]={1,7,1,3,8,4,5,3,6,7,4,2,5,8,2,6};
	bool valorEsperado = true;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestLangford8B");
}

void TestLangford16()
{
	int n = 16;
	int secuencia[]={16,6,9,15,2,3,8,2,6,3,13,10,9,12,14,8,11,16,1,15,1,5,10,7,13,4,12,5,11,14,4,7};
	bool valorEsperado = true;

	bool valorObtenido = EsSecuenciaLangford(secuencia, n);

	MostrarResultado(valorObtenido, valorEsperado, "TestLangford16");
}

void EjecutarPruebasUnitarias()
{
	TestEjemplo1();
	TestEjemplo2();
	TestEjemplo3();
	TestLangford7A();
	TestLangford7B();
	TestLangford8A();
	TestLangford8B();
	TestLangford16();
}

