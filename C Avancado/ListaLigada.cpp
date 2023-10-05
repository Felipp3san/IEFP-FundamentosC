#include <iostream>
#include <stdlib.h>
using namespace std;

//========= TIPOS =========

struct listaligada
{
	int numero;
	int qualquercoisa; 
	listaligada* proximo;
};

//========= FUNÇÕES =========

void trocarDoisElementos(int num, int num2);
bool verificarSeListaEstaOrdenada();
bool verificarSePosicaoExiste(int num);
void menu();
void pause();
void clear();

//========= GLOBAIS =========

listaligada* CABECA = NULL; 
listaligada* CAUDA = NULL; 

//========== MAIN ==========
int main() {
  
	listaligada* novo; listaligada* atual; listaligada* anterior; listaligada* temp;

	char op;
	int contador, num, num2, qqc;

	do
	{

		menu();
		cin >> op;
		
		switch (op)
		{
			novo = NULL;
			atual = NULL;
			anterior = NULL;
			temp = NULL;

			// ----------- LISTAR -----------
			case '1':	

				if (CABECA == NULL)
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}
				else 
				{
					atual = CABECA;

					cout << "\n============ LISTAR ============\n";
					while ( atual != NULL)
					{
						cout << "\n================================\n";
						cout << "NÚMERO: " << (*atual).numero << "\n";
						cout << "QUALQUER COISA: " << (*atual).qualquercoisa << "\n";
						cout << "PRÓXIMO: " << (*atual).proximo;
						cout << "\n================================\n";

						atual = (*atual).proximo;
					}
				}

				pause();

			break;
			// ----------- INSERIR NA LISTA -----------
			case '2' :

				cout << "\n============ INSERIR ============\n\n";
				cout << "Informe a posição(número): ";
				cin >> num;
				cout << "Indique o valor(qualquer coisa): ";
				cin >> qqc;

				novo = (listaligada*)malloc(sizeof(listaligada));
				(*novo).numero = num;
				(*novo).qualquercoisa = qqc;

				// INICIALIZAR CASO LISTA VAZIA
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

				cout << "\n=================================\n";
				cout << "O elemento foi inserido na lista!";
				cout << "\n=================================\n";

				pause();

			break;
			// ----------- REMOVE COMPLETO -----------
			case '3':

				if (CABECA != NULL)
				{
					cout << "\n============ REMOVER ============\n\n";
					cout << "Informe a posição que deseja remover: ";
					cin >> num;

					if (verificarSePosicaoExiste(num))
					{
						if (num == (*CABECA).numero)
						{
							atual = (*CABECA).proximo; 

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

						cout << "\n=================================\n";
						cout << "O elemento foi removido da lista.";
						cout << "\n=================================\n";
					}
					else
					{
						cout << "\n========================================\n";
						cout << "A posição informada não existe na lista.";
						cout << "\n========================================\n";
					}
				}
				else
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}

				pause();
				
			break;
			// ----------- LIMPAR LISTA -----------
			case 'a': case 'A':
				
				if (CABECA != NULL)
				{
					atual = CABECA;

					while (atual != NULL)
					{
						anterior = atual;
						atual = (*atual).proximo;

						free(anterior);
					}

					CABECA = NULL;
					CAUDA = NULL;	

					cout << "\n==================================\n";
					cout << "\tA lista foi limpa!";
					cout << "\n==================================\n";
				}
				else
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}

				pause();
			
			break;
			// ----------- INICIALIZA COM 3 NÓS -----------
			case 'b': case 'B':

				if (CABECA == NULL)
				{
					for (int i = 0; i < 3; i++)   
					{
						novo = (listaligada*)malloc(sizeof(listaligada));
						(*novo).numero = i + 1;
						(*novo).qualquercoisa = 123 * i;

						if (i == 0)   
						{
							CABECA = novo;  
						} 
						else if (i == 1)    
						{
							(*CABECA).proximo = novo;  
						}
						else 
						{
							(*(*CABECA).proximo).proximo = novo;   
							(*novo).proximo = NULL;   
							CAUDA = novo;  
						}
					}

					cout << "\n===================================\n";
					cout << "\tLista inicializada!";
					cout << "\n===================================\n";
				}
				else
				{
					cout << "\n============================================\n";
					cout << "\tA lista precisa estar vazia.";
					cout << "\n============================================\n";
				}

				pause();

			break;
			// ----------- LISTA ESTÁ ORDENADA? -----------
			case 'c': case 'C':

				if (CAUDA != NULL)
				{
					if (verificarSeListaEstaOrdenada())
					{
						cout << "\n======================================\n";
						cout << "\tA lista está ordenada!";
						cout << "\n======================================\n";
					}
					else
					{
						cout << "\n==========================================\n";
						cout << "\tA lista não está ordenada.";
						cout << "\n==========================================\n";
					}
				}
				else
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}

				pause();

			break;
			// ----------- ORDENA LISTA -----------
			case 'd': case 'D':

				if (CABECA != NULL)
				{
					// verifica se já está ordenada
					if (verificarSeListaEstaOrdenada())
					{
						cout << "\n=========================================\n";
						cout << "\tA lista já está ordenada!";
						cout << "\n=========================================\n";
					}
					else
					{
						while (verificarSeListaEstaOrdenada() == false)
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

						cout << "\n====================================\n";
						cout << "\tA lista foi ordenada!";
						cout << "\n====================================\n";
					}	
				}
				else
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}
				
				pause();

			break;
			//----------- CONTAR NÓS -----------
			case 'e': case 'E':		

				contador = 0;
				atual = CABECA;

				while (atual != NULL)
				{
					contador++;
					atual = (*atual).proximo;
				}

				if (contador == 1)
				{
					cout << "\n=====================================\n";
					cout << "\tA lista possui " << contador << " nó";
					cout << "\n=====================================\n";
				}
				else
				{
					cout << "\n=====================================\n";
					cout << "\tA lista possui " << contador << " nós";
					cout << "\n=====================================\n";
				}
			
				pause();

			break;
			// ----------- LER 2 NUMS; EXISTEM? TROCAR NÓS -----------
			case 'f': case 'F':

				if (CABECA != NULL)
				{
					cout << "\n============ TROCAR NÓS ============\n\n";
					cout << "Informe a primeira posição que deseja trocar: ";
					cin >> num;
					cout << "Informe a segunda posição que deseja trocar: ";
					cin >> num2;

					// verificar se o primeiro existe
					if (verificarSePosicaoExiste(num))
					{ 
						// verificar se o segundo existe
						if (verificarSePosicaoExiste(num2))
						{
							// realizar troca
							trocarDoisElementos(num, num2);
							cout << "\n===========================\n";
							cout << "As posições foram trocadas!";
							cout << "\n===========================\n";
						}
						else
						{
							cout << "\n=======================================\n";
							cout << "A segunda posição informada nao existe.";
							cout << "\n=======================================\n";
						}
					}
					else
					{
						cout << "\n========================================\n";
						cout << "A primeira posição informada nao existe.";
						cout << "\n========================================\n";
					}
				}
				else
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}
				
				pause();

			break;
			// ----------- INVERTER A LISTA -----------
			case 'g': case 'G':

				if (CABECA != NULL && (*CABECA).proximo == NULL)
				{
					cout << "\n==============================================\n";
					cout << "\tA lista só possui um elemento.";
					cout << "\n==============================================\n";
				}

				else if (CABECA != NULL && (*CABECA).proximo != NULL)
				{
					anterior = NULL;
					atual = CABECA;
					temp = (*CABECA).proximo;   

					while (temp != NULL)   
					{
						(*atual).proximo = anterior;  

						anterior = atual;  
						atual = temp; 
						temp = (*atual).proximo; 
					}

					(*atual).proximo = anterior; 

					CAUDA = CABECA; 
					CABECA = atual; 

					cout << "\n======================================\n";
					cout << "\tA lista foi invertida!";
					cout << "\n======================================\n";
				}
				else
				{
					cout << "\n====================================\n";
					cout << "\tA lista está vazia.";
					cout << "\n====================================\n";
				}

				pause();

			break;
			// ----------- MOSTRAR CABEÇA/CAUDA -----------
			case 'h': case 'H':

				if (CABECA != NULL)
				{
					cout << "\n=========== MOSTRAR ==========\n";

					cout << "\n=========== CABECA ===========\n";
					cout << "NÚMERO: " << (*CABECA).numero << "\n";
					cout << "QUALQUER COISA: " << (*CABECA).qualquercoisa << "\n";
					cout << "PRÓXIMO: " << (*CABECA).proximo << "\n";
					cout << "==============================\n";

					cout << "\n=========== CAUDA ============\n";
					cout << "NÚMERO: " << (*CAUDA).numero << "\n";
					cout << "QUALQUER COISA: " << (*CAUDA).qualquercoisa << "\n";
					cout << "PRÓXIMO: " << (*CAUDA).proximo << "\n";
					cout << "==============================\n";
				}
				else
				{
					cout << "\n==========================================\n";
					cout << "\tA CABECA/CAUDA está vazia.";
					cout << "\n==========================================\n";
				}

				pause();

			break;
			// ----------- SAIR -----------
			case '0':

				cout << "\nFim do programa...\n\n";

			break;
			// ----------- DEFAULT -----------
			default:

				cout << "\7"; //beep do sistema

			break;
		}	

	} while (op != '0');

	return 0;
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

	// Busca

	anterior = NULL;
	atual = CABECA;

	while (atual != NULL) 
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
			}

		}
		
		anterior = atual;           
		atual = (*atual).proximo;
	}

	// Troca

	// Se algum dos elementos for a CAUDA
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

