# Secure Text: A Classical Cipher Tool
**by Michael Semera**

Version 1.0

---

## 📖 Overview

Secure Text is a comprehensive command-line application that implements classical encryption and decryption techniques. This educational tool demonstrates various historical cipher methods used throughout history to secure communications.

## ✨ Features

### Cipher Types
- **Caesar Cipher** - Shift-based encryption (used by Julius Caesar)
- **Substitution Cipher** - Monoalphabetic substitution encryption
- **Vigenère Cipher** - Polyalphabetic substitution (the "indecipherable cipher")

### Analysis Tools
- **Frequency Analysis** - Analyze letter distribution in encrypted text
- **Brute Force Attack** - Automatically try all Caesar cipher shifts
- **File Operations** - Encrypt/decrypt entire files

### Additional Features
- Preserves case sensitivity (uppercase/lowercase)
- Maintains non-alphabetic characters (spaces, punctuation, numbers)
- Interactive menu-driven interface
- Beautiful ASCII art interface
- Read from and write to files

---

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Standard C++ library support

### Compilation

**On Linux/Mac:**
```bash
g++ -o securetext cipher.cpp
./securetext
```

**On Windows:**
```bash
g++ -o securetext.exe cipher.cpp
securetext.exe
```

Or using clang:
```bash
clang++ -o securetext cipher.cpp
./securetext
```

---

## 📚 How to Use

### Menu Options

1. **Caesar Cipher Encrypt** - Shift letters by a specific number
2. **Caesar Cipher Decrypt** - Reverse a Caesar cipher shift
3. **Caesar Cipher Brute Force** - Try all possible shifts
4. **Substitution Cipher Encrypt** - Use a 26-character key
5. **Substitution Cipher Decrypt** - Reverse substitution encryption
6. **Vigenère Cipher Encrypt** - Use a keyword for encryption
7. **Vigenère Cipher Decrypt** - Reverse Vigenère encryption
8. **Frequency Analysis** - Analyze letter frequencies
9. **Work with Files** - Encrypt/decrypt files
10. **About** - Program information
11. **Exit** - Close the program

---

## 🔐 Cipher Examples

### Caesar Cipher

**Example:**
- **Plaintext:** `Hello World`
- **Shift:** `3`
- **Ciphertext:** `Khoor Zruog`

**How it works:** Each letter is shifted by a fixed number of positions in the alphabet.

### Substitution Cipher

**Example:**
- **Plaintext:** `Hello World`
- **Key:** `QWERTYUIOPASDFGHJKLZXCVBNM`
- **Ciphertext:** `Itssg Vgksr`

**How it works:** Each letter is replaced by another letter according to a fixed mapping.

**Key format:** A 26-character string representing the alphabet mapping.
- A → Q, B → W, C → E, D → R, etc.

### Vigenère Cipher

**Example:**
- **Plaintext:** `Hello World`
- **Keyword:** `KEY`
- **Ciphertext:** `Rijvs Uyvjn`

**How it works:** Uses a keyword to create multiple Caesar shifts. More secure than simple Caesar cipher!

---

## 📂 File Operations

### Encrypting a File

1. Select option **9** (Work with Files)
2. Choose encryption method (Caesar, Substitution, or Vigenère)
3. Enter input filename (e.g., `message.txt`)
4. Provide the necessary key/shift
5. Enter output filename (e.g., `encrypted.txt`)

### Example Files

**input.txt:**
```
This is a secret message!
```

**After Caesar encryption (shift 5):**
```
Ymnx nx f xjhwjy rjxxflj!
```

---

## 🔍 Frequency Analysis

Frequency analysis helps break substitution ciphers by comparing letter frequencies to English language patterns.

**Most common English letters:** E, T, A, O, I, N, S, H, R, D, L, C, U

**Usage:**
1. Select option **8**
2. Enter encrypted text
3. Review the frequency distribution
4. Compare to English letter frequencies

---

## 🛡️ Security Notes

**Important:** These ciphers are **NOT secure** for modern use!

- **Educational purposes only**
- Caesar cipher can be broken in seconds
- Substitution ciphers vulnerable to frequency analysis
- Vigenère cipher can be broken with modern techniques

For real security, use modern encryption standards like:
- AES (Advanced Encryption Standard)
- RSA (for public-key cryptography)
- TLS/SSL (for web communications)

---

## 📋 Technical Details

### Algorithms Implemented

**Caesar Cipher:**
- Time Complexity: O(n)
- Space Complexity: O(n)
- Key Space: 26 possible shifts

**Substitution Cipher:**
- Time Complexity: O(n)
- Space Complexity: O(n)
- Key Space: 26! (≈ 4 × 10²⁶) possible keys

**Vigenère Cipher:**
- Time Complexity: O(n)
- Space Complexity: O(n)
- Key Space: 26^k where k is keyword length

---

## 🐛 Troubleshooting

### Common Issues

**Problem:** Compilation errors
- **Solution:** Ensure you have a C++11 compatible compiler

**Problem:** File not found error
- **Solution:** Provide the full path or ensure file is in same directory

**Problem:** Substitution key error
- **Solution:** Key must be exactly 26 unique letters

---

## 📝 Examples

### Complete Workflow Example

```
$ ./securetext

╔════════════════════════════════════════════════════════╗
║                                                        ║
║          SECURE TEXT: A CLASSICAL CIPHER TOOL          ║
║                    by Michael Semera                   ║
║                                                        ║
╚════════════════════════════════════════════════════════╝

Enter your choice: 1

--- Caesar Cipher Encryption ---
Enter text to encrypt: Attack at dawn!
Enter shift value (0-25): 7

Encrypted text: Haahjr ha khdx!
```

---

## 🤝 Contributing

This is an educational project. Feel free to:
- Suggest improvements
- Report bugs
- Add new cipher types
- Improve documentation

---

## 📜 License

This project is released for educational purposes.

---

## 👤 Author

**Michael Semera**
- LinkedIn: [Michael Semera](https://www.linkedin.com/in/michael-semera-586737295/)
- GitHub: [MichaelKS123](https://github.com/MichaelKS123)
- Email: michaelsemera15@gmail.com

## 📞 Contact & Support

For questions, suggestions, or collaboration opportunities:
- Open an issue on GitHub
- Email: michaelsemera15@gmail.com
- LinkedIn: [Michael Semera](https://www.linkedin.com/in/michael-semera-586737295/)

---

## 🎓 Educational Resources

Want to learn more about cryptography?
- "The Code Book" by Simon Singh
- "Cryptography and Network Security" by William Stallings
- Khan Academy - Cryptography course

---

## ⚠️ Disclaimer

This software is provided for educational purposes only. The author is not responsible for any misuse of this tool. Classical ciphers implemented here are **not secure** for protecting sensitive information in the modern age.

---

**Thank you for using Secure Text!**


*Stay curious, stay secure!* 🔐

