#include <stdio.h>

// Compare two strings
int isSameString(char *s1, char *s2) {
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

// Example of a palindrome: madam
int isPalindrome(char *s) {
    int i = 0, j = 0;

    // Increment 'j' till it points to element '\0'
    for (j = 0; s[j] != '\0'; j++) {}
    j--; // Decrement 'j' so it points to the second last element

    while (i < j) {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    char s1[] = "Amazing123";
    char s2[] = "Amazing123v";
    printf("1) Strings: %s and %s\n",s1,s2);
    if (isSameString(s1,s2)) printf("The strings are same\n");
    else printf("The strings are NOT same\n");

    char s3[] = "ma44am";
    printf("2) String: %s\n", s3);
    if (isPalindrome(s3)) printf("The string is palindrome\n");
    else printf("The string is NOT palindrome\n");
    return 0;
}
