// Registos com struct
// Elaborado por Felippe Santana
// 14/09/2023

#include<iostream>
#include<time.h>

using namespace std;

struct registo {
	string nome;
	int idade;
};

void preencherArray(registo registros[]);
void listarArray(registo registros[]);
int gerarValor(int min, int max);

const int TAM_ARRAY = 3;

int main() {
	
	srand(time(NULL));

	registo registros[TAM_ARRAY];

	preencherArray(registros);
	listarArray(registros);

	cout << "\nTamanho do array 'registros' em bytes: " << sizeof(registros) << "\n";

}

void preencherArray(registo registros[]) {
	
	registros[0].nome = "Ana";
	registros[1].nome = "Maria";
	registros[2].nome = "Paulo";

	for (int i = 0; i < TAM_ARRAY; i++)
	{
		registros[i].idade = gerarValor(18, 99);
	}

}

void listarArray(registo registros[]) {

	for (int i = 0; i < TAM_ARRAY; i++)
	{
		cout << registros[i].nome << " " << registros[i].idade << "\n";
	}

}

int gerarValor(int min, int max) {

	int valor;

	valor = min + rand() % (max - min + 1);

	return valor;
}

 
//// Struct
//// 12/09/2023
//// Felippe de almeida santana
//
//#include <iostream>
//using namespace std;
//
//struct ficha {
//    char nome[100];
//    char freguesia[50];
//    int ano;
//    char sexo;
//    string morada;
//};
//
//int main()
//{
//    ficha F;
//    F = { "Ana", "Braga", 2000, 'F', "Rua das flores" };
//
//    strcpy_s(F.nome, "Abel");
//
//    cout << F.nome << "\n";
//    cout << F.freguesia << "\n";
//    cout << F.ano << "\n";
//    cout << F.sexo << "\n";
//    cout << F.morada << "\n";
//
//}
