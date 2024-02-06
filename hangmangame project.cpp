#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Function to choose a random word from a word list
string chooseWord() {
    vector<string> words = {"hello", "world", "programming", "computer", "science"};
    srand(time(0)); // Seed the random number generator
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the current state of the game
void displayGame(const string& word, const string& guessedLetters, int wrongGuesses) {
    cout << "Word: ";
    for (char c : word) {
        cout << (guessedLetters.find(c) != string::npos ? c : '-') << " ";
    }
    cout << endl;

    cout << "Wrong guesses: " << wrongGuesses << endl;
    // Add code here to display the hangman figure based on wrongGuesses
}

// Function to handle a player's guess
bool makeGuess(string& word, string& guessedLetters, int& wrongGuesses) {
    char guess;
    cout << "Guess a letter: ";
    cin >> guess;

    if (guessedLetters.find(guess) != string::npos) {
        cout << "You already guessed that letter." << endl;
        return false;
    }

    guessedLetters += guess;

    if (word.find(guess) == string::npos) {
        wrongGuesses++;
        cout << "Incorrect guess." << endl;
    } else {
        cout << "Correct guess!" << endl;
    }

    return true;
}

int main() {
    string word = chooseWord();
    string guessedLetters = "";
    int wrongGuesses = 0;
    int maxWrongGuesses = 7; // Adjust this to change the difficulty

    cout << "Welcome to Hangman!\n";

    while (wrongGuesses < maxWrongGuesses && word != guessedLetters) {
        displayGame(word, guessedLetters, wrongGuesses);
        makeGuess(word, guessedLetters, wrongGuesses);
    }

    if (wrongGuesses == maxWrongGuesses) {
        cout << "You lost! The word was: " << word << endl;
    } else {
        cout << "Congratulations! You guessed the word: " << word << endl;
    }

    return 0;
}
