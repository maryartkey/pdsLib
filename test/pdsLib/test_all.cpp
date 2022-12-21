#include "../../src/Array.h"
#include "../../src/List.h"
#include "../../src/HashTable.h"
#include <doctest/doctest.h>

pdsLib::Array<int> arr;
pdsLib::Array<int> arr1 = arr.Add(1);
pdsLib::Array<int> arr2 = arr1.Add(1).Add(2);

TEST_CASE("testArray")
{
    CHECK(arr.Get(1) == NULL);
}

TEST_CASE("testIsEmpty")
{
    CHECK(arr.IsEmpty() == true);
    CHECK(arr1.IsEmpty() == false);
    CHECK(arr2.IsEmpty() == false);
}

TEST_CASE("testCount")
{
    CHECK(arr.Count() == 0);
    CHECK(arr1.Count() == 1);
    CHECK(arr2.Count() == 3);

    arr.Add(1);
    arr1.Add(2);
    arr2.Add(3);

    CHECK(arr.Count() == 0);
    CHECK(arr1.Count() == 1);
    CHECK(arr2.Count() == 3);
}

TEST_CASE("testGet")
{
    CHECK(arr.Get(0) == NULL);
    CHECK(arr1.Get(0) == 1);
    CHECK(arr2.Get(0) == 1);
}

TEST_CASE("testSet")
{
    pdsLib::Array<int> tmp = arr1.Set(0, 0);
    CHECK(tmp.Get(0) == 0);
}

TEST_CASE("testRemove")
{
    arr1.Remove(1);
    CHECK(arr1.Find(1) == true);
}

TEST_CASE("testFind")
{
    CHECK(arr1.Find(1) == true);
}


/*------------------------------------------------*/

pdsLib::List<double> list1;
pdsLib::List<double> list2 = list1.AddHead(1).AddTail(2).AddTail(3);

TEST_CASE("testIsEmptyList")
{
    CHECK(list1.IsEmpty() == true);
    CHECK(list2.IsEmpty() == false);
}

TEST_CASE("testCountList")
{
    CHECK(list1.Count() == 0);
    CHECK(list2.Count() == 3);

    list1.AddHead(1);
    list2.AddTail(1);

    CHECK(list1.Count() == 0);
    CHECK(list2.Count() == 3);
}

TEST_CASE("testAddHeadList")
{
    list1.AddHead(1);
    list2.AddHead(1);

    CHECK(list1.Count() == 0);
    CHECK(list2.Count() == 3);
}

TEST_CASE("testAddTailList")
{
    list1.AddTail(1);
    list2.AddTail(1);

    CHECK(list1.Count() == 0);
    CHECK(list2.Count() == 3);
}
/*
/*----------------------------------------*/

pdsLib::HashTable<int, std::string> ht1;
pdsLib::HashTable<int, std::string> ht2 = ht1.Add(0, "a").Add(0, "b").Add(1, "c").Add(2, "d");

TEST_CASE("testCountHT")
{
    CHECK(ht1.Count() == 0);
    CHECK(ht2.Count() == 4);

    ht1.Add(1, "e");
    ht2.Add(1, "e");

    CHECK(ht1.Count() == 0);
    CHECK(ht2.Count() == 4);
}

TEST_CASE("testFindHT")
{
    CHECK(ht1.Find("a") == false);
    CHECK(ht2.Find("a") == true);
}

TEST_CASE("testRemoveHT")
{
    pdsLib::HashTable<int, std::string> tmp = ht2.Remove("a");
    CHECK(tmp.Find("a") == false);
}