bool verificarSeListaEstaOrdenada() {

	listaligada* anterior; listaligada* atual;

	bool listaOrdenada = true;    

	anterior = CABECA;       
	atual = (*CABECA).proximo;      

	while (atual != NULL)   
	{
		if ((*atual).numero < (*anterior).numero)   
		{
			listaOrdenada = false;
		}

		anterior = atual;  
		atual = (*atual).proximo;  
	}

	return listaOrdenada;
}

bool verificarSePosicaoExiste(int num) {

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

void menu(){
	clear();
	cout << "====================== LISTA LIGADA ======================\n";
	cout << "[1] Listar" << "\n";
	cout << "[2] Inserir na lista" << "\n";
	cout << "[3] Remover da lista" << "\n";
	cout << "[a] Limpar lista" << "\n";
	cout << "[b] Iniciar lista com 3 nós" << "\n";
	cout << "[c] A lista está ordenada? (sim/nao)" << "\n";
	cout << "[d] Ordenar lista" << "\n";
	cout << "[e] Contar nós" << "\n";
	cout << "[f] Ler 2 nums, trocar os nós" << "\n";
	cout << "[g] Inverter a lista" << "\n";
	cout << "[h] Mostrar CABECA-CAUDA" << "\n";
	cout << "[0] Sair" << endl;
	cout << "Selecione uma opção: "; 
}

void pause() {
    cin.ignore();  
    cout << endl << "Pressione uma tecla para prosseguir...";
    cin.get();  
}

void clear()
{
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}