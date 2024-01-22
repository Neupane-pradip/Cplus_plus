
/*
* Programming 2:C++ Spring 2024.

* @author Pradip Neupane (pradipneupane@tuni.fi).
* StudentId: 150426327
*/


#include <iostream>

using namespace std;

int main()
{
    int n,i=1;
    cout << "How many numbers would you like to have? ";
    cin >> n;

    for (i=1;i<=n;i=i+1)
    {
        if( i%21==0)
        {
            cout<<"zip boing"<<endl;

        }
        else if( i%7 ==0)
        {
            cout<<"boing"<<endl;

        }
        else if(i%3==0)
        {
            cout<<"zip"<<endl;

        }

        else
        {
            cout <<i<<"\n";
        }
    }


    return 0;
}

