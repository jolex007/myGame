#pragma once

enum Key {
    LeftArrow,
    RightArrow,
    UpArrow,
    DownArrow,
    WKey,
    AKey,
    SKey,
    DKey,
    SpaceKey,
    EnterKey,
    EscKey
};

struct Request
{
    Key key;
};