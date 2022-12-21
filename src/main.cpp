#include <iostream>
#include "Array.h"
#include "List.h"
#include "HashTable.h"

int main()
{

	// std::cout << "Hello, array!!!" << std::endl;
	// pdsLib::Array<int> arr;
	// pdsLib::Array<int> arr1 = arr.Add(1).Add(2);

	// arr1.PrintAll();
	// std::cout << "arr out!!!" << std::endl;

	// pdsLib::HashTable<int, std::string> htI;
	// 
	// pdsLib::HashTable<int, std::string> htI2 = htI.Add(0, "a").Add(0, "B").Add(1, "b").Add(69, "nice");
	// htI.PrintAll();
	// htI2.PrintAll();
	// std::cout << "ht out!!!" << std::endl;

	pdsLib::List<double> list1;
	pdsLib::List<double> list2 = list1.AddHead(1).AddTail(2).AddTail(3);	
	pdsLib::List<double> list3 = list2.Insert(0, 3);

	list1.PrintAll();
	list2.PrintAll();
	list3.PrintAll();

	std::cout << "list out!!!" << std::endl;

}