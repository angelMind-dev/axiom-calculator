#include "menu.h"

#include <iostream>
#include <limits>

using namespace std;

namespace {
int lerOpcaoMenu() {
    int opcao;
    cin >> opcao;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return opcao;
}
}

int escolherCategoria() {
    cout << R"(
=============================================
                AXIOM CALC
=============================================
Escolha uma categoria:

1 - Operações básicas
2 - Operações intermediárias
3 - Operações avançadas
4 - Funções complexas
0 - Encerrar

Opção: )";

    return lerOpcaoMenu();
}

int menuBasicas() {
    cout << R"(
-------------------- BÁSICAS -----------------
1 - Soma
2 - Subtração
3 - Multiplicação
4 - Divisão
5 - Par ou ímpar
6 - Porcentagem
7 - Média aritmética
0 - Voltar

Opção: )";

    return lerOpcaoMenu();
}

int menuIntermediarias() {
    cout << R"(
--------------- INTERMEDIÁRIAS ---------------
8  - Potência
9  - Raiz
10 - Média ponderada
11 - Módulo ou valor absoluto
0  - Voltar

Opção: )";

    return lerOpcaoMenu();
}

int menuAvancadas() {
    cout << R"(
---------------- AVANÇADAS --------------------
12 - Logaritmo
13 - Funções trigonométricas
14 - Fatorial
15 - Conversões
16 - Exponenciais especiais
17 - Arredondamento
18 - Máximo e mínimo
19 - Funções estatísticas
20 - Equações
21 - Sequências matemáticas
0  - Voltar

Opção: )";

    return lerOpcaoMenu();
}

int menuComplexas() {
    cout << R"(
---------------- COMPLEXAS --------------------
22 - Regressão linear
23 - Integral simples: numérica
24 - Derivada numérica
0  - Voltar

Opção: )";

    return lerOpcaoMenu();
}
