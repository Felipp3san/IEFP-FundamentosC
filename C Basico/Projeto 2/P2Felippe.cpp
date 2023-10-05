//====================================
// Menu com IFs
// Autor : Felippe de Almeida Santana
// Data : 


#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	string nomes[10] = { "Figueiredo", "Paula", "Maria", "Joao", "Manoel", "Joaquim", "Marcia", "Abel", "Cassio", "Camila"};
	string freguesias[10] = { "Aveleda", "Maximinos", "Lomar", "Aveleda", "Aveleda", "Sao Vicente", "Aveleda", "Maximinos", "Lomar", "Aveleda"};
	int anoNasc[10] = { 1959, 2001, 1986, 2008, 1990, 2005, 1976, 1999, 2003, 1988};
	char sexos[10] = { 'M', 'F', 'F', 'M', 'M', 'M', 'F', 'M', 'M', 'F'};
	char op;

	do
	{
		system("cls");
		cout << "============= MENU =============\n";
		cout << "1 - Quantidade de rapazes\n";
		cout << "2 - Quantidade de raparigas de Maximinos\n";
		cout << "3 - Verificar se ha mais rapazes ou raparigas\n";
		cout << "4 - Quantidade de rapazes nascidos entre 2000 e 2010\n";
		cout << "5 - Verificar se ha freguesias repetidas\n"; 
		cout << "6 - Indicar a freguesia com mais raparigas\n";
		cout << "7 - Ler duas freguesias e indicar qual tem mais rapazes\n";
		cout << "8 - Listar rapazes em um linha e raparigas em outra\n";
		cout << "9 - Verificar se ha nomes repetidos\n";
		cout << "A - Quantidade de rapazes nascidos em anos impares\n";
		cout << "B - Diferenca de idade entre o mais velho e o mais novo da freguesia escolhida\n";
		cout << "Z - Ler dois nomes, se existirem no array, lista - los por ordem crescente de idade\n";
		cout << "W - Ler dois anos, listar tudo o que estiver entre eles\n";
		cout << "L - Listar \n";
		cout << "T - Sair do programa\n";
		cout << "\nIntroduza a opcao desejada: ";
		cin >> op;

		//==========================================
		// Quantidade de rapazes

		if (op == '1')
		{
			int contador = 0;

			for (int i = 0; i <= 9; i++)
			{
				if (sexos[i] == 'M')
				{
					contador++;
				}
			}

			cout << "\n=========== Opcao 1 ============\n";
			cout << "Quantidade de rapazes: " << contador;
			cout << "\n================================\n\n";
		}

		//==================================================
		// Quantidade de raparigas de maximinos

		if (op == '2')
		{
			int raparigasMaximinos = 0;

			for (int i = 0; i <= 9; i++)
			{
				if (sexos[i] == 'F' && freguesias[i] == "Maximinos")
				{
					raparigasMaximinos++;
				}
			}

			cout << "\n=========== Opcao 2 ============\n";
			cout << "Raparigas de Maximinos: " << raparigasMaximinos;
			cout << "\n================================\n\n";
		}

		//==================================================
		// Verificar se ha mais rapazes ou raparigas

		if (op == '3')
		{
			int qtRapazes = 0;
			int qtRaparigas = 0;

			for (int i = 0; i <= 9; i++)
			{
				if (sexos[i] == 'M')
				{
					qtRapazes++;
				}
				else
					qtRaparigas++;
			}

			if (qtRapazes > qtRaparigas)
			{
				cout << "\n=========== Opcao 3 ============\n";
				cout << "Ha mais rapazes! Quantidade: " << qtRapazes;
				cout << "\n================================\n\n";
			}
			else
			{
				cout << "\n=========== Opcao 3 ============\n";
				cout << "Ha mais raparigas! Quantidade: " << qtRaparigas;
				cout << "\n================================\n\n";
			}
		}

		//==================================================
		// Quantidade de rapazes nascidos entre 2000 e 2010

		if (op == '4')
		{
			int rapazes2000e2010 = 0;

			for (int i = 0; i <= 9; i++)
			{
				if (sexos[i] == 'M' && anoNasc[i] > 2000 && anoNasc[i] < 2010)
				{
					rapazes2000e2010++;
				}
			}

			cout << "\n=========== Opcao 4 ============\n";
			cout << "Rapazes nascidos entre 2000 e 2010: " << rapazes2000e2010;
			cout << "\n================================\n\n";
		}

		//==============================================
		// Verificar se ha freguesias repetidas

		if (op == '5')
		{
			bool haRepetidas = false;

			for (int i = 0; i <= 8; i++)
			{
				for (int j = i + 1; j <= 9; j++)
				{
					if (freguesias[i] == freguesias[j])
					{
						haRepetidas = true;
					}
				}
			}
			if (haRepetidas)
			{
				cout << "\n=========== Opcao 5 ============\n";
				cout << "Sim, ha freguesias repetidas!";
				cout << "\n================================\n\n";
			}
			else
			{
				cout << "\n=========== Opcao 5 ============\n";
				cout << "Nao ha repetidas!";
				cout << "\n================================\n\n";
			}
		}

		// =====================================================
		// freguesias com mais raparigas

		if (op == '6')
		{
			int indicefreguesias = 0;
			int maisRaparigas = 0;
			int contador = 0;

			for (int i = 0; i <= 8; i++)
			{
				contador = 0;

				for (int j = i + 1; j <= 9; j++)
				{
					if (sexos[i] == 'F' && freguesias[i] == freguesias[j] && sexos[i] == sexos[j])
					{
						contador++;
					}
				}

				if (contador > maisRaparigas)
				{
					maisRaparigas = contador;
					indicefreguesias = i;
				}
			}
			cout << "\n=========== Opcao 6 ============\n";
			cout << "Freguesia com mais raparigas: " << freguesias[indicefreguesias];
			cout << "\n================================\n\n";
		}

		// =================================================
		// Ler duas freguesias e indicar qual tem mais rapazes

		if (op == '7')
		{
			string escolha1;
			string escolha2;
			int quantRapazes1 = 0;
			int	quantRapazes2 = 0;

			cout << "\n=========== Opcao 7 ============\n";
			cout << "Indique a primeira freguesia: ";
			cin >> escolha1;
			cout << "Indique a segunda freguesia: ";
			cin >> escolha2;

			for (int i = 0; i <= 9; i++)
			{
				if (escolha1 == freguesias[i] && sexos[i] == 'M')
				{
					quantRapazes1++;
				}
				if (escolha2 == freguesias[i] && sexos[i] == 'M')
				{
					quantRapazes2++;
				}
			}

			if (quantRapazes1 > quantRapazes2)
			{
				cout << "\nA freguesia " << escolha1 << " tem mais rapazes.";
			}
			else
			{
				cout << "\nA freguesia " << escolha2 << " tem mais rapazes.";
			}
			cout << "\n================================\n\n";
		}

		// =================================================
		// Listas rapazes em uma linha e raparigas em outra

		if (op == '8')
		{
			cout << "\n=========== Opcao 8 ============\n";
			cout << "Raparigas: ";

			for(int i = 0; i <= 9; i++)
			{
				if (sexos[i] == 'F')
				{
					cout << nomes[i] << ", ";
				}
			}

			cout << "\n";

			cout << "Rapazes: ";

			for (int i = 0; i <= 9; i++)
			{
				if (sexos[i] == 'M')
				{
					cout << nomes[i] << ", ";
				}
			}
		cout << "\n================================\n\n";
		}

	// =================================================
	// Verificar se há nomes repetidos

		if (op == '9')
		{
			bool haRepetidos = false;

			for (int i = 0; i <= 8; i++)
			{
				for (int j = i + 1; j <= 9; j++)
				{
					if (nomes[i] == nomes[j])
					{
						haRepetidos = true;
					}
				}
			}

			if (haRepetidos)
			{
				cout << "\n=========== Opcao 9 ============\n";
				cout << "Ha nomes repetidos!";
				cout << "\n================================\n\n";
			}
			else
			{
				cout << "\n=========== Opcao 9 ============\n";
				cout << "Nao ha nomes repetidos!";
				cout << "\n================================\n\n";
			}
		}

		// =================================================
		// Quantos rapazes nasceram em anos impares

		if (op == 'A' || op == 'a')
		{
			int quantRapazes = 0;

			for (int i = 0; i <= 9; i++)
			{
				if(sexos[i] == 'M')
					if (anoNasc[i] % 2 != 0)
					{
						quantRapazes++;
					}
			}

			cout << "\n=========== Opcao A ============\n";
			cout << "Ha " << quantRapazes << " rapazes nascidos em anos impares.";
			cout << "\n================================\n\n";
		}
		// =================================================
		// Diferença de idade entre o mais velho e o mais novo da freguesia escolhida
		
		if (op == 'B' || op == 'b')
		{
			string freguesiaEscolhida;
			int maisVelho = 0;
			int maisNovo = 0;
			int diferenca = 0;
			bool ativador = false;

			cout << "\n=========== Opcao B ============\n";
			cout << "Introduza a freguesia desejada: ";
			cin >> freguesiaEscolhida;

			for (int i = 0; i <= 9; i++)
			{
				if (freguesiaEscolhida == freguesias[i] && ativador == false)
				{
					maisVelho = anoNasc[i];
					maisNovo = anoNasc[i];
					ativador = true;
				}

				if(freguesiaEscolhida == freguesias[i] && anoNasc[i] < maisVelho && ativador == true)
				{
					maisVelho = anoNasc[i];
				}

				if (freguesiaEscolhida == freguesias[i] && anoNasc[i] > maisNovo && ativador == true)
				{
					maisNovo = anoNasc[i];
				}
			}

			diferenca = maisNovo - maisVelho;

			cout << "\nA diferenca de idade entre o mais velho e o mais novo da freguesia " << freguesiaEscolhida
				 << ": " << diferenca;
			cout << "\n================================\n\n";
 		}

		// =================================================
		// Ler dois nomes, se existirem no array, lista-los por ordem crescente de idade

		if (op == 'Z' || op == 'z')
		{
			string escolha1, escolha2;
			int idade1 = 0;
			int idade2 = 0;

			cout << "\n=========== Opcao Z ============\n";
			cout << "Introduzir o primeiro nome: ";
			cin >> escolha1;
			cout << "Introduzir o segundo nome: ";
			cin >> escolha2;

			for (int i = 0; i <= 9; i++)
			{
				if (escolha1 == nomes[i])
				{
					idade1 = 2023 - anoNasc[i];
				}
				if (escolha2 == nomes[i])
				{
					idade2 = 2023 - anoNasc[i];
				}
			}

			if (idade1 > 0 && idade2 > 0)
			{
				if (idade1 > idade2)
				{
					cout << "\nNomes com idade em ordem crescente: " << escolha2 << ", " << escolha1;
				}
				else
				{
					cout << "\nNomes com idade em ordem crescente: " << escolha1 << ", " << escolha2;
				}
			}
			else
			{
				cout << "Um dos nomes introduzidos, ou os dois nao estao presentes na array.";
			}

			cout << "\n================================\n\n";

		}

		// =================================================
	    // Ler dois anos, listar tudo o que estiver entre eles

		if (op == 'W' || op == 'w')
		{
			int escolhaAno1 = 0;
			int escolhaAno2 = 0;

			cout << "\n=========== Opcao W ============\n";
			cout << "Introduza o primeiro ano desejado: ";
			cin >> escolhaAno1;
			cout << "Introduza o segundo ano desejado: ";
			cin >> escolhaAno2;
			cout << "\n";

			for (int i = 0; i <= 9; i++)
			{
				int idade = 0;
				string maioridade = "Menor";

				if (escolhaAno1 > escolhaAno2)
				{
					if (anoNasc[i] <= escolhaAno1 && anoNasc[i] >= escolhaAno2)
					{
						idade = 2023 - anoNasc[i];

						if (idade >= 18)
							maioridade = "Maior";

						cout << nomes[i] << ", " << freguesias[i] << ", " << sexos[i] << ", " << anoNasc[i] << ", " << idade << " anos, " << maioridade << "\n";
					}
				}
				else
				{
					if (anoNasc[i] >= escolhaAno1 && anoNasc[i] <= escolhaAno2)
					{
						idade = 2023 - anoNasc[i];

						if (idade >= 18)
							maioridade = "Maior";

						cout << nomes[i] << ", " << freguesias[i] << ", " << sexos[i] << ", " << anoNasc[i] << ", " << idade << " anos, " << maioridade << "\n";
					}
				}
			}
			cout << "================================\n\n";
		}

		// =================================================
		// Listar arrays

		if (op == 'L' || op == 'l')
		{
			cout << "\n=========== Opcao Listar ============\n";
			for (int i = 0; i <= 9; i++)
			{
				cout << nomes[i] << " " << sexos[i] << " " << freguesias[i] << " " << anoNasc[i] << "\n";
			}
			cout << "================================\n\n";
		}

		//=================================================
		system("pause");
	} while (op != 'T' && op != 't');
}

