#include "Min_Heap.hpp"

int main(){
	Min_Heap<int> my_heap;
	std::cout << "HI\n";
	my_heap.insert(3);
	my_heap.insert(20);
	my_heap.insert(1);
	std::cout << my_heap.size() << "\n";
	std::cout << my_heap.top() << "\n";
	return 0;
}
