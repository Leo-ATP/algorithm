#include "./common.h"
using namespace std;
string str_compression(string s){
    string o;
    int id =1;
    char pri=s[0];
    int count=1;
    while(id<s.length()){
        if(pri==s[id])
            count++;
        else{
            o.push_back(pri);
            o.append(to_string(count));
            pri=s[id];
            count =1;
        }

        id++;
    }
    o.push_back(pri);
    o.append(to_string(count));
    cout<<o<<endl;
    if(o.length()>=s.length())
        return s;
    else
        return o;
}

int main(){
cout<<str_compression("aabcccaaaaaa")<<endl;

}