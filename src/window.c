#include "../headers/header.h"
#include <SDL2/SDL.h>   // Ensure SDL2 headers are included
#include <stdio.h>      // For fprintf
#include <stdlib.h>     // For malloc and free

static SDL_Renderer *renderer;
static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
static SDL_Window *window;

/**
 * initializeWindow - Initialize window to display the maze
 * Return: true in case of success, false if it fails
 */
bool initializeWindow(void)
{
    SDL_DisplayMode display_mode;
    int fullScreenWidth, fullScreenHeight;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    }
    SDL_GetCurrentDisplayMode(0, &display_mode);
    fullScreenWidth = display_mode.w;
    fullScreenHeight = display_mode.h;
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        fullScreenWidth,
        fullScreenHeight,
        SDL_WINDOW_BORDERLESS
    );
    if (!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return false;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    /* Allocate the total amount of bytes in memory to hold our color buffer */
    colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);
    if (!colorBuffer)
    {
        fprintf(stderr, "Error allocating memory for color buffer.\n");
        destroyWindow();  // Clean up before returning
        return false;
    }

    /* Create an SDL_Texture to display the color buffer */
    colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                           SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!colorBufferTexture)
    {
        fprintf(stderr, "Error creating SDL texture.\n");
        destroyWindow();  // Clean up before returning
        return false;
    }

    return true;
}

/**
 * destroyWindow - destroy window when the game is over
 */
void destroyWindow(void)
{
    if (colorBuffer)
    {
        free(colorBuffer);
    }
    if (colorBufferTexture)
    {
        SDL_DestroyTexture(colorBufferTexture);
    }
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

/**
 * clearColorBuffer - clear buffer for every frame
 * @color: color buffer
 */
void clearColorBuffer(color_t color)
{
    int i;
    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
    {
        colorBuffer[i] = color;
    }
}

/**
 * renderColorBuffer - render buffer for every frame
 */
void renderColorBuffer(void)
{
    SDL_UpdateTexture(
        colorBufferTexture,
        NULL,
        colorBuffer,
        (int)(SCREEN_WIDTH * sizeof(color_t))
    );
    SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

/**
 * drawPixel - assign a color to each pixel
 * @x: x pixel coordinate
 * @y: y pixel coordinate
 * @color: pixel color
 */
void drawPixel(int x, int y, color_t color)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        colorBuffer[(SCREEN_WIDTH * y) + x] = color;
    }
}