//====================================
// Listar arrays
// Autor : Felippe de Almeida Santana
// Data : 

	/*
	#include<iostream>
	using namespace std;

	int main()
	{
		string nomes[5] = { "Silvia", "Paula", "Marcos", "João", "Julia" };

		for (int i = 0; i <= 4; i++)
		{
			cout << nomes[i] << "\n";
		}
	}
	*/

//====================================
// freguesiass com mais raparigas
// Autor : Felippe de Almeida Santana
// Data : 

	/*
	#include<iostream>
	using namespace std;

	int main()
	{
		string nomes[5] = { "Silvia", "Paula", "Marcos", "João", "Julia" };
		int anoNasc[5] = { 1959, 2001, 1986, 2005, 1990 };
		char sexos[5] = { 'F', 'F', 'M', 'M', 'F' };
		string freguesias[5] = { "Sao Vitor", "Sao Vitor", "Lomar", "Sao Vitor", "Maximinos" };
		int indicefreguesias = 0, maisRaparigas = 0, contador = 0;

		for (int i = 0; i <= 3; i++)
		{
			contador = 0;

			for (int j = i + 1; j <= 4; j++)
			{
				if (sexos[i] == 'F' && freguesias[i] == freguesias[j] && sexos[i] == sexos[j])
				{
					contador++;
				}
			}

			if (contador > maisRaparigas)
			{
				maisRaparigas = contador;
				indicefreguesias = i;
			}
		}
			cout << "freguesias com mais raparigas: " << freguesias[indicefreguesias] << "\n";
	}
	*/

