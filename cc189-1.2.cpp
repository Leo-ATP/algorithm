#include "./common.h"

using namespace std;


bool permutation(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}


bool permutation2(string s1, string s2){
    if(s1.length()!=s2.length())
        return false;
    //vector<int> v(128,0);
    int v[256]={0};
    for(int i=0;i<s1.length();i++){
        v[s1[i]]++;
    }
    
    for(int i=0;i<s1.length();i++){
        v[s2[i]]--;
        if(v[s2[i]]<0)
            return false;
    }
    return true;
}

int main(){
		string a="abcde";
        string b="edcba";
        string c="decbb";
        sort(a.begin(),a.end());
        cout<<permutation(a,b)<<endl;
        cout<<permutation(b,c)<<endl;
        cout<<permutation2(a,b)<<endl;
        cout<<permutation2(b,c)<<endl;
		return 0;
}