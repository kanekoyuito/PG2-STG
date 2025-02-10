#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"

const char kWindowTitle[] = "GC1C_05_カネコユイト_タイトル";

enum TITLE {
	TITLE,
	PLAY,
};


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player(400, 300, 10, 10);
	Enemy* enemy = new Enemy(100, 100, 3, 3);

	int currentSceen = TITLE;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (currentSceen) {
		case TITLE:
			if (keys[DIK_J]){
				currentSceen = PLAY;//シーンをPLAY
				player->resetdata(400, 300, 10, 10);
				enemy->resetdata(100,100,3,3);
			}
			break;
		case PLAY:
			player->Update(keys, preKeys);//player.hから呼び出す
			enemy->Update();//enemy.hから呼び出す

			//当たり判定
			float distX = (float)enemy->GetPosX() - player->bullet_->bulletPosX_;
			float distY = (float)enemy->GetPosY() - player->bullet_->bulletPosY_;
			float dist = (distX * distX) + (distY * distY);
			int radius = enemy->GetRadius() + player->bullet_->bulletRadius_;
			if (dist <= radius * radius) {
				enemy->isAlive_ = false;
				currentSceen = TITLE;
				if (currentSceen==TITLE){
					//初期化
					player->bullet_->bulletPosX_ = player->GetPosX();
					player->bullet_->bulletPosY_ = player->GetPosY();
					player->bullet_->bulletIsAlive_ = 0;
					enemy->isAlive_ = true;
				}
			}
			float dist2X = (float)enemy->GetPosX() - player->GetPosX();
			float dist2Y = (float)enemy->GetPosY() - player->GetPosY();
			float dist2 = (dist2X * dist2X) + (dist2Y * dist2Y);
			int radius2 = enemy->GetRadius() + player->bullet_->bulletRadius_;
			if (dist2 <= radius2 * radius2) {
				enemy->isAlive_ = false;
				currentSceen = TITLE;
				if (currentSceen == TITLE) {
					//初期化
					player->bullet_->bulletPosX_ = player->GetPosX();
					player->bullet_->bulletPosY_ = player->GetPosY();
					player->bullet_->bulletIsAlive_ = 0;
					enemy->isAlive_ = true;
				}
			}
			break;
		}

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (currentSceen){
		case TITLE:
			Novice::ScreenPrintf(100, 100, "JキーでPLAY画面");
			break;
		case PLAY:
			Novice::ScreenPrintf(10, 10, "%d", enemy->isAlive_);
			player->Draw();
			enemy->Draw();
			break;
		}
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
