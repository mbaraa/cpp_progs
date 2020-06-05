#include<iostream>
int freq[10]={};
void read2D(int matrix[9][9]){
    for ( int lol = 0 ; lol < 9 ; lol++ ){
        if ( lol == 8 ) std::cout << "OK One Last Row to fill !!\n";
        for ( int lol2 = 0 ;lol2 < 9 ; lol2++){
		std::cin >> matrix[lol][lol2];
        }
    }
}
void print2D(int matrix[9][9]){
    for ( int lol = 0 ; lol < 9 ; lol++ ){
        for ( int lol2 = 0 ;lol2 < 9 ; lol2++){
		std::cout << matrix[lol][lol2] <<  (lol2 == 8 ? "" : " | ");
        }
	std::cout << "\n----------------------------------\n";
    }
}
bool resultRows( int sudoku[9][9] ){
    for ( int lol = 0 ; lol < 9 ; lol++ ){
        for ( int lol2 = 0 ;lol2 < 9 ; lol2++){
            freq[ sudoku[lol][lol2] ]++;

            if ( freq[ sudoku[lol][lol2] ] > 1 ){
                return 0;
            }
        }
	//this resets the frequency array
	for ( int k = 0 ; k < 10 ; k++ ){	
            freq[k] = 0;
	}
    }
    return 1;
}

bool resultCols( int sudoku[9][9] ){
    for ( int lol = 0 ; lol < 9 ; lol++ ){
        for ( int lol2 = 0 ;lol2 < 9 ; lol2++){
            freq[ sudoku[lol2][lol] ]++;

            if ( freq[ sudoku[lol2][lol] ] > 1 ){
                return 0;
            }
        }
	//this resets the frequency array
	for ( int k = 0 ; k < 10 ; k++ ){	
            freq[k] = 0;
	}
    }
    return 1;
}
// I wanted to leave a comment but I don't want to....
bool resultSquares( int sudoku[9][9] ){
    for ( int rows = 0 ; rows < 9 ; rows+=3 ){
        for ( int cols = 0 ;cols < 9 ; cols+=3){
	    for ( int lol = 0 ; lol < 3 ; lol++ ){
		for ( int lol2 = 0 ; lol2 < 3 ; lol2++ ){
		
		    	freq[ sudoku[lol+rows][lol2+cols] ]++;
	
	        	if ( freq[ sudoku[lol+rows][lol2+cols] ] > 1 ){
        	       	    return 0;
        		}
		}	
	    
	    		//this resets the frequency array
			for ( int k = 0 ; k < 10 ; k++ ){	
	            		freq[k] = 0;
			}
	    } 
        }
    }
    return 1;
}
