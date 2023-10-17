#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Fonction pour choisir un mot aléatoire dans la liste
string chooseWord(const vector<string> &wordList) {
    int randomIndex = rand() % wordList.size();
    return wordList[randomIndex];
}

// Fonction pour initialiser le mot caché avec des underscores
string initializeHiddenWord(const string &word) {
    string hidden = "";
    for (char letter : word) {
        if (isalpha(letter)) {
            hidden += "_";
        } else {
            hidden += letter;
        }
    }
    return hidden;
}

// Fonction pour afficher le mot caché
void displayHiddenWord(const string &hidden) {
    for (char letter : hidden) {
        cout << letter << " ";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<string> wordList = {"programming", "computer", "algorithm", "cplusplus", "developer"};

    int maxAttempts = 6;
    int attempts = 0;
    string wordToGuess = chooseWord(wordList);
    string hiddenWord = initializeHiddenWord(wordToGuess);

    cout << "Bienvenue dans le jeu du Pendu!" << endl;

    while (attempts < maxAttempts) {
        cout << "Mot caché : ";
        displayHiddenWord(hiddenWord);

        char guess;
        cout << "Entrez une lettre : ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < wordToGuess.length(); ++i) {
            if (tolower(wordToGuess[i]) == tolower(guess)) {
                hiddenWord[i] = wordToGuess[i];
                found = true;
            }
        }

        if (!found) {
            attempts++;
            cout << "La lettre '" << guess << "' n'est pas dans le mot. Tentatives restantes : " << maxAttempts - attempts << endl;
        }

        if (hiddenWord == wordToGuess) {
            cout << "Bravo! Vous avez deviné le mot : " << wordToGuess << endl;
            break;
        }
    }

    if (hiddenWord != wordToGuess) {
        cout << "Vous avez épuisé toutes vos tentatives. Le mot était : " << wordToGuess << endl;
    }

    return 0;
}
