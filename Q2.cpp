//Q2 - Fix or improve the implementation of the below method

function printSmallGuildNames(memberCount)
//this method is supposed to print names of all guilds that have less than memberCount max members
local selectGuildQuery = "SELECT name FROM guilds WHERE max_members < %d;"
local resultId = db.storeQuery(string.format(selectGuildQuery, memberCount))
local guildName = result.getString("name")
print(guildName)
end

//Solution

//Include necessary libraries
#include <iostream>
#include <string>
using namespace std;

void printSmallGuildNames(int memberCount) {
    string selectGuildQuery = "SELECT name FROM guilds WHERE max_members < %d;"
    local queryResult = db.storeQuery(string.format(selectGuildQuery, memberCount));
    if (queryResult) {  //Check presense of query result first
        local name = result.getString(queryResult, "name");
        print(name)
        result.free(queryResult)
    }
}