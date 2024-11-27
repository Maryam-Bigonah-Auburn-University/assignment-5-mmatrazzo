#include <fstream>
#include <vector>

using namespace std;     // Use the standard namespace

// Be sure to place the .txt files in the proper location in your directory and correctly populate them with integers
// Separate each integer in the file with a space

// Function to sort and merge the input file contents and output the result in an output file
void mergeFiles(ifstream& inFile1, ifstream& inFile2, ofstream& outFile);

int main()
{
    // Declare the input and output streams
    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;

    // Open the input and output files
    inFile1.open("file1.txt");
    inFile2.open("file2.txt");
    outFile.open("file3.txt");

    // Call the mergeFiles function to perform the required operations
    mergeFiles(inFile1, inFile2, outFile);

    // Close the files
    inFile1.close();
    inFile2.close();
    outFile.close();

    return 0;     // Terminate the program
}

// Function to sort and merge the input file contents and output the result in an output file
void mergeFiles(ifstream& inFile1, ifstream& inFile2, ofstream& outFile) {
    // Declare variables needed for the function
    int nr;
    int temp;
    vector<int> intVect;     // Vector to contain all numbers obtained from the input files

    // Perform the following actions until the end of file1.txt is reached
    do {
        // Push the current number into the vector
        inFile1 >> nr;
        intVect.push_back(nr);
    } while(!inFile1.eof());

    // Perform the following actions until the end of file2.txt is reached
    do {
        // Push the current number into the vector
        inFile2 >> nr;
        intVect.push_back(nr);
    } while(!inFile2.eof());

    // Sort the vector from smallest to largest
    // Nested for loops to swap elements in the vector as the sorting algorithm progresses
    for (int i = 0; i < intVect.size() - 1; i++) {
        for (int j = i + 1; j < intVect.size(); j++) {
            // Perform if the jth element in intVector is less than the ith element
            if (intVect[j] < intVect[i]) {
                // Swap the elements
                temp = intVect[j];
                intVect[j] = intVect[i];
                intVect[i] = temp;
            }
        }
    }

    // Place the sorted list of integers into the output file (file3.txt)
    for (int i = 0; i < intVect.size(); i++) {
        outFile << intVect[i] << " ";
    }
}
