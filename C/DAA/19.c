#include <stdio.h>
#include <string.h>

int i, j, m, n, LCS_table[20][20];
char S1[20], S2[20], b[20][20];

int max(int a, int b); 
int lcs( char *X, char *Y, int l1, int l2 ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
void lcsAlgo() 
{
  m = strlen(S1);
  n = strlen(S2);

  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      if (S1[i - 1] == S2[j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      } else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
      } else {
        LCS_table[i][j] = LCS_table[i][j - 1];
      }
    }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }

  printf("S1 : %s \nS2 : %s \n", S1, S2);
  printf("LCS: %s", lcsAlgo);
}

int main() {
  printf("Enter the first string : ");
  scanf("%s", S1);
  printf("Enter the second string: ");
  scanf("%s", S2);
  printf("First string  = %s\n", S1);
  printf("Second string = %s\n", S2);
  int l1 = strlen(S1); 
  int l2 = strlen(S2);
  
  lcsAlgo();
  printf("\n");
  printf("Length of LCS is %d", lcs(S1, S2, l1, l2 ) );
  return 0;
}