#include<bits/stdc++.h>
using namespace std;
bool isValidSudoku(char board[9][9]){
	map<int,map<int,int>>R;
    map<int,map<int,int>>B;
    map<int,map<int,int>>C;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int n=board[i][j]-'0';
                if(R[i][n]==1){
                    return false;
                }
                if(C[j][n]==1){
                    return false;
                }
                int num=(i/3)*3 + j/3;
                if(B[num][n]==1){
                    return false;
                } 
                R[i][n]=1;
                C[j][n]=1;
                B[num][n]=1;           
            }
        }
    }
    return true;
}
int main(){
	char matrix[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			char ch; cin>>ch;
			matrix[i][j]=ch;
		}
	}
	if(isValidSudoku(matrix)){
		cout<<"Valid Sudoku"<<endl;
	}else{
		cout<<"Not Valid Sudoku"<<endl;
	}

}
