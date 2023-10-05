#include <iostream>
#include <stdlib.h>

using namespace std;

//=====================================

struct listaligada
{
	int numero;
	int qualquercoisa; 
	listaligada* proximo;
};

void menu();
listaligada* inserirLista(listaligada* novo);
bool existeNum(int num);
bool verificarSeEstaOrdenada();
void trocarDoisElementos(int num, int num2);

listaligada* CABECA = NULL; 
listaligada* CAUDA = NULL; 

//======================================
int main()
{
	listaligada* novo; listaligada* atual; listaligada* anterior; listaligada* temp; listaligada* temp2; 
	listaligada* anteriorPrimeiro; listaligada* proximoPrimeiro;
	listaligada* anteriorSegundo; listaligada* proximoSegundo;
	listaligada* endPrimeiro; listaligada* endSegundo;

	char op;
	int contador, num, num2;
	bool estaOrdenada;

	do
	{
		novo = NULL;
		atual = NULL;
		anterior = NULL;
		temp = NULL;
		anteriorPrimeiro = NULL;
		proximoPrimeiro = NULL;
		anteriorSegundo = NULL;
		proximoSegundo = NULL;
		endPrimeiro = NULL;
		endSegundo = NULL;

		contador = 0;

		menu();

		cin >> op;

		switch (op)
		{
		// ----------- 1:LISTAR -----------
		case '1':	

			if (CABECA == NULL)
			{
				cout << "==============================\n";
				cout << "A lista esta vazia.\n";
				cout << "==============================\n";
			}
			else 
			{
				atual = CABECA;

				while ( atual != NULL)
				{
					cout << "==============================\n";
					cout << "NUMERO: " << (*atual).numero << "\n";
					cout << "QUALQUER COISA: " << (*atual).qualquercoisa << "\n";
					cout << "PROXIMO: " << (*atual).proximo << "\n";
					cout << "==============================\n";

					atual = (*atual).proximo;
				}
			}

			system("pause");

		break;
		// ---------- 2:INSERE PRIMEIRO -----------
		case '2':

			novo = inserirLista(novo);

			if (CABECA == NULL) {
				CABECA = novo;
				CAUDA = novo;
				(*novo).proximo = NULL;
			}
			else 
			{
				(*novo).proximo = CABECA;
				CABECA = novo;
			}

		break;
		// ----------- 3:INSERE NO FIM -----------
		case '3':
			novo = inserirLista(novo);

			(*novo).proximo = NULL;

			if (CABECA == NULL) {
				CABECA = novo;
				CAUDA = novo;
			}
			else
			{
				(*CAUDA).proximo = novo;
				CAUDA = novo;
			}

		break;
		// ----------- 4:INSERE AO MEIO -----------
		case '4':
			novo = inserirLista(novo);

			if (CABECA == NULL) {
				CABECA = novo;
				CAUDA = novo;
				(*novo).proximo = NULL;
			}
			else {
				anterior = CABECA;
				atual = (*anterior).proximo;

				while (atual != NULL)
				{
					if ((*novo).numero >= (*anterior).numero && (*novo).numero <= (*atual).numero)
					{
						(*novo).proximo = atual;
						(*anterior).proximo = novo;
					}

					anterior = atual;
					atual = (*anterior).proximo;
				}
			}

		break;
		// ----------- 5:INSERE COMPLETO -----------
		case '5' :

			novo = inserirLista(novo);

			// INICIALIZAR CASO VAZIO
			if (CABECA == NULL) {
				CABECA = novo;
				CAUDA = novo;
				(*novo).proximo = NULL;
			}
			else {
				// ADICIONAR AO INICIO
				if ((*novo).numero < (*CABECA).numero)
				{
					(*novo).proximo = CABECA;
					CABECA = novo;
				}
				// ADICIONAR AO FIM
				else if ((*novo).numero > (*CAUDA).numero) 
				{
					(*novo).proximo = NULL;
					(*CAUDA).proximo = novo;
					CAUDA = novo;
				}
				// ADICIONAR AO MEIO
				else 
				{
					anterior = CABECA;
					atual = (*anterior).proximo;

					while (atual != NULL)
					{
						if ((*novo).numero >= (*anterior).numero && (*novo).numero <= (*atual).numero)
						{
							(*novo).proximo = atual;
							(*anterior).proximo = novo;
						}

						anterior = atual;
						atual = (*anterior).proximo;
					}
				}
			}
		break;
		// ----------- 6:REMOVE CABECA -----------
		case '6':

			atual = (*CABECA).proximo;  // salva nó seguinte em atual.

			free(CABECA);
			CABECA = atual;   // nó seguinte se torna a cabeca.

		break;
		// ----------- 7:REMOVE CAUDA -----------
		case '7':	

			atual = CABECA;

			while (atual != CAUDA)  // percorre a lista até encontrar CAUDA e salva em atual
			{
				anterior = atual;   // salva o anterior de atual
				atual = (*atual).proximo;
			}

			free(CAUDA);

			CAUDA = anterior;    // anterior se torna a cauda
			(*anterior).proximo = NULL;   // proximo de anterior se torna nulo

		break;
		// ----------- 8:REMOVE AO MEIO -----------
		case '8':

			cout << "Insira a posicao que deseja remover: ";
			cin >> num;

			atual = CABECA;
			
			if (existeNum(num))      // verifica se o numero existe na lista.
			{
				while (atual != NULL)   // percorre a lista para encontrar o numero (ate atual se tornar nulo)
				{
					if (num == (*atual).numero)   // se encontrar o numero...
					{
						(*anterior).proximo = (*atual).proximo;
						free(atual);
						atual = NULL;   // atual se torna nulo para encerrar o ciclo.
					}
					else   // se não encontrar, pula para proximo elemento.
					{
						anterior = atual;
						atual = (*atual).proximo;
					}
				}
			}
			else
			{
				cout << "\nA posicao informada nao existe na lista.\n\n";
				system("pause");
			}
		break;
		// ----------- 9:REMOVE COMPLETO -----------
		case '9':

			cout << "Insira a posicao que deseja remover: ";
			cin >> num;

			if (existeNum(num))
			{
				if (num == (*CABECA).numero)
				{
					atual = (*CABECA).proximo;  // salva nó seguinte em atual.

					free(CABECA);
					CABECA = atual;
				}

				else if (num == (*CAUDA).numero)
				{
					atual = CABECA;

					while (atual != CAUDA)
					{
						anterior = atual;
						atual = (*atual).proximo;
					}

					free(CAUDA);

					CAUDA = anterior;
					(*CAUDA).proximo = NULL;
				}
				else 
				{
					atual = CABECA;

					while (atual != NULL)
					{
						if (num == (*atual).numero)
						{
							(*anterior).proximo = (*atual).proximo;
							free(atual);
							atual = NULL;
						}
						else
						{
							anterior = atual;
							atual = (*atual).proximo;
						}
					}
				}
			}
			else
			{
				cout << "\nA posicao informada nao existe na lista.\n\n";
				system("pause");
			}

		break;
		// ----------- a:LIMPA LISTA -----------
		case 'a':
			
			atual = CABECA;

			while (atual != NULL)
			{
				anterior = atual;
				atual = (*atual).proximo;

				free(anterior);
			}

			CABECA = NULL;
			CAUDA = NULL;

		break;
		// ----------- b:INICIALIZA COM 3 NOS "FIXOS" -----------
		case 'b':

			for (int i = 0; i < 3; i++)   // ciclo com 3 repetições para inicializar a lista com 3 elementos
			{

				// cria um novo elemento com numero e qualquer coisa diferente do anterior.
				novo = (listaligada*)malloc(sizeof(listaligada));

				(*novo).numero = i + 1;
				(*novo).qualquercoisa = 123 * i;
				// ======================================================================

				if (i == 0)   // se o ciclo estiver na primeira execução.  
				{
					CABECA = novo;  // primeiro elemento se torna CABECA.
				} 
				else if (i == 1)   // se o ciclo estiver na segunda execução.  
				{
					(*CABECA).proximo = novo;  // segundo elemento se torna proximo de CABECA.
				}
				else  // se o ciclo estiver na terceira execução.  
				{
					(*(*CABECA).proximo).proximo = novo;   // terceiro elemento se torna proximo do segundo elemento.
					(*novo).proximo = NULL;   // proximo do terceiro elemento se torna nulo.
					CAUDA = novo;  // terceiro elemento se torna cauda.
				}
			}
		break;
		// ----------- c:LISTA ORDENADA? SIM/NAO -----------
		case 'c':

			estaOrdenada = true;    // estaOrdenada começa como true

			anterior = CABECA;       // salva primeiro nó em anterior
			atual = (*CABECA).proximo;      // salva segundo nó em atual

			if ((*atual).numero > (*anterior).numero)    // se o numero do primeiro for menor que o numero do segundo ( ordem crescente )
			{
				while (atual != NULL)   // ciclo até atual se tornar nulo
				{
					if ((*atual).numero < (*anterior).numero)   // se encontrar algum numero menor que o anterior, a lista não está ordenada
					{
						estaOrdenada = false;
					}

					anterior = atual;   // anterior avança 1 a frente 
					atual = (*atual).proximo;  // atual avança 1 a frente
				}
			}

			else   // se o numero do primeiro for maior que o numero do segundo ( ordem decrescente )
			{
				while (atual != NULL)  // ciclo até atual se tornar nulo
				{
					if ((*atual).numero > (*anterior).numero)  // se encontrar algum numero maior que o anterior, a lista não está ordenada
					{
						estaOrdenada = false;
					}

					anterior = atual;    // anterior avança 1 a frente 
					atual = (*atual).proximo;   // atual avança 1 a frente
				}
			}

			if (estaOrdenada)    // se estiver ordenada. 
			{
				cout << "\nA lista esta ordenada!\n\n";
				system("pause");
			}
			else  // se não estiver ordenada.
			{
				cout << "\nA lista nao esta ordenada.\n\n";
				system("pause");
			}

		break;
		// ----------- d:ORDENA LISTA -----------
		case 'd':

			while (verificarSeEstaOrdenada() == false)
			{
				anterior = CABECA;
				atual = (*CABECA).proximo;

				while (atual != NULL)
				{
					if ((*atual).numero < (*anterior).numero)
					{
						trocarDoisElementos((*atual).numero, (*anterior).numero);
					}

					anterior = atual;
					atual = (*atual).proximo;
				}
			}

		break;
		//----------- e:CONTA NOS -----------
		case 'e':		

			atual = CABECA;

			while (atual != NULL)
			{
				contador++;
				atual = (*atual).proximo;
			}
			
			cout << "\nA lista possui " << contador << " nos.\n\n";
			system("pause");
		break;
		// ----------- f:LER 2 NUMS; EXISTEM? TROCAR NOS -----------
		case 'f':		

			cout << "\nInforme a primeira posicao que deseja trocar: ";
			cin >> num;
			cout << "\nInforme a segunda posicao que deseja trocar: ";
			cin >> num2;

			if (existeNum(num) && existeNum(num2))  // caso os dois numeros existam
			{ 

				// BUSCA

				anterior = NULL;
				atual = CABECA;

				//primeiro elemento da lista
				while (atual != NULL)  // percorrer lista até atual se tornar nulo
				{
					// o primeiro NUM que for for encontrado na lista, permanece como primeiro na troca
					if ((*atual).numero == num || (*atual).numero == num2) 
					{

						anteriorPrimeiro = anterior;
						endPrimeiro = atual;
						proximoPrimeiro = (*atual).proximo;

						atual = NULL;
					}
					else
					{
						anterior = atual;           // pula para a proxima posição
						atual = (*atual).proximo;
					}
				}

				// procura o segundo elemento, partindo do primeiro encontrado.
				anterior = endPrimeiro;
				atual = (*endPrimeiro).proximo;

				// o elemento a ser encontrado pode ser num ou num2
				while ((*atual).numero != num2 && (*atual).numero != num)
				{
					anterior = atual;           // pula para a proxima posição
					atual = (*atual).proximo;
				}

				//TROCA

				// CAUDA
				if (atual == CAUDA)
				{
					CAUDA = endPrimeiro;
				}

				// contiguos
				if ((*endPrimeiro).proximo == atual )
				{
					if (endPrimeiro == CABECA)
					{
						CABECA = atual;
					}
					else
					{
						(*anteriorPrimeiro).proximo = atual;
					}
					(*endPrimeiro).proximo = (*atual).proximo;
					(*atual).proximo = endPrimeiro;

				}
				// não contiguos
				else
				{
					if (endPrimeiro == CABECA)
					{
						CABECA = atual;
					}
					else
					{
						(*anteriorPrimeiro).proximo = atual;
					}
					(*endPrimeiro).proximo = (*atual).proximo;
					(*anterior).proximo = endPrimeiro;
					(*atual).proximo = proximoPrimeiro;
				}
			}
			else
			{
				cout << "\nA primeira posicao informada nao existe.\n\n";
				system("pause");
			}

		break;
		// ----------- g:INVERTER A LISTA -----------
		case 'g':

			atual = CABECA;
			temp = (*atual).proximo;    // salva o elemento seguinte a CABECA

			while (temp != NULL)    // percorre lista até temp se tornar nulo
			{
				(*atual).proximo = anterior;      // faz o proximo de atual apontar para o anterior

				anterior = atual;     // anterior se torna atual
				atual = temp;    // atual se torna proximo
				temp = (*atual).proximo;    // temp se torna proximo de atual
			}

			(*atual).proximo = anterior;    // chegou até a cauda, proximo de cauda se torna o anterior
			CAUDA = CABECA;     // cabeca se torna cauda
			CABECA = atual;    // atual se torna cabeca

		break;
		//
		case 'z':

			if (CABECA != NULL)
			{
				cout << "========= CABECA =============\n";
				cout << "NUMERO: " << (*CABECA).numero << "\n";
				cout << "PROXIMO: " << (*CABECA).proximo << "\n";
				cout << "==============================\n";

				cout << "========= CAUDA ==============\n";
				cout << "NUMERO: " << (*CAUDA).numero << "\n";
				cout << "PROXIMO: " << (*CAUDA).proximo << "\n";
				cout << "==============================\n";
			}
			else
			{
				cout << "\n-- CABECA/CAUDA vazia --\n" << endl;
			}

			system("pause");

		break;
		// ----------- H:INVERTER A LISTA -----------
		case 'H':
			cout << "\n\nEXERCICIO PRATICO COM LISTA LIGADA\nO objetivo e elaborar as opcoes 5 e 9.\nPara isso, comecar pelas mais simples:\n"
				<< "Exemplo: 2->3->4->5\n"
				<< "Sera pedido que alguns formandos facam as opcionais, para no final \njuntar tudo e o exercicio ficar completo."
				<< "\nNesse caso: respeitar a organizacao do codigo, nao usar funcoes, \ncomentar todas a linhas relevantes, identificar autor e data.\nObrigado. :)\n\n";

		break;
		// ----------- 0:SAIR -----------
		case '0':
			cout	<< "\n fim do programa...\n";
		break;
		// ----------- DEFAULT -----------
		default:
			cout << "\7"; //beep do sistema
		break;
		}	
	} while (op != '0');
}

