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
    hitBox[0] = xPos;
    hitBox[1] = xPos + float(size) * 2.0f;
    hitBox[2] = yPos;
    hitBox[3] = yPos + float(size) * 2.0f;
    isInitialized = true;
}

// Calculate vector direction and new position
void Target::UpdatePosition()
{
    // Allow only on initialized object
    assert(isInitialized == true);

    if (hitBox[0] - speed < 2.0f || hitBox[1] + speed > float(Graphics::ScreenWidth) - 3.0f)
    {
        xVector *= -1.0;
    }

    if (hitBox[2] - speed < 2.0f || hitBox[3] + speed > float(Graphics::ScreenHeight) - 3.0f)
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

    hitBox[0] = xPos;
    hitBox[1] = xPos + float(size) * 2.0f;
    hitBox[2] = yPos;
    hitBox[3] = yPos + float(size) * 2.0f;
}

bool Target::IsOnScreen(const Graphics& gfx, const float x_pos, const float y_pos) const
{
    return x_pos > 0 && x_pos < float(gfx.ScreenWidth) && y_pos > 0 && y_pos < float(gfx.ScreenHeight);
}

// Using double loop to rectangle target depending on size
void Target::Draw(Graphics& gfx) const
{
    // Allow only on initialized object
    assert(isInitialized == true);

    if (isAlive)
    {
        const int radius = size;
        const int radius_sqr = radius * radius;

        for (int row = 0; row < (radius * 2); ++row)
        {
            for (int col = 0; col < (radius * 2); ++col)
            {
                int x = col - radius;
                int y = radius - row;
                int sumsqr = x * x + y * y;

                if (sumsqr <= radius_sqr && IsOnScreen(gfx, xPos + float(row), yPos + float(col)))
                {
                    gfx.PutPixel(int(xPos + float(row)), int(yPos + float(col)), colorRed, colorGreen, colorBlue);
                }
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
        return (float(objectHitbox[0]) <= hitBox[1] && float(objectHitbox[1] >= hitBox[0]) && float(objectHitbox[2]) <= hitBox[3] && float(objectHitbox[3]) >= hitBox[2]);
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
