#include <iostream>
// Utilidades para manipulación de arreglos de caracteres (cadenas de texto)
#include <cstring>

using namespace std;

/**
 * Un registro (o estructura) es una agrupación de datos, los cuales no
 * necesariamente son del mismo tipo. Se definen con la palabra 'struct'.
 */
struct Auto {
    bool isNew = true;
    char marca[50];
    int puertas;
};

Auto crearAuto(int, char[]);

int main() {

    /**
     * El registro se declara con el tipo de dato con el nombre de la estructura
     * creada.
     */
    Auto jetta;
    jetta.puertas = 4;
    strcpy(jetta.marca, "Volkswagen"); // Best approach to assign value to char array in struct...

    /**
     * También es posible asignar todos los valores de un solo tirón.
     */
    Auto frontier = { true, "Nissan", 4 };
    
    cout << "Marca del auto 1: " << jetta.marca << endl;
    cout << "Marca del auto 2: " << frontier.marca << endl;

    /**
     * Así mismo, el registro puede usarse como tipado de una función:
     */
    Auto rio = crearAuto(4, "Kia");
    cout << "Marca del auto 3: " << rio.marca << endl;

    return 0;
}

Auto crearAuto(int puertas, char marca[]) {
    Auto a;
    a.puertas = puertas;
    strcpy(a.marca, marca);
    return a;
}