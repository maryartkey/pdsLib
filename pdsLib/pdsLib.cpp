﻿/*entry point for the application*/

#include "HashTable.h"
#include "Array.h"
#include "List.h"

using namespace std;

int main()
{
	// pdsLib::List<double> list1;
	// pdsLib::List<double> list2 = list1.AddHead(1).AddTail(2).AddTail(3);
	// pdsLib::List<double> list3 = list2.Insert(0, 3);
	// 
	// //std::cout << list2.Get(0) << std::endl;
	// 
	// list1.PrintAll();
	// list2.PrintAll();
	// list3.PrintAll();

	// pdsLib::HashTable<int, std::string> htI;
	// 
	// pdsLib::HashTable<int, std::string> htI2 = htI.Add(0, "a").Add(0, "B").Add(1, "b").Add(69, "nice");
	// 
	// htI.PrintAll();
	// htI2.PrintAll();
	// htI2.Set(1, "bb").PrintAll();

	pdsLib::Array<double> array;
	pdsLib::Array<double> array2 = array.Add(1).Add(2).Add(3);

	//std::cout << array2.Find(7) << std::endl;
	array2.Set(200, 0).PrintAll();
	//array2.Remove(4).PrintAll();
	array2.PrintAll();

	return 0;
}
