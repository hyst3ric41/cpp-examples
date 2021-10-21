#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159

int main() {

    typedef unsigned short int _int;
    _int option; 
    cout << "Seleccione el ejercicio a ejecutar: " << endl;

    cout << "(?) Salir" << endl;
    cout << "(1) Convertir un texto a mayúsculas" << endl;
    cout << "(2) Extraer el menor valor de un arreglo" << endl;
    cout << "(3) Ordenar un arreglo por bubble sort (On^2)" << endl;
    cout << "(4) Producto de dos matrices (arreglos bidimensionales)" << endl;

    cout << endl;
    cin >> option;
    cout << endl;

    // Limpiando buffer
    cin.ignore(256, '\n');

    switch (option) {
        case 1: {
            /**
             * Convertir texto a mayúsculas.
             */
            char texto[50], resultado[50];
            cout << "Ingresa el texto a convertir: ";
            cin.getline(texto, 50);
            for (_int i = 0; i < 50; i++) {
                resultado[i] = toupper(texto[i]);
            }
            cout << "Resultado: " << resultado << endl;
        }
        break;
        case 2: {
            /**
             * Extraer el menor valor de un arreglo.
             */
            cout << "Introduce 10 valores numéricos: " << endl;
            _int j = 0;
            _int lowerValue;
            while (j < 10) {
                _int current;
                cout << "Valor del elemento " << j + 1 << ": ";
                cin >> current;
                // Ingresar primer valor del arrego
                if (j == 0) lowerValue = current;
                // Actualizando menor valor en caso de que el actual sea menor incluso
                if (current < lowerValue) lowerValue = current;
                j++;
            }
            cout << "El número " << lowerValue << " es el menor" << endl;
        }
        break;
        case 3: {
            /**
             * Ordenar un arreglo por bubble sort (On^2).
             */
            cout << "Introduce 10 valores numéricos: " << endl;
            _int a = 0;
            _int arreglo[10];
            while (a < 10) {
                cout << "Valor del elemento " << a + 1 << ": ";
                cin >> arreglo[a];
                a++;
            }
            // Bucle que itera miembro a miembro
            for (_int b = 0; b < 10; b++) {
                // Bucle que itera para comparar y hacer swap
                for (_int c = 0; c < 9; c++) {
                    if (arreglo[c] > arreglo[c + 1]) {
                        _int aux = arreglo[c];
                        arreglo[c] = arreglo[c + 1];
                        arreglo[c + 1] = aux;
                    }
                }
            }
            cout << "Arreglo ordenado:" << endl;
            a = 0;
            while (a < 10) {
                cout << arreglo[a];
                if (a < 9) cout << ", ";
                a++;
            }
        }
        break;
        case 4: {
            /**
             * Producto de dos matrices (arreglos bidimensionales).
             * 
             * Al declarar una matriz, primero se indica la cantidad de filas
             * y luego la cantidad de columnas.
             */
            const _int max = 3;
            _int a[max][max];
            _int b[max][max];

            cout << "Introduce valores numéricos para la 1ra matriz de " << max << "x" << max << ":" << endl;
            for (_int i = 0; i < max; i++) {
                for (_int j = 0; j < max; j++) {
                    cout << "Matriz 1, valor F:" << i << ", ";
                    cout << "C:" << j << " = ";
                    cin >> a[j][i];
                }
            }

            cout << endl << "Introduce valores numéricos para la 2da matriz de " << max << "x" << max << ":" << endl;
            for (_int i = 0; i < max; i++) {
                for (_int j = 0; j < max; j++) {
                    cout << "Matriz 2, valor F:" << i << ", ";
                    cout << "C:" << j << " = ";
                    cin >> b[j][i];
                }
            }

            cout << endl << "Matriz 1:" << endl;
            for (_int i = 0; i < max; i++) {
                for (_int j = 0; j < max; j++) {
                    cout << a[j][i] << " ";
                    if (j == (max - 1)) cout << endl;
                }
            }

            cout << endl << "Matriz 2:" << endl;
            for (_int i = 0; i < max; i++) {
                for (_int j = 0; j < max; j++) {
                    cout << b[j][i] << " ";
                    if (j == (max - 1)) cout << endl;
                }
            }

            cout << endl << "Producto resultante:" << endl;
            for (_int i = 0; i < max; i++) {
                for (_int j = 0; j < max; j++) {
                    _int result = 0;
                    for (_int k = 0; k < max; k++) {
                        result = result + a[i][k] * b[k][j];
                    }
                    cout << result << " ";
                    if (j == (max - 1)) cout << endl;
                }
            }
            
        }
        break;
    }

    cout << endl;
    return 0;
}

void loop() {}