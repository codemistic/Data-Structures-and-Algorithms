#include<stdio.h>
#include<string.h>
int main(){
    char str1[105],str2[105],count=0;
    scanf("%s%s",str1,str2);
    int length=strlen(str1);
    for(int i=0;i<length;i++)
    {
        if(str1[i]==str2[length-i-1])
            count++;
    }
    count==length?printf("YES\n"):printf("NO\n");
}
