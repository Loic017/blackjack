#include <vector>
#include <iostream>
#include "deck.h"
#include "hand.h"
#include "card.h"
#include "game.h"

void Game::start_game() {
  std::cout << "Starting blackjack game..." << std::endl;
  deck.shuffle_deck();
}

void Game::reset_game() {
  std::cout << "Resetting blackjack game..." << std::endl;
  deck = Deck();
}

int Game::calculate_hand(Hand hand) {
  return hand.get_points();
};

void Game::deal_card(Hand hand) {
  Card card = Card(deck.draw_card());
  hand.add_card(card);
}

void Game::initial_deal() {
  std::cout << "-------------- Dealing player cards" << std::endl;
  deal_card(player);
  deal_card(player);
  std::cout << "Player's hand:" << std::endl;
  player.show_hand();
  std::cout << "Player's points: " << player.get_points() << std::endl;

  std::cout << "-------------- Dealing dealer cards" << std::endl;
  deal_card(dealer);
  deal_card(dealer);
  std::cout << "Dealer's face up card:" << std::endl;
  dealer.show_a_card(0);
}

void Game::dealer_turn() {
  std::cout << "-------------- Dealer's turn" << std::endl;
  std::cout << "Dealer's hand:" << std::endl;
  dealer.show_hand();
  std::cout << "Dealer's Points: " << dealer.get_points() << std::endl;

  while (true) {
    if (dealer.get_points() < 17) {
      std::cout << "Dealer gets another card" << std::endl;
      deal_card(dealer);
    } else if (dealer.get_points() == 21) {
      std::cout << "Blackjack!" << std::endl;
      dealer_blackjack = true;
      return;
    } else {
      std::cout << "Dealer's points above 17, turn ended" << std::endl;
      return;
    }
    std::cout << "Dealer's hand:" << std::endl;
    dealer.show_hand();
    std::cout << "Dealer's Points: " << dealer.get_points() << std::endl;
  }
}

void Game::player_turn() {
  std::cout << "-------------- Player's turn" << std::endl;
  while (true) {
    int input;
    while (true) {
      std::cout << "Hit or stand (1 or 2)?" << std::endl;
      std::cin >> input;

      if (input == 1 || input == 2) {
        break;
      } else {
        std::cout << "Invalid input, please try again" << std::endl;
      }
    }

    if (input == 1) {
      std::cout << "Dealing a card" << std::endl;
      deal_card(player);
      player.show_hand();
      std::cout << "Points: " << player.get_points() << std::endl;

      if (player.get_points() > 21) {
        std::cout << "Bust! Dealer's turn" << std::endl;
        return;
      }

      if (player.get_points() == 21) {
        std::cout << "Blackjack!" << std::endl;
        player_blackjack = true;
        return;
      }

    } else if (input == 2) {
      std::cout << "Stand chosen, dealer's turn" << std::endl;
      return;
    }
  }
}

void Game::check_winner() {
  std::cout << "Calculating Points" << std::endl;
  int player_points = player.get_points();
  int dealer_points = dealer.get_points();

  std::cout << "Player's points: " << player_points << std::endl;
  std::cout << "Dealer's points: " << dealer_points << std::endl;

  if (player_points > 21) {
    if (dealer_points > 21) {
      std::cout << "Both players bust! Draw!" << std::endl;
    } else {
      std::cout << "Player busts! Dealer wins!" << std::endl;
    }
  } else if (dealer_points > 21) {
    std::cout << "Dealer busts! Player wins!" << std::endl;
  } else {
    if (player_points > dealer_points) {
      std::cout << "Player wins!" << std::endl;
    } else if (player_points < dealer_points) {
      std::cout << "Dealer wins!" << std::endl;
    } else {
      std::cout << "It's a draw!" << std::endl;
    }
  }
}

}