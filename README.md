# ������������� ��������� ������

������:

����������� ���������� �� ���������� ����������� ������ � ������������� ���������:

* ������������ ������ (����������� ����� �������, ���������� �����)
* ���������� ������
* ������������� ������ (�� ������ ���-�������)

� ������� �������� ������� ��������������� ����� ���� ����������� �� ������ Fat Node.

���� ����������: C++

����������:

* ������ API ��� ���� �������� ������.

�������������� ����������:

* ���������� ������������ ����������� ������ (template).

* ����������� ����� ����������� �� �������� ������� ������ ������� �� ��������� � Fat Node.

�������������� ���� �������

������������� ��������� ������ (persistent data structure, PDS) � ��� ��������� ������, ������� ��� �������� � ��� �����-�� ��������� ��������� ��� ���� ���������� ��������� � ������ � ���� ����������.

PDS ����� �����������, ��������� ����� ��������� ����� (Fat Node), ��� ������� ��� ������� �������� ��������� ������ �������� ������� ��� ���������. ����������� ������� ������� ���������� ���� �������, ����� ����������� ����������� ����� ����������� ����������.

����� ����������� ���������� ������������ ������������� ����� ���������� (smart pointers, C++11) - [std::shared_ptr](https://en.cppreference.com/w/cpp/memory/shared_ptr).

������  | ����� | �����������
------------- | ------------- | -------------
����������� ����, ����� ���������� � PDS | 24.11.22 | �����, �����
����������� ����������� ����� ����������� ���������� PDS | 24.11.22 | �����
����������� ������� ������ ������������ ������ | 7.12.22 | �����
����������� ���������� ������ �� ������ smart pointers | 7.12.22 | �����
����������� ������� ������ ������������� ������� �� ������ fat node | 8.12.22 | �����
����������� ������������� ������ �� ������ ���-������� � �������������� smart pointers | 13.12.22 | �����
����������� ������������ ������ �������������� smart pointers | 14.12.22 | �����
��������� ������������ � ������� | 14.12.22 | �����

## pdsLib
### List (���������� ������������� ������)


List(); *constructor*


List(std::shared_ptr<Element<T>>, List const&); *list-constructor used to pop front*


List(T, List const&); *list-constructor used to add head element*


List(List const&, T); *list-constructor used to add tail element*


bool IsEmpty() const; *is empty flag*


int Count() const; *get num of elements in List*


List<T> AddHead(T) const; *return new List with added head element*


List<T> AddTail(T) const; *return new List with added tail element*


List<T> Take(int) const; *take and return new List from 0 to int elements*


T Get(int) const; *get element of List by index*


List<T> Set(int, T) const; *set element of List by index*


List<T> Insert(T, int index = 0) const; *insert element in List by index*


List Remove(int) const; *delete element in List by index*


void PrintAll() const; *print all List*

### Array (������������ ������������� ������)


Array(); *constructor*


Array(std::shared_ptr<Element>, Array const&); *constructor used to add elements*


Array(int, Array const&); *constructor used to remove elements*


bool IsEmpty() const; *is empty flag*


int Count() const; *get num of elements in Array*


Array Add(const T&) const; *return new Array with added element*
		

Array Remove(const T&) const; *return new Array with removed element*


bool Find(const T&) const; *find element in Array*
		

void PrintAll() const; *print all elements from Array*

### HashTable (������������� ������ �� ������ ���-�������)


HashTable(); *constructor*


HashTable(std::shared_ptr<Element>, HashTable const&); *constructor used to add elements*


HashTable(int, HashTable const&); *constructor used to remove elements*


bool IsEmpty() const; *is empty flag*


int Count() const; *get num of elements in HashTable*


void Hash(std::shared_ptr<Element> element, const HashFunction1& hash1 = HashFunction1(), const HashFunction2& hash2 = HashFunction2()); *change keys*


HashTable Add(const T&) const; *return new HashTable with added element*
		

HashTable Remove(const T&) const; *return new HashTable with removed element*


bool Find(const T&) const; *find element in HashTable*
		

void PrintAll() const; *print all elements from HashTable*
