#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Card.h"
#include "Player.h"
#include "Game.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    int numJugadores = 0;
    std::cout << "Cuantos jugadores jugaran al juego: ";
    std::cin >> numJugadores;
    system("CLS");

    Game juego(numJugadores); 

    Player juan;
    juan.setID("Juan");

    // Insertar cartas aleatorias
    for (int i = 0; i < 5; ++i) {
        Card c;
        juan.InsertCard(c);
    }

    juan.SortCards();

    std::cout << juan << std::endl;

    Card robada = juan.GetCard();
    std::cout << "Carta aleatoria robada: (" << static_cast<int>(robada.getSuit()) << ", " << robada.getValue() << ")" << std::endl;

    return 0;
}
