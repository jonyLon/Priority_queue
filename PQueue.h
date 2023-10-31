#pragma once
#include <iostream>
using namespace std;
class PQueue
{
public:
	PQueue(const size_t& size, const size_t& step) : caparcity{ size }, step{ step } {
		queue = new pair<int,int>[caparcity];
	}
	~PQueue() {
		delete[] queue;
	}
	bool isEmpty() const {
		return last == -1;
	}
	bool isFull() const {
		return last == caparcity;
	}
	void insertWithPriority(int data, int priority) {
		last++;
		if (isFull()) {
			cout << "Queue is full" << endl;
			resize();
		}
		queue[last].first = priority;
		queue[last].second = data;
	}
	void pullHighestPriorityElement() {
		if (last > 0)prioritySort();
		first++;
		if (first == caparcity)
		{
			first = 0;
			last = -1;
		}
	}
	void show() {
		if (last > 0)prioritySort();
		for (size_t i = first; i <= last; i++)
		{
			cout << "Priority: "<< queue[i].first << "  Value: " << queue[i].second << "\n";
		}
		cout << endl;
	}
	pair<int,int> peek() {
		if (last > 0)prioritySort();
		return queue[first];
	}


private:
	int first = 0;
	int last = -1;
	pair<int,int>* queue = nullptr;
	size_t caparcity;
	size_t counter = 4;
	size_t step;
	void resize() {
		caparcity += counter * step;
		pair<int, int>* tmp = new pair<int, int>[caparcity];
		for (size_t i = first; i < last; i++)
		{
			tmp[i] = queue[i];
		}
		delete[] queue;
		queue = tmp;
	}
	void prioritySort() {
		for (size_t i = first; i < last+1; i++)
		{
			for (size_t j = first; j < last+1 - i - 1; j++)
			{
				if (queue[j].first > queue[j + 1].first) {
					swap(queue[j], queue[j + 1]);
				}
			}
		}
	}
};