//====================================
// Verificar se há freguesiass repetidas
// Autor : Felippe de Almeida Santana
// Data : 
	
	/*
	#include<iostream>
	using namespace std;

	int main()
	{
		string freguesias[5] = { "Aveleda", "Maximinos", "Lomar", "Sao Vitor", "Aveleda" };
		bool haRepetidas = false;

		for (int i = 0; i <= 3; i++)
		{
			for (int j = i+1; j <= 4; j++)
			{
				if (freguesias[i] == freguesias[j])
				{
					haRepetidas = true;
				}
			}
		}
		if (haRepetidas)
		{
			cout << "Ha repetidas!\n";
		}
		else
		{
			cout << "Nao ha repetidas!\n";
		}
	}
	*/

//====================================
// Rapazes nascidos entre 2000 e 2010
// Autor : Felippe de Almeida Santana
// Data : 
	/*
	#include<iostream>
	using namespace std;

	int main()
	{
		string nomes[5] = { "Figueiredo", "Paula", "Maria", "João", "Julia" };
		int anoNasc[5] = { 1959, 2001, 1986, 2005, 1990 };
		char sexos[5] = { 'M', 'F', 'F', 'M', 'F' };
		int rapazes2000e2010 = 0;

		for (int i = 0; i <= 4; i++)
		{
			if (sexos[i] == 'M' && anoNasc[i] > 2000 && anoNasc[i] < 2010)
			{
				rapazes2000e2010++;
			}
		}

		cout << "Rapazes nascidos entre 2000 e 2010: " << rapazes2000e2010 << "\n";
	}
	*/

