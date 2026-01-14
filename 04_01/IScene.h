#pragma once

// シーン名列挙型定義
enum Scene { TITLE, STAGE, CLEAR };

// シーン基底クラス定義
class IScene {
public:
	virtual ~IScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	Scene GetSceneNo() const { return sceneNo_; }

protected:
	// 全シーン共通の「現在のシーン番号」
	static Scene sceneNo_;
};
