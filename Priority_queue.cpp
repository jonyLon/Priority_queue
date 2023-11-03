#include "PQueue.h"

int main()
{
    PQueue data(5, 2);
    data.insertWithPriority(78, 5);
    data.insertWithPriority(99, 3);
    data.insertWithPriority(92, 6);
    data.insertWithPriority(90, 4);
    data.insertWithPriority(9, 2);
    data.insertWithPriority(5, 1);
    data.pullHighestPriorityElement();
    data.show();
    cout << "Peek priority: " << data.peek().first << " Peek Value: " << data.peek().second << "\n";
}


