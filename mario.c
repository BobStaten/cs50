/* This program displays a half-pyramid
or staircase of #s. */

int height=0;

do
{
    printf("Height? ");
    height = get_int();
}

while (height < 0 || height > 23);
// Controls number of rows printed
for( int i = 0; i < height; i++)
{
// Prints spaces

    for( int j = 0; j < height - i - 1; j++)
// As row number (i) increases, spaces decrease
    {
        printf(" ");
    }

// Prints #s
    for(int k = 0; k < i + 2; k++)
// As row number (i) increases; #s increase.
    {
        printf("#");
    }
