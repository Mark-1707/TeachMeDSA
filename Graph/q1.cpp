#include<bits/stdc++.h>
using namespace std;

// bool dfs(int b, int a, int rem){ 
    
//     if(rem <= 0 && b == 0) return true;
//     if(rem <= 0 && b != 0) return false;

//     rem = rem - b;

//     if(rem >= 1){
//         if(rem >= 2){
//             if(rem >= 5){
//                 a = 5;
//                 rem = rem - 5;
//             }else{
//                 a = 2;
//                 rem = rem - 2;
//             }
//         }else{
//             a = 1;
//             rem = rem - 1;
//         }
//     }

//     return dfs(b, a, rem) || dfs(b+1, a, rem);
// }

int main(){
    int n;
    cin>>n;


    // cout<<dfs(1, 0, n)<<endl;

}