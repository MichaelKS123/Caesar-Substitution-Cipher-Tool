#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

class CipherTool {
private:
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
public:
    // Caesar Cipher Encryption
    string caesarEncrypt(string text, int shift) {
        string result = "";
        shift = ((shift % 26) + 26) % 26;
        
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                result += char((c - base + shift) % 26 + base);
            } else {
                result += c;
            }
        }
        return result;
    }
    
    // Caesar Cipher Decryption
    string caesarDecrypt(string text, int shift) {
        return caesarEncrypt(text, -shift);
    }
    
    // Vigenere Cipher Encryption
    string vigenereEncrypt(string text, string key) {
        string result = "";
        string upperKey = key;
        transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);
        int keyIndex = 0;
        
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int shift = upperKey[keyIndex % upperKey.length()] - 'A';
                result += char((c - base + shift) % 26 + base);
                keyIndex++;
            } else {
                result += c;
            }
        }
        return result;
    }
    
    // Vigenere Cipher Decryption
    string vigenereDecrypt(string text, string key) {
        string result = "";
        string upperKey = key;
        transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);
        int keyIndex = 0;
        
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int shift = upperKey[keyIndex % upperKey.length()] - 'A';
                result += char((c - base - shift + 26) % 26 + base);
                keyIndex++;
            } else {
                result += c;
            }
        }
        return result;
    }
    
    // Substitution Cipher Encryption
    string substitutionEncrypt(string text, string key) {
        if (key.length() != 26) {
            return "Error: Key must be exactly 26 characters!";
        }
        
        string result = "";
        string upperKey = key;
        transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);
        
        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int index = toupper(c) - 'A';
                char encrypted = upperKey[index];
                result += isupper(c) ? encrypted : tolower(encrypted);
            } else {
                result += c;
            }
        }
        return result;
    }
    
    // Substitution Cipher Decryption
    string substitutionDecrypt(string text, string key) {
        if (key.length() != 26) {
            return "Error: Key must be exactly 26 characters!";
        }
        
        string result = "";
        string upperKey = key;
        transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);
        
        map<char, char> reverseMap;
        for (int i = 0; i < 26; i++) {
            reverseMap[upperKey[i]] = alphabet[i];
        }
        
        for (char c : text) {
            if (isalpha(c)) {
                char upper = toupper(c);
                char decrypted = reverseMap[upper];
                result += isupper(c) ? decrypted : tolower(decrypted);
            } else {
                result += c;
            }
        }
        return result;
    }
    
    // Frequency Analysis
    void frequencyAnalysis(string text) {
        map<char, int> freq;
        int totalLetters = 0;
        
        for (char c : text) {
            if (isalpha(c)) {
                freq[toupper(c)]++;
                totalLetters++;
            }
        }
        
        vector<pair<char, int>> sortedFreq(freq.begin(), freq.end());
        sort(sortedFreq.begin(), sortedFreq.end(), 
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });
        
        cout << "\n=== Frequency Analysis ===\n";
        cout << "Total Letters: " << totalLetters << "\n\n";
        cout << "Letter | Count | Percentage | Bar\n";
        cout << "-------|-------|------------|" << string(30, '-') << "\n";
        
        for (const auto& p : sortedFreq) {
            double percentage = (double)p.second / totalLetters * 100;
            int barLength = (int)(percentage * 0.5);
            cout << "   " << p.first << "   |  " 
                 << setw(4) << p.second << " |   " 
                 << fixed << setprecision(2) << setw(5) << percentage << "%  | "
                 << string(barLength, '#') << "\n";
        }
        
        cout << "\nMost common English letters: E T A O I N S H R D L C U\n";
    }
    
    // Caesar Cipher Brute Force
    void caesarBruteForce(string text) {
        cout << "\n=== Caesar Cipher Brute Force Attack ===\n";
        for (int shift = 1; shift < 26; shift++) {
            cout << "Shift " << setw(2) << shift << ": " 
                 << caesarDecrypt(text, shift) << endl;
        }
    }
    
    // File Operations
    bool readFromFile(string filename, string& content) {
        ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        content = "";
        string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        return true;
    }
    
    bool writeToFile(string filename, const string& content) {
        ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        file << content;
        file.close();
        return true;
    }
};

void displayTitle() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║                                                        ║\n";
    cout << "║          SECURE TEXT: A CLASSICAL CIPHER TOOL         ║\n";
    cout << "║                    by Michael                          ║\n";
    cout << "║                                                        ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
}

