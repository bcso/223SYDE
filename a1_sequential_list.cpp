#include "a1_sequential_list.hpp"
#include <iostream>
#include <string>

using namespace std;

//Brian So, 20477254
//Kenny Lam, 20519190 

SequentialList::SequentialList(unsigned int cap)
{
	//Define max number of elements this list can sure
	capacity_ = cap;
	//Initial size of list
	size_ = 0;
	
	//Create dynamic array to house the list
	data_ = new int[capacity_];
}

SequentialList::~SequentialList()
{
	//Free up the space
	delete [] data_;
	//Remove dangling pointers
	data_ = NULL;
}

unsigned int SequentialList::size() const
{
	//return size
	return size_;
}

unsigned int SequentialList::capacity() const
{
	//return size
	return capacity_;
}

bool SequentialList::empty() const
{
	//Check size of list for empty
	if (size_ == 0){
		return true;
	} else {
		return false;
	}
}

bool SequentialList::full() const
{
	//Check size of list for empty
	if (size_ == capacity_){
		return true;
	} else {
		return false;
	}
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	//Check if index is in size
	if (index >= size_){
		return data_[size_-1];
	}
	return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
	//iterate through array until proper value is found
	for (int i = 0; i<size_; i++){
		if (data_[i] == val){
			return i;
		}
	}

	return size_;
}

void SequentialList::print() const
{
	//Print the list
	for (int i = 0; i<size_; i++){
		cout << data_[i] << " ";
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	//Initialize the vars
	size_ = size_ + 1;
	int temp = 0;
	int tempVal = data_[index];
	data_[index] = val;

	//shuffle the list over
	for (int i = index + 1; i<size_; i++){
		temp = data_[i];
		data_[i] = tempVal;
		tempVal = temp;
	}

	return true;
}

bool SequentialList::insert_front(DataType val)
{
	//Initliaze the vars
	size_ = size_ + 1;
 	int temp = 0;
 	int tempVal = data_[0];
 	data_[0] = val;

	//shuffle the list over
	for (int i = 1; i<size_; i++){
		temp = data_[i];
		data_[i] = tempVal;
		tempVal = temp;
	}

	return true;
}

bool SequentialList::insert_back(DataType val)
{ 
	data_[size_] = val;
	size_ = size_ + 1;
	return true;
}

bool SequentialList::remove(unsigned int index)
{
	//Check for empty array
	if (size_ == 0){
		return false;
	}

	//Decrement size
	size_ = size_ - 1;

	//Shift all values over
	for (int i = index; i < size_; i++){
		data_[i] = data_[i+1];
	}
    
    return true;
}

bool SequentialList::remove_front()
{
	//Check for empty array
	if (size_ == 0){
		return false;
	}

	//Decrement size
	size_ = size_ - 1;

	//Shift all values over
	for (int i = 0; i < size_; i++){
		data_[i] = data_[i+1];
	}
    data_[size_ + 1] = NULL;

    return true;
}

bool SequentialList::remove_back()
{
	//Check for empty array
	if (size_ == 0){
		return false;
	}

	data_[size_] = NULL;

	//Decrement size
	size_ = size_ - 1;
    
    return true;	
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	//Check for empty array
	if (size_ == 0){
		return false;
	}

	data_[index] = val;

	return true;	
}
