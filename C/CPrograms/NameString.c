#include <stdio.h>

//ni=first two letter of name.
int main()
{
    char ni_name[100], ni_copied[1000];
    printf("Enter ni_name : ");
    scanf("%[^\n]", ni_name);
    int ni_k = 5, ni_counter = 0, ni_letter = 0;
    char ni_ch = ni_name[ni_counter];
    for (int ni_i = 0; ni_name[ni_i] != '\0'; ni_i++)
    {
        if (ni_name[ni_i] == ' ')
        {
            ni_name[ni_i] = ni_name[0];
        }
    }
    printf("Modified ni_name : %s", ni_name);
    while (ni_ch != '\0')
    {
        ni_copied[ni_letter++] = ni_ch;
        for (int ni_i = 0; ni_i < ni_k; ni_i++)
        {
            ni_copied[ni_letter++] = ' ';
        }
        ni_counter++;
        ni_ch = ni_name[ni_counter];
    }
    ni_copied[ni_letter] = '\0';
    printf("\n%s", ni_copied);
    return 0;
}
