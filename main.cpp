#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>

using namespace std;

void log(string languageSelected, string strITA, string strEN);
void sleep(int ms);
string toLowerCase(string x);

int main() {
    string language;
    
    cout << "Insert the language (ITA or EN): ";
    cin >> language;

    language = toLowerCase(language);

    if (language != "ita" && language != "en") {
        language = "en";
    }

    string word;
    log(language, "Inserisci il testo che vuoi animare: ", "Enter the text you want to animate: ");
    
    cin.ignore();
    getline(cin, word);

    system("cls");
    
    const int wordLength = word.length();
    const int animationSwitchInterval = 25; 
    string wordResult = "";

    for (int i = 0; i < wordLength; i++) {
        const char c = word[i];
        char offset;
        
        if (c != ' ') {
            offset = c - animationSwitchInterval;
            for (int j = 0; j < animationSwitchInterval; j++) {
                cout << "\r" << wordResult << offset << flush;
                sleep(10);
                offset++;
            }
        } else {
            offset = c;
        }
        
        wordResult += offset;
    }

    cout << "\r" << wordResult << endl;

    return 0;
}

void log(string languageSelected, string strITA, string strEN) {
    if (languageSelected == "en") {
        cout << strEN;
    } else {
        cout << strITA;
    }
}

void sleep(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

string toLowerCase(string x) {
    for (auto& c : x) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return x;
}
