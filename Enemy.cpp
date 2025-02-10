#include "Enemy.h"
#include"Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY){
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 20;
	isAlive_ = true;
}

void Enemy::SetSpeed(int x, int y){
	posX_ = x;
	posY_ = y;
}

void Enemy::SetPosition(int x, int y){
	speedX_ = x;
	speedY_ = y;
}

void Enemy::Update(){
	//敵の更新処理
	posX_ += speedX_;
	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
}

void Enemy::Draw(){
	//敵の描画処理
	if (isAlive_ == true){
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLACK, kFillModeSolid);
	}
}
