#include <iostream>
#include <vector>

using namespace std;

vector <int> converterParaBinario(int decimal);
vector <char> converterParaHexadecimal(int decimal);
vector <int> converterParaOctal(int decimal);
char converterNumeroParaLetra(int num);

int main()
{
    vector <int> convertido;
    vector <char> convertidoChar; 
    int decimal;
    int op;

    do
    {
        system("clear");
        cout << "Informe um numero para converter: ";
        cin >> decimal;

        cout << "\n=== Opções ===\n";
        cout << "[1] Binario" << "\n";
        cout << "[2] Hexadecimal" << "\n";
        cout << "[3] Octal" << "\n";
        cout << "[0] Sair" << "\n";

        cout << "\nSelecione a opcao desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:

                convertido = converterParaBinario(decimal);

                cout << "\nA conversao do decimal " << decimal << " para binario: ";
                for (size_t i = 0; i < convertido.size(); i++)
                {
                    cout << convertido[i];
                }

                cin.ignore();
                cout << "\n\nPressione alguma tecla para continuar...\n";
                cin.get();

                convertido.clear();
            
            break;
        case 2:

                convertidoChar = converterParaHexadecimal(decimal);

                cout << "\nA conversao do decimal " << decimal << " para hexadecimal: 0x";

                for (int i = 0; i < convertidoChar.size(); i++)
                {
                    cout << convertidoChar[i];
                }

                cin.ignore();
                cout << "\n\nPressione alguma tecla para continuar...\n";
                cin.get();

                convertidoChar.clear();

            break;
        case 3:

                convertido = converterParaOctal(decimal);
                
                cout << "\nA conversao do decimal " << decimal << " para octal: ";

                for (int i = 0; i < convertido.size(); i++)
                {
                    cout << convertido[i];
                }

                cin.ignore();
                cout << "\n\nPressione alguma tecla para continuar...\n";
                cin.get();

                convertido.clear();

            break;
        case 0:

                cout << "\nFim do programa...\n\n";

            break;
        default:

                cout << "\nOpção invalida!\n";

                cin.ignore();
                cout << "\nPressione alguma tecla para continuar...\n";
                cin.get();
                
            break;
        }
    } while (op != 0);

    return 0;
}

vector <int> converterParaBinario(int decimal){

    vector <int> resultado;

    while ((decimal / 2) != 0)
    {   
        resultado.insert(resultado.begin(), decimal % 2);
        decimal = decimal / 2;
    }

    resultado.insert(resultado.begin(), decimal);

    return resultado;
}

vector <char> converterParaHexadecimal(int decimal){

    vector <char> resultado;
    int resto;
    char intToChar;
    
    while ((decimal / 16) != 0)
    {   
        resto = decimal % 16;

        if (resto >= 10)
        {
           resultado.insert(resultado.begin(), converterNumeroParaLetra(resto));
        }
        else
        {
            intToChar = resto + '0';
            resultado.insert(resultado.begin(), intToChar); 
        }
        
        decimal = decimal / 16;
    }

    if (decimal >= 10)
    {
        resultado.insert(resultado.begin(), converterNumeroParaLetra(decimal));
    }
    else
    {    
        intToChar = decimal + '0';
        resultado.insert(resultado.begin(), intToChar); 
    }

    return resultado;
}

vector <int> converterParaOctal(int decimal){

    vector <int> resultado;

    while ((decimal / 8) != 0)
    {   
        resultado.insert(resultado.begin(), decimal % 8);
        decimal = decimal / 8;
    }

    resultado.insert(resultado.begin(), decimal);

    return resultado;
}

char converterNumeroParaLetra(int num){

    switch (num)
    {
    case 10:
            return 'A';
        break;
    case 11:
            return 'B';
        break;
    case 12:
            return 'C';
        break;
    case 13:
            return 'D';
        break;
    case 14:
            return 'E';
        break;
    default:
            return 'F';
        break;
    }  
}