import java.util.*;
class Rope_cutting 
{
    static int get_max(int n, int a, int b, int c)
    {
        if(n < 1)
          return n;
        /* 
        // first drafts are bad at times
        int x = -1 , y = -1, z = -1;
        x = get_max(n-a,a,b,c);
        y = get_max(n-b,a,b,c);
        z = get_max(n-c,a,b,c);
        x = (x > -1) ? x+1 : -1; 
        y = (y > -1) ? y+1 : -1; 
        z = (z > -1) ? z+1 : -1;
        return (Math.max(x, Math.max(y,z)));
        */
        int ans = Math.max(get_max(n-a,a,b,c),Math.max(get_max(n-b,a,b,c),get_max(n-c,a,b,c))); //Concise version of the above code
        if(ans > -1)
        return ans + 1;
        return -1;
    }
    public static void main(String args[])
    {
        Scanner I = new Scanner(System.in);
        int n = I.nextInt(),a = I.nextInt(),b = I.nextInt(),c = I.nextInt();
        int ans = get_max(n,a,b,c);
        System.out.println("Answer : " + ans);
        I.close();
    }
}
//TIME COMPLEXITY  = 3^N, WHERE N = LENGTH OF THE ROD




/*  
//DP Solution for the same
    #include<bits/stdc++.h>   //Given that a way to cut the ribbon exists therefore {a*x + b*y +c*z = n}
                              //Task is to maximise x+y+z
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n,a,b,c,x=-1,y=-1,z=-1;
        cin >> n >> a >> b >> c;
        int dp[n+1] = {};
        dp[0] = 0;
        for(int i = 1;i<=n;i++,x = -1,y=-1,z=-1)
        {
            x = ((i >= a) ? dp[i-a] : -1);
            y = ((i >= b) ? dp[i-b] : -1);
            z = ((i >= c) ? dp[i-c] : -1);
            if(x+y+z == -3)
              dp[i] = -1;
            else
              dp[i] = max({x,y,z}) + 1;
        }
        cout << dp[n];
        return 0;
    }
*/