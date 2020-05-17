//matrix class by Baraa Al-Masri
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
//this whole thing deals with square matrices so rows = columns
class Matrix{
public:
    // constructors
    Matrix(int order){
        setRows(order);
        setCols(order);
    }
    Matrix(){
        setRows(1);
        setCols(1);
    }
    // copy constructor
    Matrix(vector< vector< double > > sourceMatrix){
        Matrix::matrix = sourceMatrix;
    }
    // lame setters & getters
    void setRows(int rows){
        if(rows < 0)
            rows = 1;
        else
            this->rows = rows;
    }    
    int getRows(){
        return this->rows;
    }
    
    void setCols(int cols){
        if(cols < 0)
            cols = 1;
        else
            this->columns = cols;
    }    
    int getCols(){
        return this->columns;
    }
    //
    void setMatrix(vector< vector<double> > mtrx){
        Matrix::matrix = mtrx;
    }
    vector< vector<double> > getMatrix(){
        return matrix;
    }
    ////////

    // action functions :)
    // read values into the matrix
    void readMatrix(){
        printf("Enter matrix's elements:\n");

        int cols = Matrix::rows; // for readablity
        for(int row = 0 ; row < rows ; row++){
            // temporary vector to store columns
            vector<double> tempVector;
            for(int col = 0 ; col < cols ; col++){
                // temporary variable to store element
                double temp;
                printf("m%i%i = ", row+1,col+1);
                scanf("%lf", &temp);
                // add the temporary variable to the temporary vector
                tempVector.push_back(temp);

            }
            // new line for better formatting
            printf("\n");
            // add the temporary vector to the current row of the main 2D vector
            Matrix::matrix.push_back(tempVector);   
            // and roll over if condition is true :) 
        }
    }
    // well it's a printing function no comments needed :)
    void printMatrix(){
        printf("\nM = | ");
        int cols = Matrix::rows; // for readablity
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                std::cout << Matrix::matrix[row][col] << "";
                std::cout << (col == cols-1 ? " |" : " ");
            }
            printf("\n");
            std::cout << (row != rows - 1 ? "    | " : "");
            
        }
        printf("\n");
    }
    // add an another matrix to the current matrix
    void add(vector< vector<double> > anotherMatrix){
        int order = Matrix::matrix.size();
        int order2 = anotherMatrix.size();
        
        if(order != order2 ){
            printf("Hold up different orders no sum for you!\n");
            exit(0);
        }

        for(int row = 0; row < order; row++){
            for(int col = 0; col < order; col++){
                Matrix::matrix[row][col] += anotherMatrix[row][col];
            }
        }

    }
    // multiply an another matrix to the current matrix an returns the new matrix
    vector< vector<double> >  multiply(vector< vector<double> >  anotherMatrix){
        vector< vector<double> > newMatrix;
        int newRows, newCols;
        // reminder: when multiplying two matrices the answer is a matrix
        // with number of rows from the first and number of columns from the second
        newRows = Matrix::rows;
        newCols = anotherMatrix.front().size();
        initMatrix(newMatrix, newRows, newCols);
        
        for(int row = 0; row < newRows; row++)
            for(int col = 0; col < newCols; col++)
                for(int shared = 0; shared < Matrix::rows; shared++){
                    newMatrix[row][col] += Matrix::matrix[row][shared] * anotherMatrix[shared][col];
                }

        return newMatrix;

    }
    // matrix trace finder
    double findTrace(){
        int trace = 0;
        for(int diag = 0; diag < Matrix::rows; diag++){
            trace += matrix[diag][diag];
        }
        return trace;
    }
    
    // find determinant of a matrix
    double findDeterminant(){
        return det(rows, matrix);
    }
    // end of functions, well I lied :)    
    ////////////////

private:
    // da matrix blin
    std::vector< std::vector<double> > matrix;
    // rows & columns blyat
    int rows;
    int columns;

    // determinant finder, it's private so the object function call is not parameterized :)
    // otherwise it'll get messy like a bee hive
    double det(int rows, std::vector<std::vector<double>> mainMatrix){ //wondering why called mainMatrix
        int cols = rows; // for readablity                 //scroll down to see some messed up blin 
        double answer = 0;
        if(rows == 2){
            return ( mainMatrix[0][0] * mainMatrix[1][1] ) - ( mainMatrix[1][0] * mainMatrix[0][1] );
        }
            
        else if (rows > 2){

            int newRows, newCols;
            int cols = rows; // for readablity
            newRows = rows - 0; // those two where "rows - 1" then I realised that
            newCols = cols - 0; // this moo ain't working so....


            // first row, alternating columns
            for(int mainCol = 0; mainCol < cols; mainCol++){
                std::vector< std::vector<double> > newMatrix;
                // for future reads :)
                // I had to stop @ newRows - 1 so the index won't be out of range in the main matrix
                for(int newRow = 0; newRow < newRows - 1; newRow++){
                    // temporary vector to store columns
                    std::vector<double> tempVector;
                    
                    for(int newCol = 0; newCol < newCols; newCol++){
                        
                        if( newCol != mainCol ){
                            double temp;
                            temp = mainMatrix[newRow+1][newCol];
                            tempVector.push_back(temp);

                        }
                    }
                    // add the temporary vector to the current row of the main 2D vector
                    newMatrix.push_back(tempVector);

                }
                answer += pow(-1, mainCol) * mainMatrix[0][mainCol] * (det(newRows-1, newMatrix));
            }
            //printf("LOL Cyka\n");
        }
        // finally return the answer when the recieved matrix is 1*1
        return answer;
    
    }

    // initialize a matrix with zeros
    void initMatrix(vector< vector<double> > &mtrx, int rows, int cols){
        for(int row = 0; row < rows; row++){
            // temporary array to store columns
            std::vector<double> tempVector;
            for(int col = 0; col < cols; col++){
                // temporary variable to store element
                double temp;
                temp = 0;
                // add the temporary variable to the temporary array
                tempVector.push_back(temp);
            }
            // add the temporary array to the current row of the main 2D array
            mtrx.push_back(tempVector);   
            // and roll over if condition is true :) 
        }
    }
    // find sum of a row
    double rowSum(vector< vector<double> > mtrx, int desiredRow){
        double sum = 0;
        for(int col = 0; col < mtrx.front().size(); col++){
            sum += mtrx[desiredRow][col];
        }
        return sum;
    }
    // find sum of a column
    double columnSum(vector< vector<double> > mtrx, int desiredColumn){
        double sum = 0;
        for(int row = 0; row < mtrx.size(); row++){
            sum += mtrx[row][desiredColumn];
        }
        return sum;
    }

};

