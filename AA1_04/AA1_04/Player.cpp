#include "Player.h"

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	os << "Player " << player.id << ": ";

	for (std::list<Card>::const_iterator it = player.hand.begin(); it != player.hand.end(); ++it)
	{
		os << "(";

		switch (it->getSuit())
		{
		case Suit::HEART:   os << "HEART";   break;
		case Suit::DIAMOND: os << "DIAMOND"; break;
		case Suit::SPADE:   os << "SPADE";   break;
		case Suit::CLUB:    os << "CLUB";    break;
		}

		os << ", " << it->getValue() << ") ";
	}

	return os;
}