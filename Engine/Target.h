#pragma once

#include "Graphics.h"
#include "Crosshair.h"
#include <assert.h>

class Target
{
public:
	void Init(int xPosInput, int yPosInput, int xVectorInput, int yVectorInput, int sizeInput, int speedInput, int colorRedInput, int colorGreenInput, int colorBlueInput);
	void UpdatePosition();
	void UpdateHitbox();
	void Draw(Graphics& gfx) const;
	bool isAliveCheck() const;
	bool isColliding(const int objectHitbox[4]);
	void KillTarget();
	void UpdateTargetStatus(const int objectHitbox[4], bool trigger);
	
private:
	int xPos;
	int yPos;
	int xVector;
	int yVector;
	int size;
	int speed;
	int colorRed;
	int colorGreen;
	int colorBlue;
	int hitBox[4];
	bool isAlive = true;
	bool isInitialized = false;
};
