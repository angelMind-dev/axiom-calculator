#include "operations/advanced.h"
#include "operations/basic.h"

#include <cmath>
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
    
using namespace std;

namespace {
string removerAcentos(const string& texto) {
    string acentuados = "áàãâäÁÀÃÂÄéèêëÉÈÊËíìîïÍÌÎÏóòõôöÓÒÕÔÖúùûüÚÙÛÜçÇ";
    string substitutos = "aaaaaAAAAAeeeeEEEEiiiiIIIIoooooOOOOOuuuuUUUUcC";

    string resultado = texto;

    for (size_t i = 0; i < resultado.size(); i++) {
        for (size_t j = 0; j < acentuados.size(); j++) {
            if (resultado[i] == acentuados[j]) {
                resultado[i] = substitutos[j];
                break;
            }
        }
    }

    return resultado;
}
}

void executarLogaritmo() {
    string tipo;
    int tipo_int = 0;

    cout << "\nLOGARITMOS selecionado!\n";
    cout << "1 - Logaritmo na base 10\n";
    cout << "2 - Logaritmo na base e (natural)\n";
    cout << "3 - Logaritmo em base personalizada\n";
    cout << "Informe o tipo de logaritmo desejado (com número ou nome): ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, tipo);

    tipo = removerAcentos(tipo);

    for (auto& c : tipo) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    stringstream ss(tipo);
    if (!(ss >> tipo_int)) {
        tipo_int = 0;
    }

    double numero;
    double base;

    cout << "Informe o número (deve ser maior que 0): ";
    cin >> numero;

    if (numero <= 0) {
        cout << "Erro! O número deve ser maior que 0.\n";
        return;
    }

    if (tipo == "logaritmo na base 10" || tipo_int == 1) {
        double result = log10(numero);
        cout << "Resultado do logaritmo na base 10: " << result << "\n";
    } else if (tipo == "logaritmo na base e" || tipo == "logaritmo natural" || tipo_int == 2) {
        double result = log(numero);
        cout << "Resultado do logaritmo natural: " << result << "\n";
    } else if (tipo == "logaritmo em base personalizada" || tipo_int == 3) {
        cout << "Informe a base (deve ser maior que 0 e diferente de 1): ";
        cin >> base;

        if (base <= 0 || base == 1) {
            cout << "Erro! A base deve ser maior que 0 e diferente de 1.\n";
            return;
        }

        double result = log(numero) / log(base);
        cout << "Resultado do logaritmo na base " << base << ": " << result << "\n";
    } else {
        cout << "Opção inválida para logaritmo.\n";
    }
}

void executarFuncoesTrigonometricas() {
    string tipo;
    int tipo_int = 0;
    const double PI = acos(-1.0);

    cout << "\nFUNÇÕES TRIGONOMÉTRICAS selecionada!\n";
    cout << "1 - Normal\n";
    cout << "2 - Inversa (arc)\n";
    cout << "3 - Hiperbólica\n";
    cout << "Informe a função desejada (com número ou nome): ";
    cin >> tipo;

    tipo = removerAcentos(tipo);

    for (auto& c : tipo) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    stringstream ss(tipo);
    if (!(ss >> tipo_int)) {
        tipo_int = 0;
    }

    double angulo;

    cout << "Informe o ângulo em graus: ";
    cin >> angulo;

    double radianos = angulo * (PI / 180.0);

    if (tipo == "normal" || tipo_int == 1) {
        cout << "Seno: " << sin(radianos) << "\n";
        cout << "Cosseno: " << cos(radianos) << "\n";
        cout << "Tangente: " << tan(radianos) << "\n";
    } else if (tipo == "inversa" || tipo == "arc" || tipo_int == 2) {
        cout << "Arco Seno: " << asin(sin(radianos)) * (180.0 / PI) << " graus\n";
        cout << "Arco Cosseno: " << acos(cos(radianos)) * (180.0 / PI) << " graus\n";
        cout << "Arco Tangente: " << atan(tan(radianos)) * (180.0 / PI) << " graus\n";
    } else if (tipo == "hiperbolica" || tipo_int == 3) {
        cout << "Seno Hiperbólico: " << sinh(radianos) << "\n";
        cout << "Cosseno Hiperbólico: " << cosh(radianos) << "\n";
        cout << "Tangente Hiperbólica: " << tanh(radianos) << "\n";
    } else {
        cout << "Opção inválida para funções trigonométricas.\n";
    }
}

