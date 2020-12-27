#include <vector>       /* File: queue.h */

template <typename T>
class Queue             // Circular queue
{
  public:
    Queue();            // Default CONSTRUCTOR 

    bool empty() const; // Check if the queue is empty
    int size() const;   // Give the number of data currently stored
    T& front();         // Retrieve front item for non-const Queue
    const T& front() const; // Retrieve front item for const Queue

    void enqueue(const T&); // Add new item to the back of the queue
    void dequeue();         // Remove the front item from the queue

  private:
    vector<T> data;     // Use an array to store data
    int first;          // Index of the first item; start from 0
};
