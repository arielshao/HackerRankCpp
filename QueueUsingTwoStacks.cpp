#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack <int> s1, s2;
    int q;
    cin >>q;
    while (q--){
        int type, x;
        cin>> type;
        if (type==1){
            cin>>x;
            s1.push(x);
        }
            
        else {
            if (s2.empty()){
                // move all the elements from s1 to s2
                while (!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if (!s2.empty()){
                if (type==2){
                    s2.pop();
                }
                else if (type==3){
                    cout<<s2.top()<<endl;
                }
            }
        }
       
    }
    
  
    return 0;
}
