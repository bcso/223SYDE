#include "a1_sequential_list.hpp"
#include <iostream>
#include <string>

using namespace std;

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
	delete [] data_;
	data_ = NULL;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	if (size_ == 0){
		return true;
	} else {
		return false;
	}
}

bool SequentialList::full() const
{
	if (size_ == capacity_){
		return true;
	} else {
		return false;
	}
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (index >= size_){
		return data_[size_-1];
	}
	return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i = 0; i<size_; i++){
		if (data_[i] == val){
			return i;
		}
	}

	return size_;
}

void SequentialList::print() const
{
	for (int i = 0; i<size_; i++){
		cout << data_[i] << " ";
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
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
	if (size_ == 0){
		return false;
	}

	data_[index] = val;

	return true;	
}