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

    // Insertar cartas aleatorias
    for (int i = 0; i < numJugadores; i++)
    {
        juego.players[i].SortCards();
        std::cout << juego.players[i] << std::endl;
        std::cout << std::endl;
    }

    // Printear el deck
    std::cout << "Deck: " << juego.getDeck() << std::endl;

    // Player roba una carta
    char a;
    std::cout << "Pulsa cualquier tecla para Robar Carta: ";
    std::cin >> a;
    system("CLS");
    Card c = juego.GetNewCard();
    juego.players[0].InsertCard(c);
    juego.players[0].SortCards();

    std::cout << juego.players[0].GetID() << " ha robado una carta" << std::endl;

    std::cout << juego.players[0] << std::endl;
    // Printear el deck
    std::cout << "Deck: " << juego.getDeck() << std::endl;

    char b;
    std::cout << "Pulsa cualquier tecla para Descartar carta del deck: ";
    std::cin >> b;
    system("CLS");
    juego.DiscardCard(juego.deck.top());
    
    juego.PrintDiscarted();

    // Printear el deck
    std::cout << "Deck de descartes: " << juego.getDeckDiscarted() << std::endl;

    return 0;
}
