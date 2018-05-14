/**
    Toshal Ghimire

    implementation of the made of Card Game

    worked with jerry and one other dude, Asian guy with glasses (forgot his name)
*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "CardGame.h"
#include "Player.h"
#include "Deck.h"



/**
    function that calls take turns until winner is found, first makes deck object and prints out useful information.

    @param hand size
    @return
*/
void CardGame::PlayGame(const int hand_size){
    std::cout<<"You are playing with hand size of "<<hand_size<<"!\n";

    //make a new deck and shuffle it
    delt_count_ = hand_size;
    deck_ = new Deck();
    deck_->Shuffle();

    ////print out players and deal cards to each players
    std::cout<<" Players\n-----------\n";
    for(auto a : players_){ //print name
            std::cout<<" "<<a->get_name()<<"\n";
            a->GiveCards(deck_->Draw(hand_size));
    }

    std::cout<<"\n";
    system("pause");
    system("cls");

    //loop that calls TakeTurn until game is over or deck runs out; checks hand in each loop
    while(this->won_ == false){
        for(auto a: players_){
            if(deck_->GetCardsLeft() == 0) {
                std::cout<< "Its a stalemate!";
                break;
            }else {
                this->TakeTurn(a);//takes turn
            }

            //Win check
            this->won_ = IsWinner(a->GetCards());
            if(this->won_ == true) {
                std::cout<<a->get_name()<<" has won the game!\n"<<std::endl;
                std::cout<<"Winning Hand:\n"<<CardStringify(a->GetCards())<<std::endl;
                break;
            }
        }

    }



};


/**
    Takes one turn with player object. asks where the player will draw from.
    returns the card to the hand, then asks player to choose what to discard.

    @param player pointer
    @return

*/
void CardGame::TakeTurn(Player *p){

    std::cout<<"\n< "<<p->get_name()<<"'s turn >\n\nYOUR HAND:\n"<<CardStringifyWithNums(p->GetCards())<<std::endl;

    std::string choice = "";
    std::cout<<"Where will you draw from?\n";
    std::cout << "(a)The top card of the deck.\n(b)The top of the discard pike.\n\n";

    //prints the discard pile
    (deck_->GetTopDiscard() == "no discard") ? std::cout<<"Discard Pile is empty!\nChoice: " : std::cout<<"Top of Discard pile is \""<<deck_->GetTopDiscard()<<"\"\nChoice: ";

    //makes sure user input is either a or b
    while (true)
    {
        std::cin >> choice;
        if ((choice == "a") || (choice == "b")){
            break;
        }
        else{
            std::cout << "Please enter a valid input (\"a\" or \"b\").\nChoice: ";

        }
    }

    system("cls");

    //draw from deck
    if(choice == "a"){
        p->GiveCard(deck_->Draw());
        std::cout<<"\nYou drew \""<< CardStringify(p->GetCards().back())<<"\" from the deck.\n";

    }else if (choice == "b"){
        //draw from discard
        if ( deck_->GetTopDiscard() == "no discard" ){
            std::cout << "Your card must be drawn from the Top of the deck.\n";
            p->GiveCard(deck_->Draw());
        }else {
            p->GiveCard(deck_->DrawFromDiscard());
        }
        std::cout<<"\nYou drew \""<< CardStringify(p->GetCards().back())<<"\".\n";

    }

    std::cout<<"\nYOUR HAND:\n"<<CardStringifyWithNums(p->GetCards())<<std::endl;
    int discard_choice;
    std::cout<<"Please select a card to discard: ";
    std::cin>>discard_choice;
    deck_->Discard(p->DiscardCard(--discard_choice));
    std::cout<<"You threw \""<<deck_->GetTopDiscard()<<"\" into Discard pile.\n";

    std::cout<<"\nYOUR NEW HAND:\n"<<CardStringify(p->GetCards())<<std::endl;


    system("pause");
    system("cls");

};

/**
    checks hand to see if its a winner

    @param vector of cards (hand)
    @return true if winner, false otherwise

*/
bool CardGame::IsWinner(std::vector<Card> cards) {
    bool won = true;
    for (int i = 1; i < cards.size(); ++i) {
            if(cards[i-1].value != cards[i].value){
                won = false;
				break;
                }
    }
    return won;
};

/**
    returns the player that won

    @param
    @return

*/
Player * CardGame::GetWinner(){
    for(auto a : this->players_){
        if(IsWinner(a->GetCards())){
            std::cout<<a->get_name()<<" is a winner!"<<std::endl;
            return a;
        }
    }
}//end
