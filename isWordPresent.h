#ifndef isWordPresent_h
#define isWordPresent_h

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

// Function that returns true if the word is found
bool isWordPresent(string sentence, string word)
{
    // To convert the word in uppercase
    transform(word.begin(),
        word.end(), word.begin(), ::toupper);

    // To convert the complete sentence in uppercase
    transform(sentence.begin(), sentence.end(),
        sentence.begin(), ::toupper);

    // Both strings are converted to the same case,
    // so that the search is not case-sensitive

    // To break the sentence in words
    stringstream s(sentence);

    // To temporarily store each individual word
    string temp;

    while (s >> temp) {

        // Comparing the current word
        // with the word to be searched
        if (temp.compare(word) == 0) {
            return true;
        }
    }
    return false;
}

bool findWords(string sentence, vector<string> words)
{ //takes in a vector of words to search multiple words easily/automatically
    for (string i : words)
    {
        if (isWordPresent(sentence, i))
        {
            return true;
        }
        else {}
    }
    return false;
}

#endif