void executarFatorial() {
    cout << "\nFATORIAL selecionado!\n";

    int numero;
    unsigned long long fatorial = 1;

    cout << "Informe um número inteiro não negativo (MÁXIMO DE APENAS até o número 20): ";
    cin >> numero;

    if (numero < 0) {
        cout << "Erro! O número deve ser não negativo.\n";
        return;
    }

    for (int i = 1; i <= numero; ++i) {
        fatorial *= i;
    }

    cout << "O fatorial de " << numero << " é: " << fatorial << "\n";
}

void executarConversoes() {
    cout << "\nCONVERSÕES selecionada!\n";
    cout << "Escolha o tipo de conversão:\n";
    cout << "1 - Celsius para Fahrenheit\n";
    cout << "2 - Fahrenheit para Celsius\n";
    cout << "3 - Quilômetros para Milhas\n";
    cout << "4 - Milhas para Quilômetros\n";
    cout << "5 - Graus para radianos\n";
    cout << "6 - Radianos para graus\n";

    int escolha;
    cout << "Informe o número da conversão desejada (apenas o número): ";
    cin >> escolha;

    double valor;
    double convertido;
    const double PI = acos(-1.0);

    if (escolha == 1) {
        cout << "Informe a temperatura em Celsius: ";
        cin >> valor;

        convertido = (valor * 9.0 / 5.0) + 32.0;
        cout << valor << " graus Celsius equivalem a " << convertido << " graus Fahrenheit.\n";
    } else if (escolha == 2) {
        cout << "Informe a temperatura em Fahrenheit: ";
        cin >> valor;

        convertido = (valor - 32.0) * 5.0 / 9.0;
        cout << valor << " graus Fahrenheit equivalem a " << convertido << " graus Celsius.\n";
    } else if (escolha == 3) {
        cout << "Informe a distância em Quilômetros: ";
        cin >> valor;

        convertido = valor * 0.621371;
        cout << valor << " quilômetros equivalem a " << convertido << " milhas.\n";
    } else if (escolha == 4) {
        cout << "Informe a distância em Milhas: ";
        cin >> valor;

        convertido = valor / 0.621371;
        cout << valor << " milhas equivalem a " << convertido << " quilômetros.\n";
    } else if (escolha == 5) {
        cout << "Informe o ângulo em Graus: ";
        cin >> valor;

        convertido = valor * (PI / 180.0);
        cout << valor << " graus equivalem a " << convertido << " radianos.\n";
    } else if (escolha == 6) {
        cout << "Informe o ângulo em Radianos: ";
        cin >> valor;

        convertido = valor * (180.0 / PI);
        cout << valor << " radianos equivalem a " << convertido << " graus.\n";
    } else {
        cout << "Opção de conversão inválida.\n";
    }
}

void executarExponenciaisEspeciais() {
    cout << "\nEXPONENCIAIS ESPECIAIS selecionada!\n";

    double numero;

    cout << "Informe um número: ";
    cin >> numero;

    double exp_result = exp(numero);
    double exp2_result = pow(2.0, numero);
    double exp10_result = pow(10.0, numero);

    cout << "e elevado a " << numero << " é: " << exp_result << "\n";
    cout << "2 elevado a " << numero << " é: " << exp2_result << "\n";
    cout << "10 elevado a " << numero << " é: " << exp10_result << "\n";
}

void executarArredondamento() {
    cout << "\nARREDONDAMENTO selecionada!\n";

    double numero;

    cout << "Informe um número: ";
    cin >> numero;

    cout << "Arredondado para baixo (floor): " << floor(numero) << "\n";
    cout << "Arredondado para cima (ceil): " << ceil(numero) << "\n";
    cout << "Arredondado para o inteiro mais próximo (round): " << round(numero) << "\n";
}

