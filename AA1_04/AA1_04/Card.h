#pragma once
#include <iostream>

enum class Suit { HEART, DIAMOND, SPADE, CLUB };

class Card
{
	Suit suit;
	int value = 0;

public:
	Card()
	{
		value = rand() % 13 + 1;
		int r = rand() % 4;
		switch (r)
		{
		case 0: suit = Suit::HEART; break;
		case 1: suit = Suit::DIAMOND; break;
		case 2: suit = Suit::SPADE; break;
		case 3: suit = Suit::CLUB; break;
		default: suit = Suit::CLUB; break; // por seguridad
		}
	}


	Card(Suit s, int v) : suit(s), value(v) {}

	Suit getSuit() const { return suit; }
	int getValue() const { return value; }

	bool operator==(const Card& card) const {
		return suit == card.getSuit() && value == card.getValue();
	}
};
