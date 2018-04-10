#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*wrong "aaab","aab" xxxxx
bool one_way(string s1, string s2){
    int l1=s1.length();
    int l2=s2.length();
    if(abs(l1-l2)>1) return 0;
    bool FofE = (l1==l2)?true:false;
    cout<<FofE<<"==";
    int diff=0;
    for(int i=0;i<min(l1,l2);i++){
        if(s1[i]!=s2[i])
            diff++;
    }
    
    if(!FofE)
        if(diff>0) return 0;
    return 1;
}*/

/*
bool one_way(string s1, string s2){
    int l1=s1.length();//longer
    int l2=s2.length();
    if(abs(l1-l2)>1) return 0;
    unordered_map<char,int> mp; 
    bool FofE = true;
    if(l1!=l2){
        FofE =0;
        if(l2>l1){
            string t=s1;
            s1=s2;
            s2=t;
            l1=s1.length();
            l2=s2.length();
        }
    }
    cout<<FofE<<"==";
    int diff=0;
    for(int i=0;i<l1;i++){
        mp[s1[i]]++;
    }
    int miss=0;
    for(int i=0;i<l2;i++){
        mp[s2[i]]--;
        if(mp[s2[i]]<0) miss++;
    }
    if(miss>1) return 0;
    if(!FofE && miss>0) return 0;
    return 1;
}
*/

//answer
bool replacef(string s1, string s2){
    bool diff1st=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            if(diff1st) return 0;
            diff1st=1;
        }
    }
    return 1;
}


bool insertf(string s1,string s2){
    int id1=0;
    int id2=0;
    bool diff1st=0;
    while(id1<s1.length() && id2<s2.length()){
        if(s1[id1]!=s2[id2]){
            if(diff1st) return 0;
            diff1st=1;
        }
        else
            id1++;
        id2++;
    }
    return 1;

}

bool one_way(string s1, string s2){
    //if(abs(s1.length()-s2.length())>1) return 0;
    ///xxxx
    
    if(s1.length()==s2.length())
        return replacef(s1,s2);
    if(s1.length()<s2.length())
        return insertf(s1,s2);
    else
        return insertf(s2,s1);
}


int main(){
    cout<<one_way("aaa","aaab")<<endl;
    cout<<one_way("aaa","aab")<<endl;
    cout<<one_way("aaab","aab")<<endl;
    cout<<one_way("","b")<<endl;
    cout<<one_way("aaa","aaabb")<<endl;
    cout<<one_way("aaa","abb")<<endl;
}