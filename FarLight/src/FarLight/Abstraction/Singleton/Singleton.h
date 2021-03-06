#pragma once

#include <cassert>

namespace FarLight
{
    template<typename T>
    class Singleton
    {
    public:
        virtual ~Singleton() noexcept = default;

        Singleton(const Singleton<T>&) = delete;
        Singleton(Singleton<T>&&) = delete;
        Singleton& operator=(const Singleton<T>&) = delete;
        Singleton& operator=(Singleton<T>&&) = delete;

        static void Create() noexcept
        {
            if (s_Instance == nullptr)
                s_Instance = new T();
        }

        static void Destroy() noexcept
        {
            delete s_Instance;
            s_Instance = nullptr;
        }

        static T& GetInstance() noexcept
        {
            assert(s_Instance != nullptr);
            return (*s_Instance);
        }

        static T* GetInstancePtr() noexcept
        {
            return s_Instance;
        }

    protected:
        explicit Singleton() noexcept
        {
            assert(s_Instance == nullptr);
            s_Instance = static_cast<T*>(this);
        }

    private:
        inline static T* s_Instance = nullptr;
    };
}
