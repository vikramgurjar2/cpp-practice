#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int dp[701][701];

int numDistinct(string A, string B)
{
  int m = A.size();
  int n = B.size();

  for (int i = 0; i < m + 1; i++)
  {
    dp[0][i] = 0;
  }
  for (int j = 0; j < n + 1; j++)
  {
    dp[j][0] = 0;
  }

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      if (A[j - 1] == B[i - 1])
      {
        if (i != 1)
        {
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
        else
        {
          dp[i][j] = 1 + dp[i][j - 1];
        }
      }
      else
      {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }
  return dp[n][m];
}

int main()
{
  string A = "rabbbit";
  string B = "rabbit";
  int res = numDistinct(A, B);
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}