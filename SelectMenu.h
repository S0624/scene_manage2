#pragma once

class SelectMenu
{
public:
	SelectMenu();
	virtual ~SelectMenu();

	//�������A�I������
	void init();
	void end();

	//�X�V
	void updata();
	//�`��
	void draw();


private:
	class Item
	{
	public:
		Item();
		virtual ~Item();		//���O���Ԃ������邽�߃N���X�̒��ɃN���X�����

		void setText(const char* text);
	private:
		//�\�����镶����
		const char* m_text;
	};

private:

};