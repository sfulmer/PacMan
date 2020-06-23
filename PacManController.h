#pragma once

#include "GameModel.h"

using net::draconia::games::pacman::model::GameModel;

namespace net
{
    namespace draconia
    {
        namespace games
        {
            namespace pacman
            {
                class PacManApp;

                class PacManController
                {
                    GameModel mObjModel;
                    PacManApp &mRefApp;
                protected:
                    PacManApp &getApplication();
                public:
                    PacManController(PacManApp &refApp);
                    void exit();
                    GameModel &getModel();
                };
            }
        }
    }
}
