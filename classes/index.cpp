#include <iostream>
#include <string>

using namespace std;

/**
 * La diferencia entre una clase y una estructura es que la estructura (struct) tiene
 * miembros de acceso público por defecto, mientras que en una clase sus miembros son
 * privados por defecto, mientras que también puede utilizar modificadores de
 * acceso (public, private, protected) para restringir o permitir el acceso de sus
 * miembros desde fuera de la clase.
 * 
 * Además, una estructura no tiene un método constructor.
 */
class Pokemon {
    // En el caso de C++, se abre una lista de los miembros que serán públicos
    public:
        // Miembros de la clase con acceso público
        string name;
        int power;
        bool captured = false; // <-- Propiedad con valor por defecto
        void attack() {
            cout << name << " ataca con " << power << " de poder" << endl;
        }
        void sleep() {
            if (sleeping) {
                cout << name << " ya estába durmiendo..." << endl;
            } else {
                cout << name << " comenzó a dormir..." << endl;
            }
            sleeping = true;
        }
        Pokemon &updateName(string name) {
            /**
             * En otros casos, el puntero this será útil cuando se necesita
             * acceder a la instancia desde la clase misma.
             */
            cout << this->name << " ahora es " << name << "!" << endl;
            this->name = name;
            /**
             * También puede ser útil para retornar la instancia misma y
             * encadenar métodos de forma que pueda lograrse una lectura
             * de código más humana, como por ejemplo:
             * 
             * instance.play().stop("abc").others(9);
             * 
             * Se retorna el puntero (*) de this y se indica el tipo y símbolo de
             * amperson (&) en el método para indicar que se tomará el valor
             * del puntero, que en este caso viene a ser la instancia.
             */
            return *this;
        }
        /**
         * Un constructor es un bloque de código que se ejecutará al momento de
         * que se cree una nueva instancia de clase y que además puede recibir
         * parámetros de todo tipo.
         * 
         * Es posible hacer una sobrecarga de constructores en donde la única
         * diferencia entre ellos es la cantidad y tipos de parámetros que reciben.
         * 
         * La siguiente sintaxis de constructor:
         *   Pokemon(string a, int b) {
         *     name = a;
         *     power = b;
         *   }
         * Es equivalente a la sintaxis de asignación in-line:
         *   Pokemon(string a, int b) : name(n), power(b) {
         *     // code
         *   }
         * Pero, en la práctica es más conveniente utilizar el puntero
         * this el cual es una autoreferencia de la clase, y permite
         * referirse a las propiedades de clase de forma adecuada y sin ambiguedades:
         */
        Pokemon(string name, int power) {
            this->name = name;
            this->power = power;
            cout << "-->> Constructor de " << name << " ejecutado <<--" << endl;
        }
        /**
         * Sintaxis de destructor, comenzando siempre por virgulilla (~).
         * 
         * C++ invoca en tiempo de ejecución al método destructor cuando la
         * instancia del objeto ya no se necesita más, pero es buena práctica
         * invocarlo manualmente para preveer escenarios donde se asigne memoria
         * de forma dinámica dentro del objeto, como p. ej., en funciones. A
         * diferencia de otros lenguajes de programación, C++ no tiene un
         * recolector de basura que haga esta tarea por nosotros.
         * 
         * Es importante que lo anterior solo sucede de forma automática cuando
         * se crean instancias de clase en las que su memoria fue asignada por el
         * compilador, o en otras palabras, cuando no se usa la sintaxis new. En este
         * caso en particular, es obligatorio liberar la memoria manualmente.
         */
        ~Pokemon() {
            cout << "-->> Destructor de " << name << " ejecutado <<--" << endl;
        }
    private:
        // Miembros de la clase con acceso privado
        bool sleeping = false;
};

int main() {

    // Declarando nueva instancia de clase
    Pokemon pikachu = Pokemon("Pikachu", 30);
    pikachu.power = 35;

    cout << "Pokémon 1: " << endl;
    cout << "Nombre: " << pikachu.name << endl;
    cout << "Poder: " << pikachu.power << endl;
    cout << "Capturado: " << pikachu.captured << endl;
    pikachu.sleep();
    pikachu.updateName("Raichu");
    pikachu.sleep();

    cout << endl;

    /**
     * Al igual que con las estructuras (struct), la sintaxis new creará una instancia on-demand
     * en tiempo de ejecución:
     */
    Pokemon *charizard = new Pokemon("Charizard", 50);
    charizard->captured = true;

    cout << "Pokémon 2: " << endl;
    cout << "Nombre: " << charizard->name << endl;
    cout << "Poder: " << charizard->power << endl;
    cout << "Capturado: " << charizard->captured << endl;
    charizard->attack();

    cout << endl;

    // Liberando memoria dinámica
    cout << "Liberando memoria de la instancia de " << charizard->name << " ya que " << pikachu.name << " lo hará automáticamente" << endl;
    // La palabra reservada delete liberará la memoria ocupada por el puntero indicado
    delete charizard;

    return 0;
}

void loop() {}