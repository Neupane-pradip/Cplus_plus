#include <cstdlib>
#include <iostream>
#include <vector>


// Prints the elements in the parameter vector ints.
void print_integers(const std::vector< int >& ints)
{
    for(auto elem : ints) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Reads as many integers as the parameter count indicates
// and stores them into the parameter vector ints.
void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i) {
        std::cin >> new_integer;
        // TODO: Implement your solution here
        ints.push_back(new_integer);

    }
}


// TODO: Implement your solution here

// Returns true if all integers in the vector are the same.
bool same_values(const std::vector<int>& ints) {
    if (ints.size() <= 1) {
        return true;
    }

    int first_value = ints[0];
    for (std::vector<int>::size_type i = 1; i < ints.size(); ++i) {
        if (ints[i] != first_value) {
            return false;
        }
    }

    return true;
}

// Returns true if the integers are in a non-strict ascending order.
bool is_ordered_non_strict_ascending(const std::vector<int>& ints) {
    for (std::vector<int>::size_type i = 1; i < ints.size(); ++i) {
        if (ints[i - 1] > ints[i]) {
            return false;
        }
    }
    return true;
}

// Returns true if the integers form an arithmetic series.
bool is_arithmetic_series(const std::vector<int>& ints) {
    if (ints.size() <= 1) {
        return true;
    }

    int common_difference = ints[1] - ints[0];


    for (std::vector<int>::size_type i = 2; i < ints.size(); ++i) {
        if (ints[i] - ints[i - 1] != common_difference) {
            return false;
        }
    }

    return true;
}

// Returns true if the integers form a geometric series.
bool is_geometric_series(const std::vector<int>& ints) {
    if (ints.size() <= 1) {
        return true;
    }

    double common_ratio = static_cast<double>(ints[1]) / ints[0];
    for (std::vector<int>::size_type i = 2; i < ints.size(); ++i) {
        if (static_cast<double>(ints[i]) / ints[i - 1] != common_ratio) {
            return false;
        }
    }

    return true;
}


// Triples each integer in the vector.
void triple_integers(std::vector<int>& ints) {
    for (int& value : ints) {
        value *= 3;
    }
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    if(how_many <= 0) {
        return EXIT_FAILURE;
    }

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers)) {
        std::cout << "All the integers are the same" << std::endl;
    } else {
        std::cout << "All the integers are not the same" << std::endl;
    }

    if(is_ordered_non_strict_ascending(integers)) {
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    } else {
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;
    }

    if(is_arithmetic_series(integers)) {
        std::cout << "The integers form an arithmetic series" << std::endl;
    } else {
        std::cout << "The integers do not form an arithmetic series" << std::endl;
    }

    if(is_geometric_series(integers)) {
        std::cout << "The integers form a geometric series" << std::endl;
    } else {
        std::cout << "The integers do not form a geometric series" << std::endl;
    }

    triple_integers(integers);
    std::cout << "Tripled values: ";
    print_integers(integers);

    return EXIT_SUCCESS;
}

