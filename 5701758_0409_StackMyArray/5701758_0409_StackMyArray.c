#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1; //스택에 현재 들어간 아이템의 수 최솟값은 -1

// create : 이미 만듬
// delete : 할 수 없음

// is_empty
int is_full() {
	/*if (top == MAX_STACK_SIZE - 1) return 1;
	else return 0;*/
	return (top == MAX_STACK_SIZE - 1);
}

int is_empty() {
	/*if (top == -1)return 1;
	else return 0;*/
	return(top == -1);
}

// push
void push(element item) {
	if (is_full()) { //stack 풀
		fprintf(stderr, "stack is FULL\n");
		return;
	}
	else {
		top = top + 1;
		stack[top] = item;
	}
}

element pop() {
	element r;
	if (is_empty()) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		/*r = stack[top];
		top = top - 1;
		return r;*/
		return (stack[top--]);
	}
}

element peek() {

	srand(time(NULL));
	element r;
	if (is_empty()) {
		fprintf(stderr, "stack is empty\n");
		exit(1);
	}
	else {
		/*r = stack[top];
		top = top - 1;
		return r;*/
		return (stack[top]);
	}
}
int main() {
	//element e;
	srand(time(NULL));
	int data;
	
	for (int i = 0; i < 30; i++) {
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0) {
			printf("current rand_num : %d | Even\n", rand_num);
			push(rand_num);
			printf("Push : %d\n", rand_num);
			printf("Stack elemnets: ");
			for (int i = 0; i < top+1; i++) {
					printf(" %d ", stack[i]);
				}
			printf("\n");
		}
		else {
			printf("current rand_num : %d | Odd\n", rand_num);
			data = pop();
			printf("Pop : %d\n", data);
			printf("Stack elemnets: ");
			for (int i = 0; i < top+1; i++) {
				printf(" %d ", stack[i]);
			}
			printf("\n");
		}

		if (is_full == 1) {
			printf("Stack Overflow\n");
		}
		else if (is_empty == 1) {
			printf("Stack Underflow\n");
			printf("Stack is empty\n");
			printf("\n");
		}
	}
	/*e = rand() % 100 + 1;
	for (int i = 0; i < 5; i++) {
		if (e % 2 == 0) {
			push(e);
			printf("Push %d\n", e);
		}
		else {
			e = pop();
			printf("Pop %d\n", e);
		}
	}*/
	return 0;
}