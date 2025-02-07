#include "deck.h"
#include <iostream>
#include <vector>
#include <cstdlib>

Deck::Deck() {
    std::vector<std::string> suits = { "Spades", "Hearts", "Diamonds", "Clubs" };
    std::vector<std::string> ranks = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };

    for (auto & suit : suits)
    {
        for (auto & rank : ranks)
        {
            deck.emplace_back(rank, suit);
        }
    }
}

void Deck::print_deck()
{

    for (auto & card : deck) {
        std::cout << std::get<0>(card) << " of " << std::get<1>(card) << " | ";
    }
}

std::vector<std::tuple<std::string, std::string>> Deck::get_deck()
{
    return deck;
}

std::tuple<std::string, std::string> Deck::draw_card()
{
    return deck[0];
}

// std::tuple<std::string, std::string> Deck::return_card()
// {
//     deck.emplace();
// }

void Deck::shuffle_deck()
{
    std::vector<std::tuple<std::string, std::string>> copy_deck;
    for (auto & i : deck)
    {
        int idx = rand() % deck.size();
        copy_deck.emplace_back(deck[idx]);
        deck.erase(deck.begin() + idx);
    }
    deck.swap(copy_deck);

}

int Deck::deck_size()
{
    return deck.size();
}