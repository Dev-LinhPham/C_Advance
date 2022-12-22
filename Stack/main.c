#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef uint8_t bool;

typedef struct
{
    uint8_t index;
    uint8_t size;
    uint8_t *array;
}Stacks;


void createStacks(Stacks *stacks, int size)
{
    stacks->index = 0;
    stacks->size = size;
    stacks->array = (uint8_t *)malloc(size * sizeof(uint8_t));
}

bool isEmpty(Stacks stacks)
{
    if (stacks.index == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(Stacks stacks)
{
    if (stacks.size - stacks.index < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(Stacks *stacks, int value)
{
    if (isFull(*stacks))
    {
        printf("Stacks is Full\n");
    }
    else
    {
        stacks->array[stacks->index] = value;
        stacks->index++;
    }
}

void pop(Stacks *stacks)
{
    if (isEmpty(*stacks))
    {
        printf("Stacks is Empty\n");
    }
    else
    {
        stacks->index--;
        stacks->array[stacks->index] = '\0';
    }
}

uint8_t top(Stacks stacks)
{
    return stacks.array[(stacks.index) - 1];
}

uint8_t size(Stacks stacks)
{
    return stacks.index;
}

int main(int argc, char const *argv[])
{
   
    printf("---STACKS 1---\n");
    Stacks stacks1;
    createStacks(&stacks1,5);
    printf("---PUSH ST1---\n");

    push(&stacks1, 5);
    push(&stacks1, 4);
    push(&stacks1, 8);
    push(&stacks1, 2);

    printf("size: %d\n",size(stacks1));

    printf("---POP ST1---\n");
    pop(&stacks1);

    printf("size: %d\n",size(stacks1));

    printf("top: %d\n",top(stacks1));

    printf("---POP ST1---\n");
    pop(&stacks1);

    printf("size: %d\n",size(stacks1));

    printf("top: %d\n",top(stacks1));

    printf("---STACKS 2---\n");

    Stacks stacks2;
    createStacks(&stacks2,7);

    printf("---PUSH ST2---\n");
    push(&stacks2, 10);
    push(&stacks2, 21);
    push(&stacks2, 27);
    push(&stacks2, 29);
    push(&stacks2, 45);
    push(&stacks2, 67);

    printf("size: %d\n",size(stacks2));
    printf("top: %d\n",top(stacks2));
    
    printf("---MASTER---\n");

    Stacks *master;
    master = &stacks1;

    printf("stack1[2]: %d\n",master->array[master->index]);

    printf("size stack1: %d\n",master->index);

    return 0;
}
