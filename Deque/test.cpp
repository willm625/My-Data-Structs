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
	m.push_back(5);
	m.push_front(20);
	for(Deque_Iterator<int> it = m.begin(); it != m.end(); it++){
		cout << it.get() << "\n";
	}
	Deque<int> m1(m);
	std::cout << "m1 created m1(m)\n";
	for(Deque_Iterator<int> it = m1.begin(); it != m1.end(); it++){
		cout << it.get() << "\n";
	}
	Deque<int> m2 = m1;
	std::cout << "m2 created m2 = m1\n";
	
	for(Deque_Iterator<int> it = m2.begin(); it != m2.end(); it++){
	
		cout << it.get() << "\n";
	}
	//m1.erase(m1.begin()+1, m1.begin()+4);
	//cout << "ERASED\n";	
	if(m1 == m2){
		cout << "m1 == m2\n";
	}
	m1.pop_back();
	if(m1 != m2){
		cout << "m1 != m2\n";	
	}
	for(Deque_Iterator<int> it = m1.begin(); it != m1.end(); it++){

		cout << it.get() << "\n";
	}
	//cout << "m1 size " << m1.size() << "\n";	
	//cout << "m1 at 0: " << m1.at(0) << " m1[0] : " << m1[0] << "\n";
	
	//cout << "m2 at 0: " << m2.at(0) << " m2[0] : " << m2[0] << "\n";
	/*	
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
	*/
	return 0;
}
