#pragma once

#include <unordered_map>

#include "FarLight/Core/Core.h"
#include "FarLight/LogSystem/Logger.h"

namespace FarLight
{
	template<typename T>
	class Library
	{
	public:
		void Add(const std::string& name, const Ref<T>& entity)
		{
			FL_CORE_ASSERT(!IsExist(name), "Library already contains the desired entity!");
			m_EntityMap[name] = entity;
		}

		void Erase(const std::string& name, const Ref<T>& entity)
		{
			auto it = m_EntityMap.find(name);
			if (it != m_EntityMap.end()) m_EntityMap.erase(it);
		}

		const Ref<T>& Get(const std::string& name) const
		{
			FL_CORE_ASSERT(IsExist(name), "Library doesn't contains the desired entity!");
			return m_EntityMap.find(name)->second;
		}

		bool IsExist(const std::string& name) const
		{
			return m_EntityMap.find(name) != m_EntityMap.end();
		}

	private:
		std::unordered_map<std::string, Ref<T>> m_EntityMap;
	};
}