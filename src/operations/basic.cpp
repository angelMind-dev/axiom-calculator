#include "operations/basic.h"

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<double> lerNumeros() {
    while (true) {
        vector<double> numbers;
        double num;
        int i = 1;

        while (true) {
            cout << "Informe o " << i << "º número (0 para parar): ";
            cin >> num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida! Digite apenas números.\n";
                continue;
            }

            if (num == 0) {
                break;
            }

            numbers.push_back(num);
            i++;
        }

        if (numbers.empty()) {
            cout << "Nenhum número informado! Tente novamente.\n";
            continue;
        }

        return numbers;
    }
}

void executarSoma() {
    cout << "\nSOMA selecionada!\n";
    auto numbers = lerNumeros();

    double result = 0;

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        result += numbers[i];
    }

    cout << "Resultado da soma: " << result << "\n";
}

void executarSubtracao() {
    cout << "\nSUBTRAÇÃO selecionada!\n";
    auto numbers = lerNumeros();

    double result = numbers[0];

    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        result = result - numbers[i];
    }

    cout << "Resultado da subtração: " << result << "\n";
}

void executarMultiplicacao() {
    cout << "\nMULTIPLICAÇÃO selecionada!\n";
    auto numbers = lerNumeros();

    double result = numbers[0];

    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        result = result * numbers[i];
    }

    cout << "Resultado da multiplicação: " << result << "\n";
}

void executarDivisao() {
    cout << "\nDIVISÃO selecionada!\n";
    auto numbers = lerNumeros();

    double result = numbers[0];
    bool divisaoValida = true;

    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        if (numbers[i] == 0) {
            cout << "Erro: divisão por zero! Operação cancelada.\n";
            divisaoValida = false;
            break;
        }

        result = result / numbers[i];
    }

    if (divisaoValida) {
        cout << "Resultado da divisão: " << result << "\n";
    }
}

void executarParOuImpar() {
    int numero;

    cout << "\nPAR OU ÍMPAR selecionado!\n";
    cout << "Informe um número inteiro: ";
    cin >> numero;

    if (numero % 2 == 0) {
        cout << "O número " << numero << " é PAR.\n";
    } else {
        cout << "O número " << numero << " é ÍMPAR.\n";
    }
}

void executarPorcentagem() {
    double numero;
    double porcentagem;
    double result;

    cout << "\nPORCENTAGEM selecionada!\n";
    cout << "Informe o número total: ";
    cin >> numero;

    cout << "Informe a porcentagem que deseja calcular (sem o símbolo %): ";
    cin >> porcentagem;

    result = (porcentagem / 100) * numero;

    cout << "Resultado: " << result << "\n";
}

void executarMediaAritmetica() {
    cout << "\nMÉDIA selecionada!\n";

    double quant = 0;
    double total = 0;
    auto numbers = lerNumeros();

    quant = numbers.size();

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        total += numbers[i];
    }

    double result = total / quant;

    cout << "\nA média dos números informados é: " << result << "\n";
}
