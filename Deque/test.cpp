#include "Deque.hpp"
using namespace std;
int main(){
	Deque<int> m;
	std::cout << "CREATED MY_QUEUE INT\n";
	std::cout << m.size() << " is the size\n";
	if(m.empty()){
		cout << "m is empty\n";
	};
	m.push_back(3);
	m.push_back(1);	
	std::cout << m.size() << " is the size\n";
	if(!m.empty()){
		cout << "m not empty\n";
	}
	cout << m.at(0) << " is m at 0\n";
	
	cout << m.at(1) << " is m at 1\n";
	cout << "pop_back\n";
	m.pop_back();	
	std::cout << m.size() << " is the size\n";
	
	cout << m.at(0) << " is m at 0\n";
	
	cout << "pop_back\n";
	m.pop_back();
		
	std::cout << m.size() << " is the size\n";
	Deque<int> m1;	
	std::cout << "PUSHFRONT\n";
	m1.push_front(20);

	std::cout << m1.size() << " is the size\n";
	std::cout << m1.at(0) << " is m1 at 0\n";
	return 0;
}
