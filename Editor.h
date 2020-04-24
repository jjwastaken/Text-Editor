#pragma once
#include "NodeList.h"
#include <string>
#include <iostream>

using namespace std;

class Editor
{
private:
	NodeList word;
	int cursor;
public:
	Editor();
	Editor(string s);
	void left();
	void right();
	void insertChar(char c);
	void deleteChar();
	void getPosition();
	void toPosition(int num);
	void display();
	void quit();
	void printMenu();
};

Editor::Editor()
{
	cursor = 0;

}

Editor::Editor(string s)
{
	cursor = s.length();
	for (int i = 0; i < s.length(); i++)
	{
		word.insertBack(s[i]);
	}

}

void Editor::left() // 1
{
	if (word.empty()|| cursor <= 0)
	{
		cout << "Cursor cannot go any left" << endl;
		return;
	}
	cout << "Cursor moved to the left" << endl;
	cursor--;
}

void Editor::right() // 2
{
	if (word.empty() || cursor >= word.size())
	{
		cout << "Cursor cannot go any right" << endl;
		return;
	}
	cursor++;
	cout << "Cursor moved to the right" << endl;
}

void Editor::insertChar(char c) // 3
{
	word.insert(word.atIndex(cursor), c);
}

void Editor::deleteChar() // 4
{
	if (word.empty() || cursor >= word.size())
	{
		cout << "No characters to delete" << endl;
		return;
	}
	word.erase(word.atIndex(cursor));
	cout << "Deleted one character" << endl;
}

void Editor::getPosition() // 5
{
	cout << "Current position: " << cursor << endl;
}

void Editor::toPosition(int num) // 6
{
	if (num < 0 || num >= word.size())
	{
		cout << "Invalid position" << endl;
		return;
	}
	cursor = num;
	cout << "Moved to position " << cursor << endl;
}

void Editor::display() // 7
{
	word.insert(word.atIndex(cursor), '>');
	cout << "String: \"";
	for (auto i = word.begin(); i != word.end(); ++i)
	{
		cout << *i;
	}
	word.erase(word.atIndex(cursor));
	cout << "\"";
	cout << endl;
	cout << "Length: " << word.size() << endl;
}

void Editor::quit() // 8
{
	cout << "Thanks for using my editor program." << endl;
}

void Editor::printMenu()
{
	cout << "Editing document..." << endl << endl;
	cout << "  Editing menu" << endl << endl;
	cout << "1. Left" << endl;
	cout << "2. Right" << endl;
	cout << "3. Insert character" << endl;
	cout << "4. Delete character" << endl;
	cout << "5. Get current position" << endl;
	cout << "6. Go to position" << endl;
	cout << "7. Display" << endl;
	cout << "8. Quit" << endl;

}