
#include<iostream>
using namespace std;
int main()
{
    int m,n,x,y;
    cout << "Enter the number of rows in array A: "<<endl;
    cin >> m;
    cout << "Enter the number of columns in array A: \n";
    cin >> n;
    cout << "Enter the number of rows in array B: \n";
    cin >> x;
    cout << "Enter the number of columns in array B: \n";
    cin >> y;
    if(n==x)
    {
        int A[m][n],B[x][y];
        cout << "Enter the elements of array A: \n";
         for(int i=0;i<m;i++) 
          {
            for(int j=0;j<n;j++)
            {
               cin >> A[i][j];
            }
        }
        cout << "The array A is: \n"<<endl;
        for (int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++)
            {
               cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }



        cout << "Enter the elements of array B: \n";
        for(int i=0;i<x;i++) 
        {
            for(int j=0;j<y;j++)
            {
               cin >> B[i][j];
            }
        }
        cout << "The array B is: \n"<<endl;
        for (int i=0;i<x;i++) 
        {
            for(int j=0;j<y;j++)
            {
               cout<<B[i][j]<<" ";
            }
            cout<<endl;
        }



        int C[m][y],sum;
        for (int i =0;i<m;i++) 
        {
            for(int j=0;j<y;j++)
            {
                sum=0;
                for(int k=0;k<n;k++)
                {
                    sum=sum+A[i][k]*B[k][j];
                }
                 C[i][j]=sum;
            }
        }
        cout << "The array C=A*B is: \n"<<endl;
        for (int i =0;i<m;i++) 
        {
            for(int j=0;j<y;j++)
            {
                cout<<C[i][j]<<" ";
            }
        cout<<endl;
        }
    }
    else
    {
        cout<<"Invalid"<<endl;
    }
}
