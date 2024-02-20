#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif



bool is_palindrome_recursive(std::string s, int start, int end) {
    // Base case: if the start index crosses the end index, it means we have checked all characters
    // and the string is a palindrome
    if (start >= end) {
        return true;
    }

    // Check if the characters at start and end indexes are equal
    if (s[start] != s[end]) {
        return false;
    }

    // Recur for the substring excluding the start and end characters
    return is_palindrome_recursive(s, start + 1, end - 1);
}
bool palindrome_recursive(std::string s)

{
  RECURSIVE_FUNC

// Do not modify rest of the code, or the automated testing won't work.
          return  is_palindrome_recursive(s, 0, s.length() - 1);

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

