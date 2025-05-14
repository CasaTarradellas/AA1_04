#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Card.h"
#include <stdexcept>
#include <algorithm>

class Player
{
	std::string id;
	std::list<Card> hand;


public:
	void setID(std::string name)
	{
		id = name;
	}

	std::string GetID()
	{
		return id;
	}

	void InsertCard(const Card& card)
	{
		std::list<Card>::iterator it;
		it = hand.begin();
		hand.insert(it, card);
	}
	Card GetCard() const {
		if (hand.empty()) throw std::runtime_error("No hay cartas en la mano");
		int index = rand() % hand.size();
		std::list<Card>::const_iterator it = hand.begin();
		std::advance(it, index);
		return *it;
	}

	Card GetCard(const Suit& suit)
	{
		if (hand.empty()) throw std::runtime_error("No hay cartas en la mano");
		std::list<Card>::iterator it;
		it = hand.begin();
		for (; it != hand.end(); it++)
		{
			if (it->getSuit() == suit)
			{
				return *it;
			}
		}
		throw std::runtime_error("No hay cartas de ese palo");
	}

	friend std::ostream& operator<<(std::ostream& os, const Player& player);

	void SortCards()
	{
		std::list<Card> sortedHand;
		std::list<Card>::const_iterator it = hand.begin();

		for (; it != hand.end(); ++it)
		{
			std::list<Card>::iterator insertIt = sortedHand.begin();

			while (insertIt != sortedHand.end())
			{
				if (it->getValue() > insertIt->getValue()) break;
				else if (it->getValue() == insertIt->getValue() &&
					static_cast<int>(it->getSuit()) < static_cast<int>(insertIt->getSuit()))
					break;

				++insertIt;
			}

			sortedHand.insert(insertIt, *it);
		}

		hand = sortedHand;
	}
};