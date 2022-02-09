#include <iostream>
// Utilidades para manipulación de arreglos de caracteres (cadenas de texto)
#include <cstring>

using namespace std;

/**
 * Un registro (o estructura) es una agrupación de datos del mismo o diferentes
 * tipos definida por la palabra reservada 'struct'. Esta estructura de datos funciona
 * por debajo con punteros.
 * 
 * Estructura de datos llamada Auto.
 */
struct Auto {

    /**
     * Como se puede osbervar, una estructura puede tener miembros que describan
     * el valor de una propiedad o funciones que puedan acceder al scope de la
     * estructura misma de una forma completamente abstracta y encapsulada. Todos
     * los miembros de la estructura son de acceso público.
     * 
     * Este concepto es el preámbulo a la Programación Orientada a Objetos (POO).
     */

    bool isNew = true;
    char marca[50];
    int puertas;

    void arrancar() {
        cout << "Encendiendo auto " << marca << "..." << endl;
    }
    
};

// Prototipo de función que recibe dos parámetros y retorna una estructura de datos llamada Auto
Auto crearAuto(int, char[]);

int main() {

    /**
     * Un registro se declara colocando como tipo de dato el nombre de la
     * estructura creada.
     */
    Auto jetta;
    jetta.puertas = 4;
    strcpy(jetta.marca, "Volkswagen"); // <-- La mejor manera de asignar un valor char array a una estructura...

    /**
     * La siguientes sentencias declaran e inicializan a la estructura de un tirón, diferenciandose
     * por el momento en el que la memoria necesaria es asignada (tiempo de compilación vs tiempo de
     * ejecución).
     * 
     * En el primer caso, el proceso de compilación asigna de forma automática el espacio en
     * memoria requerido para la estructura:
     */
    Auto mustang = Auto();
    strcpy(mustang.marca, "Ford");
    /**
     * O trambién utilizando llaves ubicando los valores en el orden en que fueron declaradas
     * las propiedades en la estructura.
     */
    Auto frontier = { true, "Nissan", 4 };

    /**
     * En el segundo caso, se declara un puntero en donde se crea on-demand una instancia
     * de la estructura mediante la palabra reservada new, y es en tiempo de ejecución cuando
     * el espacio en memoria se asigna.
     */
    Auto *prius = new Auto();
    // En este caso, para acceder al valor de cada propiedad se utiliza la sintaxis de flecha (->)
    prius->puertas = 4;
    
    cout << "Marca del auto 1: " << jetta.marca << endl;
    cout << "Marca del auto 2: " << mustang.marca << endl;
    cout << "Marca del auto 3: " << frontier.marca << endl;
    cout << "Puertas del auto 4: " << prius->puertas << " puertas" << endl;

    /**
     * Así mismo, el registro puede usarse como tipado de una función:
     */
    Auto rio = crearAuto(4, "Kia");
    cout << "Marca del auto 5: " << rio.marca << endl;

    // Llamando función dentro de estructura
    rio.arrancar();

    return 0;
}

// Método para crear una estructura Auto
Auto crearAuto(int puertas, char marca[]) {
    Auto a;
    a.puertas = puertas;
    strcpy(a.marca, marca);
    return a;
}