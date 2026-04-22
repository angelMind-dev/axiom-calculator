#include "menu.h"
#include "operations/advanced.h"
#include "operations/basic.h"
#include "operations/complex.h"
#include "operations/intermediate.h"

#include <clocale>
#include <cctype>
#include <iostream>

using namespace std;

/*
    Bem-vindo ao programa de calculadora em C++, a Axiom Calc!
    Este programa realiza várias operações matemáticas básicas, intermediárias e avançadas.
    Ele foi desenvolvido utilizando o padrão C++14.
    Divirta-se utilizando a calculadora!


    --------------------------------------------------------------------------------------------------


    Data de criação: 08/11/2025
    Autor: Angelo de Paula Dias Morais Alves
    Aluno do curso de desenvolvimento de sistemas - ETEC Philadelpho Gouvea Netto Sao Jose do Rio Preto - SP

    Compilador: MinGW g++
    Versão do C++: C++
    Versão do programa: 1.0
    Número de operações implementadas: 24
    Última atualização: 22/04/2026 - 13:36 - horário de Brasília


    Descrição da última atualização: Correção das palavras do código 
    Separação das operações em arquivos .cpp e .h para melhor organização do código
    Implementação de um menu para escolher as operações


        Instruções de uso:
    No início do programa, você verá uma lista de operações disponíveis (24).
    Escolha a operação desejada digitando o número correspondente ou o nome da operação.
    O programa solicitará os números ou parâmetros necessários para realizar a operação escolhida.
    Após a operação ser realizada, o resultado será exibido na tela.
    Você poderá escolher realizar outra operação ou encerrar o programa digitando 's' quando perguntado se deseja realizar outra operação.
*/

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char continuar = 's';

    while (continuar == 's') {
        int categoria = escolherCategoria();
        int operacao = 0;

        if (categoria == 0) {
            break;
        }

        switch (categoria) {
            case 1:
                operacao = menuBasicas();
                break;
            case 2:
                operacao = menuIntermediarias();
                break;
            case 3:
                operacao = menuAvancadas();
                break;
            case 4:
                operacao = menuComplexas();
                break;
            default:
                cout << "Opção de categoria inválida.\n";
                continue;
        }

        if (operacao == 0) {
            continue;
        }

        switch (operacao) {
            case 1:
                executarSoma();
                break;
            case 2:
                executarSubtracao();
                break;
            case 3:
                executarMultiplicacao();
                break;
            case 4:
                executarDivisao();
                break;
            case 5:
                executarParOuImpar();
                break;
            case 6:
                executarPorcentagem();
                break;
            case 7:
                executarMediaAritmetica();
                break;
            case 8:
                executarPotencia();
                break;
            case 9:
                executarRaiz();
                break;
            case 10:
                executarMediaPonderada();
                break;
            case 11:
                executarModulo();
                break;
            case 12:
                executarLogaritmo();
                break;
            case 13:
                executarFuncoesTrigonometricas();
                break;
            case 14:
                executarFatorial();
                break;
            case 15:
                executarConversoes();
                break;
            case 16:
                executarExponenciaisEspeciais();
                break;
            case 17:
                executarArredondamento();
                break;
            case 18:
                executarMaximoMinimo();
                break;
            case 19:
                executarFuncoesEstatisticas();
                break;
            case 20:
                executarEquacoes();
                break;
            case 21:
                executarSequenciasMatematicas();
                break;
            case 22:
                executarRegressaoLinear();
                break;
            case 23:
                executarIntegralNumerica();
                break;
            case 24:
                executarDerivadaNumerica();
                break;
            default:
                cout << "Opção inválida.\n";
                continue;
        }

        cout << "\nDeseja realizar outra operação? (s/n): ";
        cin >> continuar;
        continuar = static_cast<char>(tolower(static_cast<unsigned char>(continuar)));
    }

    cout << "\n=============================================\n";
    cout << "   Encerrando a calculadora... até mais! :)\n";
    cout << "=============================================\n";

    return 0;
}

// Compilação e execução:
// Compilador: MinGW g++

// Para compilar o programa, use o comando abaixo no terminal, estando na pasta do projeto:
// g++ src/*.cpp src/operations/*.cpp -Iinclude -o main.exe

//-------------------------------------------------------------------------------------------

// Para rodar o programa, use o comando abaixo no terminal, estando na pasta do projeto:
// .\main.exe


// chcp 65001 (Windows para acentuação e UTF-8)