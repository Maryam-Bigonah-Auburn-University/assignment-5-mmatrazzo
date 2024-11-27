#include <iostream>
#include <cstring>
#include <string>

using namespace std;     // Standard namespace

int main() {
    char cstring[300];     // Set max length of c-string to 300 characters
    int charCounter = 0;     // Initialize character counter to zero

    // Prompt user to enter a line of text
    cout << "Please enter your line of text: " << endl;

    cin.getline(cstring, 300);     // Obtain user input

    // For loop to check each character in the c-string
    for(int i = 0; i < strlen(cstring); i++) {
        // Check if the current character is a letter (upper case or lower case)
        if((cstring[i] > 64 && cstring[i] < 91) || (cstring[i] > 96 && cstring[i] < 123)) {
            charCounter++;     // Increment the character counter
        }

        // Reset the character counter if a non-letter character has been reached
        else {
            charCounter = 0;
        }

        // Check if four consecutive characters have been encountered
        if (charCounter == 4) {
            // Check if the fifth character is a non-letter
            if(cstring[i + 1] < 65 || (cstring[i + 1] > 90 && cstring[i + 1] < 97) || cstring[i + 1] > 122) {
                // Check if the first letter in the four-letter word is upper-case
                if(isupper(cstring[i - 3])) {
                    // Convert the four-letter word to "Love"
                    cstring[i - 3] = 'L';     // Make the first letter in "love" upper-case to match
                    cstring[i - 2] = 'o';
                    cstring[i - 1] = 'v';
                    cstring[i] = 'e';
                }

                // Runs if the first letter in the four-letter word is lower-case
                else {
                    // Convert the four-letter word to "love"
                    cstring[i - 3] = 'l';     // Make the first letter in "love" lower-case to match
                    cstring[i - 2] = 'o';
                    cstring[i - 1] = 'v';
                    cstring[i] = 'e';
                }
            }
        }
    }

    // Print the modified c-string
    cout << endl << "the resulting sentence is: " << cstring;

    return 0;     // Terminate the program
}
