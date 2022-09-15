#include <iostream>
using namespace std;

bool ExisteSecuenciaLangfordParaN(unsigned int n) {
	return (n % 4) == 0 or (n % 4) == 3;
}

int main() {

	cout << ExisteSecuenciaLangfordParaN(0) << endl; 
	cout << ExisteSecuenciaLangfordParaN(5) << endl; 
	cout << ExisteSecuenciaLangfordParaN(3) << endl; 
	cout << ExisteSecuenciaLangfordParaN(4) << endl; 
	cout << ExisteSecuenciaLangfordParaN(7) << endl; 

	return 0;
}
