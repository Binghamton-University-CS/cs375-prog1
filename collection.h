#ifndef COLLECTION_H
#define COLLECTION_H
#include "card.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Collection{
    private:
        vector<Card> *setOfCards;
        int numCards;
        int maxSpend;
    public:
        Collection(int numCards, int maxSpend){
            this->numCards = numCards;
            this->maxSpend = maxSpend;
           //setOfCards = new vector<Card>();
        
        }
        //get and set max Spend
        void setMaxSpend(int i){
            maxSpend = i;
        }
        int getMaxSpend(){
            return maxSpend;
        }
        void setNumCards(int i){
            numCards = i;
        }
        int getNumCards(){
            return numCards;
        }
        /*
        Card getSetOfCards(){
            return setOfCards;
        }
        */
        int getSize(){
            return setOfCards->size();
        }
        void addCard(Card myCard);

        void printCollection();
};
#endif