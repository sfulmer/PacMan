#pragma once

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
                    PacManApp &mRefApp;
                protected:
                    PacManApp &getApplication();
                public:
                    PacManController(PacManApp &refApp);
                    void exit();
                };
            }
        }
    }
}
