
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("input.in");

int main()
{
    char* p = (char*)malloc(sizeof(char)*214);
    int i, j, k, v[10]{}, w[25]{}, count, sum = 0;
    for (i = 1; i <= 214; i++)
    {
        k = 0, count = -1;
        if(i < 10)
            while (k < 6)
            {
                fin >> *p;
                k++;
            }
        else if (i < 100)
            while (k < 7)
            {
                fin >> *p;
                k++;
            }
        else
            while (k < 8)
            {
                fin >> *p;
                k++;
            }

        for (j = 0; j < 10; j++)
            fin >> v[j];
        fin >> *p;
        for (j = 0; j < 25; j++)
            fin >> w[j];
        for (j = 0; j < 10; j++)
            for (k = 0; k < 25; k++)
                if (w[k] == v[j])
                    count++;
        if(count > -1)
            sum += pow(2, count);
    }
    cout << sum;
    return 0;
}
