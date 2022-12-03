#include "abstractqueue.h"

template<typename T>
class Node {
  public:
    T data;
    Node<T>* next;

    //Constructor:
    Node(): next(NULL) {}
};

template<typename T>
class LinkedQueue: public AbstractQueue<T> 
{
  Node<T>* head; //Pointer to front element
  Node<T>* tail; //Pointer to back element
  
  public:
    // PURPOSE: Checks if a queue is empty
    // RETURNS: 'true' if the queue is empty
    //   'false' otherwise
    LinkedQueue(T& x) {
      head = new Node<T>;
      head->data = x; 
      tail = head;
    }

    bool isEmpty() const {
      return head == NULL;
    }

    // PURPOSE: looks at the front of the queue
    // RETURNS: a reference to the element currently in front of the queue
    // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
    //   message!!!
    const T& front() const throw (Oops) {
      if (isEmpty()) throw (Oops("Error: Queue is Empty"));
      else return head->data;
    }

    // PURPOSE: looks at the back of the queue
    // RETURNS: a reference to the element currently in the back of the queue
    // EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
    //   message!!!
    const T& back() const throw (Oops) {
      if (isEmpty()) throw (Oops("Error: Queue is Empty"));
      return tail->data;
    }

    // PURPOSE: enqueue an element into the queue
    // PARAMETERS: x is the item to add to the queue
    // POSTCONDITIONS: x is now the element at the end of the queue,
    void enqueue(const T& x) {
      if (isEmpty()) {
        head = new Node<T>;
        tail = head;
        head->data = x;
      }
      else {
        tail->next = new Node<T>;
        tail = tail->next;
        tail->data = x;
      }
    }
    // PURPOSE: dequeues an elemet from the queue
    // POSTCONDITIONS: the element formerly at the front of the queue has
    //     been removed.
    // NOTE: Dequeueing an empty queue results in an empty queue.
    void dequeue() {
      if(isEmpty()) throw Oops("Error: Queue is Empty");
      Node<T>* tmp;
      tmp = head;
      head = head->next;
      delete tmp;
      if(isEmpty()) tail = NULL;
    }

    // PURPOSE: clears the queue
    // POSTCONDITIONS: the queue is now empty
    void clear() {
      while(head!=NULL){
        this->dequeue();
      }
      head = NULL;
      tail = NULL;
    }

    //Derived Destructor
    ~LinkedQueue() {
      Node<T>* tmp;
      while (head != tail) {
        tmp = head;
        head = head->next;
        delete tmp;
      }
      head = NULL;
      tail = NULL;
    }
};