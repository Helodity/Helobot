#include "commands.h"
#include "utils/mathUtils.h"
#include "utils/generalUtils.h"
#include <format>

using namespace std;

dpp::task<void> pingCommand(const dpp::slashcommand_t& event) {
    event.reply("Pong!");
    co_return;
}

dpp::task<void> scpCommand(const dpp::slashcommand_t& event) {
    int number = generateRandomInt(1, 2000);
    string link = "http://www.scpwiki.com/scp-";

    int numLength = to_string(number).length();
    for (int i = numLength; i < 3; i++)
    {
        link += "0";
    }
    link += to_string(number);

    event.reply(link);
    co_return;
}

dpp::task<void> howCommand(const dpp::slashcommand_t& event){
    string output = format(
        "You are {0}% {1}.", 
        to_string(generateRandomInt(0,100)),
        get<string>(event.get_parameter("what"))
    );
    event.reply(output);
    co_return;
}


dpp::task<void> eightBallCommand(const dpp::slashcommand_t& event){
    string thinkStr = getRandomFromList<string>(
        vector<string>{
            "ponders",
            "imagines",
            "thinks",
            "judges",
            "reckons"
        }
    );
    string firstMsg = format(
        "{0} questions the ball. It {1}...", 
        event.command.usr.username,
        thinkStr
    );
    event.reply(firstMsg);

    co_await botCluster.co_sleep(generateRandomInt(2,5));

    string resultStr = getRandomFromList<string>(
        vector<string>{
            "likely",
            "unlikely",
            "chances say yes",
            "probably not",
            "ask again"
        }
    );

    string secondMessage = format(
        "{0} asks: \"{1}\" \nThe ball says {2}.", 
        event.command.usr.username,
        get<string>(event.get_parameter("question")),
        resultStr
    );
    event.edit_response(secondMessage);
    co_return;
}