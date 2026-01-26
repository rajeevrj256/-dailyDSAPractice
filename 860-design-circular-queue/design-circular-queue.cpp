class MyCircularQueue {
public:
    int rear;
    int front;
    vector<int>queue;
    int cap;
    MyCircularQueue(int k) {
        cap=k;
        queue.resize(k);
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
           return false; 
        }

        if(front==-1){
            front=rear=0;
        }else{
            rear=(rear+1)%cap;
        }

        queue[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==rear){
            front=rear=-1;
        }else{
        front=(front+1)%cap;
        }

        return true;
        
    }
    
    int Front() {
        
        return !isEmpty()?queue[front]:-1;
    }
    
    int Rear() {
        return !isEmpty()? queue[rear]:-1;
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return front==(rear+1)%cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */