#include <iostream>
#include <cstring>
#include <string>

using namespace std;     // Standard namespace

int main() {
    char sentence[100];     // Primary c-string
    char tempSentence[100];     // Temporary c-string
    bool spaceDetected = false;     // Boolean variable for detecting multiple consecutive spaces

    // Prompt user to enter a period-terminated sentence
    cout << "Please enter your sentence (period-terminated): " << endl;

    cin.getline(sentence, 100);     // Obtain user input

    sentence[0] = toupper(sentence[0]);     // Convert the first character to upper case

    // For loop that loops through each element in the entered c-string
    for(int i = 1; i < strlen(sentence); i++) {
        // Check if a period has been reached, and discards anything entered after the period
        if (sentence[i] == '.') {
            // Create a temporary c-string with only the characters leading up to and including the period
            for(int k = 0; k <= i; k++) {
                tempSentence[k] = sentence[k];
            }
            strcpy(sentence, tempSentence);     // Copy the temporary c-string into the original c-string
            break;     // Force-exit the for loop
        }

        // Check the character and, if it is upper case, convert it to lower case
        if (isupper(sentence[i])) {
            sentence[i] = tolower(sentence[i]);
        }

        // Check if the previous and current character was a space
        if (spaceDetected == true && sentence[i] == ' ') {
            i--;     // Decrement the index to account for the removed character
            // Remove the extra space by shifting all remaining elements in the c-string down by one index
            for (int j = i; j < strlen(sentence); j++) {
                sentence[j] = sentence[j + 1];
            }
        }

        // Check if the current character is a space, and, if so, set the boolean spaceDetected to true
        if (sentence[i] == ' ') {
            spaceDetected = true;
        }

        // Check if the current character is not a space, and, if so, se the boolean spaceDetected to false
        if (sentence[i] != ' ') {
            spaceDetected = false;
        }
    }

    // Print the modified c-string
    cout << endl << "the resulting sentence is: " << sentence;

    return 0;     // Terminate the program
}
