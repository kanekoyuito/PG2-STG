#pragma once
class Bullet
{
public:
	int bulletPosX_;
	int bulletPosY_;
	int bulletRadius_;
	int bulletSpeed_;
	int bulletIsAlive_;
public:
	Bullet();
	void Update();
	void Draw();
};

