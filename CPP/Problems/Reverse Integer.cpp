class Solution {
public:
   int reverse(int x) {
int reverse =0;
while (x!=0)
{
if(214748364<reverse || -214748364 > reverse)
return 0;
reverse= (reverse * 10) + x%10;
x/=10;
}
return reverse;
}
        
        
    
};
