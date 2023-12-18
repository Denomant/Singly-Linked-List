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
		//MyString Version
				
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
		//char Version

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


	MyString Get(int IndexStart, int IndexEnd) {
		//MyString Version
		// Includes IndexStart, and does not IndexEnd

		MyString MyStringEmpty;
		MyString MyStringReturn;
		
		// Special cases
		if(IndexStart == IndexEnd) {
			MyStringReturn.HeadNode->Value = this->Get(IndexStart);
			return MyStringReturn;
		}
		
		if(IndexEnd < IndexStart) {
			return MyStringEmpty;
		}

		if(IndexStart < 0) {
			return MyStringEmpty;
		}
		

		CharNode *CurrentNodeToAdd = HeadNode;
		int NodesBeforeIndexStart = IndexStart;
		
		//Find IndexStart
		while(NodesBeforeIndexStart > 0) {
			//if IndexStart out of range
			if(CurrentNodeToAdd->Nextptr == nullptr) {
				
				return MyStringEmpty;
			}
			CurrentNodeToAdd = CurrentNodeToAdd->Nextptr;
			NodesBeforeIndexStart -= 1;
			
		}
		//CurrentNodeToAdd at IndexStaert
		
		CharNode *CurrentNodeToSave = MyStringReturn.HeadNode;
		int CountCharsToAdd = IndexEnd-IndexStart;
		
		while(CountCharsToAdd >= 0) {
			//if IndexEnd out of range
			if(CurrentNodeToAdd->Nextptr == nullptr and CountCharsToAdd != 0) {
				return MyStringEmpty;
			}
			
			CurrentNodeToSave->Value = CurrentNodeToAdd->Value;
			cout << CurrentNodeToAdd->Value << " Added\n";
			CurrentNodeToSave->Nextptr = new CharNode('\0');
			CurrentNodeToSave = CurrentNodeToSave->Nextptr;
			CurrentNodeToAdd = CurrentNodeToAdd->Nextptr;
			CountCharsToAdd -= 1;
		}
		return MyStringReturn;
	}
};