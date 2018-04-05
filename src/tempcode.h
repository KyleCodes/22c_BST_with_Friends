template < class T >
void BST<T>::insert(T obj)
{
	Node<T>* newNode = new Node<T>;
	Node<T>* parent;

	newNode->data = obj;
	newNode->left = NULL;
	newNode->right = NULL;
	parent = NULL;

	// If this is the first insert for a new tree
	if (isEmpty())
		root = newNode;
	else
	{
		// Inserts as a leaf Node
		Node<T>* currPtr;
		currPtr = root;

		// Find the Node's parents
		while (currPtr != NULL)
		{
			parent = currPtr;
			if (newNode->data > currPtr->data)
				currPtr = currPtr->right;
			else if (newNode->data < currPtr->data)
				currPtr = currPtr->left;
		}

		if (newNode->data < parent->data)
			parent->right = newNode;
		else if (newNode->data > parent->data)
			parent->left = newNode;

	}
}

template < class T >
void BST<T>::remove(T obj)
{
	Node<T>* currPtr;
	Node<T>* parent;
	bool found = false;

	// If node has multiple children 

	if (isEmpty())
	{
		cout "The tree is empty" << endl;
		return;
	}

	currPtr = root;
	parent = NULL;

	while (currPtr != NULL)
	{
		if (currPtr->data == obj)
		{
			found = true;
			break;
		}
		else
		{
			parent = currPtr;
			if (obj > currPtr->data)
				currPtr = currPtr->right;
			else if (obj < currPtr->data)
				currPtr = currPtr->left;
		}
	}
	if (found == false)
	{
		cout << "Member not found" << endl;
		return;
	}

	// If node has one child
	if ((currPtr->left == NULL && currPtr->right != NULL) || (currPtr->left != NULL && currPtr->right == NULL))
	{
		// Right child is there, no left child
		if (currPtr->left == NULL && currPtr->right != NULL)
		{
			if (parent->left == currPtr)
			{
				parent->left = currPtr->right;
				delete curr;
			}
			else
			{
				parent->right = currPtr->right
			}
		}
		// Left child is there, no right child
		else if (currPtr->left != NULL && currPtr->right == NULL)
		{
			if (parent->left == currPtr)
			{
				parent->left = parent->left;
				delete currPtr;
			}
			else
			{
				parent->right = currPtr->left;
				delete curr;
			}
		}
		return;
	}

	// Now observing a leaf node
	if (currPtr->left == NULL && currPtr == NULL)
	{
		if (parent == NULL)
		{
			delete currPtr;
		}
		else
		{
			if (parent->left == currPtr)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete currPtr;
			return;
		}
	}

	if (currPtr->left != NULL && currPtr->right != NULL)
	{
		Node<T>* checker;
		checker = currPtr->right;

		if ((checker->left == NULL) && (checker->right == NULL))
		{
			currPtr = checker;
			delete checker;
			currPtr->right = NULL;
		}
		else
			if ((currPtr->right)->left != NULL)
			{
				Node<T>* lcurr;
				Node<T>* lcurrp;
			}
	}







}