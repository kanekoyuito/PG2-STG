#pragma once
#include"Bullet.h"
class Player{
public:
	Player(int ppsX, int posY, int speedX, int speedY);
	int GetPosX() { return posX_; };//mainから触れない変わりにここで教えてもらう
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	int GetRadius() { return radius_; };
	void SetSpeed(int x, int y);
	void SetPosition(int x, int y);

	/// <summary>
	/// 更新
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	~Player();
	Bullet* bullet_;
private:	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
};

