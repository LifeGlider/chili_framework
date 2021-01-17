#pragma once

#include "Graphics.h"

class Crosshair
{
public:
    Crosshair(int xPosInput, int yPosInput, int colorRedInput, int colorGreenInput, int colorBlueInput)
    {
        xPos = xPosInput;
        yPos = yPosInput;
        colorRed = colorRedInput;
        colorGreen = colorGreenInput;
        colorBlue = colorBlueInput;
        hitBox[0] = xPos - 2;
        hitBox[1] = xPos + 3;
        hitBox[2] = yPos - 2;
        hitBox[3] = yPos + 3;
    }
    bool BorderCheck(int pixel_pos, int screen_border) const;
    void UpdatePosition(const int xPosition, const int yPosition);
    void UpdateHitbox();
    void UpdateColor(int red, int green, int blue);
    void Draw(Graphics& gfx) const;
    int hitBox[4];

private:
    int xPos;
    int yPos;
    int colorRed;
    int colorGreen;
    int colorBlue;
    static const int pixelCount = 32;
    static const int pixelAxisCount = 2;
    int pixelMesh[pixelCount][pixelAxisCount] = {
        { -3, 0 }, { -4, 0 },
        { -5, 0 }, { -6, 0 },
        { -3, 1 }, { -4, 1 },
        { -5, 1 }, { -6, 1 },
        { 4, 0 }, { 5, 0 },
        { 6, 0 }, { 7, 0 },
        { 4, 1 }, { 5, 1 },
        { 6, 1 }, { 7, 1 },
        { 0, -3 }, { 0, -4 },
        { 0, -5 }, { 0, -6 },
        { 1, -3 }, { 1, -4 },
        { 1, -5 }, { 1, -6 },
        { 0, 4 }, { 0, 5 },
        { 0, 6 }, { 0, 7 },
        { 1, 4 }, { 1, 5 },
        { 1, 6 }, { 1, 7 }
    };
};