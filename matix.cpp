#include <iostream>
using namespace std;
int main()
{
    int a[20][20],b[20][20],c[20][20],i,j,k;
    int r1,c1,r2,c2;
    cout<<"enter the size of matrix 1"<<endl;
    cout<<"r1 :";
    cin>>r1;
    cout<<"c1 :";
    cin>>c1;
    cout<<"enter the size of matrix 2"<<endl;
    cout<<"r2 :";
    cin>>r2;
    cout<<"c2 :";
    cin>>c2;
    if(c1==r2)
    {
        cout<<"enter the elements of the matrix 1"<<endl;
        for( i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                cout<<"enter the element a["<<i+1<<"]["<<j+1<<"]:";
                cin>>a[i][j];
            }
         }
        cout<<"enter the elements of the matrix 2"<<endl;
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++){
                cout<<"enter the element b["<<i+1<<"]["<<j+1<<"]:";
                cin>>b[i][j];
            }
        }
        for(i = 0; i < r1; ++i) {
            for(j = 0; j < c2; ++j){
                c[i][j]=0;
            }
        }
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++){
                for(k = 0; k < c1; k++){
                        c[i][j] += a[i][k] * b[k][j];
                }
            }
        } 
        cout << endl << "Multiplication matrix" << endl;
         for(int i = 0; i < r1; i++) {
              for( int j = 0; j < c2;j++)  {
                      cout<<c[i][j]<<" ";
                 }
             cout<<endl;
          }

    }
 else{  
        cout<<"matrix multipliaction not possible";
       
    }
    return 0;
   
}