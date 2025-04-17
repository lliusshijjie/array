#include <iostream>
#include "stl/array.h"

using namespace stl;
using namespace std;

int main() {
	Array<int, 10> a;
	
	// Init array
	for (int i = 0; i < 10; i++) {
		a[i] = i + 1;
	}
	
	cout << "Array content: ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	
	cout << "Iterator test: ";
	for (auto it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "Const iterator test: ";
	const Array<int, 10>& ca = a;
	for (auto it = ca.begin(); it != ca.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "Reverse iterator test: ";
	for (auto it = a.rbegin(); it != a.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}