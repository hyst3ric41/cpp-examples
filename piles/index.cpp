#include <iostream>

using namespace std;

/**
 * Pilas.
 * 
 * Una pila es una estructura de datos de entradas ordenadas
 * tales que solo se pueden introducir y eliminar por un extremo,
 * llamado cima. También son conocidas como estructuras
 * LIFO (Last In, First Out). Esto tiene como consecuencia que el
 * orden en que los elementos salen es inverso al orden en que
 * los elementos ingresaron a la pila.
 * 
 * Las operaciones más frecuentes en este tipo de estructuras son:
 * - push(). Ingresa un elemento a la cima de la pila.
 * - pop(). Elimina un elemento de la pila.
 * 
 * Cada elemento (o nodo) de la pila está compuesto por dos partes:
 * - El contenido del elemento (int, float, bool, etc.).
 * - Un puntero que señala a la sig. posición de la pila. En caso
 * de ser el primer elemento en insertarse, dicho puntero valdrá
 * NULL.
 */
struct Nodo {
    int valor;
    Nodo *siguiente;
};

void push(Nodo *&pilaActual, int valor);

int main() {

    /**
     * Crear pila (nodo genesis).
     */
    Nodo *pila = NULL;

    cout << "Valor de pila: " << pila << endl;
    int numero = 0;
    cout << "Ingresa un número: ";
    cin >> numero;
    push(pila, numero);
    cout << "Valor de pila: " << pila << endl;

    return 0;
}

// Función para agregar elemento en la cima de la pila 
void push(Nodo *&pila, int valor) {
    /**
     * Reservar espacio en memoria para almacenar nuevo nodo
     * 
     * La palabra reservada 'new' es un simil de la utilidad malloc()
     * y sirve para reservar un espacio en memoria equivalente al peso
     * del tipo u objeto que se le coloque en frente.
     * 
     * Por ejemplo, al ejecutar 'new int' se estarían reservando 4 bytes
     * en memoria, y entonces se estaría retornando una dirección en memoria
     * que habría que almacenar en un puntero.
     */
    Nodo *nodo = new Nodo();
    // Asignando dato del nodo
    nodo->valor = valor;
    // Asignando puntero a siguiente nodo
    nodo->siguiente = pila;
    pila = nodo;
}