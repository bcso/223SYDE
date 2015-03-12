#include <iostream>
#include "a2_circular_queue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
}

CircularQueue::CircularQueue(unsigned int capacity) {
}

CircularQueue::~CircularQueue() {
}

int CircularQueue::size() const {  
}

bool CircularQueue::empty() const {    
}

bool CircularQueue::full() const {
}

void CircularQueue::print() const {
}

QueueItem CircularQueue::peek() const {
}

bool CircularQueue::enqueue(QueueItem value) {
}

QueueItem CircularQueue::dequeue() {
}
