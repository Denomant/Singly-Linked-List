#include <iostream>

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
};



