#include"DxLib.h"
#include"SelectMenu.h"

namespace
{
	//???j???[???ڂ̊Ԋu
	constexpr int kMenuItemInterval = 32;
}

//-----------------------------------------
//SelectMenu::Item
//-----------------------------------------


SelectMenu::Item::Item()
{
	m_text = nullptr;
}

SelectMenu::Item::~Item()
{

}

void SelectMenu::Item:: draw(int x, int y)
{
	DrawString(x, y, m_text, GetColor(255, 255, 255));
}

int SelectMenu::Item:: getTextWidth()
{
	return GetDrawStringWidth(m_text, strlen(m_text));
}

void SelectMenu::Item::setText(const char* text)
{
	m_text = text;
}

//-----------------------------------------
//SelectMenu::Item
//-----------------------------------------
SelectMenu::Cursor::Cursor()
{
	m_selectIndex = 0;
}

SelectMenu::Cursor::~Cursor()
{

}

void SelectMenu::Cursor::draw()
{
	int posX = m_menuPos.x ;
	int posY = m_menuPos.y + kMenuItemInterval * m_selectIndex;

	DrawBox(posX, posY, posX + m_size.x, posY + m_size.y, GetColor(255, 0, 0),false);
}

//-----------------------------------------
//SelectMenu
//-----------------------------------------

SelectMenu::SelectMenu()
{

}

SelectMenu::~SelectMenu()
{

}

void SelectMenu::init()
{

}

void SelectMenu::end()
{
	for (auto& pItem : m_pItem)
	{
		delete pItem;
	}
	m_pItem.clear();
}

void SelectMenu::updata()
{

}

void SelectMenu::draw()
{
	int width = getWindowWidth();
	int height = getWindowHeight();
	
	DrawBox(m_pos.x, m_pos.y, 128, m_pos.y + height, GetColor(64, 64, 64), true);
	for (int i = 0; i < i < m_pItem.size(); i++)
	{
		m_pItem[i]->draw(m_pos.x, m_pos.y + i * kMenuItemInterval);
	}
	m_cursor.draw();
}
void SelectMenu::setupCursor()
{
	m_cursor.setMenuPos(m_pos);
	m_cursor.setSize(Vec2( getWindowWidth(),kMenuItemInterval ));
}

void SelectMenu::setPos(float x, float y)
{
	setPos(Vec2(x, y));
}

void SelectMenu::setPos(Vec2 pos)
{
	m_pos = pos;
}

void SelectMenu::addItem(const char* text)
{
	Item* pItem = new Item;
	pItem->setText(text);
	m_pItem.push_back(pItem);

}

int SelectMenu::getWindowWidth()
{
	int width = 0;
	//???ԉ????̍L?????j???[???ڂ̕????E?C???h?E?T?C?Y?ɂ???

	for (auto& pItem : m_pItem)
	{
		if (width < pItem->getTextWidth())
		{
			width = pItem->getTextWidth();
		}
	}
	return width;
}

int SelectMenu::getWindowHeight()
{
	return kMenuItemInterval * m_pItem.size();
}