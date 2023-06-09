#include <iostream>
#include <vector>
#include <random>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string muskWord(std::random_device& rd ,const string& word);
int randomNum(std::random_device& rd, const int& length);
bool updateGuess(string& guess, const string& answer, const char& guessChar);
void print(const string& message);
void printl(const string& message);
char input();

void print(const string& message) {
  cout << message;
}

void printl(const string& message) {
  cout << message << "\n";
}

char input(){
    char data;
    cin.get(data);
    cin.ignore(100, '\n'); // Ignore any remaining input on the line
    return data;
}

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

bool updateGuess(string& guess, const string& answer, const char& guessChar) {
    for (int i = 0; i < answer.length(); i++) {
        if (guessChar == answer[i] && guessChar != guess[i]) {
            guess[i] = guessChar;
            return true;
        }
    }
    return false;
}


int main() {
    std::random_device rd;
    std::vector<string> words = {"Google", "Jump", "People", "Run", "Know"};
    int length = words.size();
    int limit = 12;
    int ranWordIndex = randomNum(rd, length-1);
    string guess = muskWord(rd, words[ranWordIndex]);
    printl("For help type ?");
    printl("Your guess is :" + guess);
    while (true) {
        print("Enter guess: ");
        char guessLetter = input();
        print("\n");

        if (guessLetter  == '!') {
            printl("sad to see you leave :( Goodbye.");
            print("\n");
            break;
        } else if (guessLetter == '?') {

            printl("You can only type in characters");
            printl("Help : ?\nQiut : !");

        }else {

            bool result = updateGuess(guess, words[ranWordIndex], guessLetter);
            if (guess == words[ranWordIndex]) {
                printl("Welldone you win.");
                printl("The word is: " + words[ranWordIndex]);
                print("\n");
                break;
            }else if (result) {
                printl("Correct guess");
                printl("Your guess is :" + guess);
                print("\n");
            } else {
                printl("Wrong guess");
                printl("Your guess is :" + guess);
                print("\n");
            }

        }        
    }

    return 0;
}