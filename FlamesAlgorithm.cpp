#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
The Flames Algorithm
Implementation using C++

Description:
The game of FLAMES is apparently a popular game played by teenagers as a way to deal with the unpredictability of their romantic relationships. This belongs to the vast class of prediction devices such as the counting of petals, numerological tricks, horoscopes and the like. However, unlike many of these other methods, the FLAMES game is based on a transparent deterministic algorithm.

Authors:
Raja Rajan A. (aka Amruth A. Pillai)
Email: im.amruth(at)gmail.com

Prabhu B.
Email: im.prabhu(at)gmail.com
*/

int k = 0;
std::string FLAMES = "FLAMES";
char destinationArray[100];

class FlamesAlgorithm {
private:
    int yourNameLength, partnerNameLength, completeNameLength;
    std::string yourName, yourNameDisplay, partnerName, partnerNameDisplay, completeName;

public:
    FlamesAlgorithm() {
        readName();
        eliminateCommonLetters();
        flamesCalculator();
        displayFlames();
    }

    void readName();
    void eliminateCommonLetters();
    void eliminateNullCharacters(int length, std::string& sourceString);
    void strToLowercase(std::string& str);
    void flamesCalculator();
    void displayFlames();
};

void FlamesAlgorithm :: readName() {
    cout << "Enter your name: ";
    cin >> yourName;
    yourNameDisplay = yourName;
    std::transform(yourName.begin(), yourName.end(), yourName.begin(), ::tolower);
    yourNameLength = yourName.length();

    cout << "Enter your partner's name: ";
    cin >> partnerName;
    partnerNameDisplay = partnerName;
    std::transform(partnerName.begin(), partnerName.end(), partnerName.begin(), ::tolower);
    partnerNameLength = partnerName.length();
}

void FlamesAlgorithm :: eliminateCommonLetters() {
    int i, j;

    for (i = 0; i < yourNameLength; i++) {
        for (j = 0; j < partnerNameLength; j++) {
            if (yourName[i] == partnerName[j]) {
                yourName[i] = partnerName[j] = ' ';
                break;
            }
        }
    }

    eliminateNullCharacters(yourNameLength, yourName);
    eliminateNullCharacters(partnerNameLength, partnerName);

    completeName = string(destinationArray);
    completeNameLength = completeName.length();
}

void FlamesAlgorithm :: eliminateNullCharacters(int length, std::string& sourceString) {
    for (int i = 0; i < length; i++) {
        if (sourceString[i] != ' ') {
            destinationArray[k++] = sourceString[i];
        }
    }
}

void FlamesAlgorithm :: flamesCalculator() {
    int index, flamesLength = 6;

    while (FLAMES.length() != 1) {
        index = completeNameLength % flamesLength;

        if (index == 0) {
            FLAMES = FLAMES.replace(FLAMES.find(FLAMES[FLAMES.length() - 1]), 1, "");
        }
        else {
            FLAMES = FLAMES.replace(FLAMES.find(FLAMES[index - 1]), 1, "");
            FLAMES = FLAMES.substr(index - 1) + FLAMES.substr(0, index - 1);
        }
        flamesLength -= 1;
    }
}

void FlamesAlgorithm :: displayFlames() {
    switch(FLAMES[0]) {

    case 'F':
        cout << yourNameDisplay << " and " << partnerNameDisplay << " are Friends!";
        break;

    case 'L':
        cout << yourNameDisplay << " and " << partnerNameDisplay << " are Lovers!";
        break;

    case 'A':
        cout << yourNameDisplay << " and " << partnerNameDisplay << " are Affectionate towards Each Other!";
        break;

    case 'M':
        cout << yourNameDisplay << " and " << partnerNameDisplay << " are or will be Married!";
        break;

    case 'E':
        cout << yourNameDisplay << " and " << partnerNameDisplay << " are Enemies!";
        break;

    case 'S':
        cout << yourNameDisplay << " and " << partnerNameDisplay << " are like Siblings!";
        break;
    }
}

int main() {
    FlamesAlgorithm flamesAlgorithm;

    return 0;
}
