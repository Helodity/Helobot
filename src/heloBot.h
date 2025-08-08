#pragma once

#define DPP_CORO

#include <dpp/dpp.h>
#include "config.h"

extern BotConfig CONFIG_FILE;
extern dpp::cluster botCluster;
extern std::map<std::string, std::function<dpp::task<void>(const dpp::slashcommand_t&)>> registered_commands;