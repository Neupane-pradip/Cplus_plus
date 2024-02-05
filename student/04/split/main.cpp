#include <iostream>
#include <string>
#include <vector>


// TODO: Implement split function here
// Do not change main function

// Function to split the string into parts at the separators

std::vector<std::string> split(const std::string& input, char separator, bool ignoreEmpty = false) {
    std::vector<std::string> parts;
    std::string currentPart;

    for (char ch : input) {
        if (ch == separator) {
            if (!ignoreEmpty || !currentPart.empty()) {
                parts.push_back(currentPart);
                currentPart.clear();
            }
        } else {
            currentPart += ch;
        }
    }

    // Add the last part
    if (!ignoreEmpty || !currentPart.empty()) {
        parts.push_back(currentPart);
    }

    return parts;
}


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
