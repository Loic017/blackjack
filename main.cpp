#include <iostream>

#include "deck.h"

int main() {

    Deck deck;
    deck.print_deck();
    deck.shuffle_deck();
    deck.print_deck();

    std::cout << std::endl;
    std::cout << "Getting one card";
    std::tuple<std::string, std::string> card = deck.draw_card();
    std::cout << std::get<0>(card) << std::endl;
    std::cout << std::get<1>(card) << std::endl;

    return 0;
}