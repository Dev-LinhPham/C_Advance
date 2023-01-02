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
} Queue;

void createQueue(Queue *element, int size)
{
    element->index = 0;
    element->size = size;
    element->array = (uint8_t *)malloc(size * sizeof(uint8_t));
}

// This operation indicates whether the queue is empty or not.
bool isEmpty(Queue element)
{
    if (element.index == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// This operation indicates whether the queue is full or not.
bool isFull(Queue element)
{
    if (element.index - element.size >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Inserts an element at the end of the queue i.e. at the rear end.
void enqueue(Queue *element, int value)
{
    if (isFull(*element))
    {
        printf("Queue is full\n");
    }
    else
    {
        element->array[element->index] = value;
        element->index++;
    }
}
// This operation removes and returns an element that is at the front end of the queue.
void dequeue(Queue *element)
{
    if (isEmpty(*element))
    {
        printf("Queue is empty !\n");
    }
    else
    {
        for (int i = 0; i < element->index; i++)
        {
            element->array[i] = element->array[i + 1];
        }
        element->index--;
    }
}
// This operation returns the element at the front end without removing it.
uint8_t front(Queue element)
{
    if (isEmpty(element))
    {
    }
    else
    {
        return element.array[0];
    }
}
// This operation returns the element at the rear end without removing it.
uint8_t rear(Queue element)
{
    if (isEmpty(element))
    {
    }
    else
    {
        return element.array[element.index - 1];
    }
}
// This operation returns the size of the queue i.e. the total number of elements it contains.
uint8_t size(Queue element)
{
    return element.index;
}

int main(int argc, char const *argv[])
{
    printf("---QUEUE 1---\n");
    Queue queue1;
    createQueue(&queue1, 7);

    printf("---ENQUEUE 1---\n");

    enqueue(&queue1, 4);
    enqueue(&queue1, 1);
    enqueue(&queue1, 7);

    printf("size: %d\n", size(queue1));
    printf("front: %d\n", front(queue1));
    printf("rear: %d\n", rear(queue1));

    printf("---ENQUEUE 1---\n");

    enqueue(&queue1, 5);
    enqueue(&queue1, 2);

    printf("size: %d\n", size(queue1));
    printf("front: %d\n", front(queue1));
    printf("rear: %d\n", rear(queue1));

    printf("---DEQUEUE 1---\n");

    dequeue(&queue1);
    dequeue(&queue1);

    printf("size: %d\n", size(queue1));
    printf("front: %d\n", front(queue1));
    printf("rear: %d\n", rear(queue1));

    return 0;
}
