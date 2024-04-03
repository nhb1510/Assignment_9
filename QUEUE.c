#include <stdio.h>
#include <stdlib.h>


struct Queue {
    // Định nghĩa cấu trúc dữ liệu Queue
    // Bao gồm các thành phần như front, rear, size, capacity, và array.
    int front;
    int rear ;
    int size ;
    int capacity;
    int array[];
};

struct Queue *createQueue (unsigned int capacity) {
    // Triển khai hàm tạo Queue mới
    struct Queue *createQueue = malloc(sizeof (struct Queue));
    createQueue->front = -1;
    createQueue->rear = -1;
    createQueue->size = 0;
    createQueue->capacity = capacity;
    createQueue->array[capacity];
    return createQueue;
}

int isFull (struct Queue *queue) {
    // Triển khai hàm kiểm tra Queue có đầy không
    if ( queue->size == queue->capacity)
    {
        printf ("Queue is FULL\n");
        return (queue->rear == (queue->capacity - 1));
    }
    return 0;
}

int isEmpty (struct Queue *queue) {
    if ( queue->front == -1 ){
        return 1;
    }
    return 0;
}
void enqueue (struct Queue *queue, int item) {
    // Triển khai hàm thêm phần tử vào Queue
    if (isEmpty(queue) != 0){
        queue->front = 0;
    }
    if ( isFull(queue)){
        printf ("Queue is FULL! Can not add more.\n");
        return;
    }
    printf ("=> %d added to queue.\n",item);

    //rear khai báo là -1, 
    queue->rear ++; // ở lần gọi đầu tiền queue->rear = 0;
    queue->array[queue->rear] = item;
    //tăng size queue sau khi gán
    queue ->size ++;

    return ;
}

int dequeue (struct Queue* queue) {
    // Triển khai hàm lấy phần tử từ Queue
    if (isEmpty (queue)){
        printf ("Queue is EMPTY\n");
        return 1;
    }

    else
    {   //Nhập vị trí phần tử chứa item để lấy ra khỏi Queue
        printf("\nEnter the position of the item you want to dequeue from the Queue: %d to %d\n", queue->front , queue->rear );
        int n;
        scanf ("%d",&n);
        int buffer = queue->array[n];
        //gán lại giá trị Queue sau khi lấy phần tử ra khỏi Queue
        for (n ; n < queue->size ; n++){
            queue->array [n] = queue->array[n + 1];
        }
        // giảm size , raear . rear -1 sau khi lấy phần tử là vị trí cuối của hàng đợi
        queue->rear --; 
        queue->size --;
        return buffer;
    }
}
//in hàng đợi và thông tin Queue hiện tại
void showqueue (struct Queue* queue)
{
    printf ("\n######## QUEUE INFO ######## \n");
    for (int i = 0; i < queue->size ; i++)
    {
        printf ("%d\t", queue->array[i]);
    }
    printf("\nfront: %d\nrear: %d\nsize: %d\ncapacity: %d",queue->front, queue->rear,queue->size, queue->capacity);
    printf ("\n############################ \n");
}

int main() {
    struct Queue *queue = createQueue(5);

    // Thêm phần tử vào Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("=> %d dequeued from queue\n", dequeue(queue));
    printf("=> %d dequeued from queue\n", dequeue(queue));
    showqueue (queue);

    // Thêm phần tử mới vào Queue
    printf ("\n");
    enqueue(queue, 50);
    showqueue (queue);

    // In ra phần tử ở đầu và cuối Queue
    printf("\nFront item is Queue[%d] %d\n",queue->front , queue->array[queue->front]);
    printf("Rear item is Queue[%d] %d\n",queue->rear, queue->array[queue->rear]);

    free (queue);

    return 0;
}
