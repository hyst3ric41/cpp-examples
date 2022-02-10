#include <iostream>
#include <string>

using namespace std;

class Auto {
    public:
        string marca;
        string modelo;
        /**
         * El modificador static tiene el mismo comportamiento que en cualquier
         * otro lenguaje de programación que soporte POO.
         * 
         * Este modificador establece a un miembro de la clase apuntando siempre
         * a la misma dirección de memoria sin importar cuantas instancias se
         * generen. En todas las instancias, esta miembro siempre será el mismo.
         * 
         * C++ no permite inicializar a un miembro estático, por lo que primero
         * hay que declarar al miembro (ya sea una propiedad o función) y después
         * definirlo por fuera de la clase.
         */
        static int llantas; // <-- Solo la declaración
        static int contador;
        Auto(string marca, string modelo) {
            this->marca = marca;
            this->modelo = modelo;
            contador++;
        }
        void encender();
    /**
     * El modificador protected expone miembros de la clase accesibles desde la
     * clase que los define (esta) y la clase que extiendan de la misma, pero bloqueando
     * el acceso desde las instancias generadas.
     */
    protected:
        bool usado = false;
};

/**
 * C++ ofrece el operador de resolución de alcance (::), que entre otras
 * cosas, permite definir a un miembro de clase por fuera de la misma.
 * 
 * Más información del operador:
 * + https://www.geeksforgeeks.org/scope-resolution-operator-in-c/
 */
void Auto::encender() {
    cout << this->marca << " " << this->modelo << " de " << this->llantas << " llantas arrancando..." << endl;
}
// En este caso, el operador es útil para definir también al miembro estático
int Auto::llantas = 4;
int Auto::contador = 0;

/**
 * La sintaxis para definir una clase que extienda de otra clase
 * es mediante el operador :, simil a extends en otros lenguajes de programación
 * como Dart, Javascript o Java.
 * 
 * Todos los miembros public y protected serán extendidos a esta nueva clase.
 * 
 * Una característica particular de C++ es que se puede definir una capa de
 * acceso encima de la herencia. Es decir, establecer un modificador de acceso
 * a la clase heredada en cuestión. Si se omite este modificador, por defecto
 * queda expuesta con public.
 */
class Sedan : public Auto {
    public:
        int puertas = 4;
        string color;
        /**
         * A diferencia de otros lenguajes donde la keyword super llama al
         * constructor de la clase padre, en C++ se utiliza la sintaxis de
         * dos puntos (:).
         */
        Sedan(string marca, string modelo, string color) : Auto(marca, modelo) {
            this->color = color;
            this->usado = true;
        }
        void derrapar() {
            cout << "El sedan " << this->marca << " " << this->modelo << " está derrapando!" << endl;
        }
};

class Coupe : public Auto {
    public:
        int puertas = 2;
        string motor;
        Coupe(string marca, string modelo, string motor) : Auto(marca, modelo) {
            this->motor = motor;
        }
};

/**
 * Existirán casos de uso donde se necesite heredar de múltiples clases
 * a la vez.
 */
class Hatchback : public Sedan, public Coupe {
    public:
        Hatchback(
            string marca,
            string modelo,
            string color,
            string motor
        ) : Sedan(marca, modelo, color), Coupe(marca, modelo, motor) {
            // ...
        }
        void describir() {
            /**
             * Este ejemplo en particual es un poco problemático puesto que tanto la clase
             * Sedan como Coupe extienden de la clase Auto, entonces Auto ha recibido dos
             * constructores, por lo que llamar a una propiedad de auto como "marca" puede ser
             * ambiguo para el compilador. Aprovechando el scope actual, el operador de resolución
             * de alcance (::) puede identificar a qué propiedad estoy refiriendome en específico.
             * 
             * Como se puede ver, la propiedad "motor" solo existe en la clase Coupe, por lo que no
             * hace falta utilizar el operador de resolución de alcance.
             */
            cout << "Soy un hatckback " << Sedan::marca << " " << Coupe::modelo << " de motor " << this->motor << endl;
        }
};

int main() {

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * --------------------------------- Miembros de clase estáticos ----------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     */
    Auto *auto1 = new Auto("Kia", "Rio");
    auto1->encender();

    Auto *auto2 = new Auto("Nissan", "Altima");
    auto2->encender();

    cout << endl;

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * ------------------------------------------- Herencia -------------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     */
    Sedan *auto3 = new Sedan("Volkswagen", "Jetta", "Rojo");
    auto3->derrapar();

    Coupe *auto4 = new Coupe("Mini", "Cooper", "2.1 lt");
    cout << "Coupe con " << auto4->puertas << " puertas" << endl;
    auto4->encender();

    Hatchback *auto5 = new Hatchback("Mazda", "3", "Gris espacial", "2.5 lt");
    auto5->describir();
    auto5->Sedan::encender(); // <-- Operador :: para resolver alcance (scope)

    cout << endl;

    cout << "Autos creados: " << Auto::contador << endl;

    /**
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * ---------------------------------------- Polimorfismo ------------------------------------------
     * ////////////////////////////////////////////////////////////////////////////////////////////////
     * 
     * Es una intención de programación que sugiere utilizar una estructura en común entre
     * dos o más objetos con el propósito de manipular un mensaje sintácticamente igual al
     * otro pero proveniente de dos tipos distintos. Por ejemplo:
     * 
     * class Sala {
     *   void reproducir(Largometraje x);
     * }
     * 
     * class Largometraje {
     *   ...
     * }
     * 
     * class Pelicula : public Largometraje {
     *   ...
     * }
     * 
     * class Documental : public Largometraje {
     *   ...
     * }
     * 
     * En el caso anterior, los objetos distintos Pelicula y Documental son sintácticamente
     * consecuentes a Largometraje, por lo que el método Reproducir de la clase sala sería
     * reutilizable. A eso se le conoce como polimorfismo.
     */

    return 0;
}