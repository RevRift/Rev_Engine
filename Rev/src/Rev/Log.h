#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rev {

	class REV_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
							
	private:				
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};						
							
}							

// Core log macros
#define REV_CORE_TRACE(...)      ::Rev::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define REV_CORE_INFO(...)      ::Rev::Log::GetCoreLogger()->info(__VA_ARGS__);
#define REV_CORE_WARN(...)     ::Rev::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define REV_CORE_ERROR(...)     ::Rev::Log::GetCoreLogger()->error(__VA_ARGS__);
#define REV_CORE_FATAL(...)     ::Rev::Log::GetCoreLogger()->fatal(__VA_ARGS__);
	
// Client log macros
#define REV_TRACE(...)          ::Rev::Log::GetClientLogger()->trace(__VA_ARGS__);
#define REV_INFO(...)	        ::Rev::Log::GetClientLogger()->info(__VA_ARGS__);
#define REV_WARN(...)	        ::Rev::Log::GetClientLogger()->warn(__VA_ARGS__);
#define REV_ERROR(...)	        ::Rev::Log::GetClientLogger()->error(__VA_ARGS__);
#define REV_FATAL(...)	        ::Rev::Log::GetClientLogger()->fatal(__VA_ARGS__);

