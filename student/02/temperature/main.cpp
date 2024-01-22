#include <iostream>

using namespace std;

int main()

{
    float fahrenheit,celsius;

    int temperature;
    cout << "Enter a temperature: ";

    // Write your code here
    cin>>temperature;

    //change given input temperaturre from celsius to fahrenheit
    fahrenheit=(1.8*temperature)+32;

    cout<<temperature<<" degrees Fahrenheit is " << fahrenheit<<" degrees Celsius"
       << endl;

    //change given temperature from fahrenhit to celsius
     celsius = (temperature - 32) /1.8;
     cout <<temperature << " degrees Fahrenheit is " << celsius<<" degrees Celsius"
     << endl;


    return 0;
}
