#include "card.h"
#include "cardMK.h"
#include "collection.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h> 
#include <bitset>

using namespace std;

vector<Card> generateSubset(vector<Card>& pass, int s){
    // num of total subsets convert to binary 
    // 111 = 7
    // 110 = 6
    // 011 = 5
    // turn binary num intro string, if there is a 1 in that index u add that 1 to that index 
    // use those indexes for the vector 
    // // calculate maxProfit
    // loop through 
    vector<Card> subset;
    string binaryRep = "";

    binaryRep = bitset<8>(s).to_string();
    cout << endl << endl;
    cout << "BINARY REP: " << binaryRep << endl;

    // use the 1's to get the indexes of a new vector that we will pass back
        for(int i = 0; i < binaryRep.size(); ++i){
            if(binaryRep[i] == '1'){
                subset.push_back(pass[i]);
            }
        }

        return subset;
    }

    
    //populate subset based off pass
    
  //  vector<Card> subset;
    //if()
    



int computeMaxProfit(Collection collection, int w, int sumOfWeights){
    int sizeOfCollection = collection.getSize();
    cout << "SIZE OF COLLECTION: " << sizeOfCollection << endl;

   // this is the collection set 
    int maxProfit = 0;
    vector<Card> S; // initial vector
    vector<Card> M;
   // int sumOfWeights = collection.findSum();
    if(sumOfWeights < w){
       // cout << " HIT " << endl;
        int prof = 0;
        prof = collection.findTotalROI();
        return prof;        
    }
    // generate subsets
    int totalSubsets = pow(sizeOfCollection, 2);
    //cout << "Size of colleciton: " << sizeOfCollection << endl;
    // cout << "Total Subsets: " << totalSubsets << endl;
    // while more subsets to generate
    int subsetsHit = 0;
    while(subsetsHit <= totalSubsets){
        
        Collection subsetCollection;
        //vector<Card> subset;
        string binaryRep = "";

        binaryRep = bitset<8>(subsetsHit).to_string();
        cout << endl << endl;
        cout << "BINARY REP: " << binaryRep << endl;

        // use the 1's to get the indexes of a new vector that we will pass back
        for(int i = 0; i < binaryRep.size(); ++i){
            if(binaryRep[i] == '1'){
                subsetCollection.addCard(collection.getSpecificCard(i));
            }
        }
        subsetCollection.setSum();
        subsetCollection.setTotalROI();
        int tempROI = subsetCollection.findTotalROI();
        if(tempROI > maxProfit){
            maxProfit = tempROI;
        }

       // cout << "LINE 69:  " << collection.getSpecificCard(i) << endl;
       // T.push_back(collection.getSpecificCard(i));
    
        subsetsHit++;
    }
     
     /*
     for(int i = 0; i < collection.getSize(); ++i){
       // cout << "LINE 69:  " << collection.getSpecificCard(i) << endl;
        cout << "LINE 75: " << S[i] << endl;
    }
    */


   /* 
    int subsetsHit = 0;
    while(subsetsHit <= totalSubsets){
        cout << endl << "NEW WHILE LOOP: " << endl;
        S = generateSubset(S, subsetsHit);
        subsetsHit++;
    }
    */
        // if progit of items in S > maxProfit
            //updateMax Profit 
            // copy S to M; // for loop
        // genereate the next subset S

    // return maxProfit 
     return maxProfit;
}



