#include <iostream>
#include <vector>
#include <math.h>
using namespace std;




int main() {
    int n;
    int number=0;
    cin >> n;
    n++;
    vector<char> array(int(pow(2, n)));
    array[1]='a'; // without 0-th element due to multiplication
    for (int i=1; i<int(pow(2, n-1)); i++)
    {
        if(array[i]=='a')
        {
            array[2*i]='b';
            array[2*i+1]='c';
        }
        if(array[i]=='b') {
            array[2 * i] = 'c';
            array[2 * i + 1] = 'a';
        }
        if(array[i]=='c') {
            array[2 * i] = 'b';
            array[2 * i + 1] = 'a';
        }
    }
    for (int i=int(pow(2, n-1))+1; i<int(pow(2, n)); i++)
    {
        if (array[i]=='a')
        {
            for(int j=i; j>0; j/=2)
            {
                cout<<array[j];
            }
            cout << " " << ++number << endl;
        }
    }
    return 0;

}