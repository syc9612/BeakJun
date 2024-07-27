#include <cstdio>
#include <cstdlib>

#define MAX_QUEUE_SIZE 100

inline void error(char* str){}

class CircularQueue{
    protected:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];

    public:
    CircularQueue(){front = rear = 0;}
    bool isEmpty(){return front == rear;}
    bool isFull(){return (rear+1)%MAX_QUEUE_SIZE == front;}

    //큐에 삽입
    void enqueue(int val){
        if(isFull()){
            error("ERROR: que is full \n");
        }
        else{
            rear = (rear +1)% MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    int dequeue(){
        if(isEmpty()){
            error("ERROR: que is empty \n");
        }
        else{
            front = (front+1)%MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    int peek(){
                if(isEmpty()){
            error("ERROR: que is empty \n");
        }
        else{
            front = (front+1)%MAX_QUEUE_SIZE;
            return data[(front+1)%MAX_QUEUE_SIZE];
        }
    }

    int display(){
        printf("queue: ");
        int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;

        for(int i = front+1; i<=maxi;i++){
            printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
        }
        printf("\n");
    }
};