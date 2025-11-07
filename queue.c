#include <stdio.h>
#define MAX_SIZE 5 

int q[MAX_SIZE]; 
int front = -1;
int rear = -1;

void enqueue(int item)
{
    // Check for Queue Full condition
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue %d.\n", item);
    }
    else
    {
        // If the queue was initially empty, set front to 0
        if (front == -1) 
        {
            front = 0;
        }
        
        // Increment rear and insert the item
        rear = rear + 1;
        q[rear] = item;
        printf("%d enqueued.\n", item);
    }
}

void dequeue()
{
    // Check for Queue Empty condition
    if (front == -1) // Simpler check for empty: only front == -1 is sufficient
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        int deleted_item = q[front]; 
        printf("Deleted item is %d\n", deleted_item);
        
        // If this was the last element, reset front and rear
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // Move front pointer forward
            front = front + 1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty. Nothing to display.\n");
    }
    else
    {
        printf("Queue elements: ");
        // Declare loop variable 'i' locally inside the function (best practice)
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    int item; 
    printf("Queue size is fixed to %d.\n", MAX_SIZE); 
    
    do
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        // Added error check for scanf, though often skipped in simple examples
        if (scanf("%d", &choice) != 1) { 
            // Handle non-integer input to prevent infinite loop
            while(getchar() != '\n'); 
            choice = 0; // Set to invalid choice
        }

        switch(choice)
        {
            case 1:
            {
                printf("Enter the item to be inserted: ");
                // Added error check for scanf
                if (scanf("%d", &item) != 1) {
                    printf("Invalid input for item.\n");
                    while(getchar() != '\n'); 
                    break;
                }
                enqueue(item);
                break;
            }
            case 2:
            {
                dequeue(); 
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting program.\n");
                break;
            }
            default:
                printf("Invalid choice.\n");
        }
    }
    while(choice != 4);

    return 0; 
}