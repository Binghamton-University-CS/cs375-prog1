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
        vector<Card> setOfCards;
        int numCards;
        int maxSpend;
        int sum; // the sumOfGertPrices
        int totalROI;
    public:
        Collection(int numCards, int maxSpend){
            this->numCards = numCards;
            this->maxSpend = maxSpend;
            sum = -1;
            totalROI = -1;
           //setOfCards = new vector<Card>();
        }
        Collection(){
            numCards = -1;
            maxSpend = -1;
            sum = -1;
            totalROI = -1;
        };
        void setSum();
        void setTotalROI();
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
        vector<Card> getSetOfCards(){
            return setOfCards;
        }
        /*
        Card getSetOfCards(){
            return setOfCards;
        }
        */
       Card getSpecificCard(int j){
           return setOfCards[j];
       }
        int getSize(){
            return setOfCards.size();
        }
        void addCard(Card myCard);

        void printCollection();
        int findSum();
        int findTotalROI();
};
#endif