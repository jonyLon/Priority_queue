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
		pair<int, int> tmp = { priority, data };
		last++;
		if (isFull()) {
			cout << "Queue is full" << endl;
			resize();
		}
		int index = getPos(priority);
		if (isEmpty() || index == -1) {
			queue[last] = tmp;
		}
		for (int i = last; i > index; i--)
		{
			queue[i] = queue[i - 1];
		}
		queue[index] = tmp;
	}
	void pullHighestPriorityElement() {
		first++;
		if (first == caparcity)
		{
			first = 0;
			last = -1;
		}
	}
	void show() {
		for (size_t i = first; i <= last; i++)
		{
			cout << "Priority: "<< queue[i].first << "  Value: " << queue[i].second << "\n";
		}
		cout << endl;
	}
	pair<int,int> peek() {
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
	//void prioritySort() {
	//	for (size_t i = first; i < last+1; i++)
	//	{
	//		for (size_t j = first; j < last+1 - i - 1; j++)
	//		{
	//			if (queue[j].first > queue[j + 1].first) {
	//				swap(queue[j], queue[j + 1]);
	//			}
	//		}
	//	}
	//}
	int getPos(int priority) {
		for (size_t i = first; i < last + 1; i++)
		{
			if (priority > queue[i].first) {
				return i;
			}
		}
		return -1;
	}
};

