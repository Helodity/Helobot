#pragma once

#include <dpp/dpp.h>

void registerCommands(
    std::vector<dpp::slashcommand> commands, 
    dpp::snowflake* guildID
);

dpp::slashcommand createCommand(
    std::string name, 
    std::string description, 
    std::function<dpp::task<void>(const dpp::slashcommand_t&)> callback
);