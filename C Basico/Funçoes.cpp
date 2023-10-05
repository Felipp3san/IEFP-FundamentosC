
#include <iostream>
#include <locale.h>

using namespace std;

bool ePar(int x);
bool eMultiplo10(int x);
int lerNumero0a100();

int main()
{
	setlocale(LC_ALL, "portuguese");

	int numero = lerNumero0a100();

	if (ePar(numero) == true)
	{
		cout << "É par!";
	}
	else {
		cout << "Impar!";
	}

	cout << "\n";

	if (eMultiplo10(numero) == true)
	{
		cout << "Sim, é multiplo de 10";
	}
	else {
		cout << "Nao é multiplo de 10!";
	}

	cout << "\n";

}

bool ePar(int x)
{
	if (x % 2 != 0)
	{
		return false;
	}
	else {
		return true;
	}
}

bool eMultiplo10(int x)
{
	int numero = 10;

	if (x % 10 == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

int lerNumero0a100()
{
	int x = 0;

	do {
		cout << "Introduza um numero de 0 a 100: \n";
		cin >> x;

		if (x > 100 || x < 0)
		{
			cout << "Numero invalido! \n";
		}
	} while (x > 100 || x < 0);

	return x;
}

