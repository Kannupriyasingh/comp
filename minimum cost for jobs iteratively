#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int **cost, int n)
{
    int *dp = new int[1<<n];
    for(int i = 0; i < (1<<n); i++)
    dp[i] = INT_MAX;
    
    dp[0] = 0;
    
    for(int mask = 0; mask < ((1<<n)-1); mask++)
    {
        //count number of set bits
        int temp = mask;
        int k = 0;
        while(temp)
        {
            if((temp%2) == 1)
            k++;
            
            temp/=2;
        }
        
        for(int j = 0; j < n; j++)
        {
            if(!(mask&(1<<j)))
            {
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + cost[k][j]);
            }
        }
    }
    return dp[(1<<n) - 1];
}

int main()
{
    int jobs, person;
    cin >> jobs >> person;
    int **cost = new int*[jobs];
    
    for(int i = 0; i < jobs; i++)
    {
        cost[i] = new int[person];
        for(int j = 0; j < person; j++)
        cin >> cost[i][j];
    }
    
    cout << solve(cost, jobs);
    for(int i = 0; i < jobs; i++)
    delete [] cost[i];
    
    delete [] cost;

    return 0;
}
