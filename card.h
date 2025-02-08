#pragma once

#include <vector>
#include <iostream>

class Card {
public:
    Card(std::tuple<std::string, std::string> card);                  // Constructor
    ~Card() = default;                 // Destructor (if needed)

    std::string get_rank();
    std::string get_suit();
    int get_points();

private:
    bool in_hand = false;
    bool is_discarded = false;

    void calculate_points();

    std::string suit;
    std::string rank;
    int points;
};