//====================================
// Quantidade de raparigas de Maximinos
// Autor : Felippe de Almeida Santana
// Data : 
	/*
	#include<iostream>
	using namespace std;

	int main()
	{
		string nomes[5] = { "Figueiredo", "Paula", "Maria", "João", "Julia" };
		string freguesias[5] = { "Aveleda", "Maximinos", "Lomar", "Sao Vitor", "Maximinos" };
		char sexos[5] = { 'M', 'F', 'F', 'M', 'F' };
		int raparigasMaximinos = 0;

		for (int i = 0; i <= 4; i++)
		{
			if (sexos[i] == 'F' && freguesias[i] == "Maximinos")
			{
				raparigasMaximinos++;
			}
		}

		cout << "Raparigas de maximinos: " << raparigasMaximinos << "\n";
	}
	*/

//====================================
// Quantidade de rapazes
// Autor : Felippe de Almeida Santana
// Data : 
	/*
	#include<iostream>
	using namespace std;

	int main() 
	{
		string nomes[5] = { "Figueiredo", "Paula", "Maria", "João", "Manoel" };
		char sexos[5] = { 'M', 'F', 'F', 'M', 'M' };
		int contador = 0;

		for (int i = 0; i <= 4; i++)
		{
			if (sexos[i] == 'M')
			{
				contador++;
			}
		}

		cout << "Quantidade de rapazes: " << contador << "\n";
	}
	*/
//===========================