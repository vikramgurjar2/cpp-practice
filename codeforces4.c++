#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(int x, char y, string  z){
        vector<char> arr;
        int c=0;
        int i=0;
      while(y<z[i] && i<x){
        c++;
        i++;

      }
      for(int i=0;i<=x;i++){
        if(i==c){
            arr.push_back(y);
            arr.push_back(z[i]);
        }
        else{
            arr.push_back(z[i]);
        }
        
      }
      for(int i=0 ;i<=x;i++){
        cout<<arr[i];
      }

}
int main(){

int n;
char a;
string b;
cin>>n;
cin>>a;
cin>>b;
solve(n,a,b);






return 0;
}