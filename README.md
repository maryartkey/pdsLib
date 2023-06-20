## pdsLib

pdsLib is a C++ library including persistent variants of a bi-directional list, a dynamic array, and a hash table. 

### List (bi-directional list)

#### *Constructor:*

List(); 

#### *List-constructor used to pop front:*

List(std::shared_ptr<Element<T>>, List const&); 

####  *List-constructor used to add head element:*

List(T, List const&);

####  *List-constructor used to add tail element:*

List(List const&, T);

#### *Is empty flag:*

bool IsEmpty() const; 

#### *Get num of elements in List:*

int Count() const;

#### *Return new List with added head element:*

List<T> AddHead(T) const;

#### *Return new List with added tail element:*

List<T> AddTail(T) const;

#### *Take and return new List from 0 to int elements:*

List<T> Take(int) const;

#### *Get element of List by index:*

T Get(int) const;

#### *Set element of List by index:*

List<T> Set(int, T) const;

#### *Insert element in List by index:* 

List<T> Insert(T, int index = 0) const;

#### *Delete element in List by index:*

List Remove(int) const;

#### *Print all List:*

void PrintAll() const;

### Array (dynamic persistent array)

#### *Constructor:*

Array(); 

#### *Constructor used to add elements:*

Array(std::shared_ptr<Element>, Array const&);

#### *Constructor used to remove elements:*

Array(int, Array const&);

#### *Is empty flag:*

bool IsEmpty() const;

#### *Get num of elements in Array:*

int Count() const;

#### *Return new Array with added element:*

Array Add(const T&) const;
		
#### *Return new Array with removed element:*

Array Remove(const T&) const;

#### *Find element in Array:*

bool Find(const T&) const;

#### *Print all elements from Array:*

void PrintAll() const;

### HashTable

#### *Constructor:* 

HashTable();

#### *Constructor used to add elements:* 

HashTable(std::shared_ptr<Element>, HashTable const&);

#### *Constructor used to remove elements:*

HashTable(int, HashTable const&);

#### *Is empty flag:*

bool IsEmpty() const;

#### *Get num of elements in HashTable:*

int Count() const;

#### *Change keys:*

void Hash(std::shared_ptr<Element> element, const HashFunction1& hash1 = HashFunction1(), const HashFunction2& hash2 = HashFunction2());

#### *Return new HashTable with added element:*

HashTable Add(const T&) const;

#### *Return new HashTable with removed element:*

HashTable Remove(const T&) const;

#### *Find element in HashTable:*

bool Find(const T&) const;

#### *Print all elements from HashTable:*

void PrintAll() const;
