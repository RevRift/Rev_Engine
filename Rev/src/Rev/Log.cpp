#include "revpch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Rev {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		try {
			// start color scheme, time stamp, name of logger, log message, end color scheme
			spdlog::set_pattern("%^[%T] %n: %v%$");
			// got to https://github.com/gabime/spdlog/wiki/3.-Custom-formatting for more details

			s_CoreLogger = spdlog::stdout_color_mt("REV");
			s_CoreLogger->set_level(spdlog::level::trace);

			s_ClientLogger = spdlog::stdout_color_mt("APP");
			s_ClientLogger->set_level(spdlog::level::trace);
		}
		catch (const spdlog::spdlog_ex& ex)
		{
			std::cout << "Log Initialisation failed: %s" << ex.what() << "\n";
		}
	}
}