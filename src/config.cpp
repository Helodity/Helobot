#include <dpp/dpp.h>
#include "config.h"
#include <sstream>

BotConfig::BotConfig() {
    using json = nlohmann::json;
    json configdocument;
    std::ifstream configfile("build/config.json");
    configfile >> configdocument;
    
    BotToken = configdocument["token"];
    long guildID = configdocument["debugGuild"];
    if(guildID != -1) {
        DebugGuild = dpp::snowflake(guildID);
    } else {
        DebugGuild = nullptr;
    }
}