#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;


int multi(int x, int n) {
	
	if (n == 1) {
		return x;
	}
	else if (x == 1) {
		return n;
	}


	return x + multi(x, n-1);

}


string decimalabasefinal(int base, int n) {

	string result = "";
	vector<char> digits = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	while (n > 0) {
		int convert = n % base;
		result = digits[convert] + result;
		n /= base;
	}

	return  result.empty() ? "0" : result;
}

int baseadecimal(int base, int n) {
	int decimal = 0;
	int potencia = 0;

	while (n > 0) {
		int digito = n % 10; 
		decimal += digito * pow(base, potencia);
		n /= 10;
		potencia++;
	}


	return decimal;
}



bool espalindromo(const string& palabra) {
	int left = 0;
	int right = palabra.size() - 1;

	while (left < right) {
		if (palabra[left] != palabra[right]) {
			return false;
		}
		left++;
		right--;

	}
	return true;


}


int main() {
	int eleccion;
	cout << "SELECCIONE EL EJERCICIO" << endl;
	cout << "1. Ejercicio 1" << endl; 
	cout << "2. Ejercicio 2" << endl;
	cout << "3. Ejercicio 3" << endl;
	cin >> eleccion;
	

	if (eleccion == 1) {
		cout << "\033[2J\033[1;1H";

		int n;
		int x;
		cout << "Ingrese el numero a multiplicar" << endl;
		cin >> x; 
		cout << "Ingrese el numero que multiplicara" << endl;
		cin >> n;
		cout << "\033[2J\033[1;1H";
		cout << "El resultado de la multiplicacion " << x << " X " << n << " = " << multi(x, n) << endl;
		
	}
	else if (eleccion == 2) {
		
		ifstream archivo;

		archivo.open("texto.txt", ios::in);

		if (archivo.fail()) {
			cout << "Error al abrir el archivo." << endl;
		}
		vector<string> palabraspalindromas;
		string palabra;

		while (getline(archivo, palabra, ',')) {
			if (espalindromo(palabra)) {
				palabraspalindromas.push_back(palabra);
			}
		}

		archivo.close();

		cout << "Las palabras palindromas encontradas son: " << endl;
		for (const string& palindromo : palabraspalindromas) {
			cout << palindromo << ", ";
		}
		cout << endl;

		cout << "La cantidad de palabras palindromas son: " << palabraspalindromas.size() << endl;
	}
	else if (eleccion == 3) {
		int numero;
		int base;
		int basefinal;

		cout << "Ingrese el numero: " << endl;
		cin >> numero;

		cout << "Ingrese la base del numero: " << endl;
		cin >> base; 

		cout << "Ingrese la base a la que quiere pasar: " << endl;
		cin >> basefinal;

		int num = baseadecimal(base, numero);

		
		cout << "EL numero es: " << decimalabasefinal(basefinal, num)  << endl;




	}

}