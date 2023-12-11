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
		 
		//First Append
		if(HeadNode->Value == '\0') {
			HeadNode->Value = Value;
			return;
		}

		//Skip Valued Nodes
		CharNode *CurrentNode = HeadNode;
		while(CurrentNode->Nextptr != nullptr) {
			CurrentNode = CurrentNode->Nextptr;
		}

		//New Node Set
		CurrentNode->Nextptr = new CharNode(Value);
	}


	void Append(MyString *StringToAdd) {
		//MyString
				
		// Non empty MyString
		if(StringToAdd->HeadNode->Value == '\0') {
			return;
		}

		// Skip valued nodes
		CharNode *CurrentNodeToSave = HeadNode;
		while(CurrentNodeToSave->Nextptr != nullptr) {
			CurrentNodeToSave = CurrentNodeToSave->Nextptr;
		}

		CharNode *CurrentNodeToAdd = StringToAdd->HeadNode;
		while(CurrentNodeToAdd->Nextptr != nullptr) {
			CurrentNodeToSave->Nextptr = new CharNode(CurrentNodeToAdd->Value);
			CurrentNodeToSave = CurrentNodeToSave->Nextptr;
			CurrentNodeToAdd = CurrentNodeToAdd->Nextptr;
		}
		CurrentNodeToSave->Nextptr = new CharNode(CurrentNodeToAdd->Value);


	}

};



