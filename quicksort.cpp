
#include "./quicksort.h"
using namespace std;




int main(){

    int itt[]= {6,3,4,1};
    vector<int> v(itt, itt+sizeof(itt)/sizeof(int));
    cout<<v.size()<<endl;
    quicksort(v,0,v.size()-1);

    for(auto i : v)
        cout<<i<<endl;

}


void quicksort(vector<int> &v, int st,int ed){
    if(st<ed){
        int n = partition(v,st,ed);
        quicksort(v,st,n-1);
        quicksort(v,n+1,ed);
    }
}

int partition(vector<int> &v, int st, int ed){
    int i= st-1;
    int p=v[ed];
    for(int j=st;j<ed;j++){
        if(v[j]<p){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[ed]);
    return i+1;
}