#include <iostream>

const int ASCII_MIN = 97;
const int ASCII_MAX = 122;
const int Key_Max_Length = 26;

const std::string Error_length= "Error! The encryption key must contain 26 characters.";
const std::string Error_lowercase= "Error! The encryption key must contain only lower case characters.";
const std::string Error_Alphabet= "Error! The encryption key must contain all alphabets a-z.";
const std::string Error_length_in_lowercase= "Error! The text to be encrypted must contain only lower case characters.";

bool check_key_length(const std::string &key, const std::string &error_message);
bool check_all_lowercase(const std::string &key,const std::string &error_message);
bool check_all_Alphabet(const std::string &key, const std::string &error_message);

void encrypt_text(std::string &text, const std::string &key);

int main()
{
   std::string key = "";
   std::string text = "";

   std::cout <<"Enter the encryption key: ";
   std::getline(std::cin, key);

   if(!check_key_length(key,Error_length) or
      !check_all_lowercase(key,Error_lowercase) or
      !check_all_Alphabet(key,Error_Alphabet))
   {
      return EXIT_FAILURE;
   }


   std::cout << "Enter the text to be encrypted: ";
   std::getline(std::cin, text);

   if (!check_all_lowercase(text,Error_length_in_lowercase))
   {
       return EXIT_FAILURE;
   }

   encrypt_text(text,key);
   std::cout <<"Encrypted text: " << text << std::endl;


    return 0;
}

bool check_key_length(const std::string &key, const std::string &error_message) {
    if(key.length()== Key_Max_Length)
     {
        return true;
    }
    std::cout << error_message <<std::endl;
    return false;
}

bool check_all_lowercase(const std::string &key, const std::string &error_message){


    for(char c : key)
    {

        if (c < ASCII_MIN || c > ASCII_MAX)
        {
            std::cout <<error_message <<std::endl;
            return false;
        }
    }
    return true;
}

bool check_all_Alphabet(const std::string &key, const std::string &error_message){

    for(uint c = ASCII_MIN; c <= ASCII_MAX; c++)
    {
        if (key.find(c) == std::string::npos)
        {
            std::cout <<error_message <<std::endl;
            return false;
        }
    }
    return true;
}

void encrypt_text(std::string &text, const std::string &key)
{
   for(uint i =0; i < text.length(); i++)
   {
       char c = text.at(i);
       text.at(i) = key.at(c - ASCII_MIN);

   }

}







