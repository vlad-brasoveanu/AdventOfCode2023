#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

ifstream fin("input.in");

char* t;
int lungime;

int checkifDigit_LTR(char s[], int &lmax)
{
    int nr = 0;
    lmax = 0;
    char* m = strstr(s, "one");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 1;
    }
    m = strstr(s, "two");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 2;
    }
    m = strstr(s, "three");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 3;
    }
    m = strstr(s, "four");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 4;
    }
    m = strstr(s, "five");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 5;
    }
    m = strstr(s, "six");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 6;
    }
    m = strstr(s, "seven");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 7;
    }
    m = strstr(s, "eight");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 8;
    }
    m = strstr(s, "nine");
    if (m != NULL && strlen(m) > lmax)
    {
        lmax = strlen(m);
        nr = 9;
    }
    return nr;
}

int checkifDigit_RTL(char s[], int &lmax)
{
    int nr = 0;
    lmax = 0;
    char* p = strstr(s, "eno");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 1;
    }
    p = strstr(s, "owt");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 2;
    }
    p = strstr(s, "eerht");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 3;
    }
    p = strstr(s, "ruof");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 4;
    }
    p = strstr(s, "evif");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 5;
    }
    p = strstr(s, "xis");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 6;
    }
    p = strstr(s, "neves");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 7;
    }
    p = strstr(s, "thgie");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 8;
    }
    p = strstr(s, "enin");
    if (p != NULL && strlen(p) > lmax)
    {
        lmax = strlen(p);
        nr = 9;
    }
    return nr;
}

void mirrorstr(char s[], char t[])
{
    int i = 0, j = 0;
    for (i = strlen(s) - 1; i >= 0; i--)
        t[j++] = s[i];
    t[j] = '\0';
}

int main()
{
    long sum = 0;
    char s[1000];
    for (int k = 0; k < 1000; k++)
    {
        int st = 0, dr = 0, i = 0;
        fin.getline(s, 100);
        while (isdigit(s[i]) == 0 && s[i] != '\0')
            i++;
        int cf = checkifDigit_LTR(s, lungime);
        if (i < strlen(s) - lungime + 1)
            st = s[i] - '0';
        else
            st = cf;
        char t[101] = "";
        mirrorstr(s, t);
        i = 0;
        while (isdigit(t[i]) == 0 && t[i] != '\0')
            i++;
        cf = checkifDigit_RTL(t, lungime);
        if (i < strlen(t) - lungime + 1)
            dr = t[i] - '0';
        else
            dr = cf;
        sum += (st * 10 + dr);
    }
    cout << sum;
    return 0;
}