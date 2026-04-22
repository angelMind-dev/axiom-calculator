#include "operations/complex.h"

#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

void executarRegressaoLinear() {
    cout << "\nREGRESSÃO LINEAR selecionada!\n";

    int n;
    cout << "Quantos pontos (x, y) deseja informar? ";
    cin >> n;

    if (n <= 0) {
        cout << "Número de pontos inválido! Deve ser maior que 0.\n";
        return;
    }

    vector<double> x(n);
    vector<double> y(n);

    for (int i = 0; i < n; i++) {
        cout << "Informe x[" << i + 1 << "]: ";
        cin >> x[i];

        cout << "Informe y[" << i + 1 << "]: ";
        cin >> y[i];
    }

    double somaX = 0;
    double somaY = 0;

    for (int i = 0; i < n; i++) {
        somaX += x[i];
        somaY += y[i];
    }

    double mediaX = somaX / n;
    double mediaY = somaY / n;

    double numerador = 0;
    double denominador = 0;

    for (int i = 0; i < n; i++) {
        numerador += (x[i] - mediaX) * (y[i] - mediaY);
        denominador += (x[i] - mediaX) * (x[i] - mediaX);
    }

    if (denominador == 0) {
        cout << "Erro: denominador zero (provavelmente todos os x iguais); regressão indeterminada.\n";
        return;
    }

    double b = numerador / denominador;
    double a = mediaY - b * mediaX;

    cout << "\nEquação da reta de regressão linear:\n";
    cout << "y = " << a << " + " << b << " * x\n";

    double valorX;
    char resposta;

    cout << "\nDeseja calcular y para um valor de x específico? (s/n): ";
    cin >> resposta;

    if (tolower(static_cast<unsigned char>(resposta)) == 's') {
        cout << "Informe o valor de x: ";
        cin >> valorX;

        double valorY = a + b * valorX;
        cout << "Para x = " << valorX << ", y = " << valorY << "\n";
    }
}

void executarIntegralNumerica() {
    cout << "\nINTEGRAL SIMPLES: NUMÉRICA selecionada!\n";
    cout << "Função padrão: f(x) = x²\n";

    double a;
    double b;

    cout << "Informe o limite inferior (a): ";
    cin >> a;

    cout << "Informe o limite superior (b): ";
    cin >> b;

    int n = 1000;
    double h = (b - a) / n;
    double integral = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        integral += x * x * h;
    }

    cout << "O valor aproximado da integral de f(x) de " << a << " a " << b << " é: " << integral << "\n";
}

void executarDerivadaNumerica() {
    cout << "\nDERIVADA NUMÉRICA selecionada!\n";
    cout << "Função padrão: f(x) = x²\n";

    double x;

    cout << "Informe o ponto x onde deseja calcular a derivada: ";
    cin >> x;

    double h = 1e-5;
    double derivada = ((x + h) * (x + h) - (x - h) * (x - h)) / (2 * h);

    cout << "A derivada de f(x) no ponto x = " << x << " é aproximadamente: " << derivada << "\n";
}
