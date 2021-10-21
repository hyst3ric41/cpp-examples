#include <iostream>

using namespace std;

/**
 * En C y C++, antes de escribir un método o función, primero
 * hace falta declarar su prototipo. Un prototipo le indica al
 * compilador cómo se llamará el método y qué parámetros recibirá.
 * 
 * Recordar que 'void' hace referencia a que el método en cuestión
 * no retornará ningún valor. Lo anterior técnicamente se le conoce como
 * procedimiento.
 */
void saludar();
int sumar(int a, int b); // No importa si se especifica un nombre de variable o no
bool esImpar(int); // En este caso, no se especifica un nombre del parámetro y funciona igual
void dividir(float &ref);
void reemplazar(int *a);
/**
 * Una sobrecarga de funciones sucede cuando se prototipan múltiples funciones
 * con el mismo nombre pero retornando distintos tipos de valor y recibiendo
 * distintos parámetros. Por ejemplo:
 */
short potencia(int);
bool potencia(double);
long potencia(int, int);

int main() {

    // Invocando procedimiento}
    saludar();

    // Sumando dos números invocando a método
    int numero = sumar(2, 3);
    cout << "El resultado de la suma es: " << numero << endl;
    bool impar = esImpar(numero);
    if (impar) {
        cout << "El número " << numero << " es impar" << endl;
    }

    /**
     * Es una práctica común pasar una variable hacia una
     * función y que sea recibida como referencia. De esta forma
     * se puede afectar a la variable original sin tener que
     * volver a realizar asignaciones.
     * 
     * Comprar método sumar() vs procedimiento dividir() para
     * ilustrar diferencia.
     * 
     * Importante:
     * Los arreglos unidimensionales y bidimensionales son pasados
     * siempre por referencia.
     */
    float decimal = 8.8;
    cout << "Variable decimal antes de dividir: " << decimal << endl;
    dividir(decimal);
    cout << "Variable decimal después de dividir: " << decimal << endl;

    /**
     * El ejemplo anterior aplica de la misma forma para punteros:
     */
    int metros = 30;
    cout << "Variable metros antes de reemplazar: " << metros << endl;
    reemplazar(&metros);
    cout << "Variable metros después de reemplazar: " << metros << endl;

    return 0;
}

// Procedimiento para imprimir un saludo por consola
void saludar() {
    cout << "¡Hola!" << endl;
}

// Método para sumar dos números y retornar el resultado
int sumar(int a, int b) {
    return a + b;
}

// Método para resolver si un número es par o impar
bool esImpar(int numero) {
    return (numero % 2) != 0;
}

// Procedimiento que divide un número entre dos
void dividir(float &ref) {
    ref = ref / 2.0;
}

// Procedimiento para reemplazar un número por 100
void reemplazar(int *puntero) {
    *puntero = 100;
}