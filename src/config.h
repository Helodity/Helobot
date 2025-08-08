#pragma once

struct BotConfig {
    std::string BotToken;
    dpp::snowflake DebugGuild;

    BotConfig();
};