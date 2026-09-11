#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}