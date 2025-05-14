#pragma once
#include <vector>
#include <stack>
#include "Player.h"

class Game
{
	
	
	std::stack<Card> deckDiscarted;

public:

	std::stack<Card> deck;
	std::vector<Player> players;

	Game(int numPlayers)
	{
		std::string nombresDisponibles[8] = { "Pepe", "Juan", "Alberto", "Frigusterio", "Emanuel", "Aura", "Rodolfo", "Eustaquio Abichuela" };

		for (int i = 0; i < numPlayers; i++)
		{
			Player player;
			player.setID(nombresDisponibles[i]);
			players.push_back(player);
		}

		for (int i = 0; i < 100; i++)
		{
			Card c;
			deck.push(c);
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < numPlayers; j++)
			{
				players[j].InsertCard(GetNewCard());
			}
		}
	}

	int getDeck() const
	{
		return deck.size();
	}

	int getDeckDiscarted() const
	{
		return deckDiscarted.size();
	}

	Card GetNewCard()
	{
		if (deck.empty()) 
		{ 
			throw std::runtime_error("Deck is empty"); 
		}
		Card c = deck.top();
		deck.pop();
		return c;
	}

	void DiscardCard(const Card& card)
	{
		deckDiscarted.push(card);
	}

	void PrintDiscarted() const
	{
		if (!deckDiscarted.empty())
		{
			const Card& carta = deckDiscarted.top();
			std::cout << "Ultima carta descartada: (";

			switch (carta.getSuit())
			{
			case Suit::HEART:   std::cout << "HEART"; break;
			case Suit::DIAMOND: std::cout << "DIAMOND"; break;
			case Suit::SPADE:   std::cout << "SPADE"; break;
			case Suit::CLUB:    std::cout << "CLUB"; break;
			}

			std::cout << ", " << carta.getValue() << ")" << std::endl;
		}
		else
		{
			std::cout << "No hay cartas descartadas." << std::endl;
		}
	}

};