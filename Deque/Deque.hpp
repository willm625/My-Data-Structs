#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#ifndef DEQUE_HPP
#define DEQUE_HPP

template<typename T> class Deque{
	class Deque_Iterator{
		private:
			int index;
			int start;
			int end;
			T * datap;
		public:
			Deque_Iterator(int ind, int st, int en, T* d){
				index = ind;
				start = st;
				end = en;
				datap = d;
			}	
			void inc(){
				if(index == end){
					index = start;
				}
				else{
					index++;
				}
			}
			void dec(){
				if(index < start){
					index = end - 1;
				}
				else{
					index--;
				}
			}
			T& deref(){
				return datap[index];
			}
		
	};
	private:
		T * data;
		size_t sz;
	public:	
		//DequeIterator
		Deque(){
			data = NULL;
			sz = 0;
		}
		Deque &operator=(Deque &q);
		size_t size(){
			return sz;
		}
		bool empty(){
			return sz > 0 ? false : true;
		}
		void push_back(const T& val){
			if(data == NULL){
				//only for first insert
				std::cout << "DATA IS NULL\n";
				sz = 1;
				data =  new T[1];
				data[0] = val;
			}
			else{
				sz = sz + 1;
				T * temp = new T[sz];
				for(size_t i = 0; i < sz-1;i++){
					temp[i] = data[i];
				}
				temp[sz-1] = val;
				delete data;
				data = temp;
				temp = NULL;
			}
		}
		void push_front(const T& val){
			if(data == NULL){
				sz = 1;
				data = new T[1];
				data[0] = val;
			}
			else{
				sz = sz + 1;
				T * temp = new T[sz];
				int index = 1;
				for(size_t i = 0; i < sz-1; i++){
					temp[index] = data[i];
					index++;
				}
				temp[0] = val;
				delete data;
				data = temp;
				temp = NULL;
			}
			
		}
		void pop_front(){
			assert(sz > 0);
			int oldsz = sz;
			sz--;
			T * temp = new T[sz];
			for(size_t i = 1; i < sz; i++){
				temp[i] = data[i];
			}
			delete data;
			data = temp;
			temp = NULL;
		}
		void pop_back(){
			assert(sz > 0);
			int oldsz = sz;
			sz--;
			T * temp = new T[sz];
			for(size_t i = 0; i < sz; i++){
				temp[i] = data[i];
			}
			delete data;
			data = temp;
			temp = NULL;
		}	
		T& front(){
			assert(sz > 0);
			return data[0];
		}
		T& back(){
			assert(sz > 0);
			return data[sz-1];
		}
		T& at(int i){
			assert(i < (int) sz);
			return data[i];
		}
		void clear(){
			T * temp = new T[0];
			delete data;
			data = temp;
			temp = NULL;
			sz = 0;
		}
		
		Deque_Iterator begin(){
			Deque iter(0, 0, sz, &data);
			return iter;
		}
	
		
};
//template <typename T1, typename T2> bool operator==(Deque &q1, Deque &q2);
#endif 
