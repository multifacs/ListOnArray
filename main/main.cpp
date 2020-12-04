#include "AList.h"

int main()
{
	AList<int> lst;
	lst.push_back(1);
	lst.push_back(5);
	lst.push_back(100);

	cout << "Size: " << lst.GetSize() << endl;
	cout << lst << endl;
	
	cout << endl << "Deleting first" << endl;
	lst.pop_front();
	cout << lst << endl;

	cout << endl << "Inserting" << endl;
	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);
	cout << lst << endl;

	cout << endl << "Removing" << endl;
	lst.remove(2);
	cout << lst << endl;

	cout << endl << "Pop back" << endl;
	lst.pop_back();
	cout << lst << endl;

	AList<int> lst2(lst);
}