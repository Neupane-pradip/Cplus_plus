#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>


std::vector<std::string> read_file(std::string filename, int &status)
{  //open the file and check
   std::ifstream  file(filename);
   if(!file)
   {
       std::cout<<"Error! The file " + filename + " cannot be opened."<<std::endl;
       status =EXIT_FAILURE;
       return {};
   }

   std::vector<std::string> lines = {};
   std::string line = "";
   while (std::getline(file,line))
   {
       lines.push_back(line);
   }


   return lines;

}

using DATA =  std::map<std::string ,std::set<int>>;

void parse_data_line(std::string const &line, int line_number ,DATA &rows_data)
{
   std::string word = "";
   std::istringstream streams_of_word(line);
   while(streams_of_word >> word)
   {
       //save data to structure
       if (rows_data.find(word) == rows_data.end())
       {
           rows_data.insert({word, {}});

       }
       rows_data.at(word).insert(line_number);
   }




}

void print_out_data_structure(DATA const &rows_data)
{
    for (DATA::const_iterator iter = rows_data.begin(); iter != rows_data.end(); iter++)
    {
        std::string word  = iter ->first;
        std::set<int> line_number = iter ->second;

        std::cout <<word << " " << line_number.size() <<": ";
        //print oout the lines
        for (std::set<int>::iterator lines_iter = line_number.begin();
                                                  lines_iter != line_number.end(); lines_iter)
        {


            std::cout << *lines_iter;
            if (++lines_iter == line_number.end())
            {
                std::cout<<std::endl;

            }
            else{
                std::cout<<", ";
            }
            lines_iter--;
        }
    }

}



int main()
{
    //dat structure
    DATA rows_data = {};
    int status = EXIT_SUCCESS;


   // get file name
   std::string filename = "";
   std::cout <<"Input file: ";
   std::getline(std::cin,filename);

   //implement file reading
    std::vector<std::string> lines = read_file(filename, status);




    //implement read into data
    for (uint i=0 ; i < lines.size();i++)
    {
        std::string  line = lines.at(i);
        int line_number = i + 1;
        parse_data_line(line,line_number,rows_data);
    }

    //print out
    print_out_data_structure(rows_data);




    return status;

}
