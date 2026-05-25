#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");      // Windows
#else
    system("clear");    // Linux/macOS
#endif
}

void drawLine(int n) {
    for(int i=0; i<n; ++i)
        cout << "+---";
    cout << "+\n";
}

void showTable(string table) {
    drawLine(static_cast<int>(table.size()));
    cout << "| ";
    for(int i=0; i<table.size(); ++i)
        cout << table[i] << " | ";
    cout << "\n";
    drawLine(static_cast<int>(table.size()));
}

char input() {
    cout << "Input letter: ";
    char c;
    cin >> c;
    return c;
}

bool openLetters(string word, string& table, char c) {
    bool found = false;
    for(int i=0; i<word.size(); ++i) {
        if (word[i] == c) {
            table[i] = c;
            found = true;
        }
    }
    return found;
}

void draw(int err) {
    if(err == 0) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl;
    } else if(err == 1) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|    o    |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl;
    } else if(err == 2) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|    o    |" << endl;
        cout << "|   /     |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl;
    } else if(err == 3) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|    o    |" << endl;
        cout << "|   / \\   |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl;
    } else if(err == 4) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|    o    |" << endl;
        cout << "|   /|\\   |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl;
    } else if(err == 5) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|    o    |" << endl;
        cout << "|   /|\\   |" << endl;
        cout << "|   /     |" << endl;
        cout << "|   |     |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl ;
    } else if(err == 6) {
        cout << "|_________|" << endl;
        cout << "|    |    |" << endl;
        cout << "|    o    |" << endl;
        cout << "|   /|\\   |" << endl;
        cout << "|   / \\   |" << endl;
        cout << "|   | |   |" << endl;
        cout << "|         |" << endl;
        cout << "|         |" << endl;
        cout << "|ШШШШШШШШШ|" << endl << endl;
    }
}

string randomWord() {
    vector<string> words {
        "apricot",
        "apple",
        "avocado",
        "cherry",
        "kiwi",
        "banana",
        "mango",
        "grape",
        "lime",
        "papaya",
        "fig",
        "peach",
        "pear",
        "plum",
        "watermelon",
        "lemon"
    };
    
    int r = rand() % words.size();
    return words[r];
}

int main() {
    srand(time(0));
    string word = randomWord();
    string table(word.size(), ' ');
    
    int err = 0;
    while(table != word && err < 6) {
        draw(err);
        showTable(table);
        char c = input();
        if(!openLetters(word, table, c))
            ++err;
        clearScreen();
    }
    
    if (table == word)
        cout << "!!!YOU WON!!!" << endl;
    else {
        cout << endl << "!!!GAME OVER!!!" << endl;
        draw(err);
    cin.get();
    }
}
