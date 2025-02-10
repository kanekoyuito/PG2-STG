#include "Bullet.h"
#include"Novice.h"

Bullet::Bullet(){
	bulletPosX_ = 0;
	bulletPosY_ = 0;
	bulletRadius_ = 10;
	bulletIsAlive_ = 0;
	bulletSpeed_ = 5;
}


void Bullet::Update(){
	//弾の更新処理
	if (bulletIsAlive_ == 1) {
		bulletPosY_ -= bulletSpeed_;
	}
	if (bulletPosY_ < -5) {
		bulletIsAlive_ = 0;
	}
}

void Bullet::Draw(){
	//弾の描画処理
	if (bulletIsAlive_ == 1) {
		Novice::DrawEllipse(bulletPosX_, bulletPosY_, bulletRadius_, bulletRadius_, 0.0f, WHITE, kFillModeSolid);
	}
}
