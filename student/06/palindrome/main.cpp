#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif



bool is_recursive(std::string s) {


    // Base case: if the length of the string is 0 or 1, it is a palindrome
        if (s.length() <= 1) {
            return true;
        }

        // Check if the first and last characters of the string are equal
        if (s.front() != s.back()) {
            return false;
        }

        // Recur for the substring excluding the first and last characters
        return is_recursive(s.substr(1, s.length() - 2));
}
bool palindrome_recursive(std::string s)

{
  RECURSIVE_FUNC

// Do not modify rest of the code, or the automated testing won't work.
          return  is_recursive(s);

          }

#ifndef UNIT_TESTING

int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif

