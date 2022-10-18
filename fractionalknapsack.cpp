#include <bits/stdc++.h>
using namespace std;

class item{
    public :
    double profit;
    double weight;
};

void merge(item *a, int low, int mid, int high){

    int p = mid - low + 1;
    int q = high - mid;

    item *first = new item [p];
    item *second = new item [q];

    for(int i=0; i<p;i++){
        first[i].profit=a[low+i].profit;
        first[i].weight=a[low+i].weight;
    }

    for(int i=0; i<q;i++){
        second[i].profit=a[mid+1+i].profit;
        second[i].weight=a[mid+1+i].weight;
    }

    int i=0,j=0,k=low;

    while(i<p && j<q){

        if((first[i].profit/first[i].weight)>(second[j].profit/second[j].weight)){
            a[k].profit = first[i].profit;
            a[k].weight = first[i].weight;
            i++;
            k++;
        }
        else{
            a[k].profit = second[j].profit;
            a[k].weight = second[j].weight;
            j++;
            k++;
        }
    }

    while(i<p){
        a[k].profit = first[i].profit;
        a[k].weight = first[i].weight;
        k++;
        i++;
    }

    while(j<q){
        a[k].profit = second[j].profit;
        a[k].weight = second[j].weight;
        j++;
        k++;
    }

    delete []first;
    delete []second;
}

void mergesort(item *a,int low,int high){
    if(low<high){
        int mid = (low + high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void knapsack(item *a, int capacity, int no){
        double flag[no];
        double totalprofit=0;
        int c = capacity;
        int i;

        for(int j=0 ; j<no; j++){
            flag[j]=0.0;
        }

        for( i=0;i<no;i++){
            if(c<a[i].weight){
                break;
            }
            else{
                flag[i]=1;
                c = c - a[i].weight;
                totalprofit += a[i].profit;
            }
        }

        if(i<no){
            flag[i] = c/a[i].weight;
            double pwratio = (a[i].profit/a[i].weight);
            totalprofit += (c)*pwratio;        
        }

        cout<<"FLAG ARRAY IS : ";
        for(int j=0;j<no;j++){
            cout<<flag[j]<<" ";
        }
        cout<<"\n";

        cout<<"TOTAL PROFIT IS : " << totalprofit;
}
int main(){
    int n,c;
    cout<<"ENTER NUMBER OF ITEMS : ";
    cin>>n;
    cout<<"ENTER CAPACITY OF SACK : ";
    cin>>c;
    cout<<"**************************************************************\n";
    item a[n];
    for(int i=0;i<n;i++){
        cout<<"ENTER WEIGHT AND PROFIT OF ITEM "<<(i+1)<<": ";
        cin>>a[i].weight>>a[i].profit;
    }
    cout<<"**************************************************************\n";
    cout<<"DETAILS OF THE ITEM ARE : "<<"\n";
    for(int i=0;i<n;i++){
        cout<< " ITEM NO. "<<(i+1)<<" : ";
        cout<< " WEIGHT: "<<a[i].weight;
        cout<< " PROFIT: "<<a[i].profit<<"\n";
    }

    mergesort(a,0,n-1);

    cout<<"**************************************************************\n";
    cout<<"DETAILS OF THE ITEM AFTER SORTING THEM BY P/W ARE : "<<"\n";
    for(int i=0;i<n;i++){
        cout<< " ITEM NO. "<<(i+1)<<" : ";
        cout<< " WEIGHT: "<<a[i].weight;
        cout<< " PROFIT: "<<a[i].profit<<"\n";
    }
    knapsack(a,c,n);

    return 0;
}
