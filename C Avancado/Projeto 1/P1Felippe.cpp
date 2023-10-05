#include <iostream>
#include <conio.h>

using namespace std;

struct Viagem {
	int numeroViagem;
	string marcaCarro;
	int quilometragem;
};

void inicializar();
void inicializarCom3();
void listar();
int somarQuilometragens();
void trocarViagens();
void menu();

Viagem viagens[10];

int main() {

	char op;

	do
	{
		menu();

		op = _getch();

		switch (op)
		{
		case '1':
			inicializar();
			inicializarCom3();
			break;
		case '2':
			listar();
			system("pause");
			break;
		case '3':
			cout << "\n\nA quilometragem total das viagens: " << somarQuilometragens() <<"kms" << "\n\n";
			system("pause");
			break;
		case '4': 
			break;
		case '5':
			trocarViagens();
			cout << "\nTroca efetuada!!!\n\n";
			system("pause");
			break;
		case 27:
			cout << "\nPrograma encerrado.\n";
			break;
		default:
			cout << "\nOpcao invalida!\n";
			system("pause");
			break;
		}


	} while ( op != 27 );

}

void inicializar() {
	for (int i = 0; i < 10; i++)
	{
		viagens[i].numeroViagem = 0;
		viagens[i].marcaCarro = '#';
		viagens[i].quilometragem = 0;
	}

}

void inicializarCom3() {

	viagens[0].numeroViagem = 11;
	viagens[0].marcaCarro = "Honda";
	viagens[0].quilometragem = 11;

	viagens[1].numeroViagem = 77;
	viagens[1].marcaCarro = "Ford";
	viagens[1].quilometragem = 43;

	viagens[2].numeroViagem = 99;
	viagens[2].marcaCarro = "Hyundai";
	viagens[2].quilometragem = 5;

}

void listar() {
	
	cout << "\n\n";

	for (int i = 0; i < 10; i++)
	{
		if (viagens[i].numeroViagem != 0)
		{
			cout << "Viagem " << i + 1 << "\n";
			cout << "Numero da viagem: " << viagens[i].numeroViagem << "\n";
			cout << "Marca do veiculo: " << viagens[i].marcaCarro << "\n";
			cout << "Quilometragem: " << viagens[i].quilometragem << "\n";
			cout << "============================================\n\n";
		}
	
	}
}

int somarQuilometragens() {

	int quilometragemTotal = 0;

	for (int i = 0; i < 10; i++)
	{
		quilometragemTotal += viagens[i].quilometragem;
	}
	return quilometragemTotal;
}

void trocarViagens() {
	
	int numViagem1, numViagem2;
	int posViagem1, posViagem2;
	Viagem temp;

	cout << "\n\nInforme o numero da primeira viagem para troca: ";
	cin >> numViagem1;

	cout << "Informe o numero da segunda viagem para troca: ";
	cin >> numViagem2;

	for (int i = 0; i < 10; i++)
	{
		if (numViagem1 == viagens[i].numeroViagem)
		{
			posViagem1 = i;
		}

		if (numViagem2 == viagens[i].numeroViagem)
		{
			posViagem2 = i;
		}
	}

	temp = viagens[posViagem1];
	viagens[posViagem1] = viagens[posViagem2];
	viagens[posViagem2] = temp;
}

void menu() {
	system("cls");
	cout << "============== MENU ==============\n";
	cout << "Opcao 1 - Inicializar contentor\n";
	cout << "Opcao 2 - Listar contentor\n";
	cout << "Opcao 3 - Somar quilometragens\n";
	cout << "Opcao 4 - ##############\n";
	cout << "Opcao 5 - Trocar viagens\n";
	cout << "ESC para sair. \n";
	cout << "\nEscolha uma opcao: ";
}