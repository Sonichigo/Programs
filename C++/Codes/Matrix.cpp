#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class solution
{
public:
   void prinDiag(int mat[][3])
   {
      int i,j,p,q,bound=2;

      int i1=0,j1=0;
      int i2=2;
      int j2=2;

      /* Reversing principal diagonal */
      while(i1!=i2)
       {
         swap(mat[i1][j1],mat[i2][j2]);
         i1++;j1++;
         i2--;j2--;
       }
        i=0;j=1;
        p=i+1;q=j+1;
        swap(mat[i][j],mat[p][q]);

        i=1;j=0;
        p=i+1;q=j+1;
        swap(mat[i][j],mat[p][q]);
    }
    void print(int mat[][3])
    {
       for(int i=0;i<3;i++)
       {
          for(int j=0;j<3;j++)
          {
            cout<<mat[i][j]<<" ";
          }
         cout<<endl;
       }
    }
};
int main()
{
    int mat[3][3];
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cin>>mat[i][j];
      }
    }
    solution S;
    S.prinDiag(mat);
return 0;
}
