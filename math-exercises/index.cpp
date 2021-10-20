#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159

int main() {

    unsigned short int option; 
    cout << "Seleccione el programa a ejecutar: " << endl;

    cout << "(?) Salir" << endl;
    cout << "(1) Área de un triángulo" << endl;
    cout << "(2) Volúmen de una esfera" << endl;
    cout << "(3) Promedio de notas" << endl;
    cout << "(4) Conversión de temperaturas" << endl;
    cout << "(5) Distancia entre puntos" << endl;

    cout << endl;
    cin >> option;
    cout << endl;

    switch (option) {
        case 1:
            /**
             * Área de un triángulo.
             */
            float base, altura, area;
            cout << "Ingrese base (cm): ";
            cin >> base;
            cout << "Ingrese altura (cm): ";
            cin >> altura;
            area = (base * altura) / 2;
            cout << "Área del triángulo: " << area << "cm²" << endl;
        break;
        case 2:
            /**
             * Volúmen de una esfera.
             */
            float radio, volumen;
            cout << "Ingrese radio (cm): ";
            cin >> radio;
            volumen = (4 / 3) * PI * pow(radio, 3);
            cout << "Área del triángulo: " << volumen << "cm³" << endl;
        break;
        case 3:
            /**
             * Promedio de notas.
             */
            float nota1, nota2, nota3, promedio;
            cout << "Ingrese nota 1: ";
            cin >> nota1;
            cout << "Ingrese nota 2: ";
            cin >> nota2;
            cout << "Ingrese nota 3: ";
            cin >> nota3;
            promedio = (nota1 + nota2 + nota3) / 3;
            cout << "Promedio total: " << promedio << endl;
        break;
        case 4:
            /**
             * Conversión de temperaturas.
             */
            float celsius, fahrenheit, kelvin;
            cout << "Ingrese temperatura (°C): ";
            cin >> celsius;
            fahrenheit = ((celsius * 9) / 5) + 32;
            kelvin = celsius + 273.15;
            cout << "Equivalente en Fahrenheit: " << fahrenheit << "°F" << endl;
            cout << "Equivalente en Kelvin: " << kelvin << "K" << endl;
        break;
        case 5:
            /**
             * Distancia entre puntos.
             * 
             * Fórmula:
             *      __________________________
             * d = √ (x2 - x1)^2 + (y2 - y1)^2
             */
            float x1, y1, x2, y2, distancia;
            cout << "Ingrese valor de X del P1: ";
            cin >> x1;
            cout << "Ingrese valor de Y del P1: ";
            cin >> y1;
            cout << "Ingrese valor de X del P2: ";
            cin >> x2;
            cout << "Ingrese valor de Y del P2: ";
            cin >> y2;
            distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            cout << endl << "Distancia entre P1 y P2: " << distancia << endl;
        break;
    }

    cout << endl;
    return 0;
}

void loop() {}