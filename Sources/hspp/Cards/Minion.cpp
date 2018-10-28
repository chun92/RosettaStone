// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <hspp/Cards/Minion.h>

namespace Hearthstonepp
{
Minion::Minion(Card& card) : Character(card)
{
    CheckAbilities();
}

void Minion::SetAbility(GameTag tag, bool flag)
{
    Character::SetAbility(tag, flag);

    CheckAbilities();
}

void Minion::CheckAbilities()
{
    if (gameTags[GameTag::CHARGE] == 1 && attackableCount == 0)
    {
        attackableCount = 1;
    }
    else if (gameTags[GameTag::WINDFURY] == 1 && attackableCount == 1)
    {
        attackableCount = 2;
    }
}
}  // namespace Hearthstonepp