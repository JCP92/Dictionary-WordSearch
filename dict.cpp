//
//  main.cpp
//  DictionarySet
//
//  Created by Joshua Peckham on 2/16/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//
#include "DictionaryDef.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
