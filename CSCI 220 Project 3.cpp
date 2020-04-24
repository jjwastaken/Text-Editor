
#include <iostream>
#include "Editor.h"

using namespace std;

int main()
{
	string word;
	int option;
	cout << "Enter a starting string: ";
	getline(cin, word);
	Editor e(word);
	e.printMenu();
	
	do
	{
		cout << endl << "Enter an option: ";
		cin >> option;

		
		
		switch (option)
		{
		case 1:
			e.left();
			break;
		case 2:
			e.right();
			break;
		case 3:
			char letter;
			cout << "Enter a character: ";
			cin >> letter;
			cout << "Inserted character " << letter << endl;
			e.insertChar(letter);
			break;
		case 4:
			e.deleteChar();
			break;
		case 5:
			e.getPosition();
			break;
		case 6:
			int position;
			cout << "Enter a position: ";
			cin >> position;
			e.toPosition(position);
			break;
		case 7:
			e.display();
			break;
		case 8:
			e.quit();
			return 0;
		default:
			cout << "Not a valid option, please try again." << endl;
			break;
		}
	} while (option != 8);



}

