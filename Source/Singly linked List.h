#include <iostream>

using namespace std;

class CharNode {
public:
	char Value;
	CharNode *Nextptr = nullptr;
	CharNode(char Value) {
		this->Value = Value;
	}
};


class MyString {
public:
	CharNode *HeadNode = new CharNode('\0');//null

	void Append(char Value) {
		//Char Version
		 
		// First Append
		if(HeadNode->Value == '\0') {
			HeadNode->Value = Value;
			return;
		}

		// Skip Valued Nodes
		CharNode *CurrentNode = HeadNode;
		while(CurrentNode->Nextptr != nullptr) {
			CurrentNode = CurrentNode->Nextptr;
		}

		// New Node Set
		CurrentNode->Nextptr = new CharNode(Value);
	}


	void Append(MyString *StringToAdd) {
		//MyString
				
		// Non empty MyString
		if(StringToAdd->HeadNode->Value == '\0') {
			return;
		}

		// Skip valued nodes
		// To change O(n^2) to O(n)
		CharNode *CurrentNodeToSave = HeadNode;
		while(CurrentNodeToSave->Nextptr != nullptr) {
			CurrentNodeToSave = CurrentNodeToSave->Nextptr;
		}

		CharNode *CurrentNodeToAdd = StringToAdd->HeadNode;

		// if the String that we add to it, is empty
		if(CurrentNodeToSave->Value == '\0') {
			CurrentNodeToSave->Value = CurrentNodeToAdd->Value;
			if(CurrentNodeToAdd->Nextptr == nullptr) {
				return;
			}
			CurrentNodeToAdd = CurrentNodeToAdd->Nextptr;
		}

		while(CurrentNodeToAdd->Nextptr != nullptr) {
			CurrentNodeToSave->Nextptr = new CharNode(CurrentNodeToAdd->Value);
			CurrentNodeToSave = CurrentNodeToSave->Nextptr;
			CurrentNodeToAdd = CurrentNodeToAdd->Nextptr;
		}
		CurrentNodeToSave->Nextptr = new CharNode(CurrentNodeToAdd->Value);


	}


	char Get(int Index) {
		//char

		// return null if the index is negative
		if(Index < 0) {
			return '\0';
		}

		CharNode *CurrentNode = HeadNode;

		while(Index != 0) {
			// return null if index out of range
			if(CurrentNode->Nextptr == nullptr) {
				return '\0';
			}

			CurrentNode = CurrentNode->Nextptr;
			Index -= 1;
		}
		return CurrentNode->Value;
	}
};



