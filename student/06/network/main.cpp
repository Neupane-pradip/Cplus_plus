#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";

using NETWORK = std::map<std::string, std::vector<std::string>>;



std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

void store(std::string const &id1, std::string const &id2, NETWORK &network)
{
   if(network.find(id1) == network.end())
   {

    network.insert({id1, {}});
   }

    network.at(id1).push_back(id2);
}

void print(std::string const &id, NETWORK const &network, std::string identation = "")
{


         std::cout<< identation << id << std::endl;

         if(network.find(id) != network.end())
         {

            std::vector<std::string> :: const_iterator iter= network.at(id).begin();

            while (iter!=network.at(id).end())
            {
            print(*iter, network, identation + "..");
            iter++;
            }
        }

}

unsigned count(std::string const &id , NETWORK const &network)
{
    if(network.find(id) == network.end()
       || network.at(id).empty())
    {
        return 0;
    }

    else{
        unsigned int total_count =0;

        for(std::vector<std::string>::const_iterator iter = network.at(id).begin()
            ; iter != network.at(id).end()
            ; iter++)
        {
            total_count ++;
            total_count += count(*iter,network);
        }

        return total_count;
    }
}

unsigned depth(std::string const &id , NETWORK const &network)
{
    unsigned int max_level =0;
    unsigned int temp_level =0;

    if(network.find(id)!=network.end())
    {
        for(std::string person : network.at(id))
        {
            temp_level =depth(person, network);
            if(temp_level > max_level)
            {
                max_level = temp_level;
            }
        }
    }

    return max_level+1;
}



int main()
{
    // TODO: Implement the datastructure here
    NETWORK network = {};


    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here!

            store(id1,id2, network);

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!

            print(id, network);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
             std::cout<< count(id,network) <<std::endl;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            std::cout<< depth(id,network) <<std::endl;


        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
