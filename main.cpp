#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_events.h>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string SCREEN_TITLE = "GAME";
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(SCREEN_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc,char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    // Your drawing code here
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 20, 120, 150);   // white
    SDL_RenderDrawPoint(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
    SDL_RenderDrawLine(renderer, 90, 90, 200, 200);
    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH - 300;
    filled_rect.y = SCREEN_HEIGHT - 150;
    filled_rect.w = 320;
    filled_rect.h = 100;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(renderer, &filled_rect);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    SDL_RenderPresent(renderer);
    // use SDL_RenderPresent(renderer) to show it

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
