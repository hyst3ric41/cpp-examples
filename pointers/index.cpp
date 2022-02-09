#include <iostream>

using namespace std;

int main() {

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * ----------------------------------------- Punteros ---------------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * Para acceder al puntero de una variable existente, se antepone
     * como prefijo el símbolo amperson (&):
     */
    int variable = 5;
    cout << "Contenido de la variable: " << variable << endl;
    cout << "Tamaño en memoria de la variable: " << sizeof(variable) << " bytes" << endl;
    cout << "Dirección hexadecimal de la variable: " << &variable << endl; // P. ej. 0x7ffd89e2389c

    cout << endl;
    
    /**
     * Para crear un puntero, se utiliza el caracter asterisco (*) como
     * prefijo del nombre del puntero:
     * 
     * El tipado de un puntero hace referencia únicamente al tipo de variable
     * del puntero de la variable original.
     * 
     * Importante:
     * El puntero solo necesitará la dirección en memoria del primer byte de
     * la variable puesto que gracias al tipado ya sabe de antemano cuántos
     * espacios en memoria avanzar para conocer todo el espacio ocupado por
     * la variable a la que apunta.
     * 
     * Por ejemplo, el puntero de la variable char letra = 'a' no se puede asignar
     * al puntero int *b.
     */
    int *puntero = &variable;
    cout << "Contenido del puntero: " << puntero << endl;
    cout << "Dirección del puntero: " << &puntero << endl;
    /**
     * Para obtener el contenido de la variable original desde el puntero creado,
     * se utilza el caracter asterisco (*). A esta sintaxis se le conoce como
     * operador de indirección.
     */
    cout << "Contenido de la variable original: " << *puntero << endl;
    cout << "Tamaño en memoria del puntero: " << sizeof(puntero) << " bytes" << endl;

    cout << endl;

    /**
     * Así mismo, es posible crear una variable que apunte a exactamente la misma dirección
     * en memoria de una variable en en lugar de almacenar la dirección perse.
     * 
     * Es decir, una referencia puede manipularse exactamente igual que como la variable orignal,
     * cuando en un puntero primero tiene que usarse el operador de indirección para poder manipular
     * el contenido de la variable.
     */
    int &referencia = variable;
    referencia += 9;
    cout << "Contenido de la referencia: " << referencia << endl;
    cout << "Contenido original de la variable referenciada: " << variable << endl;

    cout << endl;

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * ----------------------------------- Aritmética de punteros -------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * El caso de los arreglos es especial. Cuando un arreglo se define, en realidad se trata
     * de un puntero que retornará un valor en específico según la sintaxis de corchetes ([]).
     * 
     * Partiendo del hecho de que un entero (int) equivale a 4 bytes en memoria, el sig.
     * arreglo pesa 16 bytes:
     */
    int arreglo[] = { 10, -99, 4, 54 };
    cout << "Dir. hexadecimal del arreglo: " << arreglo << endl; // Tan solo imprimiendo el arreglo se obtiene su dirección en memoria
    /**
     * Cuando se ejecuta la sig. operación, se está avanzando en la tabla de memoria +1 veces el peso
     * del tipo de variable al que el arreglo pertenece. Eso puede verse en los últimos digitos de la
     * dirección del arreglo.
     */
    cout << "Dir. hexadecimal del arreglo en index 0: " << arreglo << endl;
    cout << "Dir. hexadecimal del arreglo en index 1: " << arreglo + 1 << endl;
    cout << "Dir. hexadecimal del arreglo en index 2: " << arreglo + 2 << endl;
    /**
     * Al ser un arreglo entonces un puntero, también se puede utilizar el operador de indirección
     * para acceder al contenido de el espacio en memoria de determinada posición en el arreglo: 
     */
    cout << "Contenido de index 0: " << *(arreglo + 0) << endl;
    cout << "Contenido de index 3: " << *(arreglo + 3) << endl;

    return 0;
}

void loop() {}