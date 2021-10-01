#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Rev {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
	// color, time stamp, name of logger, log message
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("REV");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_CoreLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}