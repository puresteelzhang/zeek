// See the file "COPYING" in the main distribution directory for copyright.

#include "MySQL.h"
#include "plugin/Plugin.h"
#include "analyzer/Component.h"

namespace zeek::plugin::detail::Zeek_MySQL {

class Plugin : public zeek::plugin::Plugin {
public:
	zeek::plugin::Configuration Configure() override
		{
		AddComponent(new zeek::analyzer::Component("MySQL", zeek::analyzer::mysql::MySQL_Analyzer::Instantiate));
		zeek::plugin::Configuration config;
		config.name = "Zeek::MySQL";
		config.description = "MySQL analyzer";
		return config;
		}
} plugin;

} // namespace zeek::plugin::detail::Zeek_MySQL
