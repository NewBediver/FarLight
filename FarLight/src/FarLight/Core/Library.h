#pragma once

#include <unordered_map>

#include "FarLight/LogSystem/Logger.h"
#include "Core.h"

namespace FarLight
{
	template<typename T>
	class FARLIGHT_API Library
	{
	public:
		void Add(const std::string& name, const Ref<T>& entity)
		{
			FL_CORE_ASSERT(!IsExist(name), "Library contains the desired entity!");
			_map[name] = entity;
		}

		void Erase(const std::string& name, const Ref<T>& entity)
		{
			FL_CORE_ASSERT(IsExist(name), "Library doesn't contains the desired entity!");
			_map.erase(name);
		}

		const Ref<T>& Get(const std::string& name) const
		{
			FL_CORE_ASSERT(IsExist(name), "Library doesn't contains the desired entity!");
			return _map.find(name)->second;
		}

		bool IsExist(const std::string& name) const
		{
			return _map.find(name) != _map.end();
		}

	private:
		std::unordered_map<std::string, Ref<T>> _map;
	};
}