#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int x);
int peek();
int is_empty();
int is_full();
void display();
int dequeue();
int main()
{
    int option, cont, x;

    do
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Display Queue\n");
        printf("7. Quit\n");

        printf("Enter your choice (1-7): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            x = dequeue();
            if (x != -1)
            {
                printf("Dequeued element: %d\n", x);
            }
            break;

        case 3:
            x = peek();
            if (x != -1)
            {
                printf("The element at the front is %d\n", x);
            }
            break;

        case 4:
            if (is_empty())
            {
                printf("The queue is empty\n");
            }
            else
            {
                printf("The queue is not empty\n");
            }
            break;

        case 5:
            if (is_full())
            {
                printf("The queue is full\n");
            }
            else
            {
                printf("The queue is not full\n");
            }
            break;

        case 6:
            display();
            break;

        case 7:
            cont = 0;
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (cont);

    return 0;
}

void enqueue(int x)
{
    if (is_full())
    {
        printf("The queue is full\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = x;
}

int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    int x = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }

    return x;
}

int peek()
{
    if (is_empty())
    {
        printf("The queue is empty\n");
        return -1;
    }

    return queue[front];
}

int is_empty()
{
    return front == -1;
}

int is_full()
{
    return (rear + 1) % MAX_SIZE == front;
}

void display()
{
    if (is_empty())
    {
        printf("The queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    int i = front;

    do
    {
        printf("%d\n", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
}
