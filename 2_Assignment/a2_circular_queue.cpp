#include <iostream>
#include "a2_circular_queue.hpp"

#include <iostream>
using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
	head_ = 0; // init head_
	tail_ = 0; // init tail_
	size_ = 0; // init size_
	capacity_ = 16; // init default capacity_
	items_ = new QueueItem[capacity_]; // create the array
}

CircularQueue::CircularQueue(unsigned int capacity) {
	head_ = 0; // init head_
	tail_ = 0; // init tail_
	size_ = 0; // init size_
	capacity_ = capacity; // init the specified capacity
	items_ = new QueueItem[capacity_]; // create the array
}

CircularQueue::~CircularQueue() {
	delete [] items_;
	items_ = NULL;
}

int CircularQueue::size() const {  
	return size_;
}

bool CircularQueue::empty() const {
	if (size_ == 0){ // check for empty queue
		return true;
	}
	return false;
}

bool CircularQueue::full() const {
	if (size_ == capacity_){
		return true;
	}
	return false;
}

void CircularQueue::print() const {
	int currIndex = head_; // temp index counter
	for (int i = 0; i < size_; i++){
		cout << items_[currIndex] << ", ";
		if (currIndex == (capacity_ - 1)){
			currIndex = 0; //Set curr index to loop back to beginning of the array
		}
		currIndex = currIndex + 1;
	}
	cout << endl;
}

QueueItem CircularQueue::peek() const {
	if (size_ == 0){ // check for empty queue
		return EMPTY_QUEUE;
	}
	return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
	if (size_ == capacity_){ // check if queue is full
		return false;
	}

	if (size_ == 0){ // check for empty queue
		items_[0] = value;
		tail_ = tail_ + 1;
		size_ = size_ + 1;
		return true;
	}

	if (tail_ == capacity_ - 1){ //we are adding at the end of the array
		items_[0] = value; 
		tail_ = 0; // set tail to be at the front of the array
		size_ = size_ + 1;
		return true;
	} else { // the normal case
		items_[tail_] = value;
		tail_ = tail_ + 1;
		size_ = size_ + 1;
		return true;
	}

}

QueueItem CircularQueue::dequeue() {
	if (size_ == 0){ // check for empty queue
		return EMPTY_QUEUE;
	}

	QueueItem valToReturn = items_[head_]; // get the value to return

	// deal with head_ index assignment
	if (head_ == capacity_ - 1){ // we are removing from the end of the array
		head_ = 0;
		size_ = size_ - 1;
	} else { // the normal case
		head_ = head_ + 1;
		size_ = size_ - 1;
	}
	return valToReturn;

}
