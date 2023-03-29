#include <iostream>
#include <vector>
#include <random>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string muskWord(std::random_device& rd ,const string& word);
int randomNum(std::random_device& rd, const int& length);
bool checkPosition(const string& guess, const string& answer);

string muskWord(std::random_device& rd ,const string& word) {
    string newWord = word;  
    int ranIndex = randomNum(rd, word.length() - 1);
    for (int i = 0; i < newWord.length(); i++) {
        if (ranIndex != i) {
            newWord[i] = '_';
        }
    }
    return newWord;
}

int randomNum(std::random_device& rd, const int& length) {
    std::uniform_int_distribution<int> dist(0, length);
    return dist(rd);
}

int main() {
    std::random_device rd;
    std::vector<string> words = {"Google", "Jump", "People", "Run", "Know"};
    int length = words.size();
    int ranWordIndex = randomNum(rd, length-1);
    string guess = muskWord(rd, words[ranWordIndex]);
    cout << guess << endl;

    return 0;
}