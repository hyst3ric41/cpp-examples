#include <iostream>
#include <string>
/**
 * La biblioteca fstream permite manipular archivos de
 * texto externos al programa.
 * 
 * Como buena práctica recomendada por el desarrollador, evitar
 * en lo posible manipular más de un archivo a la vez.
 */
#include <fstream>

using namespace std;

int main() {

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * ------------------------------------- Creación de archivos -------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * ofstream es una definición de tipo (typedef) de un objeto que recibirá
     * como parámetro el nombre del archivo a crear.
     * 
     * La siguiente línea ya estará creando el archivo como tal.
     */
    ofstream MyFileA("nombre_archivo.txt");

    /**
     * Comprobando si el archivo existe. Aplicaciones tipo firewall o el
     * mismo sistema operativo puede bloquear la creación de archivos.
     */
    if (MyFileA.is_open()) {
        /**
         * Tal como sucede con la librería iostream (cin, cout), el operador de
         * inserción permite escribir directamente sobre el archivo creado.
         */
        MyFileA << "¡Hola, " << endl << "mundo!";
    }

    /**
     * Atendiendo a las buenas prácticas sugeridas por el desarrollador, 
     * proceder a cerrar el canal de steaming de datos del archivo una
     * vez se termine de manipularlo.
     */
    MyFileA.close();

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * -------------------------------------- Lectura de archivos -------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * ifstream es un objeto que permitirá leer el archivo con el nombre
     * indicado como parámetro.
     */
    ifstream MyFileB("nombre_archivo.txt");

    // Comprobando si el archivo existe
    if (MyFileB.is_open()) {
        /**
         * getline() es un método de la biblioteca istream que gracias al
         * namespace std se llama directamente.
         * 
         * La siguiente línea lee la primera línea del archivo. Cuando getline
         * ha detectado una secuencia de escape de salto (\n), entonces cesará
         * la lectura.
         * 
         * La próximma vez que se llame a getline con el mismo stream de datos,
         * en este caso, MyFileB, se obtendrá la segunda línea del archivo.
         */
        string line1, line2;
        getline(MyFileB, line1);
        getline(MyFileB, line2);

        cout << line1 << endl;
        cout << line2 << endl;
    }
 
    return 0;
}