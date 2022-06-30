#include "dynamic-stack.h"
#include <iostream>
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -99999;


DynamicStack::DynamicStack() {
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity){
    capacity_ = capacity;
    init_capacity_ = capacity;
    size_ = 0;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack() {
    delete []items_;
    items_ = nullptr;
}

bool DynamicStack::empty() const {
    if (size_ == 0){
        return true;
    }
    else{
        return false;
    }
}

int DynamicStack::size() const {
    //need to add edge cases
    return size_;
}

void DynamicStack::push(StackItem value) {
    if (size_ == capacity_){
        //might have to call parametric constructor with capacity*2 as input
        capacity_ *= 2;
    }
    items_[size_] = value;
    size_++;

}

DynamicStack::StackItem DynamicStack::pop() {
    StackItem value = items_[size_-1];
    if (empty()){
        return EMPTY_STACK;
    }
    if ((size_-2) <= (capacity_/4) && capacity_/2 >= init_capacity_){
        capacity_ /= 2;
    }
    items_[size_-1] = EMPTY_STACK;
    size_--;
    return value;
}

DynamicStack::StackItem DynamicStack::peek() const {
    if (empty()){
        return EMPTY_STACK;
    }
    else{
        return items_[size_-1];
    }

}

void DynamicStack::print() const {
    for(int i=size_-1; i=0; i--){
        std::cout << items_[i] << std::endl;
    }
}
