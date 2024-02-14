#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

int main() {
    std::string filename;
    std::cout << "Input file: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error! The file " << filename << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    std::map<std::string, int> scores;

       std::string line;
       while (std::getline(file, line)) {
           std::string name = line.substr(0, line.find(":"));
           int points = std::stoi(line.substr(line.find(":") + 1));
           scores[name] += points;
       }

       file.close();

       std::cout << "Final scores:" << std::endl;
       for (const auto& pair : scores) {
           std::cout << pair.first << ": " << pair.second << std::endl;
       }

    return EXIT_SUCCESS;
}
