#pragma once

#include <vector>
#include <iostream>
#include "deck.h"
#include "hand.h"
#include "card.h"

class Game {
public:
  Game() = default;
  ~Game() = default;

  void start_game();
  void reset_game();

  int calculate_hand(Hand hand);

  void deal_card(Hand hand);

  void initial_deal();
  void dealer_turn();
  void player_turn();

  void check_winner();

private:
  Deck deck;
  Hand dealer;
  Hand player;

  bool player_blackjack = false;
  bool dealer_blackjack = false;
};
