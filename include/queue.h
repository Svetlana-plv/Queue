#include <iostream>

template<typename T>
class TQueue {
private:
	T* pMem = nullptr;
	size_t memSize;
	size_t sz;

	size_t front;
	size_t back;

public:

	TQueue(size_t size=4): memSize(size), sz(0), front(0), back(0) {
	
		pMem = new T[memSize];
	}

	~TQueue() { delete[] pMem; }

	TQueue(const TQueue& queue) = delete;

	TQueue& operator=(const TQueue& queue) = delete;

	void Clear() {
		delete[] pMem;
		pMem = new T[memSize];
		sz = 0;
		front = 0;
		back = 0;

	}

	bool Empty() const { return sz == 0; }

	bool Full() const { return sz == memSize; }

	size_t Size() const { return sz; }

	size_t GetMemSize() const { return memSize; }

	void Push(const T& val) {
		if (Full()) Repack();
		pMem[back] = val;
		back = (back + 1) % memSize;
		back++;
		sz++;

	}

	void Pop() {
		if (Empty()) throw std::logic_error("Queue is empty!");
		front = (front + 1) % memSize;
		sz--;

	}

	T Top() {
		if (Empty()) throw std::logic_error("Queue is empty!");
		return pMem[front];
	}

private:

	void Repack() {
		T* new_data = new T[memSize * 2];

		for (int i = 0; i < sz; i++) 
			new_data[i] = pMem[(front + i) % memSize];

		memSize *= 2;
		front = 0;
		back = sz-1;
		
		delete[] pMem;
		pMem = new_data;
	}
}; 