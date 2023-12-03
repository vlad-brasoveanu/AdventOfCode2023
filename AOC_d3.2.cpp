
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.in");

int main()
{
    int i, j, sum = 0, n = 140, m = 140;
    char a[142][142];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            fin >> a[i][j];

    for (i = 1; i < n - 1; i++)
        for (j = 3; j < m - 2; j++)
        {
            int ok = 0, x = 0, prod = 1, k = 0;
            if (a[i][j] == '*')
            {
                if (isdigit(a[i - 1][j]))
                {
                    x = a[i - 1][j] - '0';
                    if (isdigit(a[i - 1][j - 1]))
                    {
                        x = (a[i - 1][j - 1] - '0') * 10 + x;
                        if (isdigit(a[i - 1][j - 2]))
                            x = (a[i - 1][j - 2] - '0') * 100 + x;
                    }
                    if (isdigit(a[i - 1][j + 1]))
                    {
                        x = (a[i - 1][j + 1] - '0') + x * 10;
                        if (isdigit(a[i - 1][j + 2]))
                            x = (a[i - 1][j + 2] - '0') + x * 10;
                    }
                    prod *= x;
                    k++;
                }
                else
                {
                    if (isdigit(a[i - 1][j - 1]))
                    {
                        x = a[i - 1][j - 1] - '0';
                        if (isdigit(a[i - 1][j - 2]))
                        {
                            x = x + (a[i - 1][j - 2] - '0') * 10;
                            if (isdigit(a[i - 1][j - 3]))
                                x = x + (a[i - 1][j - 3] - '0') * 100;
                        }
                        prod *= x;
                        k++;
                    }
                    if (isdigit(a[i - 1][j + 1]))
                    {
                        x = a[i - 1][j + 1] - '0';
                        if (isdigit(a[i - 1][j + 2]))
                        {
                            x = x * 10 + (a[i - 1][j + 2] - '0');
                            if (isdigit(a[i - 1][j + 3]))
                                x = x * 10 + (a[i - 1][j + 3] - '0');
                        }
                        prod *= x;
                        k++;
                    }
                }
                if (isdigit(a[i + 1][j]))
                {
                    x = a[i + 1][j] - '0';
                    if (isdigit(a[i + 1][j - 1]))
                    {
                        x = (a[i + 1][j - 1] - '0') * 10 + x;
                        if (isdigit(a[i + 1][j - 2]))
                            x = (a[i + 1][j - 2] - '0') * 100 + x;
                    }
                    if (isdigit(a[i + 1][j + 1]))
                    {
                        x = (a[i + 1][j + 1] - '0') + x * 10;
                        if (isdigit(a[i + 1][j + 2]))
                            x = (a[i + 1][j + 2] - '0') + x * 10;
                    }
                    prod *= x;
                    k++;
                }
                else
                {
                    if (isdigit(a[i + 1][j - 1]))
                    {
                        x = a[i + 1][j - 1] - '0';
                        if (isdigit(a[i + 1][j - 2]))
                        {
                            x = x + (a[i + 1][j - 2] - '0') * 10;
                            if (isdigit(a[i + 1][j - 3]))
                                x = x + (a[i + 1][j - 3] - '0') * 100;
                        }
                        prod *= x;
                        k++;
                    }
                    if (isdigit(a[i + 1][j + 1]))
                    {
                        x = a[i + 1][j + 1] - '0';
                        if (isdigit(a[i + 1][j + 2]))
                        {
                            x = x * 10 + (a[i + 1][j + 2] - '0');
                            if (isdigit(a[i + 1][j + 3]))
                                x = x * 10 + (a[i + 1][j + 3] - '0');
                        }
                        prod *= x;
                        k++;
                    }
                }
                if (isdigit(a[i][j - 1]))
                {
                    x = a[i][j - 1] - '0';
                    if (isdigit(a[i][j - 2]))
                    {
                        x = x + (a[i][j - 2] - '0') * 10;
                        if(isdigit(a[i][j-3]))
                            x = x + (a[i][j-3] - '0') * 100;
                    }
                    prod *= x;
                    k++;

                }
                if (isdigit(a[i][j + 1]))
                {
                    x = a[i][j + 1] - '0';
                    if (isdigit(a[i][j + 2]))
                    {
                        x = x * 10 + (a[i][j + 2] - '0');
                        if (isdigit(a[i][j + 3]))
                            x = x * 10 + (a[i][j + 3] - '0');
                    }
                    prod *= x;
                    k++;
                }
                if (k == 2)
                    sum += prod;
            }
            
        }
    cout << sum;
    return 0;
}
