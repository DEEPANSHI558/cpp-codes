#include<bits/stdc++.h>
using namespace std;
int getMax(int arr[], int n)
{
    stack<int> t;
    int m_area = 0; 
    int k;
    int area;
    int i = 0;
    while (i < n)
    {
        if (t.empty() || arr[t.top()] <= arr[i])
            t.push(i++);
        else
        {
            k = t.top();  
            t.pop();  
            area = arr[k] * (t.empty() ? i :
                                   i - t.top() - 1);
            if (m_area < area)
                m_area = area;
        }
    }
    while (t.empty() == false)
    {
        k = t.top();
        t.pop();
        area = arr[k] * (t.empty() ? i :
                                i - t.top() - 1);
        if (m_area < area)
            m_area = area;
    }
 
    return m_area;
}
 
int main(){
    int n,b,h;
    cin>>n;
    cin>>b;
    cin>>h;
    int *arr=new int[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];

    }
    int total=b*h*sum;
    int ans=getMax(arr,n);
    int a=ans*h;
    cout<<total-a;
    return 0;
    
}