void displayMenu() {
    cout << "\n========================================\n";
    cout << "   MAIN MENU\n";
    cout << "========================================\n";
    cout << " 1. Caesar Cipher Encrypt\n";
    cout << " 2. Caesar Cipher Decrypt\n";
    cout << " 3. Caesar Cipher Brute Force\n";
    cout << " 4. Substitution Cipher Encrypt\n";
    cout << " 5. Substitution Cipher Decrypt\n";
    cout << " 6. Vigenere Cipher Encrypt\n";
    cout << " 7. Vigenere Cipher Decrypt\n";
    cout << " 8. Frequency Analysis\n";
    cout << " 9. Work with Files\n";
    cout << "10. About\n";
    cout << "11. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

void displayAbout() {
    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║              ABOUT SECURE TEXT v1.0                    ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
    cout << "\nSecure Text is a classical cipher tool that implements\n";
    cout << "various historical encryption methods.\n\n";
    cout << "Features:\n";
    cout << "  • Caesar Cipher (shift cipher)\n";
    cout << "  • Substitution Cipher (monoalphabetic)\n";
    cout << "  • Vigenere Cipher (polyalphabetic)\n";
    cout << "  • Frequency Analysis\n";
    cout << "  • Brute Force Attack\n";
    cout << "  • File Input/Output\n\n";
    cout << "Created by: Michael\n";
    cout << "Version: 1.0\n";
    cout << "Educational purposes only.\n";
}

void handleFileOperations(CipherTool& cipher) {
    int choice;
    string filename, content, result, key;
    int shift;
    
    cout << "\n--- File Operations ---\n";
    cout << "1. Encrypt file (Caesar)\n";
    cout << "2. Decrypt file (Caesar)\n";
    cout << "3. Encrypt file (Substitution)\n";
    cout << "4. Decrypt file (Substitution)\n";
    cout << "5. Encrypt file (Vigenere)\n";
    cout << "6. Decrypt file (Vigenere)\n";
    cout << "7. Analyze file frequency\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();
    
    cout << "Enter input filename: ";
    getline(cin, filename);
    
    if (!cipher.readFromFile(filename, content)) {
        cout << "Error: Could not read file!\n";
        return;
    }
    
    cout << "File loaded successfully!\n";
    
    switch (choice) {
        case 1:
        case 2:
            cout << "Enter shift value: ";
            cin >> shift;
            result = (choice == 1) ? cipher.caesarEncrypt(content, shift) 
                                   : cipher.caesarDecrypt(content, shift);
            break;
        case 3:
        case 4:
            cout << "Enter 26-character key: ";
            cin.ignore();
            getline(cin, key);
            result = (choice == 3) ? cipher.substitutionEncrypt(content, key)
                                   : cipher.substitutionDecrypt(content, key);
            break;
        case 5:
        case 6:
            cout << "Enter keyword: ";
            cin.ignore();
            getline(cin, key);
            result = (choice == 5) ? cipher.vigenereEncrypt(content, key)
                                   : cipher.vigenereDecrypt(content, key);
            break;
        case 7:
            cipher.frequencyAnalysis(content);
            return;
    }
    
    cout << "Enter output filename: ";
    cin.ignore();
    getline(cin, filename);
    
    if (cipher.writeToFile(filename, result)) {
        cout << "File saved successfully!\n";
    } else {
        cout << "Error: Could not write file!\n";
    }
}

int main() {
    CipherTool cipher;
    int choice;
    string text, result, key;
    int shift;
    
    displayTitle();
    cout << "\nWelcome to Secure Text - Your Classical Cipher Tool\n";
    
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "\n--- Caesar Cipher Encryption ---\n";
                cout << "Enter text to encrypt: ";
                getline(cin, text);
                cout << "Enter shift value (0-25): ";
                cin >> shift;
                result = cipher.caesarEncrypt(text, shift);
                cout << "\nEncrypted text: " << result << endl;
                break;
                
            case 2:
                cout << "\n--- Caesar Cipher Decryption ---\n";
                cout << "Enter text to decrypt: ";
                getline(cin, text);
                cout << "Enter shift value (0-25): ";
                cin >> shift;
                result = cipher.caesarDecrypt(text, shift);
                cout << "\nDecrypted text: " << result << endl;
                break;
                
            case 3:
                cout << "\n--- Caesar Cipher Brute Force ---\n";
                cout << "Enter encrypted text: ";
                getline(cin, text);
                cipher.caesarBruteForce(text);
                break;
                
            case 4:
                cout << "\n--- Substitution Cipher Encryption ---\n";
                cout << "Enter text to encrypt: ";
                getline(cin, text);
                cout << "Enter 26-character substitution key: ";
                getline(cin, key);
                result = cipher.substitutionEncrypt(text, key);
                cout << "\nEncrypted text: " << result << endl;
                break;
                
            case 5:
                cout << "\n--- Substitution Cipher Decryption ---\n";
                cout << "Enter text to decrypt: ";
                getline(cin, text);
                cout << "Enter 26-character substitution key: ";
                getline(cin, key);
                result = cipher.substitutionDecrypt(text, key);
                cout << "\nDecrypted text: " << result << endl;
                break;
                
            case 6:
                cout << "\n--- Vigenere Cipher Encryption ---\n";
                cout << "Enter text to encrypt: ";
                getline(cin, text);
                cout << "Enter keyword: ";
                getline(cin, key);
                result = cipher.vigenereEncrypt(text, key);
                cout << "\nEncrypted text: " << result << endl;
                break;
                
            case 7:
                cout << "\n--- Vigenere Cipher Decryption ---\n";
                cout << "Enter text to decrypt: ";
                getline(cin, text);
                cout << "Enter keyword: ";
                getline(cin, key);
                result = cipher.vigenereDecrypt(text, key);
                cout << "\nDecrypted text: " << result << endl;
                break;
                
            case 8:
                cout << "\n--- Frequency Analysis ---\n";
                cout << "Enter text to analyze: ";
                getline(cin, text);
                cipher.frequencyAnalysis(text);
                break;
                
            case 9:
                handleFileOperations(cipher);
                break;
                
            case 10:
                displayAbout();
                break;
                
            case 11:
                cout << "\nThank you for using Secure Text!\n";
                cout << "Stay secure! - Michael\n\n";
                return 0;
                
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
        
        cout << "\nPress Enter to continue...";
        cin.get();
    }
    
    return 0;
}