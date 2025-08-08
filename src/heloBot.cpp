#include "heloBot.h"
#include "utils/commandUtils.h"
#include "commands.h"

BotConfig CONFIG_FILE = BotConfig();
dpp::cluster botCluster = dpp::cluster(CONFIG_FILE.BotToken);
std::map<std::string, std::function<dpp::task<void>(const dpp::slashcommand_t&)>> registered_commands;

int main(int argc, char const *argv[])
{
    /* Output simple log messages to stdout */
    botCluster.on_log(dpp::utility::cout_logger());

    /* Handle slash command */
    botCluster.on_slashcommand([](const dpp::slashcommand_t& event) -> dpp::task<void> {
        std::string cmdName = event.command.get_command_name();
        if (auto search = registered_commands.find(cmdName); search != registered_commands.end()){
            co_await search->second(event);
        }
    });

    /* Register slash command here in on_ready */
    botCluster.on_ready([](const dpp::ready_t& event) {
        /* Wrap command registration in run_once to make sure it doesnt run on every full reconnection */
        if (dpp::run_once<struct register_bot_commands>()) {

            botCluster.global_bulk_command_delete(); //Clear existing commands

            std::vector<dpp::slashcommand> commandList{
                createCommand("ping", "Ping pong!", pingCommand),
                createCommand("scp", "Generate a random SCP article", scpCommand),
                createCommand("how", "find out how something you are", howCommand)
                    .add_option(dpp::command_option(dpp::co_string, "what", "how what you are", true)),
                createCommand("8ball", "ask the ball a question", eightBallCommand)
                    .add_option(dpp::command_option(dpp::co_string, "question", "Question to ask", true))
            };
            registerCommands(commandList, &CONFIG_FILE.DebugGuild);
        }
    });

    //TODO: https://dpp.dev/subcommands.html

    /* Start the bot */
    botCluster.start(dpp::st_wait);

    return 0;
}
