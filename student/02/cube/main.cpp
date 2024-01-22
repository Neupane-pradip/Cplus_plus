#include <iostream>

using namespace std;


int main()
{

    cout << "Enter a number: ";

    int number;

    cin >> number;

    int cube = number*number*number;

    if(number == 0)
    {
        cout << "The cube of " << number << " is " << cube<< "." << endl;

        return 0;

    }

    if(cube/number/number == number)
    {
         cout << "The cube of " << number << " is " << cube<< "." << endl;
    }

    else {
          cout << "The cube of " << number << " is not " << cube<< "." << endl;
    }


    return 0;
}


