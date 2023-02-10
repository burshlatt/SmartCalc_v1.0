#include "s21_SmartCalc.h"

#include <stdio.h>
#include <stdlib.h>

// // Описываем структуру стека
// struct Stack {
//     int top; // Индекс верхнего элемента стека
//     int capacity; // Максимальная емкость стека
//     int *array; // Указатель на динамический массив, хранящий элементы стека
// };

// // Функция создает новый стек с заданной емкостью
// struct Stack *createStack(int capacity) {
//     struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack)); // Выделяем память под стек
//     stack->capacity = capacity; // Устанавливаем емкость стека
//     stack->top = -1; // Устанавливаем индекс верхнего элемента в -1, так как стек пока пустой
//     stack->array = (int*) malloc(stack->capacity * sizeof(int)); // Выделяем память под динамический массив
//     return stack; // Возвращаем указатель на созданный стек
// }

// // Функция проверяет, заполнен ли стек
// int isFull(struct Stack *stack) {
//     return stack->top == stack->capacity - 1; // Если индекс верхнего элемента равен максимальной емкости стека - 1, то стек заполнен
// }

// // Функция проверяет, пуст ли стек
// int isEmpty(struct Stack *stack) {
//     return stack->top == -1; // Если индекс верхнего элемента равен -1, то стек пуст
// }

// // Функция добавляет элемент в стек
// void push(struct Stack *stack, int item) {
//     if (isFull(stack)) {
//         printf("Error: Stack overflow\n");
//         return;
//     }
//     stack->array[++stack->top] = item; // Увеличиваем индекс верхнего элемента и добавляем элемент в массив
// }

// // Функция удаляет верхний элемент из стека
// int pop(struct Stack *stack) {
//     if (isEmpty(stack)) {
//         printf("Error: Stack is empty\n");
//         return -1;
//     }
//     return stack->array[stack->top--]; // Уменьшаем индекс верхнего элемента и возвращаем его значение
// }

// // Функция возвращает верхний элемент стека
// int peek(struct Stack *stack) {
//     if (isEmpty(stack)) {
//         printf("Error: Stack is empty\n");
//         return -1;
//     }
//     return stack->array[stack->top]; // Возвращаем значение верхнего элемента стека
// }

// // Функция удаляет стек
// void deleteStack(struct Stack *stack) {
//     if (stack) {
//         if (stack->array) {
//             free(stack->array);
//         }
//         free(stack);
//     }
// }

// int main() {
//     struct Stack *stack = createStack(100); // Создаем стек с емкостью 100
//     push(stack, 10); // Добавляем элемент 10 в стек
//     push(stack, 20); // Добавляем элемент 20 в стек
//     push(stack, 30); // Добавляем элемент 30 в стек
//     printf("Top element is %d\n", peek(stack)); // Выводим верхний элемент стека
//     printf("Popped element is %d\n", pop(stack)); // Удаляем верхний элемент стека и выводим его значение
//     deleteStack(stack); // Удаляем стек
//     return 0;
// }

// Структура для хранения стека
struct Stack {
    int top;
    int capacity;
    int *array;
};

// Функция создает стек с заданной емкостью
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Функция проверяет, пуст ли стек
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Функция вычисляет количество элементов в стеке
int size(struct Stack *stack) {
    return stack->top + 1;
}

// Функция удаляет стек
void deleteStack(struct Stack *stack) {
    if (stack) {
        if (stack->array) {
            free(stack->array);
        }
        free(stack);
    }
}

// Функция увеличивает емкость стека
void resizeStack(struct Stack *stack) {
    int newCapacity = stack->capacity * 2;
    int *newArray = (int *)realloc(stack->array, newCapacity * sizeof(int));
    if (newArray) {
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
}

// Функция добавляет элемент в стек
void push(struct Stack *stack, int item) {
    if (size(stack) == stack->capacity) {
        resizeStack(stack);
    }
    stack->array[++stack->top] = item;
}

// Функция возвращает верхний элемент стека
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top];
}

// Функция удаляет верхний элемент стека и возвращает его
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}

double polish_notation(char *string) {
    double result = 0.0;
    return result;
}

int main() {
    struct Stack *stack = createStack(2);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d popped from stack\n", pop(stack));

    printf("Top element is %d\n", peek(stack));

    deleteStack(stack);

    return 0;
}
