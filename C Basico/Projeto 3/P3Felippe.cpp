#include <iostream>
#include <conio.h>				// para input getchar()
#include <locale.h>				// para usar carateres nacionais
#include <iomanip>				// para a formatação do output 
#include <string>				// stoi
using namespace std;

void lerNomesVerificar();
void listarNomeMaiorFreguesia();
void contarMenoresDeIdade();
int contarRapazes();
void verificarRapazes();
void copiarRapazes();
void contarMaioresDe();
void listarRaparigas();
void haAnosRepetidos();
void lerAnoVerificarSeRepete();
void quantidadeRapazesMaximinos();
void quantidadeRaparigas();
void maisVelho();
void inserirFicha();
void inicializaMatriz();
void listaMatriz();
void menu();
void submenu();

const int ANO_ATUAL = 2023;
string fichas[20][4];

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char op;

	do {
		menu();
		op = _getch();

		switch (op)
		{
		case '1':
			inicializaMatriz();
			break;
		case '2':
			listaMatriz();
			break;
		case '3':
			inserirFicha();
			break;
		case '4':
			maisVelho();
			break;
		case '5':
			quantidadeRaparigas();
			break;
		case '6':
			quantidadeRapazesMaximinos();
			break;
		case '7':
			lerAnoVerificarSeRepete();
			break;
		case '8':
			haAnosRepetidos();
			break;
		case '9':
			listarRaparigas();
			break;
		case 'e':
			contarMaioresDe();
			break;
		case 'f':
			copiarRapazes();
			break;
		case 'g':
			verificarRapazes();
			break;
		case 'x':
			contarMenoresDeIdade();
			break;
		case 'y':
			listarNomeMaiorFreguesia();
			break;
		case 'z':
			lerNomesVerificar();
			break;
		default:
			break;
		}
	} while (op != 27);
}

// PRODUÇÃO ler dois nomes e verificar se existem simultaneamente e se estão em posições contiguas

void lerNomesVerificar()
{

	system("cls");

	string nome1;
	string nome2;
	int indiceNome1 = 0;
	int indiceNome2 = 0;
	int resultado = 0;
	bool existeNome1 = false;
	bool existeNome2 = false;

	cout << "Introduza o primeiro nome desejado: ";
	cin >> nome1;
	cout << "Introduza o segundo nome desejado: ";
	cin >> nome2;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][0] == nome1)
		{
			existeNome1 = true;
			indiceNome1 = i;
		}
		if (fichas[i][0] == nome2)
		{
			existeNome2 = true;
			indiceNome2 = i;
		}
	}

	if (existeNome1 && existeNome2)
	{
		cout << "\nSim, existem.\n";

		if (indiceNome1 > indiceNome2)
		{
			resultado = indiceNome1 - indiceNome2;
		}
		else
		{
			resultado = indiceNome2 - indiceNome1;
		}

		if (resultado == 1)
		{
			cout << "\nEstão em posições contíguas.\n";
		}
		else
		{
			cout << "\nNão estão em posições contíguas.\n";
		}
	}
	else
	{
		cout << "\nNão existem em simultaneo.\n";
	}

	_getch();

}


// PRODUÇÃO listar o nome da freguesia que tiver mais elementos entre duas
void listarNomeMaiorFreguesia()
{
	system("cls");

	string freguesia1;
	string freguesia2;
	int contadorFreguesia1 = 0;
	int contadorFreguesia2 = 0;

	cout << "Introduza a primeira freguesia desejada: ";
	cin >> freguesia1;
	cout << "Introduza a segunda freguesia desejada: ";
	cin >> freguesia2;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][1] == freguesia1)
		{
			contadorFreguesia1++;
		}

		if (fichas[i][1] == freguesia2)
		{
			contadorFreguesia2++;
		}
	}

	if (contadorFreguesia1 > contadorFreguesia2)
	{
		cout << "\nA maior freguesia é " << freguesia1 << " com " << contadorFreguesia1 << " registros.";
	}
	else
	{
		cout << "\nA maior freguesia é " << freguesia2 << " com " << contadorFreguesia2 << " registros.";
	}

	_getch();
}

// PRODUÇÃO contar menores de idade
void contarMenoresDeIdade()
{
	system("cls");

	string freguesia;
	string sexo;
	int idade;
	int contador = 0;

	cout << "Introduza a freguesia desejada: ";
	cin >> freguesia;
	cout << "Introduza o sexo desejado: ";
	cin >> sexo;

	for (int i = 0; i < 20; i++)
	{
		idade = ANO_ATUAL - stoi(fichas[i][3]);

			if (fichas[i][1] == freguesia && fichas[i][2] == sexo)
			{
				if (idade < 18)
				{
					contador++;
				}
			}
	}

	cout << "\nExistem " << contador << " menores de idade do sexo " << sexo << " da freguesia " << freguesia << "\n";

	_getch();
}

