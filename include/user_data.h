#pragma once

enum class UserDataType
{
    PLAYER_BOX,
    PLAYER_FOOT,
    PLATFORM,
    NONE,
    FLAG
};

struct UserData
{
    UserDataType userData = UserDataType::NONE;
};