#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
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
		//insert
		void insert(const T& val){
			if(arr == NULL){
				arr = new T[1];
				arr[0] = val;
			}
			else{
				
			}
		}
	
		//remove

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
