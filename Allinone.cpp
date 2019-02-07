//
//  main.cpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/16/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX = 26;
class Dictionary{
private:
    struct CheckNode{
        CheckNode* Next[MAX];
        bool Flag[MAX];
    };
    CheckNode* root;
    CheckNode* navi;
    int numWords;
public:
    Dictionary();
    // Function: Initialize the class and create the first node
    // Precondition: n/a
    // Postcondition: First node activated
    Dictionary(string file);
    // Function: Initialize node and develope the dicitionary tree
    // Precondition: must have a file to upload in tree
    // Postcondition: The tree is created with all words
    void addWord(string word);
    // Function: add a word to the dictionary
    // Precondition: word must not exist in tree
    // Postcondition: add word to tree
    bool isWord(string word);
    // Function: verify that it is a word
    // Precondition: n/a
    // Postcondition: will verify if the word is there
    bool isPrefix(string word);
    // Function: determines if their is more words based on what is given
    // Precondition: n/a
    // Postcondition: tells if it is a prefix
    int wordCount();
    // Function: keep track of words
    // Precondition: n/a
    // Postcondition: will return amount of words
};
Dictionary::Dictionary(){
    CheckNode* newNode = new CheckNode;
    for( int i = 0; i < MAX; i++){
        newNode->Flag[i] = false;
        newNode->Next[i] = NULL;
    }
    root = navi = newNode;
    numWords = 0;
}
Dictionary::Dictionary(string file){
    CheckNode* newNode = new CheckNode;
    for( int i = 0; i < MAX; i++){
        newNode->Next[i] = nullptr;
        newNode->Flag[i] = false;
    }
    root = navi = newNode;
    numWords = 0;
    string word;
    ifstream inFile;
    
    inFile.open(file);
    if (inFile.is_open())
        cout << "Successfully Opended" << endl;

    while(!inFile.eof()){
        inFile >> word;
        addWord(word);
    }
    inFile.close();
}

void Dictionary::addWord(string word){
    char letter;
    navi = root;
    int location = 0;
    
    for (int i = 0; i < word.length(); i++){
        letter = word[i];
        location = (int)letter - (int)'a';
        
        if(navi->Next[location] == NULL){
            CheckNode* newNode = new CheckNode;
            for ( int m = 0; m < 26; m++){
                newNode->Flag[m] = false;
                newNode->Next[m] = NULL;
            }
            navi->Next[location] = newNode;
        }
        navi = navi->Next[location];
    }
    navi->Flag[location] = true;
    numWords++;
}
bool Dictionary::isWord(string word){
    char letter;
    navi = root;
    int location = 0;
    for(int i = 0; i < word.length(); i++){
        letter = word[i];
        location = (int)letter - (int)'a';
        if(navi->Next[location] == nullptr)
            return false;
        navi = navi->Next[location];
    }
    return navi->Flag[location];
}
bool Dictionary::isPrefix(string word){
    char letter;
    navi = root;
    int location = 0;
    for(int i = 0; i < word.length(); i++){
        letter = word[i];
        location = (int)letter - (int)'a';
        if (navi->Next[location] == NULL)
            return false;
        navi = navi->Next[location];
    }
    return true;
}
int Dictionary::wordCount(){
    return numWords;
}
int main() {
    Dictionary test;
    test.addWord("help");
    cout << "Amount loaded: " << test.wordCount() << endl;
    string command;


    Dictionary tester("Dictionary.txt");
    cout << "Amount loaded: " << tester.wordCount() << endl;
    
    cout << "Please insert a word in all lowercase to verify if the it has a prefix and is an actual word, to quit, please put a 0. \n Word: " << endl;
    cin >> command;
    while(command != "0"){
        if (tester.isPrefix(command))
            cout << command << " is a Prefix. " << endl;
        else
            cout << command << " is not a Prefix. " << endl;
        if (tester.isWord(command))
            cout << command << " is a Word." << endl;
        else
            cout << command << " is not a Word. " << endl;
        cout << "Word: ";
        cin >> command;
        cout << endl;
    }
    return 0;
}
