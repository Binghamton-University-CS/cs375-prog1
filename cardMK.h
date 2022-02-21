#ifndef CARDMK_H
#define CARDMK_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CardMK{
    private:
        string cardName;
        int marketPrice;

    public:
     CardMK(string cardName, int marketPrice){
        this->cardName = cardName;
        this->marketPrice = marketPrice;
    }

     void printCardMK(){
        cout << "Market Object "<< endl 
        <<"Card Name: " << cardName <<
        " Market Price: " << marketPrice << endl;
     }
     string getCardNameMK(){
         return cardName;
     }
     int getMarketPrice(){
        return marketPrice;
     }
};

#endif
