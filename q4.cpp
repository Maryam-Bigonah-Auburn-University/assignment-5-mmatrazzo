#include <iostream>
#include <fstream>
#include <string>

using namespace std;     // Use the standard namespace

// Be sure to place the answers.txt file in the proper location in your directory and correctly populate it with the answers

int main() {
    // Declare the question and answer strings
    string question;
    string answer;

    // Declare and open the input stream originating from the file answers.txt
    ifstream inFile;
    inFile.open("answers.txt");

    // Infinite loop
    do {
        // Prompt for and obtain user input for the question
        cout << endl << "Enter a question (or enter 0 to exit): ";
        getline(cin, question);

        // If the user enters "0", terminate the program
        if (question == "0") {
            return 0;     // Terminate the program
        }

        // If the end of the answers.txt file has been reached, close and reopen it
        if (inFile.eof()) {
            inFile.close();
            inFile.open("answers.txt");
        }

        // Read in the next line from the file, with the end of each line being indicated by a '/n' character
        getline(inFile, answer, '\n');

        //
        cout <<endl << answer << endl;
    } while(1);
}
