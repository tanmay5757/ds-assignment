//program to find sum of every row and every column in a two-dimensional array. 
#include<iostream>
using namespace std;
int main()
{
    int m,n,rowsum=0,colsum=0;
    cout<<"Enter array dimensions"<<endl;
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Given array is :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Sum of rows :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            rowsum=rowsum+a[i][j];
            
        }
        cout<<"Sum of "<<i+1<<" row "<<rowsum<<endl;
        rowsum=0;
    }
    cout<<"Sum of column :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            colsum=colsum+a[j][i];
            
        }
        cout<<"Sum of "<<i+1<<" col "<<colsum<<endl;
        colsum=0;
    }
}