#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int temp = 0;
    int baseTen = 0;
    string binaryString = "";
    vector<int> binaryVector;
    if (argc > 1) {
        baseTen = stoi(argv[1]);
        while (baseTen != 0) {
            temp = baseTen % 2;
            baseTen = baseTen / 2;
            binaryVector.push_back(temp);
        }
        for (int i = binaryVector.size(); i > 0; i--) {
            binaryString += to_string(binaryVector[i-1]);
        }
        cout << "Binary: " << binaryString << endl;
    } else {
        cout << "Please enter a base ten number!\n";
    }
}