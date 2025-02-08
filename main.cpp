#include <iostream>

#include "deck.h"
#include "card.h"
#include "hand.h"

int main() {

    Deck deck;
    deck.print_deck();
    Card card_1 = Card(deck.draw_card());
    deck.shuffle_deck();
    deck.print_deck();
    Card card_2 = Card(deck.draw_card());

    Hand player_1;
    player_1.add_card(card_1);
    player_1.add_card(card_2);
    player_1.show_hand();


    return 0;
}