#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    if (x >= 80)
    {
        printf("A");
    }
    else if (x >= 75)
    {
        printf("B+");
    }
    else if (x >= 70)
    {
        printf("B");
    }
    else if (x >= 65)
    {
        printf("C+");
    }
    else if (x >= 60)
    {
        printf("C");
    }
}