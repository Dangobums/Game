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
struct object
{
    int x;
    int y;
    int size = 20;
    void render(SDL_Renderer *renderer)
    {
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = size;
        filled_rect.h = size;
        SDL_SetRenderDrawColor(renderer , 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &filled_rect);
    }
    void moveup()
    {
        y -= 5;
    }
    void movedown()
    {
        y += 5;
    }
    void moveleft()
    {
        x -= 5;
    }
    void moveright()
    {
        x += 5;
    }
    bool inside (int maxX, int maxY, int maxW, int maxH)
    {
        return (maxX <= x && maxY <=y && x + size <=maxW && y + size <= maxH );
    }
};
int main(int argc,char* argv[])
{
    SDL_Event e;
    SDL_Window *window = nullptr;
    //SDL_Texture *imageSurface = nullptr;
    SDL_Renderer* renderer;
    //SDL_Renderer *rendertarget = nullptr;
    //
    SDL_Init(SDL_INIT_VIDEO);


    int imgFlag = IMG_INIT_PNG;
    IMG_Init(imgFlag);
    if(!(IMG_Init(imgFlag) & imgFlag))
        cout << "error" << IMG_GetError() << endl;

    window = SDL_CreateWindow(SCREENTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
    //rendertarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    //imageSurface = Loadtexture("mainscreen.png", rendertarget);
    //SDL_RenderClear(rendertarget);
    //SDL_RenderCopy(rendertarget, imageSurface , NULL , NULL);
    object box;
    box.x = 100;
    box.y = 100;
    while (box.inside(0 , 0 ,SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        SDL_Delay(10);
        if (SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_ESCAPE: break;
        		case SDLK_LEFT: box.moveleft();
        			break;
            	case SDLK_RIGHT: box.moveright();
            		break;
            	case SDLK_DOWN: box.movedown();
					break;
            	case SDLK_UP: box.moveup();
            		break;
        		default: break;
			}
            }

        SDL_SetRenderDrawColor(renderer , 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        box.render(renderer);
        SDL_RenderPresent(renderer);
    }

    //SDL_RenderPresent(rendertarget);
    input();



    SDL_DestroyWindow(window);
    //SDL_DestroyTexture(imageSurface);
    //SDL_DestroyRenderer(rendertarget);
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    //imageSurface = nullptr;
    window = nullptr;
    //rendertarget = nullptr;
    SDL_Quit();

    //quitSDL(window, renderer);
    return 0;
}

