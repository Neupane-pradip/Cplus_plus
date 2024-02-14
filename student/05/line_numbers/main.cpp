#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string input_filename, output_filename;

    // Asking user for input and output filenames
    std::cout << "Input file: ";
    std::cin >> input_filename;
    std::cout << "Output file: ";
    std::cin >> output_filename;

    // Opening input file
    std::ifstream input_file(input_filename);

    // Checking if input file opened successfully
    if (!input_file.is_open()) {
        std::cout << "Error! The file " << input_filename << " cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    // Opening output file
    std::ofstream output_file(output_filename);

    // Writing line numbers and contents to output file
    std::string line;
    int line_number = 1;
    while (std::getline(input_file, line)) {
        std::cout << line_number << " " << line << std::endl;
        output_file << line_number << " " << line << std::endl;
        line_number++;
    }

    // Closing files
    input_file.close();
    output_file.close();



    return 0;
}
