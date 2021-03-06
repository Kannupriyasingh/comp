*****************************************************************************
/*
input : 4 4
        10 2 6 5
        1 15 12 8
        7 8 9 3
        15 13 4 10
output: 10
*/
*****************************************************************************
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int min_cost(int **arr, int jobs, int p, int mask, int *dp)
{
    if(p >= jobs)
    return 0;
    
    if(dp[mask] != INT_MAX)
    return dp[mask];
    
    int minimum = INT_MAX;
    for(int i = 0; i < jobs; i++)
    {
        int check_bit = mask&(1<<i);
        if(check_bit == 0)
        {
            int ans = min_cost(arr,jobs,p+1,mask|(1<<i), dp) + arr[p][i];
            if(minimum > ans)
            minimum = ans;
        }
    }
    return dp[mask] = minimum;
}

int main()
{

int jobs,person;
cin >> jobs >> person;
int **arr = new int*[jobs];
for(int i = 0; i < jobs; i++)
{
    arr[i] = new int[person];
    for(int j = 0; j < person; j++)
    cin >> arr[i][j];
}
// dp size is 0 to 2^n-1 and here n == jobs
int *dp = new int[1<<jobs];
for(int i = 0; i < (1<<jobs); i++)
dp[i] = INT_MAX;

cout << min_cost(arr, jobs, 0, 0, dp);

for(int i = 0; i < jobs; i++)
delete [] arr[i];

delete [] arr;
delete [] dp;
    return 0;
}
