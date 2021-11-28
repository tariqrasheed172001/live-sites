/*
AIM: Implementation of Priority queue using Heap.

Priority Queue is an extension of the queue with the following properties:  

Every item has a priority associated with it.
An element with high priority is dequeued before an element with low priority.
If two elements have the same priority, they are served according to their 
order in the queue.

ALGORITHEM:
A Binary Heap is a Binary Tree with the following properties:  
It is a Complete Tree. This property of Binary Heap makes them 
suitable to be stored in an array.
A Binary Heap is either Min Heap or Max Heap.
In a Min Binary Heap, the key at the root must be minimum 
among all keys present in Binary Heap. The same property 
must be recursively true for all nodes in Binary Tree.
Similarly, in a Max Binary Heap, the key at the root must 
be maximum among all keys present in Binary Heap. The same 
property must be recursively true for all nodes in Binary Tree.
 

Operation on Binary Heap 
insert(p): Inserts a new element with priority p.
extractMax(): Extracts an element with maximum priority.
remove(i): Removes an element pointed by an iterator i.
getMax(): Returns an element with maximum priority.
changePriority(i, p): Changes the priority of an element pointed by i to p.
*/ 

#include <iostream>
using namespace std;

int H[50];
int size = -1;

int parent(int i)
{

	return (i - 1) / 2;
}

int leftChild(int i)
{

	return ((2 * i) + 1);
}

int rightChild(int i)
{

	return ((2 * i) + 2);
}

void shiftUp(int i)
{
	while (i > 0 && H[parent(i)] < H[i]) {

		swap(H[parent(i)], H[i]);

		i = parent(i);
	}
}

void shiftDown(int i)
{
	int maxIndex = i;

	int l = leftChild(i);

	if (l <= size && H[l] > H[maxIndex]) {
		maxIndex = l;
	}
	int r = rightChild(i);

	if (r <= size && H[r] > H[maxIndex]) {
		maxIndex = r;
	}
	if (i != maxIndex) {
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}

void insert(int p)
{
	size = size + 1;
	H[size] = p;

	shiftUp(size);
}

int extractMax()
{
	int result = H[0];

	H[0] = H[size];
	size = size - 1;

	shiftDown(0);
	return result;
}

void changePriority(int i, int p)
{
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}

int getMax()
{

	return H[0];
}

void remove(int i)
{
	H[i] = getMax() + 1;

	shiftUp(i);

	extractMax();
}


int main()
{

	/*		 45
			/	 \
		31	 14
		/ \ / \
		13 20 7 11
		/ \
	12 7
	Create a priority queue shown in
	example in a binary max heap form.
	Queue will be represented in the
	form of array as:
	45 31 14 13 20 7 11 12 7 */

	// Insert the element to the
	// priority queue
	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	cout << "Priority Queue : ";
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	cout << "Node with maximum priority : "
		<< extractMax() << "\n";

	cout << "Priority queue after "
		<< "extracting maximum : ";
	int j = 0;
	while (j <= size) {
		cout << H[j] << " ";
		j++;
	}

	cout << "\n";

	changePriority(2, 49);
	cout << "Priority queue after "
		<< "priority change : ";
	int k = 0;
	while (k <= size) {
		cout << H[k] << " ";
		k++;
	}

	cout << "\n";
	remove(3);
	cout << "Priority queue after "
		<< "removing the element : ";
	int l = 0;
	while (l <= size) {
		cout << H[l] << " ";
		l++;
	}
    cout<<endl;
	return 0;
}
