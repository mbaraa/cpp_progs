#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
// prototypes
int execOperator(int,int,char);
bool isOperator(char);
int solvePostfix(std::string);

// main function
int main(void){
    printf("program terminated manually i.e. ^C !!\n");
    while(1){
        printf("enter an equation in postfix notation:  ");
        std::string postfix;
        std::cin >> postfix;
        int result = solvePostfix(postfix);
        printf("result = %d\n", result);
    }
    
    return 0;
}

// execute a binary operator using a character variable
int execOperator(int rightOperand, int leftOperand, char operation){
    switch(operation){
        case '+':
            return rightOperand + leftOperand;
        case '-':
            return rightOperand - leftOperand;
        case '*':
            return rightOperand * leftOperand;
        case '/':
            return rightOperand / leftOperand;
        case '^':
            return pow(rightOperand,  leftOperand);
        default: 
            printf("Wrong operation!!\n");
    }
}
// check for operator
bool isOperator(char character){
    char c = character;
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? 1 : 0;
}
//
int solvePostfix(std::string postfix){
    for(int lol = 0; lol < postfix.length(); lol++){
        // temporary string to store the original string after evaluating two numbers with thier operator
        std::string temp = "";
        if( isOperator(postfix.at(lol)) ){
            // step one: append elements before the operands & operator to the temporary string

            // i starts @ 0 because the main string will have final results of operands & operators
            // & ends @ main index - 2 because the index has the operator & the two indexes before it has the operands
            for(int i = 0; i < lol - 2; i++){
                if(i >= 0)
                    temp.push_back(postfix.at(i));
            }
            // step two: append the evaluated number to the temporary string

            int rightOperand = (int)(postfix.at(lol-2) - 48);
            int leftOperand = (int)(postfix.at(lol-1) - 48);

            int result = execOperator( rightOperand, leftOperand, postfix.at(lol) );
            
            temp.push_back( (char)(result + 48) );

            // step three: 
            // append the rest of the postfix into the temp string

            for(int i = lol + 1; i < postfix.length(); i++){
                temp.push_back(postfix.at(i));
            }

            // step four
            // update the postfix string with the evaluated answers

            postfix = temp;

            // step five
            // reset the counter to match with the new postfix string

            lol = 0;

            // step six if there's no more operators return the final number
            
            if(postfix.length() == 1){
                return std::stoi(postfix);
            }

        }
        // debugging issues
        //std::cout << "result : " << postfix << "\n";
    }
}
