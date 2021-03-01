#include <iostream>
#include "Queue.h"

using namespace std;

void ProcessInput(Queue& QueObj, char cInput);
void EnqueueCase(Queue& QueObj);
void DequeueCase(Queue& QueObj);

int main()
{
	Queue QueObj;
	char cInput = '-1';
	cout << "This program allows for operations on a queue implemented as a linked list.\n";
	do
	{
		cout << "Enter your selection from the menu below: \n";
		cout << "1 - Enqueue an item.\n";
		cout << "2 - Dequeue an item.\n";
		cout << "3 - Make the queue empty.\n";
		cout << "Q - Quit program.\n";
		cout << "Enter your input: ";
		cin >> cInput;

		system("cls");

		ProcessInput(QueObj, cInput);

	} while (toupper(cInput) != 'Q');

	cout << "Goodbye...\n";

	return 0;
}

void ProcessInput(Queue& QueObj, char cInput)
{
	switch (toupper(cInput))
	{
	case '1':
		EnqueueCase(QueObj);
		break;

	case '2':
		DequeueCase(QueObj);
		break; 

	case '3':
		cout << "All queue elements have been emptied.\n\n";
		QueObj.MakeEmpty();
		break;

	case 'Q':
		break;

	default:
		cout << "Unrecognized input - please try again.\n\n";
		break;
	}
}

void EnqueueCase(Queue& QueObj)
{
	ItemType iNewItem;
	int nNewData = -1;

	cout << "Enter the data that you would like to enqueue: ";
	cin >> nNewData;

	iNewItem.Set(nNewData);

	try
	{
		QueObj.Enqueue(iNewItem);
	} catch (FullQueue exception) {
		cerr << "Exception caught: The queue is currently full.\n\n";
	}
}

void DequeueCase(Queue& QueObj)
{
	ItemType iRemovedItem;

	try
	{
		QueObj.Dequeue(iRemovedItem);
		cout << iRemovedItem.Get() << " has been dequeued.\n\n";
	} catch (EmptyQueue exception) {
		cerr << "Exception caught: The queue is currently empty.\n\n";
	}
}