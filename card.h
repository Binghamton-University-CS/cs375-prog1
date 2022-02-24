#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Card{
    private:
        string cardName;
        int gertrudePrice;
        int marketPrice;
        int ROI;

    public:
    /*
    Card(string cardName, int gertrudePrice, int marketPrice){
        this->cardName = cardName;
        this->gertrudePrice = gertrudePrice;
        this->marketPrice = marketPrice;
    }
    */
    Card(string cardName, int gertrudePrice){
        this->cardName = cardName;
        this->gertrudePrice = gertrudePrice;
        marketPrice = -1;
        ROI = -1;
    }
    Card(string cardName){
        this->cardName = cardName;
        gertrudePrice = -1;
       // marketPrice = -1;
    }
     /*
     Card(string cardName, int marketPrice){
        this->cardName = cardName;
        this->marketPrice = marketPrice;
        gertrudePrice = -1;
    }
    */
   // Card(){};
    
    
    
   
    

    void printCard(){
        cout << "Gertrude Card Obj " << endl 
        << "Card Name: " << cardName <<
        " Gertrude Price:  " << gertrudePrice 
        << " Market Price: " << marketPrice 
        << " ROI: " << ROI << endl;
     }
    
    // getters and setters
    string getCardName(){
        return cardName;
    }

    int getGertrudePrice(){
        return gertrudePrice;
    }


    int getMarketPrice() {
        return marketPrice;
    }
      void setMarketPrice(int p){
        marketPrice = p;
        ROI = marketPrice - gertrudePrice;
    }
    int getROI(){
        return ROI;
    }
    void setROI(){
        ROI = marketPrice - gertrudePrice;
    }

    void setCardName(string s){
        cardName = s;
    }

    void setGertrudePrice(int p){
        gertrudePrice = p;
    }
    
  
    



};



#endif