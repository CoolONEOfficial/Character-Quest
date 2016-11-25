#include "screenrect.h"

ScreenRect::ScreenRect(pair<Coord *, Coord *> coord_, WINDOW *screen_)
{
    // Coord
    coord = coord_;

    assert(dynamic_cast<ScreenCoord*>(coord_.first) != nullptr && ("ScreenCoord*, not Coord*" || true));
    assert(dynamic_cast<ScreenCoord*>(coord_.second) != nullptr && ("ScreenCoord*, not Coord*" || true));

    // Screen
    initScreen(screen_);
}

ScreenRect::ScreenRect(Coord *coordFirst_, Coord *coordSecond_, WINDOW *screen_)
    : ScreenRect(make_pair(coordFirst_, coordSecond_), screen_)
{
}

pair<ScreenCoord *, ScreenCoord *> ScreenRect::screenCoord()
{
    // Screen coord

    ScreenCoord* coordFirst = dynamic_cast<ScreenCoord*>(coord.first);
    ScreenCoord* coordSecond = dynamic_cast<ScreenCoord*>(coord.second);

    if(coordFirst == nullptr)
    {
        qDebug()<<"First coord conversion equal null!"<<endl;
    }
    else
    {
        qDebug()<<"First coord ok!"<<endl;
    }

    if(coordSecond == nullptr)
    {
        qDebug()<<"Second coord conversion equal null!"<<endl;
    }
    else
    {
        qDebug()<<"Second coord ok!"<<endl;
    }

    pair<screenCoord*,Screen>

    return make_pair(coordFirst, coordSecond);
}

void ScreenRect::initScreen(WINDOW *screen_)
{
    // Init screen

    screenCoord().first->initScreen(screen_);
    screenCoord().second->initScreen(screen_);
}
