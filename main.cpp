#include "card.h"
#include "collection.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv){

    vector<Collection> vectOfCollections;
    //int vectOfCollectionsIndex = 0;
    bool bigCheck = true;
    while(bigCheck){

    string marketPriceFile;
    string gertrudePriceFile;
    string firstFileMarker;
    string secondFileMarker;

    gertrudePriceFile = argv[1];

    //marketPriceFile = argv[2];


    /*
    firstFileMarker = argv[1];
    secondFileMarker = argv[3];
    */

    //vector<Card> cardVect;
   // int cardIndex = 0;

    /*
    if(argc != 5){
        cout << "Wrong number of args" << endl;
    }
    */

    // reads in files based off -m or -p
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
    }


///////////////////////////////////////
// second time through gert File. first one just counted n vlaue lines
    bool allSetsViewed = false;
    int setsViewed = 0;
    int cardsViewed = 0;
    int n = 0;
    int w = 0;
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
                vectOfCollections.push_back(myCollection); 
                setsViewed++;
                cardsViewed = 0;

                // this may not be necessary, 
                // because the getline will just stop on its own
                if(setsViewed == numOfSets){
                    setsViewed = true; 
                }
            }   
            else{
                // if in this block, then reading a line that is not ints
                // construct a card obj, add it to collectionObj
                // make sure i am making a new collectionObj after one is full
                string cardName = wordsPriceLine[0];
                string priceStr = wordsPriceLine[1];
                int gertrudePrice = stoi(priceStr); 
                Card cardObj(cardName, gertrudePrice);
                vectOfCollections[setsViewed].addCard(cardObj);

                if(n == cardsViewed){
                    // if all the cards in a set have been viewed 
                    //reset the n back to 0 for the next set
                    cardsViewed = 0; // this gets done in the next iteration of loop anywyas

                    // increase sets viewed here because 
                    // if n == cardsViewed a set was just completed
                    setsViewed++;
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
       // bigCheck = false;
    }
    /*

for(int i = 0; i < vectOfCollections.size(); ++i){
    vectOfCollections[i].printCollection();
    cout << endl << endl << endl;
}
*/

/*
    string numCardsMarketFile_str;
    int numCardsMarketFile;
    ifstream inputFile;
    string myLine;
    inputFile.open(marketPriceFile);
    if(inputFile.is_open()){
        string myLine;
        int lineCount = 0;
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
                //Card cardObj(cardName, marketPrice);
                // rather just loop see if card name matches, 
                // if so just use a setter for marketPrice
            // addCard(cardObj);
                cardVect.push_back(cardObj);
                cardVect[cardIndex].printCard();
                cardIndex++;
            }
        
            lineCount++;
        }
        inputFile.close();
    }

*/




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


    }
    return 0;
}