void trocarDoisElementos(int num, int num2) {

	listaligada* anterior; listaligada* atual;
	listaligada* endPrimeiro; listaligada* anteriorPrimeiro; listaligada* proximoPrimeiro;
	listaligada* endSegundo; listaligada* anteriorSegundo; listaligada* proximoSegundo;
	
	// Inicialização

	endPrimeiro = NULL;
	anteriorPrimeiro = NULL;
	proximoPrimeiro = NULL;

	endSegundo = NULL;
	anteriorSegundo = NULL;
	proximoSegundo = NULL;

	// Busca

	anterior = NULL;
	atual = CABECA;

	while (atual != NULL)  // percorrer lista até atual se tornar nulo
	{
		if ((*atual).numero == num || (*atual).numero == num2)
		{
			if (endPrimeiro == NULL)
			{
				anteriorPrimeiro = anterior;
				endPrimeiro = atual;
				proximoPrimeiro = (*atual).proximo;
			}
			else
			{
				anteriorSegundo = anterior;
				endSegundo = atual;
				proximoSegundo = (*atual).proximo;
			}

		}
		
		anterior = atual;           // pula para a proxima posição
		atual = (*atual).proximo;
	}

	// Troca

	// Se um dos elementos for CAUDA
	if (endSegundo == CAUDA)
	{
		CAUDA = endPrimeiro;
	}

	// Se contiguos...
	if ((*endPrimeiro).proximo == endSegundo)
	{
		if (endPrimeiro == CABECA)
		{
			CABECA = endSegundo;
		}
		else
		{
			(*anteriorPrimeiro).proximo = endSegundo;
		}

		(*endPrimeiro).proximo = (*endSegundo).proximo;
		(*endSegundo).proximo = endPrimeiro;
	}
	// não contiguos..
	else
	{
		if (endPrimeiro == CABECA)
		{
			CABECA = endSegundo;
		}
		else
		{
			(*anteriorPrimeiro).proximo = endSegundo;
		}

		(*endPrimeiro).proximo = (*endSegundo).proximo;
		(*anteriorSegundo).proximo = endPrimeiro;
		(*endSegundo).proximo = proximoPrimeiro;
	}
}

