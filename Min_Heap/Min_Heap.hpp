#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
//Min heap implemented by using an array;
//dynamically resizes with inserts and removals
template<typename T> class Min_Heap{
	private:
		int * arr;
		size_t sz;
	public:
		//constructors
		Min_Heap(){
			arr = NULL;
			sz = 0;	
		}
		size_t size(){
			return sz;
		}
		bool empty(){
			return sz > 0 ? false : true;
		}
		void heapify(){
			int index = sz - 1;
			while(index > 0 && arr[get_parent(index)] > arr[index]){
				//swap
				int temp = arr[get_parent(index)];
				arr[get_parent(index)] = arr[index];
				arr[index] = temp;
				index = get_parent(index);
			}
		}
		void heapify(int index){
			int l = left(index);
			int r = right(index);
			int smallest = index;
		}
		//insert
		void insert(const T& val){
			if(arr == NULL){
				arr = new T[1];
				arr[0] = val;
				++sz;
			}
			else{
				++sz;
				int index = sz - 1;
				T* temp = new T[sz];
				for(size_t i = 0; i < sz-1;i++){
					temp[i] = arr[i];
				}
				temp[sz-1] = val;
				delete arr;
				arr = temp;
				temp = NULL;
				//now heapify
				heapify();		
			}
		}
	
		//remove
		T& top(){
			return arr[0];
		}
		void pop(){
			if(sz == 1){
				sz--;
				return arr[0];
			}
			T root = arr[0];
			arr[0] = arr[sz-1];
			sz--;
			heapify(0);
		}

		//access
		int get_parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return (2*i) + 1;
		}
		int right(int i){
			return (2*i) + 2;
		}

		//traversals
		


};
#endif
