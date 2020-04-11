#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_events.h>
#include<SDL_image.h>
using namespace std;
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREENTITLE "GAME"
SDL_Texture *Loadtexture (string filepath,SDL_Renderer *rendertarget)
{
    SDL_Texture *Texture = nullptr;
    SDL_Surface *surface = IMG_Load(filepath.c_str());
    if (surface == NULL)
    {
        cout << "optimized fail" << endl;
    }
    else
    {
        Texture = SDL_CreateTextureFromSurface(rendertarget, surface);
    }
    SDL_FreeSurface(surface);
    return Texture;
}

bool running = true;
void input()
{
    SDL_Event e;
    while (running)
    {
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_F1)
        {
            running = false;
        }
    }
    SDL_Delay(100);
    }
}
int main(int argc,char* argv[])
{
    SDL_Window *window = nullptr;
    SDL_Texture *imageSurface = nullptr;
    SDL_Renderer *rendertarget = nullptr;
    //
    SDL_Init(SDL_INIT_VIDEO);


    int imgFlag = IMG_INIT_PNG;
    IMG_Init(imgFlag);
    if(!(IMG_Init(imgFlag) & imgFlag))
        cout << "error" << IMG_GetError() << endl;

    window = SDL_CreateWindow(SCREENTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
    rendertarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    imageSurface = Loadtexture("mainscreen.png", rendertarget);
    SDL_RenderClear(rendertarget);
    SDL_RenderCopy(rendertarget, imageSurface , NULL , NULL);
    SDL_RenderPresent(rendertarget);
    input();



    SDL_DestroyWindow(window);
    SDL_DestroyTexture(imageSurface);
    SDL_DestroyRenderer(rendertarget);
    imageSurface = nullptr;
    window = nullptr;
    rendertarget = nullptr;
    SDL_Quit();

    //quitSDL(window, renderer);
    return 0;
}

