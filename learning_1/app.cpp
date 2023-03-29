#include <iostream>
#include <random>

typedef std::string String;

int randomGenerator(int length);
void print(String message);
void printl(String message);
String input();
String getInput(String message);

int randomGenerator(int length) {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, length);
  return dist(rd);
}

void print(String message) {
  std::cout << message;
}

void printl(String message) {
  std::cout << message << "\n";
}

String input(){
  String data;
  std::cin >> data;
  return data;
}

String getInput(String message) {
  print(message);
  String output = input();
  return output;
}


int main() {

  std::string words[] = {"people", "jump", "run", "Food", "Game"};
  int length = sizeof(words)/sizeof(words[0]);
  int getRandom = randomGenerator(length-1);

  while (true) {
    print("Enter command: ");
    String cmd = input();
    std::cout << "You entered: " + cmd << "\n";
    if (cmd == "exit"){
      printl("Goodbye!");
      break;
    }
  }


  return 0;
}
