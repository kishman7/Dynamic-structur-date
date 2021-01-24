#include<iostream> 
#include<windows.h>

using namespace std;

//Створити клас Однозв’язний список з наступними методами :
//
//o додавання елемента у голову списку void addToHead( int value)
//o видалення елемента у голові списку void delFromTail()
//o видалення вузла за його індексом void delByIndex(int index)
//o вставка нового вузла за індексом void insByIndex(int index,  int value)
//o перегляд списку +
//o пошук індексу вузла списку за заданим значенням int searchByValue(int value),
// при невдалому пошуку повертати - 1

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
	void Print() const  // перегляд списку
	{
		Node* temp = pHead;

		while (temp != NULL)
		{
			cout << temp->value << "\t";
			temp = temp->pNext; 
		}
		cout << endl;
	}
	void addToHead(int value) {  // додавання елемента у голову списку
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
	void delFromTail() {  // видалення елемента з хвоста списку
		Node* last = pTail; //присвоюємо останній елемент
		if (pTail!= pHead) // елементів більше ніж один
		{
			Node* temp = pHead; // беремо першу ноду
			while (temp->pNext->pNext != NULL) // шукаємо передостанню ноду
			{
				temp = temp->pNext; // переприсвоюємо ноду, допоки не буде передостання
			}

			temp->pNext = NULL; // новій останній ноді присвоюємо NULL
			pTail = temp; // хвосту присвоюємо нову останню ноду
			count--; // зменшуємо кількість
		}
		else
		{
			pTail = pHead = NULL; // якщо нода лише одна, то тут вона буде видалятись
		}
		delete last; // видаляємо кожен старий останній елемент
	}
	Node& operator [](const int index) { // перегрузка []
		Node* temp = pHead; // присвоюємо голову
		int number = 0; // лічильник
		
			while (temp) // що є ноди
			{
				if (number == index) // коли лічильник дорівнює індексу
				{
					return*temp; // повертаємо вказівник на поточну ноду, яка дорівнює нашому індексу
				}
				number++; // збільшуємо лічильник
				temp = temp->pNext; // перебираємо ноди, поточній ноді присвоюємо наступну ноду
			}
			throw ("Error array!!!"); 
	}
	void insByIndex(int index, int value) { // вставка нового вузла за індексом
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
			Node* newNode = new Node;  // тут можлива помилка!!!
			previus->value = value;
			previus->pNext = newNode;
			pTail = previus->pNext;
			count++;
		}
	}
	void delByIndex(int index) {  // видалення вузла за його індексом
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
			for (int i = 0; i < index-1; i++) // шукаємо попередню ноду перед тим елементом, що потрібно видалити
			{
				previus = previus->pNext; // поточній ноді присвоюємо значення наступної ноди
			}
			Node* todelete = previus->pNext; // адресу наступної ноди, яку потрібно видалити поміщаємо в тичасову змінну todelete
			previus->pNext = todelete->pNext; // в адресу, яку михочемо видалити поміщаємо адресу того елементу, на який вказував наш елемент який ми хочемо видалити
			delete todelete; // видаляємо елемент, який ми хочемо видалити
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
	for (int i = 0; i <= list.GetCount()-1; i++) // вивід на екран через []
	{
		cout << list[i].value << "\t";
	}
	//list.delByIndex(2);
	//for (int i = 0; i <= list.GetCount() - 1; i++) // вивід на екран через []
	//{
	//	cout << list[i].value << "\t";
	//}
	//cout<<list[0].value;

	return 0;
}