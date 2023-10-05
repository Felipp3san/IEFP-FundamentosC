
#include <iostream>
#include <vector> //para usar o container 
using namespace std;

void listarVector();

int i, n;
vector <int>::iterator it; // iterador para vector de inteiros
vector <int> lista{ 11, 12, 13, 14, 15 };

int main()
{

	cout << "\nA------------------------------------------" << endl << "\t";

	listarVector();

	cout << "\nB------------------------------------------" << endl << "\t";

	n = 101;
	lista.push_back(n);
	listarVector();

	cout << "\nC------------------------------------------" << endl << "\t";
	
	n = 102;
	lista.push_back(n);
	cout << "A lista agora tem " << lista.size() << " elementos.";

	cout << "\nD------------------------------------------" << endl << "\t";
	
	n = 99;
	lista.push_back(n);
	lista.push_back(n);
	lista.push_back(n);
	listarVector();

	cout << "\nE------------------------------------------" << endl << "\t";

	lista.pop_back();  // LIFO - Last In First Out
	listarVector();

	cout << "\nF------------------------------------------" << endl << "\t";

	n = 400;
	lista.push_back(n);
	listarVector();

	it = lista.begin();
	cout << "\n\nO primeiro da lista " << *it;
	cout << "\nO primeiro esta na posicao de memoria " << &it << endl;

	it = lista.end() - 1;
	cout << "\nO ultimo da lista " << *it;
	cout << "\nO ultimo esta na posicao de memoria " << &it << endl;

	lista.clear();
	cout << "A lista agora possui " << lista.size() << " elementos\n";
}

void listarVector() {
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << " ";
	}
}
