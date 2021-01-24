#include<iostream> 
#include<windows.h>

using namespace std;

//�������� ���� ����������� ������ � ���������� �������� :
//
//o ��������� �������� � ������ ������ void addToHead( int value)
//o ��������� �������� � ����� ������ void delFromTail()
//o ��������� ����� �� ���� �������� void delByIndex(int index)
//o ������� ������ ����� �� �������� void insByIndex(int index,  int value)
//o �������� ������ +
//o ����� ������� ����� ������ �� ������� ��������� int searchByValue(int value),
// ��� ��������� ������ ��������� - 1

struct Node {
	int value;
	Node* pNext;
};
class List {
	Node* pHead; 
	Node* pTail; 
	int count;
public:
	List() {
		pHead = pTail = NULL;
		count = 0;
	}
	int GetCount() {
		return count;
	}
	void Print() const  // �������� ������
	{
		Node* temp = pHead;

		while (temp != NULL)
		{
			cout << temp->value << "\t";
			temp = temp->pNext; 
		}
		cout << endl;
	}
	void addToHead(int value) {  // ��������� �������� � ������ ������
		Node* foradd = new Node;
		foradd->value = value;
		foradd->pNext = NULL;
		if (pTail != NULL)
		{
			foradd->pNext = pHead;
			pHead = foradd;
		}
		else pHead = pTail = foradd;

		count++;
	}
	void delFromTail() {  // ��������� �������� � ������ ������
		Node* last = pTail; //���������� ������� �������
		if (pTail!= pHead) // �������� ����� �� ����
		{
			Node* temp = pHead; // ������ ����� ����
			while (temp->pNext->pNext != NULL) // ������ ������������ ����
			{
				temp = temp->pNext; // �������������� ����, ������ �� ���� ������������
			}

			temp->pNext = NULL; // ���� ������� ��� ���������� NULL
			pTail = temp; // ������ ���������� ���� ������� ����
			count--; // �������� �������
		}
		else
		{
			pTail = pHead = NULL; // ���� ���� ���� ����, �� ��� ���� ���� ����������
		}
		delete last; // ��������� ����� ������ ������� �������
	}
	Node& operator [](const int index) { // ���������� []
		Node* temp = pHead; // ���������� ������
		int number = 0; // ��������
		
			while (temp) // �� � ����
			{
				if (number == index) // ���� �������� ������� �������
				{
					return*temp; // ��������� �������� �� ������� ����, ��� ������� ������ �������
				}
				number++; // �������� ��������
				temp = temp->pNext; // ���������� ����, ������� ��� ���������� �������� ����
			}
			throw ("Error array!!!"); 
	}
	void insByIndex(int index, int value) { // ������� ������ ����� �� ��������
		if (index == 0)
		{
			addToHead(value);
		}
		else
		{
			Node* previus = this->pHead;
			for (int i = 0; i < index - 1; i++)
			{
				previus = previus->pNext;
			}
			Node* newNode = new Node;  // ��� ������� �������!!!
			previus->value = value;
			previus->pNext = newNode;
			pTail = previus->pNext;
			count++;
		}
	}
	void delByIndex(int index) {  // ��������� ����� �� ���� ��������
		if (index==0)
		{
			Node* temp = pHead;
			if (pHead != NULL)
			{
				pHead = pHead->pNext;
			}
			count--;
			delete temp;
		}
		else
		{
			Node* previus = pHead;
			for (int i = 0; i < index-1; i++) // ������ ��������� ���� ����� ��� ���������, �� ������� ��������
			{
				previus = previus->pNext; // ������� ��� ���������� �������� �������� ����
			}
			Node* todelete = previus->pNext; // ������ �������� ����, ��� ������� �������� ������� � �������� ����� todelete
			previus->pNext = todelete->pNext; // � ������, ��� �������� �������� ������� ������ ���� ��������, �� ���� �������� ��� ������� ���� �� ������ ��������
			delete todelete; // ��������� �������, ���� �� ������ ��������
		}
	}
	~List() {
		//Node* qwert = &(*this)[0];

	}


};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List list;
	//list.Print();
	list.addToHead(513);
	list.addToHead(37);
	list.addToHead(52);
	//cout << list.GetCount() << endl;
	//for (int i = 0; i < list.GetCount(); i++)
	//{
	//	 list.Print();
	//}
	list.Print();
	system("pause");
	//list.delFromTail();
	//list.Print();
	list.insByIndex(2, 120);
	for (int i = 0; i <= list.GetCount()-1; i++) // ���� �� ����� ����� []
	{
		cout << list[i].value << "\t";
	}
	//list.delByIndex(2);
	//for (int i = 0; i <= list.GetCount() - 1; i++) // ���� �� ����� ����� []
	//{
	//	cout << list[i].value << "\t";
	//}
	//cout<<list[0].value;

	return 0;
}