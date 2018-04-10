#include "common.h"

using namespace std;




int permutation(string str, string prefix,int &num) {
    cout<<++num<<"==="<<prefix<<endl;
    //} else {
        for (int i= 0; i < str.length(); i++) {
            cout<<" "<<num<<"="<<i<<endl;
            string rem = str.substr(0, i) + str.substr(i + 1);
            permutation(rem, prefix + str[i], num);
        }
    //}
    return num;
}

int permutation0(string str) {
    int num=0;
    return permutation(str, "", num);
}
int main(){
    string a="ab";
    cout<<permutation0(a)<<endl<<endl;
    a="abc";
    cout<<permutation0(a)<<endl<<endl;
    a="abcd";
    cout<<permutation0(a)<<endl<<endl;
    return 0;
}