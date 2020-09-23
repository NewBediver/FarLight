#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "FarLight/Core/Core.h"

namespace FarLight
{
    template<typename T>
    class Queue
    {
    public:
        virtual ~Queue() noexcept = default;

        void Push(T&& elm) noexcept
        {
            {
                std::scoped_lock<std::mutex> lock(m_Mutex);
                m_Queue.push(std::move(elm));
            }
            m_WaitForRead.notify_one();
        }

        T Pop() noexcept
        {
            std::unique_lock<std::mutex> lock(m_Mutex);
            while (m_Queue.size() == 0)
                m_WaitForRead.wait(lock);
            FL_CORE_ASSERT(!m_Queue.empty(), "Collection is empty!");

            T ret = std::move(m_Queue.front());
            m_Queue.pop();
            lock.unlock();
            return ret;
        }

        size_t GetSize() const noexcept
        {
            std::scoped_lock<std::mutex> lock(m_Mutex);
            return m_Queue.size();
        }

    private:
        mutable std::mutex m_Mutex;
        std::condition_variable m_WaitForRead;

        std::queue<T> m_Queue;
    };
}

