#pragma once

class SelectMenu
{
public:
	SelectMenu();
	virtual ~SelectMenu();

	//初期化、終了処理
	void init();
	void end();

	//更新
	void updata();
	//描画
	void draw();


private:
	class Item
	{
	public:
		Item();
		virtual ~Item();		//名前かぶりを避けるためクラスの中にクラスを作る

		void setText(const char* text);
	private:
		//表示する文字列
		const char* m_text;
	};

private:

};