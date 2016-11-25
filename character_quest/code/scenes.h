#ifndef _FILE_SCENES_
#define _FILE_SCENES_

#include "screen.h"
#include "rect.h"
#include "fonts.h"
#include "scene.h"

#include <string>
#include <map>

using namespace std;

// --------------------------- Scenes ---------------------------

map <string, Scene*> scene;

// Set
void initScenes(WINDOW* screen_)
{
    // --------------------------- Screensaver ---------------------------

    scene["screensaver"] = new Scene( { new AnimationLabel("CoolONE", font["old"], Rect<ScreenCoord>(ScreenCoord(0, 0),
                                                                                     ScreenCoord(screenWidthDefault, screenHeightDefault/2))),

                                        new AnimationLabel("presents", font["future"], Rect<ScreenCoord>(ScreenCoord(0, screenHeightDefault/2),
                                                                                         ScreenCoord(screenWidthDefault, screenHeightDefault))) },

                                        {},

                                        screen_ );

    // --------------------------- Main ---------------------------

    scene["main"] = new Scene( { new AnimationLabel("Character", font["future"], Rect<ScreenCoord>(ScreenCoord(0, 0),
                                                                                   ScreenCoord(screenWidthDefault, screenHeightDefault/3))),

                                 new AnimationLabel("Quest", font["old"], Rect<ScreenCoord>(ScreenCoord(0, screenHeightDefault/3),
                                                                            ScreenCoord(screenWidthDefault, screenHeightDefault/3*2))) },

                               { new Button("Play"),
                                 new Button("Continue") },

                               screen_,
                               true, screenHeightDefault/6.0f*5 );

    // --------------------------- Exit ---------------------------

    scene["mainExit"] = new Scene( { new AnimationLabel("Really?", font["future"], Rect<ScreenCoord>(ScreenCoord(0, 0),
                                                                                     ScreenCoord(screenWidthDefault, screenHeightDefault/3*2))) },

                                   { new Button("No", ScreenCoord(screenWidthDefault/3, screenHeightDefault/6*5)),
                                     new Button("Yes", ScreenCoord(screenWidthDefault/3*2, screenHeightDefault/6*5)) },

                                   screen_,
                                   true, screenHeightDefault/6.0f*5 );

    // --------------------------- Saves ---------------------------

    scene["saves"] = new Scene( { new AnimationLabel("Saves", font["future"], Rect<ScreenCoord>(ScreenCoord(screenWidthDefault/6, screenHeightDefault/3*2/6),
                                                                                ScreenCoord(screenWidthDefault/6*5, screenHeightDefault/3*2/6*5))) },

                                { new Button("Slot 1", ScreenCoord(screenWidthDefault/6, screenHeightDefault/6*5)),
                                  new Button("Slot 2", ScreenCoord(screenWidthDefault/6*2, screenHeightDefault/6*5)),
                                  new Button("Slot 3", ScreenCoord(screenWidthDefault/6*3, screenHeightDefault/6*5)),
                                  new Button("Slot 4", ScreenCoord(screenWidthDefault/6*4, screenHeightDefault/6*5)),
                                  new Button("Delete", ScreenCoord(screenWidthDefault/6*5, screenHeightDefault/6*5)) },

                                screen_,
                                true, screenHeightDefault/6.0f*5 );

    // --------------------------- New Game ---------------------------

    scene["savesNew"] = new Scene( { new AnimationLabel("Your name?", font["future"], Rect<ScreenCoord>(ScreenCoord(0, 0),
                                                                                        ScreenCoord(screenWidthDefault, screenHeightDefault/2))),
                                     new AnimationLabel("", font["old"], Rect<ScreenCoord>(ScreenCoord(0, screenHeightDefault/2),
                                                                           ScreenCoord(screenWidthDefault, screenHeightDefault))) },

                                    {},

                                    screen_ );

    // --------------------------- Game ---------------------------

    scene["game"] = new Scene();

    // --------------------------- Game Pause ---------------------------

    scene["gamePause"] = new Scene( { new AnimationLabel("Pause", font["future"], Rect<ScreenCoord>(ScreenCoord(0, 1),
                                                                                    ScreenCoord(screenWidthDefault, screenHeightDefault/3-1))) },

                                    { new Button("Save", ScreenCoord(screenWidthDefault/3, screenHeightDefault/6*5)),
                                      new Button("Main", ScreenCoord(screenWidthDefault/3*2, screenHeightDefault/6*5)) },

                                    screen_,
                                    true, screenHeightDefault/6*5 );

    // --------------------------- Game Pause Exit ---------------------------

    scene["gamePauseExit"] = new Scene( { new AnimationLabel("You not saved!", font["future"], Rect<ScreenCoord>(ScreenCoord(0, 1),
                                                                                                 ScreenCoord(screenWidthDefault, screenHeightDefault/3-1))) },

                                        { new Button("Save and exit", ScreenCoord(screenWidthDefault/3, screenHeightDefault/6*5)),
                                          new Button("Exit unsaved", ScreenCoord(screenWidthDefault/3*2, screenHeightDefault/6*5)) },

                                        screen_,
                                        true, screenHeightDefault/6*5 );
}

#endif // _FILE_SCENES_
