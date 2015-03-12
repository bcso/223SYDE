#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem; 
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
}

DynamicStack::DynamicStack(unsigned int capacity) {
}

DynamicStack::~DynamicStack() {
}

int DynamicStack::size() const {
}

bool DynamicStack::empty() const {
}

void DynamicStack::print() const {
}

StackItem DynamicStack::peek() const {
}

void DynamicStack::push(StackItem value) {
}

StackItem DynamicStack::pop() {
}
