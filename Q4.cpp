//Q4 - Assume all method calls work fine. Fix the memory leak issue in below method

void Game::addItemToPlayer(const std::string &recipient, uint16_t itemId)
{
    Player *player = g_game.getPlayerByName(recipient);
    if (!player)
    {
        player = new Player(nullptr);
        if (!IOLoginData::loadPlayerByName(player, recipient))
        {
            return;
        }
    }

    Item *item = Item::CreateItem(itemId);
    if (!item)
    {
        return;
    }

    g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREEVER, FLAG_NOLIMIT);

    if (player->isOffline())
    {
        IOLoginData::savePlayer(player);
    }
}

// Solution

void Game::addItemToPlayer(const std::string &recipient, uint16_t itemId)
{
    Player *player = g_game.getPlayerByName(recipient);
    bool newPlayerCreated = false;  //Track if we need to allocate memory for player variable
    if (!player)
    {
        player = new Player(nullptr);   //Request for dynamic memory allocation for player variable
        newPlayerCreated = true;    //New player is created so track with bool
        if (!IOLoginData::loadPlayerByName(player, recipient))
        {
            delete player;  //Need to delete player
            return;
        }
    }

    Item *item = Item::CreateItem(itemId);
    if (!item)
    {
        if (newPlayerCreated) {
            delete player;  //Because function can exit if item isn't created, we need to delete player
        }
        return;
    }

    g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREEVER, FLAG_NOLIMIT);

    if (player->isOffline())
    {
        IOLoginData::savePlayer(player);
    }

    if (newPlayerCreated) {
        delete player;  //Lastly, delete player if we had to allocate memory to it.
    }
}