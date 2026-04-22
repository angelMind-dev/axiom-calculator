#include "operations/intermediate.h"
#include "operations/basic.h"

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void executarPotencia() {
    double base;
    double expoente;

    cout << "\nPOTÊNCIA selecionada!\n";
    cout << "Informe a base: ";
    cin >> base;

    cout << "Informe o expoente: ";
    cin >> expoente;

    double result = pow(base, expoente);

    cout << "Resultado da potência: " << result << "\n";
}

void executarRaiz() {
    double numero;
    double indice;

    cout << "\nRAIZ selecionada!\n";
    cout << "Informe o número: ";
    cin >> numero;

    cout << "Digite o índice da raiz desejada (2 para quadrada, 3 para cúbica, etc): ";
    cin >> indice;

    double result = pow(numero, 1.0 / indice);

    cout << "Resultado da raiz: " << result << "\n";
}

void executarMediaPonderada() {
    cout << "\nMÉDIA PONDERADA selecionada!\n";

    vector<double> pesos;
    double peso = -1;
    double totalPesos = 0;
    double total = 0;

    auto numbers = lerNumeros();

    for (int j = 0; j < static_cast<int>(numbers.size()); j++) {
        cout << "Informe o peso do " << (j + 1) << "º número: ";
        cin >> peso;
        pesos.push_back(peso);
    }

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        total += numbers[i] * pesos[i];
        totalPesos += pesos[i];
    }

    if (totalPesos == 0) {
        cout << "Erro! A soma dos pesos é zero.\n";
    } else {
        double result = total / totalPesos;
        cout << "Resultado da média ponderada: " << result << "\n";
    }
}

void executarModulo() {
    double numero;

    cout << "\nMÓDULO ou VALOR ABSOLUTO selecionada!\n";
    cout << "Informe um número: ";
    cin >> numero;

    double result = abs(numero);

    cout << "Resultado do módulo ou valor absoluto: " << result << "\n";
}
