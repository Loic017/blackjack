#include "hand.h"

#include <vector>
#include <iostream>
#include "card.h"

void Hand::add_card(Card card) {
  cards.emplace_back(card);
}

void Hand::remove_card(int index) {}

void Hand::show_hand() {
  for (int i = 0; i < cards.size(); i++) {
    std::cout << cards[i].get_suit() << " of " << cards[i].get_rank() << std::endl;
  }
}

void Hand::total_points() {
  int total = 0;
  for (int i = 0; i < cards.size(); i++) {
    total += cards[i].get_points();
//    std::cout << cards[i].get_points();
  }
  points = total;
}

int Hand::get_points() {
  total_points();
  return points;
}

int Hand::get_size() {
    return cards.size();
}