void executarMaximoMinimo() {
    cout << "\nMÁXIMO e MÍNIMO selecionada!\n";

    auto numbers = lerNumeros();

    double maximo = numbers[0];
    double minimo = numbers[0];

    for (int i = 1; i < static_cast<int>(numbers.size()); i++) {
        if (numbers[i] < minimo) {
            minimo = numbers[i];
        }

        if (numbers[i] > maximo) {
            maximo = numbers[i];
        }
    }

    cout << "O valor MÁXIMO é: " << maximo << "\n";
    cout << "O valor MÍNIMO é: " << minimo << "\n";
}

void executarFuncoesEstatisticas() {
    cout << "\nFUNÇÕES ESTATÍSTICAS selecionado!\n";

    auto numbers = lerNumeros();

    double media = 0;
    double soma = 0;

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        soma += numbers[i];
    }

    media = soma / numbers.size();

    double variancia = 0;

    for (int i = 0; i < static_cast<int>(numbers.size()); i++) {
        variancia += pow(numbers[i] - media, 2);
    }

    variancia /= numbers.size();

    double desvioPadrao = sqrt(variancia);

    cout << "Média: " << media << "\n";
    cout << "Variância: " << variancia << "\n";
    cout << "Desvio Padrão: " << desvioPadrao << "\n";
}

void executarEquacoes() {
    cout << "\nEQUAÇÕES selecionada!\n";
    cout << "Escolha a equação desejada:\n";
    cout << "1 - Equação do 2º grau\n";
    cout << "2 - Regra de três simples\n";

    int escolha;
    cout << "Informe o número da equação desejada (apenas o número): ";
    cin >> escolha;

    if (escolha == 1) {
        double a;
        double b;
        double c;

        cout << "Informe os coeficientes a, b e c da equação ax² + bx + c = 0:\n";
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;

        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "A equação não possui raízes reais.\n";
        } else {
            double raiz1 = (-b + sqrt(delta)) / (2 * a);
            double raiz2 = (-b - sqrt(delta)) / (2 * a);

            cout << "As raízes da equação são: " << raiz1 << " e " << raiz2 << "\n";
        }
    } else if (escolha == 2) {
        cout << "A opção Regra de três simples ainda não possui lógica implementada no código original.\n";
    } else {
        cout << "Opção de equação inválida.\n";
    }
}

void executarSequenciasMatematicas() {
    cout << "\nSEQUÊNCIAS MATEMÁTICAS selecionada!\n";
    cout << "Escolha o tipo de sequência:\n";
    cout << "1 - Sequência de Fibonacci\n";
    cout << "2 - Sequência Aritmética (PA)\n";
    cout << "3 - Sequência Geométrica (PG)\n";

    int escolha;
    cout << "Informe o número da sequência desejada (apenas o número): ";
    cin >> escolha;

    int termos;

    if (escolha == 1) {
        cout << "\nInforme o número de termos da sequência de Fibonacci: ";
        cin >> termos;

        int a = 0;
        int b = 1;
        int proximo;

        cout << "Sequência de Fibonacci:\n\n";

        for (int i = 0; i < termos; i++) {
            cout << a << " ";
            proximo = a + b;
            a = b;
            b = proximo;
        }

        cout << "\n\n";
    } else if (escolha == 2) {
        double primeiroTermo;
        double razao;

        cout << "\nInforme o primeiro termo da PA: ";
        cin >> primeiroTermo;

        cout << "Informe a razão da PA: ";
        cin >> razao;

        cout << "Informe o número de termos da PA: ";
        cin >> termos;

        cout << "Sequência Aritmética (PA):\n\n";

        for (int i = 0; i < termos; i++) {
            cout << primeiroTermo + i * razao << " ";
        }

        cout << "\n\n";
    } else if (escolha == 3) {
        double primeiroTermo;
        double razao;

        cout << "\nInforme o primeiro termo da PG: ";
        cin >> primeiroTermo;

        cout << "Informe a razão da PG: ";
        cin >> razao;

        cout << "Informe o número de termos da PG: ";
        cin >> termos;

        cout << "Sequência Geométrica (PG):\n";

        for (int i = 0; i < termos; i++) {
            cout << primeiroTermo * pow(razao, i) << " ";
        }

        cout << "\n";
    } else {
        cout << "Opção de sequência inválida.\n";
    }
}
