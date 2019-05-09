#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{

    string s = get_string();

    // Prints 1st letter of first name

        printf("%c", toupper(s[0]));

    // prints first letter after a space

        int i;
        int j;
        int n;

        for( i = 0, j = strlen(s); i < j; i++)

            // identifies spaces

            if (s[i] == ' ')
                {
                    n=i;
                    printf("%c", toupper(s[n+1]));
                }
                printf("\n");

}
