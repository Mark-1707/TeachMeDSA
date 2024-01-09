// https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int i,j,k,l,xbox,ybox;
        char temp;

        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                if(board[i][j] != '.'){
                    
                    temp = board[i][j];

                    // Row Check
                    for(k=0; k<9; k++)  { if(k==j) continue; if(board[i][k] == temp)   return false; }

                    // Column Check
                    for(k=0; k<9; k++)  { if(k==i) continue; if(board[k][j] == temp)   return false; }

                    // Matrix Check
                    xbox = i - i%3;
                    ybox = j - j%3;
                    for(k=xbox; k<xbox+3; k++){
                        for(l=ybox; l<ybox+3; l++){
                            if(k == i && l == j)  continue;
                            if(board[k][l] == temp)   return false;
                        }
                    }

                }
            }
        }
        
        return true;
    }
};