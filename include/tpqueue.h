// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
	
template<typename T, int size>
class TPQueue {
	private:
	   T* arr;
	   int start, end, cnt;
	
	public:
	   TPQueue():start(0), end(0), cnt(0) {
	       arr = new T[size + 1];
	   }
	   ~TPQueue() {
	       delete[] arr;
	   }
	   bool isEmpty() const {
	       return cnt == 0;
	   }
	   bool isFull() const {
	       return cnt == size;
	   }
	   void push(const T& value) {
	       if (isFull()) {
	           throw std::string("Full");
	       } else {
	           int oher = end;
	           ++cnt;
	           for (int i = start; i < end; i++) {
	               if (arr[i].prior < value.prior) {
	                   oher = i;
	                   break;
	               }
	           }
	           for (int l = end; l > oher; l--) {
	               arr[l % size] = arr[(l - 1) % size];
	           }
	           arr[oher % size] = value;
	           ++end;
	       }
	   }
	   T& pop() {
	       if (isEmpty()) {
	           throw std::string("Empty");
	       } else {
	           --cnt;
	           return arr[start++ % size];
	       }
	   }
};
	
struct SYM {
	 char ch;
	 int prior;
};
	
#endif  // INCLUDE_TPQUEUE_H_