int main(int argc, char** argv){

    int startSize = 0;
    vector<Collection> vectOfCollections;
    vector<CardMK> cardsMarket;
    int cardsMarketIndex = 0;
    //int vectOfCollectionsIndex = 0;
    bool bigCheck = true;
    while(bigCheck){

    string marketPriceFile;
    string gertrudePriceFile;
    string firstFileMarker;
    string secondFileMarker;

    gertrudePriceFile = argv[1];
    marketPriceFile = argv[2];


    /*
    if(firstFileMarker == "-m"){
        marketPriceFile = argv[2];
    }
    if(firstFileMarker == "-p"){
        gertrudePriceFile = argv[2];
    }

    if(secondFileMarker == "-m"){
        marketPriceFile = argv[4];
    }
    if(secondFileMarker == "-p"){
        gertrudePriceFile = argv[4];
    }
    */


// MARKET FILE

    string numCardsMarketFile_str;
    int numCardsMarketFile;
    ifstream inputFile;
    string myLine;
    int lineCount = 0;

    inputFile.open(marketPriceFile);
    if(inputFile.is_open()){
        string myLine;
        while(getline(inputFile, myLine)){
            string str(myLine);
            string tmp;
            stringstream str_strm(str);
            // vector takes each word on a line
            vector<string> itemsPerLine;
            while(str_strm >> tmp){
                itemsPerLine.push_back(tmp);
            }

            if(lineCount == 0){
                numCardsMarketFile_str = itemsPerLine[0];
                numCardsMarketFile = stoi(numCardsMarketFile_str);
            }
            else{
                string cardName = itemsPerLine[0];
                string marketPriceStr = itemsPerLine[1];
                int marketPrice = stoi(marketPriceStr);
                CardMK cardObjMK(cardName, marketPrice);
                cardsMarket.push_back(cardObjMK);
                cout << endl << endl << endl;
                cout << "PRINTING FROM MARKET FILE" << endl;
                cardsMarket[cardsMarketIndex].printCardMK();
                cout << endl;
                
                cardsMarketIndex++;

// THIS IS WORK IN PROGRESS, SET THE marketprice to the cardObj
                /*
                for(int i = 0; i < vectOfCollections.size(); ++i){
                    for(int j = 0; j < vectOfCollections[i].getSize(); ++i){
                        if(cardName == vectOfCollections[i].getSpecificCard[j]){
                            vectOfCollections[i].getSpecificCard[j].setMarketPrice(marketPrice);
                        }
                    }
                }
                */
                //Card cardObj(cardName, marketPrice);
                // rather just loop see if card name matches, 
                // if so just use a setter for marketPrice
            // addCard(cardObj);
                //cardVect.push_back(cardObj);
                //cardVect[cardIndex].printCard();
                //cardIndex++;
            }
        
            lineCount++;
        }
        inputFile.close();
    }

// END OF MARKET FIle


  // simply sets the numOfSets Value THAT IS IT
    int numOfSets = 0;
    int countTest = 0;
    ifstream inputFileGertrudeNum;
    inputFileGertrudeNum.open(gertrudePriceFile);
    if(inputFileGertrudeNum.is_open()){
        string myLine;
        while(getline(inputFileGertrudeNum, myLine)){
            countTest++;
            string str(myLine);
            string tmp;
            stringstream str_strm(str);
            vector<string> wordsPriceLine;
            while(str_strm >> tmp) {
                wordsPriceLine.push_back(tmp);
            }
            if(isdigit(wordsPriceLine[0][0])){
                // check is 1st element of line, if digit then it is a set line
                numOfSets++;
            }      
        }
        inputFileGertrudeNum.close();
    }


///////////////////////////////////////
// second time through gert File. first one just counted n vlaue lines
    bool allSetsViewed = false;
    int setsViewed = -1;
    int cardsViewed = 0;
    int n = 0;
    int w = 0;
    int collectionIndex = 0;
    ifstream inputFileGertrude;
    inputFileGertrude.open(gertrudePriceFile);
    if(inputFileGertrude.is_open()){
        string myLine;
        while(getline(inputFileGertrude, myLine)){
            string str(myLine);
            string tmp;
            stringstream str_strm(str);
            vector<string> wordsPriceLine;
            while(str_strm >> tmp) {
                wordsPriceLine.push_back(tmp);
            }
            if(isdigit(wordsPriceLine[0][0])){

                // check is 1st element of line, if digit then it is a set line
                string n_str = wordsPriceLine[0];
                n = stoi(n_str);
                string w_str = wordsPriceLine[1];
                w = stoi(w_str);
                Collection myCollection(n, w);
                // does this line below need & to be dereferenced
               // cout << "SIZE OF Vector of COllections: " << vectOfCollections.size() << endl;

                vectOfCollections.push_back(myCollection); 
                cout << "SIZE OF Vector of Collections: " << vectOfCollections.size() << endl;
                setsViewed++;
                cardsViewed = 0;

                // this may not be necessary, 
                // because the getline will just stop on its own
                
                /*  
                if(setsViewed == numOfSets){
                    allSetsViewed = true; 
                }
                */
                
            }   
            else{
                // if in this block, then reading a line that is not ints
                // construct a card obj, add it to collectionObj
                // make sure i am making a new collectionObj after one is full
                string cardName = wordsPriceLine[0];
                string priceStr = wordsPriceLine[1];
                int gertrudePrice = stoi(priceStr); 
            
                Card cardObj(cardName, gertrudePrice);
                for(int i = 0; i < cardsMarket.size(); ++i){
                     if(cardObj.getCardName() == cardsMarket[i].getCardNameMK()){
                         cardObj.setMarketPrice(cardsMarket[i].getMarketPrice());
                     }
                }
               


                //cout << "TESTING" << endl;
               // cardObj.printCard();
               // cout << endl;
                vectOfCollections[setsViewed].addCard(cardObj);
               // cout << "post vect" << endl;
                if(n == cardsViewed){
                    // if all the cards in a set have been viewed 
                    //reset the n back to 0 for the next set
                    cardsViewed = 0; // this gets done in the next iteration of loop anywyas
                    // increase sets viewed here because 
                    // if n == cardsViewed a set was just completed
                    //collectionIndex++;
                    //setsViewed++;
                }
                cardsViewed++;
            }

            /*
            else{
                // if first element is not digit, it is a card line
                //loop through vector of cards, if card is there add the gertrude price using setter
                // if not there then create new object
            }
            */
            
        }
        // setBigCheck to f
        bigCheck = false;
        inputFileGertrude.close();
    }
    

 //  *********************************


    cout << endl << endl << endl;

for(int i = 0; i < vectOfCollections.size(); ++i){
    cout << "Set: " << i << endl;
    vectOfCollections[i].printCollection();
    cout << endl << endl << endl;
}




    /*
    string marketLine;
    ifstream marketFile (marketPriceFile);
    marketFile.open(marketPriceFile);
    if(marketFile.is_open()){
        string marketLine;
        while(getline(marketFile, marketLine)){
            string strMarket(marketLine);
            string tmpMarket;
            stringstream str_strmMarket(strMarket);
            vector<string> vectMarketLine;
            

        }
    }
    */


    cout << "Market Price File: " << marketPriceFile << endl <<
    "Gertrude Price File: "<< gertrudePriceFile << endl;

    //cout << vectOfCollections.size()  << endl;
    for(int i = 0; i < vectOfCollections.size(); ++i){
        vectOfCollections[i].setSum();
        vectOfCollections[i].setTotalROI();
    }


    for(int i = 0; i < vectOfCollections.size(); ++i){
        int tempMaxSpend = vectOfCollections[i].getMaxSpend();   
        int tempSum = vectOfCollections[i].findSum();
        computeMaxProfit(vectOfCollections[i], tempMaxSpend, tempSum);
    }


    }

    return 0;
}