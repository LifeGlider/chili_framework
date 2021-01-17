#include "Crosshair.h"

// Calculate border transition for pixel if there is such
bool Crosshair::BorderCheck(int pixel_pos, int screen_border) const
{
    if (pixel_pos < 0)
    {
        return false;
    }
    else if (pixel_pos >= screen_border)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Apply new position for crosshair
void Crosshair::UpdatePosition(const int xPosition, const int yPosition)
{
    xPos = xPosition;
    yPos = yPosition;
}

// Update hitbox position
void Crosshair::UpdateHitbox()
{
    hitBox[0] = xPos - 2;
    hitBox[1] = xPos + 3;
    hitBox[2] = yPos - 2;
    hitBox[3] = yPos + 3;
}

// Change color data
void Crosshair::UpdateColor(int red, int green, int blue)
{
    colorRed = red;
    colorGreen = green;
    colorBlue = blue;
}

// Draw crosshair
void Crosshair::Draw(Graphics& gfx) const
{
    for (int pixelIndex = 0; pixelIndex < pixelCount; ++pixelIndex)
    {
        if (BorderCheck(xPos + pixelMesh[pixelIndex][0], gfx.ScreenWidth) && BorderCheck(yPos + pixelMesh[pixelIndex][1], gfx.ScreenHeight))
        {
            gfx.PutPixel
            (
                xPos + pixelMesh[pixelIndex][0],
                yPos + pixelMesh[pixelIndex][1],
                colorRed,
                colorGreen,
                colorBlue
            );
        }
    }
}
