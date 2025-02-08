#pragma once

#include <vector>
#include <iostream>
#include "card.h"

class Hand {
public:
  Hand() = default;              // Constructor
  ~Hand() = default;                 // Destructor (if needed)

  void add_card(Card card);
  void remove_card(int index);
  void show_hand();
    void show_a_card(int idx);
  void total_points();
    int get_points();
  int get_size();

private:
    std::vector<Card> cards;
    int points;
};
