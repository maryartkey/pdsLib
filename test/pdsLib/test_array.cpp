#include <Array.h>
#include <doctest/doctest.h>

pdsLib::Array<int> arr;
pdsLib::Array<int> arr1 = arr.Add(1);
pdsLib::Array<int> arr2 = arr1.Add(1).Add(2);


TEST_CASE("testing something")
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

TEST_CASE("testAdd")
{
    arr.Add(1);
    arr1.Add(2);
    arr2.Add(3);
}

TEST_CASE("testRemove")
{

}

TEST_CASE("testFind")
{
}