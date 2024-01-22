#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    uint number;
    cin >> number;

    //display the error message if user input is lesser equal to 0
    if (number <= 0)
     {
        cout <<"Only positive numbers accepted" <<endl;
        return 0;
    }

    uint min_num = number;
    uint a1 = 0;
    uint a2 = 0;

    for (uint i = 1; i < number; i++)
    // now nearest lower facors is determined
    {
        uint division_result = number/i;
        if( division_result * i == number)
        {
            uint distance = division_result - i;

            if (distance < min_num)
            {
                min_num = distance;

                a1 = i;

                a2 = division_result;
            }

        }
    }
    //display the result
    cout << number<< " = " << a1 <<" * " << a2<<endl;
    return 0;
}
