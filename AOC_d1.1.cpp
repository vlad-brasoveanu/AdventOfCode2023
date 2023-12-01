#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

ifstream fin("input.in");

int main()
{
    long sum = 0, number;
    char s[101];
    for (int i = 0; i < 1000; i++)
    {
        fin.getline(s, 100);
        int j = 0, k = strlen(s) - 1;
        while (isdigit(s[j++]) == 0);
        while (isdigit(s[k--]) == 0);
        number = (s[--j] - '0') * 10 + (s[++k] - '0');
        sum += number;
    }
    cout << sum;
    return 0;
}
