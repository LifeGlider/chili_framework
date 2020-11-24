#include "Target.h"

void Target::Init(float xPosInput, float yPosInput, float xVectorInput, float yVectorInput, float speedInput, int sizeInput, int colorRedInput, int colorGreenInput, int colorBlueInput)
{
    // Allow initialization only once
    assert(isInitialized == false);

    xPos = xPosInput;
    yPos = yPosInput;
    xVector = xVectorInput;
    yVector = yVectorInput;
    size = sizeInput;
    speed = speedInput;
    colorRed = colorRedInput;
    colorGreen = colorGreenInput;
    colorBlue = colorBlueInput;
    hitBox[0] = xPos - size;
    hitBox[1] = xPos + size;
    hitBox[2] = yPos - size;
    hitBox[3] = yPos + size;
    isInitialized = true;
}

// Calculate vector direction and new position
void Target::UpdatePosition()
{
    // Allow only on initialized object
    assert(isInitialized == true);

    if (hitBox[0] - speed < 2 || hitBox[1] + speed > Graphics::ScreenWidth - 3)
    {
        xVector *= -1.0;
    }

    if (hitBox[2] - speed < 2 || hitBox[3] + speed > Graphics::ScreenHeight - 3)
    {
        yVector *= -1.0;
    }

    xPos += speed * xVector;
    yPos += speed * yVector;
}

// Calculate new positon for hitbox sides
void Target::UpdateHitbox()
{
    // Allow only on initialized object
    assert(isInitialized == true);

    hitBox[0] = xPos - size;
    hitBox[1] = xPos + size;
    hitBox[2] = yPos - size;
    hitBox[3] = yPos + size;
}

// Using double loop to rectangle target depending on size
void Target::Draw(Graphics& gfx) const
{
    // Allow only on initialized object
    assert(isInitialized == true);

    if (isAlive)
    {
        for (int lineIndex = (-1 * size); lineIndex < size; ++lineIndex)
        {
            for (int columnIndex = (-1 * size); columnIndex < size; ++columnIndex)
            {
                gfx.PutPixel(xPos + columnIndex, yPos + lineIndex, colorRed, colorGreen, colorBlue);
            }
        }
    }
}

// Return isAlive variable
bool Target::isAliveCheck() const
{
    // Allow only on initialized object
    assert(isInitialized == true);

    return isAlive;
}

// Determine if there is collision with given object
bool Target::isColliding(const int objectHitbox[4])
{
    // Allow only on initialized object
    assert(isInitialized == true);

    if (isAlive)
    {
        return (objectHitbox[0] <= hitBox[1] && objectHitbox[1] >= hitBox[0] && objectHitbox[2] <= hitBox[3] && objectHitbox[3] >= hitBox[2]);
    }
    else
    {
        return false;
    }
}

// Set isAlive to false if collision confirmed and isAlive eq. true
void Target::KillTarget()
{
    // Allow only on initialized object
    assert(isInitialized == true);

    isAlive = false;
}

// Execute main subroutines for target global position and execute 'killing' function
void Target::UpdateTargetStatus(const int objectHitbox[4], bool trigger)
{
    // Allow only on initialized object
    assert(isInitialized == true);

    UpdatePosition();
    UpdateHitbox();
    if (Target::isColliding(objectHitbox) && isAlive && trigger)
    {
        KillTarget();
    }
}
