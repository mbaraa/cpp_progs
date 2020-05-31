#include <stack>
#include <stdio.h>
#include <math.h>
#include <iostream>

void printStack(std::stack<double>);

int main(void){
	// declare a stack
	std::stack<double> stack;

	// print size of the stack
	printf("size of stack:%lu\n", stack.size());

	// checks if the stack is empty
	printf("stack empty state:%d\n", stack.empty());

	// appending elements to the stack
	for(int e = 1; e < 5; e++){
		// appends element to the top of the stack
		stack.push(pow(e, 2));
	}
	printStack(stack);

	// checks if the stack is empty
	printf("stack empty state:%d\n", stack.empty());

	// print size of the stack
	printf("size of stack:%lu\n", stack.size());

	// declare an another stack
	std::stack<double> stack2;
	// appending elements to the stack
	for(int e = 1; e < 5; e++){
		// appends element to the top of the stack
		stack2.push(pow(e, 3));
	}
	printStack(stack2);
	// interchange stacks elements with another stack
	stack2.swap(stack);
	printStack(stack2);

	return 0;
}

// prints stacks elements
void printStack(std::stack<double> stk){
	printf("Stack elements: ");
	while(!stk.empty()){
		// returns the  the top element of the stack
		std::cout << stk.top() << " ";
		// removes the top element of the stack so the next element is accessible
		stk.pop();
	}
	printf("\n");
}
