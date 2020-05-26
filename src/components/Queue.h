// File: Queue.h
// Author: dgrubb
// Date: 26/05/2020
//
// Thread-safe queuing abstraction. Use for building event queues and the like.
// See explanation at: https://bell0bytes.eu/an-event-queue/

#ifndef QUEUE_H
#define QUEUE_H

// C++ Library headers
#include <queue>              // queue
#include <mutex>              // mutex, unique_lock
#include <condition_variable> // condition_variable

template<class T>
class Queue
{
    public:

        Queue(): queue(), mutex(), condition() {};
        ~Queue() {};

        void Enqueue(T& t)
        {
            std::lock_guard<std::mutex> lock(mutex);
            queue.push(std::move(t));
            condition.notify_one();
        }

        const T Dequeue()
        {
            std::unique_lock<std::mutex> lock(mutex);
            if (!queue.empty())
            {
                T entry = queue.front();
                queue.pop();
                return entry;
            }
            else
            {
                return T();
            }
        }

        const bool Empty() const
        {
            return queue.empty();
        }

    private:

        // Data
        std::queue<T> queue;
        mutable std::mutex mutex;
        std::condition_variable condition;
};

#endif // QUEUE_H
