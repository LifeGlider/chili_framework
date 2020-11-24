#pragma once

#include "Graphics.h"
#include "Crosshair.h"
#include <assert.h>

class Target
{
public:
	void Init(float xPosInput, float yPosInput, float xVectorInput, float yVectorInput, float speedInput, int sizeInput, int colorRedInput, int colorGreenInput, int colorBlueInput);
	void UpdatePosition();
	void UpdateHitbox();
	bool IsOnScreen(const Graphics& gfx, const float x_pos, const float y_pos) const;
	void Draw(Graphics& gfx) const;
	bool isAliveCheck() const;
	bool isColliding(const int objectHitbox[4]);
	void KillTarget();
	void UpdateTargetStatus(const int objectHitbox[4], bool trigger);
	
private:
	float xPos;
	float yPos;
	float xVector;
	float yVector;
	float speed;
	int size;
	int colorRed;
	int colorGreen;
	int colorBlue;
	float hitBox[4];
	bool isAlive = true;
	bool isInitialized = false;
};