bool verificarSeEstaOrdenada() {

	listaligada* anterior; listaligada* atual;

	bool listaOrdenada = true;    // listaOrdenada inicializada com true

	anterior = CABECA;       // salva primeiro nó em anterior
	atual = (*CABECA).proximo;      // salva segundo nó em atual

	while (atual != NULL)   // ciclo até atual se tornar nulo
	{
		if ((*atual).numero < (*anterior).numero)   // se encontrar algum numero menor que o anterior, a lista não está ordenada
		{
			listaOrdenada = false;
		}

		anterior = atual;   // anterior avança 1 a frente 
		atual = (*atual).proximo;  // atual avança 1 a frente
	}

	return listaOrdenada;
}

bool existeNum(int num) {

	listaligada* temp = CABECA;

	while (temp != NULL)
	{
		if (num == (*temp).numero) {
			return true;
		}
		else {
			temp = (*temp).proximo;
		}
	}

	return false;
}

listaligada* inserirLista(listaligada* novo){

	int n, qqc; 

	cout << "Indique a posicao(numero): ";
	cin >> n;
	cout << "Indique o valor(qualquer coisa): ";
	cin >> qqc;

	novo = (listaligada*)malloc(sizeof(listaligada));
	(*novo).numero = n;
	(*novo).qualquercoisa = qqc;

	return novo;
}

void menu(){
	system("cls");
	cout << "====================== LISTA LIGADA ======================\n";
	cout << "[1:listar]\n[2:insere primeiro][3:insere no fim][4:insere ao meio][5:INSERE(completo)]" << "\n"
		<< "[6:remove cabeca][7:remove cauda][8:remove ao meio][9:REMOVE (completo)]\n"
		<< "[a:limpa lista][b:init lista com 3 nos][c:lista ordenada? (sim/nao)][d:ordena lista][e:conta nos]\n"
		<< "[f:ler 2 nums; trocar os nos][g:inverter a lista] [H: ler isto, por favor]\n"
		<< "[z:mostrar CABECA-CAUDA]\n[0:SAIR]\n"
		<< "Op?"; 
}