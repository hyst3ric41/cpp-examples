#include <iostream>
#include <cmath>

/**
 * Declaración de constantes.
 * 
 * Cualquier directiva de preprocesador no lleva (;).
 */
#define PI 3.14159

using namespace std;

int main() {
    /**
     * Tipos de variables:
     * 
     * - int. Valores numéricos con capacidad de hasta 4 bytes con
     * signo (desde −2,147,483,648 hasta 2,147,483,647).
     */
    int numero = -2147483648;
    cout << "int: " << numero << endl;
    /**
     * - short int. Igual que int pero con capacidad de hasta 2 bytes con
     * signo (desde -32,768 hasta 32,767).
     */
    short int numeroCorto = 32767;
    cout << "short int: " << numeroCorto << endl;
    /**
     * - long long int. Igual que int pero con capacidad de hasta 8 bytes con
     * signo (desde	−9,223,372,036,854,775,808 hasta 9,223,372,036,854,775,807).
     */
    long long int numeroLargo = 9223372036854775807;
    cout << "long long int: " << numeroLargo << endl;
    /**
     * - char. Cualquier tipo de valor alfanumérico, es decir, compuesto por 1 byte. Puede
     * almacenar cualquier caracter unicode (letras, números, símbolos, etc.).
     * 
     * Se puede inicializar utilizando las comillas simples para indicar el caracter
     * directamente, o mediante su representación equivalente en la tabla ASCII.
     */
    char caracter = '#';
    char equivDecimal = 35; // equivalente en sistema decimal
    char equivHexadecimal = 0x23; // equivalente en sistema hexadecimal
    char equivOctal = 043; // equivalente en sistema octal
    cout << "char: " << caracter << ", with ASCII value of " << int(caracter) << endl;
    cout << "char initialization equivalents: " << equivDecimal << ", " << equivHexadecimal << ", " << equivOctal << endl;
    /**
     * - bool. Valores lógicos; false, para indicar una negación; y true, para
     * indicar una aserción.
     */
    bool booleano = true;
    cout << "bool: " << booleano << endl;
    /**
     * - float. Valores numéricos con punto decimal con capacidad de hasta 4 bytes. Soporta
     * hasta 7 dígitos.
     */
    float decimalCorto = 301.782;
    cout << "float: " << decimalCorto << endl;
    /**
     * - double. Valores numéricos con punto decimal con capacidad de hasta 8 bytes. Soporta
     * hasta 16 dígitos.
     * 
     * Al poder almacenar valores tan grandes, es posible escribirlos como notación
     * científica. El caso anterior es útil en, p. ej., escribir la velocidad de la luz
     * o la masa de un electrón.
    */
    double decimalLargo = -9329130411205.812349329015;
    double decimalNotCie = 4.9e3; /*4.9*10^3 (4900)*/
    cout << "double: " << decimalLargo << endl;
    cout << "double with cientific notation: " << decimalNotCie << endl;

    cout << endl;

    /**
     * Para obtener el peso en bits de la variable en cuestión, se invoca el método
     * sizeof() integrada por C++.
     */
    cout << "decimalLargo var size: " << sizeof(decimalLargo) << " bytes" << endl;

    cout << endl;

    /**
     * int pesa 4 bytes, es decir 32 bits (1 byte = 8 bits... 8 x 4 = 32), pero los computadores
     * utilizan 1 bit para representar el signo (+/-) del valor numérico, dejando entonces 31 bits
     * disponibles para tomar. Pensando en que 1 bit es un valor binario (1 o 0), entonces 2^31
     * es igual a 4,292,967,296. Este valor es repartido entre ambos signos para representar
     * valores numéricos enteros.
     * 
     * La palabra reservada 'unsigned' permite modificar el comportamiento de un
     * tipo de dato numérico indicando la ausencia de signo (comunmente del signo negativo),
     * permitiendo que su rango máximo de valor se incremente al doble. Al dejar de utilizar
     * 1 bit para el signo, entonces un 'unsigned int' puede almacenar hasta 4,294,967,295
     * valores.
     */
    unsigned int numeroSinSigno = 4294967295;
    cout << "unsigned int: " << numeroSinSigno << endl;

    cout << endl;

    /**
     * 'cin' significa Console Input, función provista por <iostream>
     * y sirve para ingresar valores por consola.
     */
    char caracterPorConsola;
    cout << "Ingresa un caracter alfanumérico: ";
    cin >> caracterPorConsola;
    cout << "Valor por consola: " << caracterPorConsola << endl;

    cout << endl;

    /**
     * Operadores aritméticos.
     * (+) - Suma.
     * (-) - Resta.
     * (*) - Multiplicación.
     * (/) - División.
     * (%) - Residuo. Solo resultará al realizarlo sobre números enteros.
     */
    cout << "Suma de (5 + 5): " << (5 + 5) << endl;
    cout << "Resta de (9 - 40): " << (9 - 40) << endl;
    cout << "Multiplicación de (6 * 2): " << (6 * 2) << endl;
    float a = 8.0 / 3.0; // <-- Es importante marcar los decimales porque sino para el compilar son ints, y entonces retornará el resultado en enteros
    cout << "División de (8.0 / 3.0): " << a << endl;
    short int b = 15 % 4;
    cout << "Residuo de (15 / 4) ... (4 x 3 = 12, sobran 3 para 15): " << b << endl;

    cout << endl;

    /**
     * Jerarquía de operaciones.
     * 
     * Las siguientes operaciones son el orden de resolución en la
     * ejecución de una operación matemática compuesta por varios tipos de operaciones:
     * 1. Operaciones entre paréntesis.
     * 2. Multiplicación, división y/o residuo.
     * 3. Suma y resta.
     * 
     * En caso de que se encuentren dos o más operaciones encadenadas del mismo orden de
     * prioridad, entonces se resolverá dicho segmento de izquierda a derecha.
     */
    cout << "14-8/2*3+1: " << 14-8/2*3+1 << endl; // 3
    cout << "(14-8)/2*3+1: " << (14-8)/2*3+1 << endl; // 10
    cout << "14-(8/2*3)+1: " << 14-(8/2*3)+1 << endl; // 3
    cout << "14-8/2*(3+1): " << 14-8/2*(3+1) << endl; // -2
    cout << "(14-8)/2*(3+1): " << (14-8)/2*(3+1) << endl; // 12

    cout << endl;

    /**
     * Operadores lógicos y de comparación.
     * 
     * A diferencia de las operaciones aritméticas, las operaciones lógicas
     * o de comparación se ejecutan de derecha a izquierda.
     * 
     * - (&&) --> AND 
     * - (||) --> OR
     * - (!)  --> NOT
     * - (==) --> equals
     * - (!=) --> not equals
     * - (<)  --> less than
     * - (>)  --> greater than
     * - (<=) --> less or equal than
     * - (>=) --> greater  or equal than
     */
    cout << "(5 < 9): " << (5 < 9) << endl;
    cout << "(-3 == -3): " << (-3 == -3) << endl;
    cout << "(9 >= 7 && true == false): " << (9 >= 7 && true == false) << endl;

    cout << endl;

    /**
     * Librería cmath.
     * 
     * Contiene decenas de funciones matemáticas. A continuación, las más importantes:
     * 
     * - pow(int1, int2). Eleva el número indicado en int1 hacia la potencia
     * indicada en int2.
     */
    double potencia = pow(5, 3); // 125
    cout << "(5^5): " << potencia << endl;
    /**
     * - sqrt(double1). Obtiene la raíz cuadrada del número indicado en el double1.
     */
    double raizCuadrada = sqrt(100.0); // 10.0
    cout << "(√100.0): " << raizCuadrada << endl;
    /**
     * - sin(double1). Función seno del valor del ángulo en radianes indicado
     * en el double1.
     */
    double seno = sin(0.523599); // sin(30°)
    cout << "(seno de 30°): " << seno << endl;
    /**
     * - cos(double1). Función coseno del valor del ángulo en radianes indicado
     * en el double1.
     */
    double coseno = cos(1.0472); // cos(60°)
    cout << "(coseno de 60°): " << coseno << endl;
    /**
     * - tan(double1). Función tangente del valor del ángulo en radianes indicado
     * en el double1.
     */
    double tangente = tan(0.785398); // tan(45°)
    cout << "(tangente de 45°): " << tangente << endl;

    cout << endl;

    /**
     * Constantes.
     * 
     * Existen dos formas de declarar una constante:
     * - Directiva #define. Ver cabecera del archivo.
     * - Palabra reservada 'const'. Se antepone la palabra reservada 'const' antes
     * de una inicialización de valor común y corriente.
     * 
     * No existen diferencia entre ambas.
     */
    cout << "Constante mediante directiva: " << PI << endl;
    const float gravedad = 9.8;
    cout << "Constante mediante palabra reservada const: " << gravedad << endl;

    return 0;
}

void loop() {}