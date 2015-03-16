// Kelley Stoll
// Stack Project
// Header File
// Exercise: Implement infix, postfix, and evaluation through stack template.
const int DEFAULT_SIZE = 50;

template<class ItemType>
class StackType
{
public:
	StackType(); // Constructor
	~StackType(); // Deconstructor
	StackType(const StackType<ItemType> &); // Copy Constructor
	StackType operator= (const StackType<ItemType> &); // Assignment Operator
	StackType(int max);
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ItemType item);
	void Pop();
	ItemType Top() const;
	unsigned int LengthIs() const;
	void resize(int);
	void two(StackType<ItemType> &stacky, ItemType& s1, ItemType& s2);

private:
	int top;
	ItemType* items; // Pointer to items
	int maxStack;
};

#include "stack.template"
