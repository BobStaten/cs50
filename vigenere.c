// program to encode and decode text using vigenere cypher
include <stdio.h>
include <cs50.h>
include <stdlib.h>
include <string.h>
include <ctype.h>

// declares two functions to encipher upper and lower case lelments
int encrypt_upper(int x, int y);
int encrypt_upper(x, y)
{
    int result =(((x - 'A') + y) % 26 + 'A');
    return result;
}

int encrypt_lower(int x, int y);
int encrypt_lower(x, y)
{
    int result = (((x - 'a') + y) % 26 + 'a');
    return result;
}

int main(int argc, string argv[])
{
    // prompts for valid key
    if (argc == 2 && argv[1] != 0)
    {
        string key = argv[1];
        int i = atoi(key);
