// c++ code to find Subarray whose elements sum is maximum with respect to other subarray
#include <bits/stdc++.h>
using namespace std;

// Function that calculate maximum sum of Subarray
int maxArray(int a[], int n)
{
  int max_sum = INT_MIN; // Store maximum sum
  int max_temp = 0;      // store temporary sum of subarray
  for (int i = 0; i < n; i++)
  {
    max_temp = max_temp + a[i];

    if (max_temp > max_sum)
    {
      max_sum = max_temp;
    }
    if (max_temp < 0)
    {
      max_temp = 0;
    }
  }
  return max_sum;
}

// Driver code
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int max_sum = maxArray(a, n)
                    cout
                << "Maximum contiguous sum is " << max_sum << endl;
  return 0;
}
