#pragma once
#include "rtu.h"
void LowerCase(string& word) {
    for (auto& i : word) {
        i = tolower(i);
    }
}

bool allLowerCase(const string& str) {
    for (char ch : str) {
        if (!islower(ch)) {
            return false;
        }
    }
    return true;
}

int firstUzdevums(string& input) {
    string word;
    int lowercaseWords = 0;
    for (char c : input) {
        if (isalpha(c)) {
            word += c;
        }
        else if (!word.empty()) {
            if (allLowerCase(word)) {
                lowercaseWords++;
            }
            word.clear();
        }
    }
    if (!word.empty() && allLowerCase(word)) {
        lowercaseWords++;
    }

    return lowercaseWords;
}


int secondUzdevums(string& input) {
    string word;

    int maxLength = 0;
    word.clear();

    for (char c : input) {
        if (isalpha(c)) {
            word += c;
        }
        else if (!word.empty()) {
            maxLength = max(maxLength, int(word.length()));
            word.clear();
        }
    }

    maxLength = max(maxLength, int(word.length()));
    return maxLength;
}

string thirdUzdevums(string& input) {
    string result;
    bool capitalizeNext = true;

    for (char c : input) {
        if (isalpha(c)) {
            if (capitalizeNext) {
                result += char(toupper(c));
                capitalizeNext = false;
            }
            else {
                result += char(tolower(c));
            }
        }
        else {
            result += c;
            capitalizeNext = true;
        }
    }

    return result;
}

vector<string> fourthUzdevums(string& input) {
    vector<string> result;
    string currentWord;
    bool inBrackets = false;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            inBrackets = true;
            if (!currentWord.empty()) {
                result.push_back(currentWord);
                currentWord.clear();
            }
        }
        else if (input[i] == ')' and input[i + 1] != ',') {
            inBrackets = false;
            if (!currentWord.empty()) {
                result.push_back(currentWord);
                currentWord.clear();
            }
        }
        else if (inBrackets && isalpha(static_cast<unsigned char>(input[i]))) {
            currentWord += tolower(input[i]);
        }
        else if (input[i] == ' ' && !currentWord.empty()) {
            result.push_back(currentWord);
            currentWord.clear();
        }
    }

    // Добавляем последнее слово, если оно есть
    if (!currentWord.empty()) {
        result.push_back(currentWord);
    }

    // From Internet. I take this function
    for (auto it = result.begin(); it != result.end(); ) {
        if (it->empty()) {
            it = result.erase(it);
        }
        else {
            ++it;
        }
    }

    return result;
}
