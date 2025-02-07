#pragma once

#include <vector>
#include <iostream>

class Deck {
public:
    // Constructor and Destructor
    Deck();                  // Constructor
    ~Deck() = default;                 // Destructor (if needed)

    // Member function prototype
    void print_deck();       // Function to print deck
    void shuffle_deck();
    int deck_size();
    std::vector<std::tuple<std::string, std::string>> get_deck();
    std::tuple<std::string, std::string> draw_card();
    std::tuple<std::string, std::string> return_card();

private:
    // Member variables
    int Ace = 1;
    int J = 10;
    int Q = 10;
    int K = 10;

    std::vector<std::string> suits = {"Hearts", "Diamonds", "Spades"};
    std::vector<std::tuple<std::string, std::string>> deck;

};
