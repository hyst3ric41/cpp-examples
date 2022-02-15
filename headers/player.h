// Otras bibliotecas
#include <iostream>
#include <string>

using namespace std;

/**
 * Este es un archivo de encabezado en donde se escribirán
 * todas las definiciones a exportar. Como buena práctica, se suele
 * emplear un archivo con el mismo nombre terminado con la extensión
 * .cpp que contenga todas las declaraciones y funcionalidades de los
 * miembros aquí definidos, pero para este caso en particular es
 * suficiente el archivo de cabecera.
 * 
 * La definición a exportar debe de comenzar y terminar siempre
 * con dos sentencias específicas; #ifndef y #endif, respectivamente,
 * mientras que #define exportará la definición que se ubique entre
 * ambos acotes.
 */
#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        string name;
        int power;
        Player(string name) {
            this->name = name;
            this->power = 10;
        }
        Player(string name, int power) {
            this->name = name;
            this->power = power;
        }
        void attack() {
            cout << "Jugador " << this->name << " ataca con " << this->power << " de poder." << endl;
        }
    protected:
        void jump() {
            cout << "Jugador " << this->name << " salta." << endl;
        }
};

#endif