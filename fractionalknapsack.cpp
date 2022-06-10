#include<bits/stdc++.h>
using namespace std;
// Fractional knapsack
struct Item{
    int weight;
    int value;
    // constructor
    Item(int value,int weight){
         this->value=value;
         this->weight=weight;
    }
};
bool cmp(Item &a ,Item &b){
    double a1=(double)a.value/(double)a.weight;
    double a2=(double)b.value/(double)b.weight;
    return a1>a2;//descending order;
}
double fractionalknapsack(vector<Item> items,int W){
    // now we sort on the basis of its fraction of value/weight
    sort(items.begin(),items.end(),cmp);
    // after sorting we have to put it in the knapsack
    int i=1;
    double ans=items[0].value;
    int currentweight=items[0].weight;
    while(currentweight+items[i].weight<=W &&i<items.size()){
        ans+=items[i].value;
        currentweight+=items[i].weight;
        i++;
    }
    int remain=W-currentweight;
    ans+=items[i].value*((double)remain/(double)items[i].weight);
    return ans;
}
int main(){
    vector<Item> items={
        { 60, 10 }, { 100, 20 }, { 120, 30 } 
    };
    int W=50;
    cout<<"the maximum profit "<<fractionalknapsack(items,W);
    return 0;
       
}