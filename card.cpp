#include "card.h"
#include <tuple>
#include <string>

Card::Card(std::tuple<std::string, std::string> card) {
  suit = std::get<0>(card);
  rank = std::get<1>(card);
  calculate_points();
}

void Card::calculate_points() {
  try {
    int number = std::stoi(suit);
    points = number;
  } catch (const std::invalid_argument& e) {
    if (suit == "Ace") {
      points = 1;
    } else {
      points = 10;
    }
  }
}

std::string Card::get_rank() {
  return rank;
}

std::string Card::get_suit() {
  return suit;
}

int Card::get_points() {
  return points;
}