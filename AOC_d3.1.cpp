
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.in");

static int verify(char x)
{
    if (x == '.')
        return 0;
    else if (x >= '0' && x <= '9')
        return 0;
    else
        return 1;
}

int main()
{
    int i, j, sum = 0, n = 140, m = 140;
    char a[142][142];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            fin >> a[i][j];

    for (i = 0; i <= n+1; i++)
        a[i][0] = a[i][n+1] = '.';
    for (j = 0; j <= m+1; j++)
        a[0][j] = a[m+1][j] = '.';

    for (i = 0; i <= n+1; i++)
    {
        for (j = 0; j <= m+1; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    for(i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            int ok = 0, x = 0;
            while (isdigit(a[i][j]))
            {
                x = x * 10 + (a[i][j] - '0');
                if (verify(a[i - 1][j - 1]) || verify(a[i - 1][j]) || verify(a[i - 1][j + 1]) ||
                    verify(a[i + 1][j - 1]) || verify(a[i + 1][j]) || verify(a[i + 1][j + 1]) ||
                    verify(a[i][j - 1]) || verify(a[i][j + 1]))
                    ok = 1;
                j++;
            }
            if (ok)
                sum += x;
        }
    cout << sum;
    return 0;
}
