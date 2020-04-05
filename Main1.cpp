#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_events.h>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
string SCREEN_TITLE = "GAME";
/*void logSDLError(ostream& os,const string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(cout, "SDL_Init", true);

    window = SDL_CreateWindow(SCREEN_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(cout, "CreateWindow", true);


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}*/
void SwitchImage(SDL_Surface *windowSurface)
{
    bool isRunning = true;
    SDL_Surface *image1 = nullptr;
    SDL_Surface *image2 = nullptr;
    SDL_Surface *currentImage = nullptr;
    image1 = SDL_LoadBMP("Test.bmp");
    image2 = SDL_LoadBMP("Test1.bmp");
    currentImage = image1;
    SDL_Event ev;
    while (isRunning)
    {
        while (SDL_PollEvent(&ev) != 0)
        {

        if (ev.type == SDL_KEYDOWN)
        {
            switch(ev.key.keysym.sym)
            {
                case SDLK_1:
                    currentImage = image1;
                    break;
                case SDLK_2:
                    currentImage = image2;
                    break;
            }
        }
        }
    }
    SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
}
void waitUntilKeyPressed()
{
    bool isRunning = true;
    SDL_Event e;
    while (isRunning)
    {
        while (SDL_PollEvent(&e) !=0)
        {
            if (e.type == SDL_QUIT)
            {
                cout << "QUIT" << endl;
                isRunning = false;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                    switch(e.key.keysym.sym)
                    {
                        case SDLK_F1:
                            cout << "QUIT" <<endl;
                            return;

                    }


            }
        }
        SDL_Delay(100);
    }
}
int main(int argc,char* argv[])
{
    SDL_Window *window = nullptr;
    SDL_Surface *winowSurface = nullptr;
    SDL_Surface *imageSurface = nullptr;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Fail" << SDL_GetError() << endl;
    }
    else
    {
        window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Window creation error" << SDL_GetError() << endl;
        }
        else
        {
            //Window Create
            imageSurface = SDL_LoadBMP("Test1.bmp");
            winowSurface = SDL_GetWindowSurface(window);
            SDL_BlitSurface(imageSurface, NULL ,winowSurface, NULL);
            SDL_UpdateWindowSurface(window);
            waitUntilKeyPressed();


        }
    }
    SDL_FreeSurface(imageSurface);
    imageSurface = nullptr;
    SDL_DestroyWindow(window);
    SDL_Quit();

    //quitSDL(window, renderer);
    return 0;
}

