--Q3 - Fix or improve the name and the implementation of the below method
function do_sth_with_PlayerParty(playerId, membername)
player = Player(playerId)
local party = player:getParty()

for k,v in pairs(party:getMembers()) do
if v == Player(membername) then
party:removeMember(Player(membername))
end
end
end

--Solution

function removeMemberFromPlayersIdsParty(playerId, memberName)
    local player = getPlayerById(playerId)  --assume existing "getPlayerById" function
    if not player then
        print("Player not found")
        return
    end
    local party = player:getParty() --get party of playerId
    local members = party:getMembers()  --get party members

    for i,member in ipairs(members) do    --iterate through party members
        if member::getName() == memberName then
            party:removeMember(member)
        end
    end
end