#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

namespace FarLight
{
    class GlobalManager
        : public Singleton<GlobalManager>
    {
    public:
        void GlobalInitialization() const noexcept;
        void GlobalTermination() const noexcept;

    private:
        void InitializeLogger() const noexcept;
        void InitializeProfiler() const noexcept;
        void InitializeFileSystem() const noexcept;
        void InitializeConfiguration() const noexcept;
        void InitializeResource() const noexcept;
        void InitializeInput() const noexcept;
        void InitializeApplication() const noexcept;
        void InitializeRender() const noexcept;
        void InitializeScene() const noexcept;

        void TerminateLogger() const noexcept;
        void TerminateProfiler() const noexcept;
        void TerminateFileSystem() const noexcept;
        void TerminateConfiguration() const noexcept;
        void TerminateResource() const noexcept;
        void TerminateInput() const noexcept;
        void TerminateApplication() const noexcept;
        void TerminateRender() const noexcept;
        void TerminateScene() const noexcept;
    };
}
