#include <iostream>

using namespace std;

int main() {

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * ------------------------------------------ Uniones ---------------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * Una unión es un tipo de estructura especial que sirven para
     * almacenar en el mismo espacio de memoria diferentes valores que
     * no son necesariamente del mismo tipo, siempre siendo uno a la vez
     * pero no todos al mismo tiempo.
     * 
     * La siguiente estructura permite tener una variable que contenga
     * o bien un número o bien un caracter:
     */
    union caracter_alfanumerico {
        int numero;
        char letra;
    };
    
    /**
     * Una vez que la estructura está definida, se declara una variable
     * utilizando como tipo el nombre de la unión, y escribiendo un par
     * de llaves para inicializar su valor.
     */
    caracter_alfanumerico variable = {'W'};
    /**
     * La siguiente impresión a consola mostrará 87 ya que es la posición de
     * la letra W en la tabla ASCII. Esto es así porque un char equivale a 1 byte,
     * y el sistema ASCII utiliza 1 byte para representar a una gama de caracteres.
     */
    cout << "(union) Valor como int: " << variable.numero << endl;
    // Lo anterior es comprobable imprimiendo la "versión" char:
    cout << "(union) Valor como char: " << variable.letra << endl;
    // O bien casteando el tipo int hacia un char:
    cout << "(union) Valor como int casteado a char: " << (char) variable.numero << endl;

    cout << endl;

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * --------------------------------------- Enumeraciones ------------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * La estructura enum establece un rango de valores previsibles que por de
     * por debajo equivaldrá a una lista numérica ordenada. Lo anterior permite
     * crear n variables que apunten al mismo elemento de dicha lista sin necesidad
     * de reservar más memoria mas que la usada por la enumeración.
     * 
     * La siguiente enumeración utiliza por defecto números (comenzando por el 0)
     * al no tener un valor asignado directamente a cada elemento.
     */
    enum dias_semana { lunes, martes, miercoles, jueves };
    
    dias_semana ayer = martes;
    dias_semana hoy = miercoles;

    cout << "(enum) Valor de ayer: " << ayer << endl; // 1
    cout << "(enum) Valor de ayer + 1: " << ayer + 1 << endl; // 2
    cout << "(enum) Valor de hoy: " << hoy << endl; // 2

    cout << endl;

    /**
     * En el siguiente caso, se asignará a cada elemento enumerado un caracter,
     * el cual por debajo se almacenará en su representación numérica también:
     */
    enum vocales { primera = 'A', segunda = 'E', tercera = 'I' };

    vocales vocal1;
    vocal1 = segunda;
    vocal1 = primera;
    vocales vocal3 = tercera;

    cout << "(enum) Valor de vocal1: " << vocal1 << endl;
    cout << "(enum) Valor de vocal1 casteado a char: " << (char) vocal1 << endl;
    cout << "(enum) Valor de vocal3: " << vocal3 << endl;

    return 0;
}