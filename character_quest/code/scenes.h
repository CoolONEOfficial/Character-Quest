#ifndef _FILE_SCENES_
#define _FILE_SCENES_

#include "screen.h"
#include "fonts.h"
#include "scene.h"

#include <string>
#include <map>

using namespace std;

// --------------------------- Scenes ---------------------------

map <string, Scene*> scene;

// Set
void initScenes()
{
    // --------------------------- Screensaver ---------------------------

    scene["screensaver"] = new Scene( { new Label("CoolONE", scrDWidth/8, scrDHeight/8, scrDWidth/4*3-scrDWidth/8, scrDHeight/2-scrDHeight/8, fontOld),
                                        new Label("presents", scrDWidth/4, scrDHeight/2, scrDWidth/8*7 - scrDWidth/4, scrDHeight/2-scrDHeight/8, fontFuture) } );

    // --------------------------- Main ---------------------------

    scene["main"] = new Scene( { new Label("Character", 0, 0, scrDWidth, scrDHeight/3, fontFuture),
                                 new Label("Quest", 0, scrDHeight/3, scrDWidth, scrDHeight/3, fontOld) },

                               { new Button("Play"),
                                 new Button("Continue") },
                               true, scrDHeight/6*5 );

    // --------------------------- Exit ---------------------------

    scene["mainExit"] = new Scene( { new Label("Really?", 0, 0, scrDWidth, scrDHeight/3*2, fontFuture) },

                                   { new Button("No", scrDWidth/3, scrDHeight/6*5),
                                     new Button("Yes", scrDWidth/3*2, scrDHeight/6*5) },
                                   true, scrDHeight/6*5 );

    // --------------------------- Saves ---------------------------

    scene["saves"] = new Scene( { new Label("Saves", scrDWidth/6, scrDHeight/3*2/6, scrDWidth/3*2, scrDHeight/3+scrDHeight/3/3, fontFuture) },

                                { new Button("Slot 1", scrDWidth/6, scrDHeight/6*5),
                                  new Button("Slot 2", scrDWidth/6*2, scrDHeight/6*5),
                                  new Button("Slot 3", scrDWidth/6*3, scrDHeight/6*5),
                                  new Button("Slot 4", scrDWidth/6*4, scrDHeight/6*5),
                                  new Button("Delete", scrDWidth/6*5, scrDHeight/6*5) },
                                true, scrDHeight/6*5 );

    // --------------------------- New Game ---------------------------

    scene["savesNew"] = new Scene( { new Label("Your name?", 0, 0, scrDWidth, scrDHeight/2, fontFuture),
                                     new Label("", 0, scrDHeight/2, scrDWidth, scrDHeight/2, fontOld, false) } );

    // --------------------------- Game ---------------------------

    scene["game"] = new Scene();

    // --------------------------- Game Pause ---------------------------

    scene["gamePause"] = new Scene( { new Label("Pause", 0, 1, scrDWidth, scrDHeight/3-2, fontFuture) },

                                    { new Button("Save", scrDWidth/3, scrDHeight/6*5),
                                      new Button("Main", scrDWidth/3*2, scrDHeight/6*5) },
                                    true, scrDHeight/6*5 );

    // --------------------------- Game Pause Exit ---------------------------

    scene["gamePauseExit"] = new Scene( { new Label("You not saved!", 0, 1, scrDWidth, scrDHeight/3-2, fontFuture) },

                                        { new Button("Save and exit", scrDWidth/3, scrDHeight/6*5),
                                          new Button("Exit unsaved", scrDWidth/3*2, scrDHeight/6*5) },
                                        true, scrDHeight/6*5 );
}

#endif // _FILE_SCENES_
