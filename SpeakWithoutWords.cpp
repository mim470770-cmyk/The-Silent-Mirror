#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void setupUI() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    system("color 1F"); // 1 = Blue Background, F = Bright White Text
#endif
}

void printHeader(string title) {
    cout << "\n\t\t╔══════════════════════════════════════════════════╗" << endl;
    cout << "\t\t║" << setw(50) << internal << title << "║" << endl;
    cout << "\t\t╚══════════════════════════════════════════════════╝" << endl;
}

char getValidChoice(string stage, string patternA, string patternB, string patternC) {
    char choice;
    while (true) {
        cout << "\n\t\t" << stage << endl;
        cout << "\t\t┌───────────────────┬───────────────────┬───────────────────┐" << endl;
        cout << "\t\t│   A) " << setw(10) << left << patternA
             << "   │   B) " << setw(10) << left << patternB
             << "   │   C) " << setw(10) << left << patternC << "   │" << endl;
        cout << "\t\t└───────────────────┴───────────────────┴───────────────────┘" << endl;
        cout << "\t\t👉 Your Selection (A/B/C): ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'A' || choice == 'B' || choice == 'C') return choice;

        cout << "\t\t⚠️  Invalid! Please choose A, B, or C." << endl;
        this_thread::sleep_for(chrono::milliseconds(600));
    }
}

void showLoading() {
    cout << "\n\t\t[";
    for(int i=0; i<35; i++) {
        this_thread::sleep_for(chrono::milliseconds(40));
        cout << "█";
        cout.flush();
    }
    cout << "] 100% Analyzed" << endl;
}

int main() {
    setupUI();
    char ch;
    int stress = 0, energy = 0, depth = 0, calm = 0;

    printHeader("THE SILENT MIRROR: EMOTION ARCHITECT");
    cout << "\t\t   Theme-w5: Meaning found beyond words." << endl;

    // --- STAGES WITH UPDATED LOGIC ---
    ch = getValidChoice("STAGE 1: Which rhythm feels like your pulse?", "⫸⫸⫸⫸⫸", "〰〰〰〰〰", "🌀🌀🌀");
    if(ch == 'A') stress += 5; else if(ch == 'B') calm += 5; else energy += 5;

    ch = getValidChoice("STAGE 2: Which structure matches your mind?", "█▓▒░", "{ ? ? }", "🕸️🕸️🕸️");
    if(ch == 'A') energy += 5; else if(ch == 'B') depth += 5; else stress += 5;

    ch = getValidChoice("STAGE 3: Which space do you prefer?", "░ ░ ░", "⬛⬛⬛", "✨✨✨");
    if(ch == 'A') calm += 5; else if(ch == 'B') depth += 5; else energy += 5;

    ch = getValidChoice("STAGE 4: Which path are you on?", "//////", "\\\\\\\\\\\\", "━━━━━━");
    if(ch == 'A') stress += 3; else if(ch == 'B') depth += 3; else calm += 5;

    ch = getValidChoice("STAGE 5: Which element defines you now?", "⚡ Power", "💧 Flow", "🔥 Heat");
    if(ch == 'A') energy += 5; else if(ch == 'B') calm += 5; else stress += 5;

    system("cls || clear");
    printHeader("SCANNING YOUR SUBCONSCIOUS...");
    showLoading();
    this_thread::sleep_for(chrono::seconds(1));

    // --- DYNAMIC RESULT CALCULATION ---
    string mood, vibe, emoji;
    if (stress >= energy && stress >= depth && stress >= calm) {
        mood = "TURBULENT (ANGRY/STRESS)"; vibe = "Your silence is a storm. ⛈️"; emoji = "😡";
    } else if (energy >= stress && energy >= depth && energy >= calm) {
        mood = "RADIANT (HAPPY/ENERGETIC)"; vibe = "You are glowing with light! 🌈"; emoji = "😀";
    } else if (depth >= stress && depth >= energy && depth >= calm) {
        mood = "REFLECTIVE (SAD/DEEP)"; vibe = "Deep thoughts like quiet rivers. 🌊"; emoji = "😔";
    } else {
        mood = "SERENE (CALM/PEACE)"; vibe = "You have found inner balance. 🍃"; emoji = "🧘";
    }

    // --- FINAL UI BOX ---
    printHeader("THE FINAL REFLECTION");
    cout << "\t\t┌──────────────────────────────────────────────────┐" << endl;
    cout << "\t\t  MOOD: " << emoji << " " << mood << endl;
    cout << "\t\t  VIBE: " << vibe << endl;
    cout << "\t\t└──────────────────────────────────────────────────┘" << endl;

    cout << "\n\t\tPress Enter to exit the Mirror...";
    cin.ignore(); cin.get();

    return 0;
}
