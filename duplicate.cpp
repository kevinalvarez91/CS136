#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main() {
    // Input and output file names
    std::string inputFile = "mailinglist.txt";
    std::string outputFile = "output.txt";

    // Open the input file
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Open the output file
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    std::unordered_set<std::string> uniqueEmails;  // To store unique emails
    std::string email;

    // Read email addresses from the input file
    while (std::getline(inFile, email)) {
        // Check if the email is already in the set (a duplicate)
        if (uniqueEmails.find(email) == uniqueEmails.end()) {
            // If not a duplicate, write it to the output file
            outFile << email << std::endl;
            // Add it to the set to track uniqueness
            uniqueEmails.insert(email);
        }
    }

    // Close the input and output files
    inFile.close();
    outFile.close();

    std::cout << "Duplicates removed and unique emails saved to " << outputFile << std::endl;

    return 0;
}
