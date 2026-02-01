#include <bits/stdc++.h>
using namespace std;


void subset(string ans,string &s,int size,int idx){
    
    char currChar = s[idx];
    
    if(idx == size){
        cout<<ans<< " ";
        return;
    }
    
    subset(ans,s,size,idx+1); // don't pick
    subset(ans + currChar,s,size,idx+1); // pick
}

int main() {
    string s = "abc";
    string ans = "";
    subset(ans,s,s.size(),0);
   

}