// contar rapazes retornando
int contarRapazes()
{
	int contador = 0;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][2] == "M")
		{
			contador++;
		}
	}

	return contador;
}

void verificarRapazes()
{
	system("cls");

	if (contarRapazes())
	{
		cout << "Há " << contarRapazes() << " rapazes.";
	}
	else 
	{
		cout << "Não há rapazes.";
	}

	_getch();
}

// copiar rapazes para novo array
void copiarRapazes()
{
	system("cls");

	string rapazes[20];
	int contador = 0;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][2] == "M")
		{
			rapazes[contador] = fichas[i][0];
			contador++;
		}
	}

	for (int i = 0; i < contador; i++)
	{
		cout << rapazes[i] << "\n";
	}

	_getch();
}

// contar pessoas com idade maior que x anos
void contarMaioresDe()
{
	system("cls");

	int idade;
	int contador = 0;

	cout << "Informe a idade desejada: ";
	cin >> idade;

	for (int i = 0; i < 20; i++)
	{
		int anoConvertido = stoi(fichas[i][3]);
		int anoParaIdade = ANO_ATUAL - anoConvertido;

		if (anoParaIdade > idade)
		{
			contador++;
		}
	}

	cout << "Existem " << contador << " pessoas com idade maiores que " << idade << " Anos.";

	_getch();
}

// listar apenas raparigas
void listarRaparigas()
{
	system("cls");

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][2] == "F")
		{
			cout << fichas[i][0] << " " << fichas[i][1] << " " << fichas[i][2] << " " << fichas[i][3] << "\n";
		}
	}

	_getch();
}

// verificar se há anos repetidos
void haAnosRepetidos()
{
	system("cls");

	bool haRepetidos = false;
	
	for (int i = 0; i < 19; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			if (fichas[i][3] == fichas[j][3])
			{
				haRepetidos = true;
			}
		}
	}

	if (haRepetidos)
	{
		cout << "\nHá repetidos!";
	}
	else
	{
		cout << "\nNão há repetidos.";
	}

	_getch();
}

// ler ano e verificar se o mesmo aparece repetido
void lerAnoVerificarSeRepete() {

	system("cls");

	string ano;
	bool haRepetido = false;

	cout << "Introduza o ano que deseja verificar: ";
	cin >> ano;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][3] == ano)
		{
			haRepetido = true;
			break;
		}
	}

	if (haRepetido)
	{
		cout << "Sim, o ano de " << ano << " aparece.";
	} 
	else
	{
		cout << "Não, o ano de " << ano << " não aparece.";
	}

	_getch();
}

// quantos rapazes de maximinos
void quantidadeRapazesMaximinos()
{
	system("cls");

	int contador = 0;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][1] == "Maximinos" && fichas[i][2] == "M")
		{
			contador++;
		}
	}

	cout << "Quantidade de rapazes de maximinos: " << contador;

	_getch();
}

// quantas raparigas há na lista
void quantidadeRaparigas() 
{
	system("cls");

	int contador = 0;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][2] == "F")
		{
			contador++;
		} 
	}

	cout << "\nQuantidade de raparigas: " << contador;

	_getch();
}

// com base no ano atual, quem é o mais velho
void maisVelho()
{
	system("cls");

	int posicaoMaisVelho = 0;

	for (int i = 0; i < 20; i++)
	{
		if (fichas[i][3] < fichas[posicaoMaisVelho][3])
		{
			posicaoMaisVelho = i;
		}
	}

	cout << "A pessoa mais velha é " << fichas[posicaoMaisVelho][0] << " da posição " << posicaoMaisVelho << ".";

	_getch();
}

// inserir nova ficha para a posiçao indicada
void inserirFicha() 
{
	system("cls");

	int posicao;
	string nome;
	string freguesia;
	string sexo;
	string anoNasc;

	do
	{
		cout << "Indique a posição desejada: ";
		cin >> posicao;

		if (posicao < 0 || posicao > 19)
		{
			cout << "Posição inválida!\n\n";
		}
		
	} while (posicao < 0 || posicao > 19);


	cout << "Indique o nome desejado: ";
	cin >> nome;
	cout << "Indique a freguesia desejada: ";
	cin >> freguesia;
	cout << "Indique o sexo desejado: ";
	cin >> sexo;
	cout << "Indique o ano de nascimento desejado: ";
	cin >> anoNasc;

	fichas[posicao][0] = nome;
	fichas[posicao][1] = freguesia;
	fichas[posicao][2] = sexo;
	fichas[posicao][3] = anoNasc;

	cout << "\nNova ficha inserida com sucesso!!!";
	_getch();
}

