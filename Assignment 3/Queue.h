#pragma once
#include<queue>
template <typename T>
class Queue {
private:
    queue<T> q;
public:
    void push(T item) {
        q.push(item);
    }
    void pop() {
        q.pop();
    }
    T front() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};