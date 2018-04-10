#include "./common.h"
using namespace std;

    bool canPermutePalindrome(string s) {
        
        int n=s.size(); if(n<=1) return 1;
        
        unordered_map<char,int> hash;
        for(auto ch:s) hash[ch]++;
        
        int odd=0;
        
        for(auto val:hash)
        {
            if(val.second%2==1) odd++;
            if(odd>1) return 0;
        }
        
        return 1;
    }

    bool canPermutePalindrome2(string s) {
        
        int n=s.size(); if(n<=1) return 1;
        
        unordered_map<char,int> hash;
        int odd=0;

        for(auto ch:s) 
        {   hash[ch]++;
            if(hash[ch]%2==1) odd++;
            else odd--;
        }
        
        return odd<=1;
    }

    bool canPermutePalindrome3(string s) {
        
        int n=s.size(); if(n<=1) return 1;
        
        int v_bit=0;
        for(auto ch:s){
            int id= ch-'a';
            int mask=1<<id;
            if((v_bit & mask)==0)
                v_bit |=mask;
            else 
                v_bit &= ~mask;
        }
        return v_bit==0 || ((v_bit-1 & v_bit)==0);
    }
    int main(){

        string s="aaaaabbcc";
        string s2="aaaaabbccd";
        cout<<canPermutePalindrome(s)<<endl;
        cout<<canPermutePalindrome2(s)<<endl;
        cout<<canPermutePalindrome3(s)<<endl;
        cout<<canPermutePalindrome(s2)<<endl;
        cout<<canPermutePalindrome2(s2)<<endl;
        cout<<canPermutePalindrome3(s2)<<endl;
        return 0;
    }
