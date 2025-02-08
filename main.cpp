#include <iostream>

#include "game.h"
#include "deck.h"
#include "card.h"
#include "hand.h"

int main() {

    Game game;
    game.start_game();
    game.initial_deal();
    game.player_turn();
    game.dealer_turn();
    game.check_winner();

    return 0;
}