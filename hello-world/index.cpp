/**
 * #include es una directiva que utiliza el preprocesador de
 * C++ para incluir código de una biblioteca Siempre se ubican
 * apenas inicie el archivo y no llevan punto y coma (;).
 * 
 * Comúnmente se les llama header files o archivos de cabecera.
 * 
 * Cualquier directiva de preprocesador no lleva (;).
 */
#include <iostream>

/**
 * Un namespace esa concepto de programación que busca contener un grupo
 * de nombres como métodos, variables, objetos, etc. Importando este namespace,
 * se evita llamar, p. ej., a 'std::cout' o 'std::endl' en el método main().
 */
using namespace std;

/**
 * main() es un método conocido como 'función principal' que
 * contiene las configuraciones del programa, como condiciones
 * iniciales, inicialización de librerías, etc. Es el primer
 * bloque de código que siempre se lee apenas el código
 * se ejecuta.
 * 
 * Por estándar, retorna un número entero positivo para indicar
 * en tiempo de ejecución que el método terminó sin errores.
 */
int main() {
    /**
     * El operador '<<' es un operador de inserción, tal como escribir
     * 'texto' + 'otro texto' en lenguajes de alto nivel como Dart o Javascript.
     * Funciona solo con objetos de salida (aquellos que imprimen en consola).
     * 
     * 'cout' significa Console Output, función provista por <iostream>
     * y sirve para imprimir por consola. Así mismo, 'endl' adjunta
     * un salto de línea (\n) al valor impreso por consola. La instrucción
     * 'endl' puede concatenarse cuantas veces se desee:
     * ... << endl << endl << endl;
     */
    cout << "Hola, mundo!" << endl;
    /**
     * Las secuencias de escape son instrucciones especiales que le indican
     * a la salida por consola un comportamiento en específico, y existen los
     * siguientes:
     */
    // --> \n : Salto de línea. Coloca el cursor en el renglón siguiente.
    cout << "Hasta luego...\n\n...¡2 saltos de línea dados! \n";
    // --> \b : Retroceso. Coloca el cursor en la última posición - 1.
    cout << "Demostración de retroceso\b\b\b\b[¡reemplazado!]" << endl;
    // --> \r : Retorno de carro. Coloca el cursor en el inicio del renglón actual.
    cout << "Texto original" << "\rSoy un retorno de carro..." << endl;
    // --> \t : Tabulación. Agrega espacios a modo de tabulación.
    cout << "Línea sin tabular" << endl << "\tLínea tabulada" << endl << "\t\tLínea doble tabulada" << endl;
    return 0;
}

/**
 * loop() es un método en donde se colocan todas las instrucciones que
 * van a realizarse de forma repetitiva.
 */
void loop() {}

/**
 * Es posible agregar cuantas funciones se deseen siempre y cuando
 * no se llamen igual que los dos métodos principales, main() y loop().
 * 
 * En el siguiente ejemplo, se creó un método que retorna el número 1.
 */
int getOne() {
    return 1;
}