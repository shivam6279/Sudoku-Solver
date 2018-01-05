#include <iostream>

using namespace std;

int grid_fixed[9][9], grid[9][9];

bool check_box(int n, int p){
    int i, j;
    int x = p % 9;
    int y = p / 9;
    //Check collumns and rows
    for(i = 0; i < 9; i++){
        if(x != i && grid[y][i] == n){
            return 0;
        }
        if(y != i && grid[i][x] == n){
            return 0;
        }
    }
    //Check 3x3 box
    for(i = 3 * (y / 3); i < 3 * (y / 3) + 3; i++){
        for(j = 3 * (x / 3); j < 3 * (x / 3) + 3; j++){
            if(j != x && i != y && grid[i][j] == n){
               return 0;
            }
        }
    }
    return 1;
}

bool solver(int p){
    int n;
    while(grid_fixed[p/9][p%9] != 0){
        p++;
        if(p == 81){
        	return 1;
		}
    }
    for(n = 1; n < 10; n++){
        if(check_box(n, p)){
        	grid[p/9][p%9] = n;        	
            if(p == 80){
                return 1;
            }
            if(solver(p+1)){
            	return 1;
			}
			else{
				grid[p/9][p%9] = 0;
			}
        }
    }
    return 0;
}

int main(){
    int i, j;
    char input[9][11];
    cout<<"Enter Sudoku row by row. Enter 9 digits at a time and enter 0 for blanks\n";
    for(i = 0; i < 9; i++){
        gets(input[i]);
    }
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            grid_fixed[i][j] = input[i][j] - 48;
            grid[i][j] = grid_fixed[i][j];
        }
    }
    
    cout<<"\nEntered Sudoku:\n";
    for(i = 0; i < 9; i++){
    	if(i % 3 == 0){
    		cout<<"-------------------\n";
		}
    	cout<<'|';
        for(j = 0; j < 9; j++){
        	if(grid[i][j] == 0){
        		cout<<' ';
			}
			else{
				cout<<grid[i][j];
			}
            if(j % 3 == 2){
            	cout<<'|';
			}
			else{
				cout<<' ';
			}
        }
        cout<<'\n';
    }
    cout<<"-------------------\n";
    
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(grid[i][j] != 0 && check_box(grid[i][j], i*9 + j) == 0){
            	cout<<"Entered sudoku is incorrect.";
            	return 0;
			}
        }
    }
    
    
    if(solver(0)){
    	cout<<"Solved:\n";
	    for(i = 0; i < 9; i++){
	    	if(i % 3 == 0){
	    		cout<<"-------------------\n";
			}
	    	cout<<'|';
	        for(j = 0; j < 9; j++){
	            cout<<grid[i][j];
	            if(j % 3 == 2){
	            	cout<<'|';
				}
				else{
					cout<<' ';
				}
	        }
	        cout<<'\n';
	    }
	    cout<<"-------------------\n";
	}
	else{
		cout<<"Sudoku has no solution.\n";
	}
    return 0;
}



