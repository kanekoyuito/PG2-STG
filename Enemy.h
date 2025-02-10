#pragma once
class Enemy{
public:
	Enemy(int ppsX, int posY, int speedX, int speedY);
	int GetPosX() { return posX_; };//mainから触れない変わりにここで教えてもらう
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	int GetRadius() { return radius_; };
	bool isAlive_;
	void SetSpeed(int x, int y);
	void SetPosition(int x, int y);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
private:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	
};

