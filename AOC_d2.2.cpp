#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#pragma warning (disable : 4996)

using namespace std;

ifstream fin("input.in");

int main()
{
    char s[200];
    int id, r, g, b, x = 0, ok, sum = 0;
    for (int k = 0; k < 100; k++)
    {

        r = 0, g = 0, b = 0, ok = 1;
        fin.getline(s, 200);
        id = stoi(s + 5);
        char* p;
        if (id < 10)
            p = strtok(s + 8, ",;");
        else if (id < 100)
            p = strtok(s + 9, ",;");
        else
            p = strtok(s + 10, ",;");
        while (p != NULL)
        {
            char t[100] = "";
            strcpy(t, p);
            if (t[0] == ' ')
                strcpy(t, t + 1);
            if (isdigit(t[0]))
                x = stoi(t);
            if (strstr(p, "red") && x > r)
                r = x;
            else if (strstr(p, "green") && x > g)
                g = x;
            else if (strstr(p, "blue") && x > b)
                b = x;
            p = strtok(NULL, ",;");
        }
        sum += r * g * b;
    }
    cout << sum;
    return 0;
}

