#include <iostream>

template<typename T>
class LinkedList // Link List
{
	private:
		class Node
		{
			public:
				Node* next;
				T data;

				Node(T data, Node* next = nullptr) // constructor
				{
					this->data = data;
					this->next = next;
				}
				~Node() // destructor
				{
					delete this->next;
				}
		};
		Node* root;
		int nofNodes;

	public:
		LinkedList() // constructor
		{
			this->root = nullptr;
			this->nofNodes = 0;
		}
		~LinkedList() // destructor
		{
			delete this->root;
		}

		void insertEnd(T data) 
		{
			if (this->root == nullptr) // List is empty, create root
			{
				this->root = new Node(data);
			}
			else
			{
				Node* walker = this->root;

				while (walker->next != nullptr)
					walker = walker->next;

				walker->next = new Node(data);
			}
			this->nofNodes++;
		}

		T getAt(int index)
		{
			if (this->root == nullptr)
				throw("List Is Empty!");
			else if (index < 0 || index >= this->nofNodes)
				throw("Index Out Of Bounds");

			T data;

			if (index == 0)
				data = this->root->data;
			else
			{
				Node* walker = this->root;

				for (size_t i = 0; i < index; i++)
				{
					walker = walker->next;
				}
				data = walker->data;
			}
			return data;
		}

};
using namespace std;

int main()
{

	LinkedList<int> list1;

	list1.insertEnd(1);
	list1.insertEnd(2);
	list1.insertEnd(3);

	cout << list1.getAt(0) << endl;
	cout << list1.getAt(1) << endl;
	cout << list1.getAt(2) << endl;

	system("Pause");
	return 0;
}