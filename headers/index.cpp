#include <iostream>
#include <string>
/**
 * Importando el archivo de cabecera personalizado.
 */
#include "player.h"

using namespace std;

int main() {

    Player p1 = Player("María");
    Player p2 = Player("Ivan", 50);

    p1.attack();
    p2.attack();

    return 0;
}