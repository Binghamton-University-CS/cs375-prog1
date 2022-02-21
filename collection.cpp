#include "collection.h"

using namespace std;

void Collection::addCard(Card myCard){
    setOfCards.push_back(myCard);
}

void Collection::printCollection(){
    cout << "NEW SET: "<<  endl <<
    "Number of cards in this set: " << numCards << endl
    << "Max Spend value for this set: " << maxSpend << endl;
    for(int i = 0; i < setOfCards.size(); ++i){
        // friend function this
        //cout << setOfCards[i].getCardName() << endl;
        setOfCards[i].printCard();
    }
}

int Collection::findSum(){
    int sum = 0;
    for(int i = 0; i < setOfCards.size(); ++i){
        sum += setOfCards[i].getGertrudePrice();
    }
    return sum;
}

int Collection::findTotalROI(){
    int totalROI = 0;
    for(int i = 0; i < setOfCards.size(); ++i){
        totalROI += setOfCards[i].getROI();
        //cout << "FIND TOTAL TESTING: " << setOfCards[i].getROI() << endl;
     
     }
     return totalROI;
}