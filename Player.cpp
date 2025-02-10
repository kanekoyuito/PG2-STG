#include "Player.h"
#include"Novice.h"

Player::Player(int posX, int posY, int speedX, int speedY) {
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 8;

	bullet_ = new Bullet;
}
void Player::SetSpeed(int x, int y){
	posX_ = x;
	posY_ = y;
}
void Player::SetPosition(int x, int y){
	speedX_ = x;
	speedY_ = y;
}

Player::~Player(){
	delete bullet_;
}
void Player::Update(char* keys, char* preKeys){
	//player更新処理

	bullet_->Update();

	if (keys[DIK_W]){
		posY_ -= speedY_;//上
	}
	if (keys[DIK_A]) {
		posX_ -= speedX_;//左
	}
	if (keys[DIK_D]) {
		posX_ += speedX_;//右
	}
	if (keys[DIK_S]) {
		posY_ += speedY_;//下
	}
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {
		if (bullet_->bulletIsAlive_ == 0) {
			bullet_->bulletPosX_ = posX_;
			bullet_->bulletPosY_ = posY_;
		}
		bullet_->bulletIsAlive_ = 1;//弾発射
	}

}
void Player::Draw(){
	//player描画処理
	bullet_->Draw();
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}

