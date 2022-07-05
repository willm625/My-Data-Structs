#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#ifndef DEQUE_HPP
#define DEQUE_HPP

//Header file for Deque implementation

//Iterator class for deque, has direct access to data for iteration 
template<typename T> class Deque_Iterator{
	private:
		int start;
		int end;
		T * datap;
		int index;
	public:	
		Deque_Iterator(int ind, int st, int en, T* d){
			index = ind;
			start = st;
			end = en;
			datap = d;
		}	
		void operator++(int){
			if(index == end){
				index = start;
			}
			else{
				index++;
			}
			
		}
		Deque_Iterator operator+(int num){
			assert(index+num != end);
			Deque_Iterator iter(index + num, start, end, datap);
			return iter;
		}
		void operator--(){
			if(index < start){
				index = end - 1;
			}
			else{
				index--;
			}
		}
		T& get(){
			return datap[index];
		}
		int get_index() const{
			return index;
		}
				

};
//non-member functions for Iterator
//not equal operator

template<typename T1, typename T2> bool operator!=(const Deque_Iterator<T1> it1, const Deque_Iterator<T2> it2){
		return it1.get_index() == it2.get_index() ? false : true;
}
//equal operator 
template<typename T1, typename T2> bool operator==(const Deque_Iterator<T1> it1, const Deque_Iterator<T2> it2){
		return it1.get_index() == it2.get_index() ? true : false;
}

/*
Double ended Queue class based on an array
data size grows dynamically for insertions
elements can be added/removed on both ends
*/
template<typename T> class Deque{
	private:
		//pointer that will reference the data 
		T * data;
		size_t sz;
	public:	
		//empty constructor
		Deque(){
			data = NULL;
			sz = 0;
		}
		//constructor where a Deque of type U is passed
		//copies the deque argument's data
		template<typename U> Deque(const Deque<U> &deq){
			if(deq.get_data() != NULL){
				data = deq.get_data();
				sz = deq.size();
			}
		}
		//constructor where a Deque is passed in, type not specified
		//copies the deque's data
		Deque(const Deque &deq){
			if(deq.get_data() != NULL){
				data = deq.get_data();
				sz = deq.size();
			
			}
		}
		//overload of assignment operator
		//copies data from deque q
		Deque &operator=(Deque &q){
			if(q.get_data() != NULL){
				data = q.get_data();
				sz = q.size();
		
			}
		}
		//returns data
		T* get_data() const{
			return data;
		}
		//returns size
		size_t size() const{
			return sz;
		}
		//returns true if deque is empty
		bool empty(){
			return sz > 0 ? false : true;
		}
		//inserts value val to the back of the deque
		//creates a new pointer in the process to allow dyanmic growth
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
		//inserts value val to the front of the queue
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
		//removes the front element in the deque
		//creates a new pointer with one less spot for memory
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
		//removes the back element in the deque
		//creates a new pointer with one less spot for memory
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
		//returns the front element of the deque
		T& front(){
			assert(sz > 0);
			return data[0];
		}
		//returns the element at the back
		T& back(){
			assert(sz > 0);
			return data[sz-1];
		}
		//returns the element at index i
		T& at(int i){
			assert(i < (int) sz);
			return data[i];
		}
		//overload of [] index operator
		//returns element at position i
		T& operator[](int i){
			assert(i < (int) sz);
			return data[i];
		}
		//empties the deque, sets size to 0
		void clear(){
			T * temp = new T[0];
			delete data;
			data = temp;
			temp = NULL;
			sz = 0;
		}
		//returns an iterator pointing to the front element
		Deque_Iterator<T> begin(){
			Deque_Iterator<T> iter(0, 0, sz, data);
			return iter;
		}
		//returns an iterator pointing to the back of the deque, null
		Deque_Iterator<T> end(){
			Deque_Iterator<T> iter(sz, 0, sz, data);
			return iter;
		}
		//erases the element which iterator pos is pointing to
		//returns an iterator pointing to the element after the recently removed one
		//if the last element was removed, then returns iterator at the end
		Deque_Iterator<T> erase(Deque_Iterator<T> pos){
			sz--;
			T * temp = new T[sz];
			int index = pos.get_index();
			int ind = 0;
			for(size_t i = 0; i < sz+1; i++){
				if(i != index){
					temp[ind] = data[i];
					ind++;
				}
			}
			delete data;
			data = temp;
			temp = NULL;
			if(index == sz){
				return end();
			}
			else{
				Deque_Iterator<T> iter(0, index, sz, data);
				return iter;
			}
		}
		//erases the elements referenced from iterators first to last
		//resizes deque
		//returns iterator pointing to the element after the recently removed one
		//if the last element was removed then returns iterator at end
		Deque_Iterator<T> erase(Deque_Iterator<T> first, Deque_Iterator<T> last){
			int len = last.get_index() - first.get_index();
			int old_sz = sz;
			sz = sz - len;
			T * temp = new T[sz];
			int ind = 0;
			for(size_t i = 0; i < old_sz; i++){
				if(i < first.get_index() || i >= last.get_index()){
					temp[ind] = data[i];
					ind++;
				}
			}
			delete data;
			data = temp;
			temp = NULL;
			if(last == end()){
				return end();
			}
			else{
				--last;
				return last;
			}
		}
		/*
		~Deque(){
			delete data;
			sz = 0; 
		}*/
	
		
};
/*FUNCTIONS TO IMPLEMENT:
	erase()
	operator print overload
	==, != <, >, <=, >=
	
*/
template <typename T> bool operator==(Deque<T> &q1, Deque<T> &q2){
	if(q1.size() != q2.size()){
		return false;
	}
	for(int i = 0; i < q1.size(); i++){
		if(q1[i] != q2[i]){
			return false;
		}
	}
	return true;
}
template <typename T> bool operator !=(Deque<T> &q1, Deque<T> &q2){
	return (q1 == q2) ? false : true;
}
#endif 