// inicializa com 20 nomes e 20 freguesias...
void inicializaMatriz()
{
	fichas[0][0] = "Zacarias";
	fichas[1][0] = "Ana";
	fichas[2][0] = "Bela";
	fichas[3][0] = "Carlos";
	fichas[4][0] = "Carlota";
	fichas[5][0] = "Daniel";
	fichas[6][0] = "Diogo";
	fichas[7][0] = "Elvira";
	fichas[8][0] = "Fernanda";
	fichas[9][0] = "Fernando";
	fichas[10][0] = "Gilherme";
	fichas[11][0] = "Hilda";
	fichas[12][0] = "Josildo";
	fichas[13][0] = "Josecas";
	fichas[14][0] = "Maria";
	fichas[15][0] = "Anabela";
	fichas[16][0] = "Otaviano";
	fichas[17][0] = "Rui";
	fichas[18][0] = "Silverio";
	fichas[19][0] = "Teodoro";

	fichas[0][1] = "Lindoso";
	fichas[1][1] = "Maximinos";
	fichas[2][1] = "Gualtar";
	fichas[3][1] = "Lomar";
	fichas[4][1] = "Lomar";
	fichas[5][1] = "Cividade";
	fichas[6][1] = "Lamaceiros";
	fichas[7][1] = "Maximinos";
	fichas[8][1] = "Ferreiros";
	fichas[9][1] = "Maximinos";
	fichas[10][1] = "Cividade";
	fichas[11][1] = "Cabreira";
	fichas[12][1] = "Cividade";
	fichas[13][1] = "Gualtar";
	fichas[14][1] = "Cividade";
	fichas[15][1] = "Gualtar";
	fichas[16][1] = "Maximinos";
	fichas[17][1] = "Maximinos";
	fichas[18][1] = "Maximinos";
	fichas[19][1] = "Gualtar";

	fichas[0][2] = "M"; fichas[0][3] = "1986";
	fichas[1][2] = "F"; fichas[1][3] = "1980";
	fichas[2][2] = "F"; fichas[2][3] = "1982";
	fichas[3][2] = "M"; fichas[3][3] = "1981";
	fichas[4][2] = "M"; fichas[4][3] = "1980";
	fichas[5][2] = "M"; fichas[5][3] = "1980";
	fichas[6][2] = "M"; fichas[6][3] = "1980";
	fichas[7][2] = "F"; fichas[7][3] = "1977";
	fichas[8][2] = "F"; fichas[8][3] = "1977";
	fichas[9][2] = "M"; fichas[9][3] = "1983";
	fichas[10][2] = "M"; fichas[10][3] = "1989";
	fichas[11][2] = "F"; fichas[11][3] = "1980";
	fichas[12][2] = "M"; fichas[12][3] = "1981";
	fichas[13][2] = "M"; fichas[13][3] = "1982";
	fichas[14][2] = "F"; fichas[14][3] = "1975";
	fichas[15][2] = "F"; fichas[15][3] = "1980";
	fichas[16][2] = "M"; fichas[16][3] = "2009";
	fichas[17][2] = "M"; fichas[17][3] = "2015";
	fichas[18][2] = "M"; fichas[18][3] = "2010";
	fichas[19][2] = "M"; fichas[19][3] = "1985";
}

// lista matriz completa.
void listaMatriz()
{
	int i;
	system("cls");
	cout << "\n\n" << endl;
	cout << "   Nº   NOME                             LOCAL          SEXO     ANO\n";
	cout << "  ------------------------------------------------------------------\n";
	for (i = 0; i <= 19; i++) //atenção: de 1 a 20 ou de 0 a 19?
	{


		cout

			<< right << setw(4) << setfill(' ') << i << ":   "
			<< left << setw(30) << setfill('.') << fichas[i][0] << "   "
			<< left << setw(15) << setfill(' ') << fichas[i][1]
			<< "  " << fichas[i][2]
			<< "     " << fichas[i][3]
			<< endl;
	}
	cout << "  ------------------------------------------------------------------\n";
	cout << " \n\n\t\t\t\t\t\t       qq. tecla ...";
	_getch();
}

// lista opcoes menu.
void menu() 
{
	system("cls");
	cout << "==================== MENU ====================\n";
	cout << "1. Inicializar matriz\n";
	cout << "2. Listar matriz\n";
	cout << "3. Inserir nova ficha\n";
	cout << "4. Quem é o mais velho\n";
	cout << "5. Quantidade de raparigas\n";
	cout << "6. Quantidade de rapazes de Maximinos\n";
	cout << "7. Ler ano e verificar se há repetição\n";
	cout << "8. Há anos repetidos?\n";
	cout << "9. Listar raparigas\n";
	cout << "e. Contar pessoas maiores que X idade\n";
	cout << "f. Criar nova array com os rapazes\n";
	cout << "g. Contar rapazes\n";
	cout << "x. Contar menores de idade de uma freguesia e sexo especificos\n";
	cout << "y. Listar o nome da freguesia que tiver mais elementos entre duas\n";
	cout << "z. Ler dois nomes e verificar se existem simultaneamente e se estão em posições contiguas\n";
	cout << "ESC. Sair\n";

	cout << "\nIntroduzir opcao desejada: ";
}

// submenu
void submenu()
{
	cout << "\n\n===================================================\n\n";
}