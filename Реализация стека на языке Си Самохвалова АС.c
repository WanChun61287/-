/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int arr[MAX];
    int top;
} Stack;


Stack* createStack() {                                     
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1; 
    return stack;
}

int isEmpty(Stack* stack) {                            //1
    return stack->top == -1;
}

int isFull(Stack* stack) {                             //2                              
    return stack->top == MAX - 1;
}

void push(Stack* stack, int value) {                   //3
    if (isFull(stack)) {
        printf("Ошибка: стек переполнен!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack* stack) {                               //4
    if (isEmpty(stack)) {
        printf("Ошибка: стек пуст!\n");
        return -1; 
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {                             //5
    if (isEmpty(stack)) {
        printf("Ошибка: стек пуст!\n");
        return -1; 
    }
    return stack->arr[stack->top];
}


int size(Stack* stack) {                              //6
    return stack->top + 1;
}

void clear(Stack* stack) {                           //7
    stack->top = -1;
    
}


   Stack* copyStack(Stack* original) {               //8
       Stack* newStack = createStack();
       for (int i = 0; i <= original->top; i++) {
           push(newStack, original->arr[i]);
       }
       return newStack;
   }
   
   

   int search(Stack* stack, int value) {            //9
       for (int i = stack->top; i >= 0; i--) {
           if (stack->arr[i] == value) {
               return i; 
           }
       }
       return -1; 
   }
   

void printStack(Stack* stack) {                     //10
    if (isEmpty(stack)) {
        printf("Стек пуст!\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

   void swap(Stack* stack) {                      //11
       if (stack->top < 1) {
           printf("Недостаточно элементов для обмена!\n");
           return;
       }
       int temp = stack->arr[stack->top];
       stack->arr[stack->top] = stack->arr[stack->top - 1];
       stack->arr[stack->top - 1] = temp;
   }
   
int main() 


{
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("Элементы стека: ");
    printStack(stack);      

    printf("Верхний элемент: %d\n", peek(stack)); 

    printf("Удаляем элемент: %d\n", pop(stack)); 
    printf("Элементы стека после удаления: ");
    printStack(stack);

    printf("Размер стека: %d\n", size(stack)); 

    swap(stack);            
    printf("После обмена верхних элементов:\n");
    printStack(stack); 

    clear(stack);                             
    printf("После очистки:\n");
    printStack(stack); 

    printf("Стек пуст? %s\n", isEmpty(stack) ? "Да" : "Нет"); 
    
    printf("добавим элементы:");
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);
    printf("Стек пуст? %s\n", isEmpty(stack) ? "Да" : "Нет");
    printf("Стек полон? %s\n", isFull(stack) ? "Да" : "Нет"); 

    clear(stack);
    printf("Очистили стек.\n"); 
    printf("Стек пуст? %s\n", isEmpty(stack) ? "Да" : "Нет");

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    
    Stack* copiedStack = copyStack(stack);
    printf("Скопированный стек: ");
    printStack(copiedStack);

    int valueToSearch = 3;
    int index = search(stack, valueToSearch);
    if (index != -1) {
        printf("Элемент %d найден на позиции %d.\n", valueToSearch, index);
    } else {
        printf("Элемент %d не найден в стеке.\n", valueToSearch);
    }

    free(stack);
    free(copiedStack);
    return 0;
}

