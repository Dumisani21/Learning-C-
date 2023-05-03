#include <iostream>
#include <vector>
#include <random>

typedef std::string String;

int randomGenerator(std::random_device& rd, int length);
int * randomDigits();
void print(const String& message);
void printl(const String& message);
String input();
String getInput(const String& message);

int randomGenerator(std::random_device& rd, int length) {
  std::uniform_int_distribution<int> dist(0, length);
  return dist(rd);
}

int * randomDigits() {
    std::random_device rd;
    int * digits = new int[4];
    for (int i = 0; i < 4; i++) {
        digits[i] = randomGenerator(rd, 9);
    }
    return digits;
}

void print(const String& message) {
  std::cout << message;
}

void printl(const String& message) {
  std::cout << message << "\n";
}

String input(){
  String data;
  std::getline(std::cin, data);
  return data;
}

String getInput(const String& message) {
  print(message);
  return input();
}

int main() {
  std::random_device rd;
//   std::vector<String> words = {"people", "jump", "run", "Food", "Game"};
//   int length = words.size();
//   int getRandom = randomGenerator(rd, length-1);

int digits[] = randomDigits();
String guess = "----";

  while (true) {
    String cmd = getInput("Enter command: ");
    std::cout << "You entered: " + cmd << "\n";
    if (cmd == "exit"){
      printl("Goodbye!");
      break;
    }
  }

  return 0;
}