#include "commandUtils.h"
#include "../heloBot.h"

void registerCommands(std::vector<dpp::slashcommand> commands, dpp::snowflake* guildID = nullptr) {
    if(guildID) {
        botCluster.guild_bulk_command_create(commands, *guildID);
    } else {
        botCluster.global_bulk_command_create(commands);
    }
}

dpp::slashcommand createCommand(
    std::string name, 
    std::string description, 
    std::function<dpp::task<void>(const dpp::slashcommand_t&)> callback
) {
    registered_commands.insert({name, callback});
    dpp::slashcommand newCommand(name, description, botCluster.me.id);
    return newCommand;
}