#pragma once

#include "heloBot.h"

dpp::task<void> pingCommand(const dpp::slashcommand_t& event);
dpp::task<void> scpCommand(const dpp::slashcommand_t& event);
dpp::task<void> howCommand(const dpp::slashcommand_t& event);
dpp::task<void> eightBallCommand(const dpp::slashcommand_t& event);