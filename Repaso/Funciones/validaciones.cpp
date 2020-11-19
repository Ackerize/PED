#include <iostream>
#include <regex>

using namespace std;

string onlyString(){
	string input;
  while(true){
		cout << "Ingrese una palabra: ";
 		getline(cin, input);
		if(regex_match (input, regex("^[a-zA-Z ]*$") )){
			return input;
		}
	}
}

int onlyInteger(){
	string input;
  while(true){
		cout << "Ingrese un entero: ";
 		cin >> input;
		if(regex_match (input, regex("^[0-9]*$") )){
			return atoi(&input[0]);
		}
	}
}

float onlyNumber(){
	string input;
  while(true){
		cout << "Ingrese un numero: ";
 		cin >> input;
		if(regex_match (input, regex("[+-]?([0-9]*[.])?[0-9]+") )){
			return atof(&input[0]);
		}
	}
}

int main() {
	//string palabraCorrecta = onlyString();
	//int enteroCorrecto = onlyInteger();
	float numeroCorrecto = onlyNumber();
  //cout << "La palabra es: " << palabraCorrecta << endl;
	//cout << "El entero es: " << enteroCorrecto << endl;
	cout << "El numero es: " << numeroCorrecto << endl;
}
