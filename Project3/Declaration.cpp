#include "Header.h"

BST::BST() {
	root = NULL;
}
void BST::insert(int item) {
	node* temp = root;
	bool flag = true;
	if (!temp) {
		temp = new node;
		root = temp;
	}
	else {
		while (true) {
			if (temp->data == item) {
				cout << "Duplicate Value Found! Unable to add Value in Tree\n";
				flag = false;
				break;
			}
			if (temp->data > item && temp->left == NULL) {
				temp->left = new node;
				temp = temp->left;
				break;
			}
			if (temp->data < item && temp->right == NULL) {
				temp->right = new node;
				temp = temp->right;
				break;
			}
			if (temp->data > item) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
	}
	if (flag) {
		temp->data = item;
		temp->left = NULL;
		temp->right = NULL;
	}
	return;
}
int BST::NoOfNodes(int& count, node* temp) {
	if (temp) {
		NoOfNodes(count, temp->left);
		count++;
		NoOfNodes(count, temp->right);
	}
	return count;
}
int BST::size() {
	int count = 0;
	return NoOfNodes(count, root);
}
bool BST::isEmpty() {
	return (root == NULL);
}
bool BST::retrieve(int item) {
	node* temp = root;
	if (!temp) {
		cout << "Tree is Already Empty\n";
		return false;
	}
	while (temp) {
		if (temp->data == item) {
			return true;
		}
		if (temp->data > item) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return false;
}
void BST::displayInOrder() {
	if (!root) {
		cout << "Tree is Empty\n";
		return;
	}
	string type = "Inorder";
	displayNode(type, root);
	cout << endl;
}
void BST::displayPreOrder() {
	if (!root) {
		cout << "Tree is Empty\n";
		return;
	}
	string type = "Preorder";
	displayNode(type, root);
	cout << endl;
}
void BST::displayPostOrder() {
	if (!root) {
		cout << "Tree is Empty\n";
		return;
	}
	string type = "Postorder";
	displayNode(type, root); 
	cout << endl;
}
void BST::displayNode(string& type,node* temp)
{
	if (temp) {
		if (type == "Preorder") {
			cout << temp->data << " ";
		}
		displayNode(type, temp->left);
		if (type == "Inorder") {
			cout << temp->data << " ";
		}
		displayNode(type, temp->right);
		if (type == "Postorder") {
			cout << temp->data << " ";
		}
	}
	return;
}
void BST::remove(int num) {
	if (!root) {
		cout << "Tree is Already Empty\n";
		return;
	}
	checkNodeToDelete(num, root);
}
void BST::checkNodeToDelete(int& num, node*& currNode) {
	if (currNode == NULL) {
		cout << num << " not found!!!\n";
		return;
	}
	if (num < currNode->data) {
		checkNodeToDelete(num, currNode);
	}
	else if (num > currNode->data) {
		checkNodeToDelete(num, currNode);
	}
	else {
		deleteNode(currNode);
	}
	return;
}
void BST::deleteNode(node*& currNode) {
	node* tempNode;
	if (currNode->left == NULL) {
		tempNode = currNode;
		currNode = currNode->right;
		delete tempNode;
	}
	if (currNode->right == NULL) {
		tempNode = currNode;
		currNode = currNode->left;
		delete tempNode;
	}
	else {
		tempNode = currNode->right;
		while (tempNode->left) {
			tempNode = tempNode->left;
		}
		tempNode->left = currNode->left;
		tempNode = currNode;
		currNode = currNode->right;
		delete tempNode;
	}
	return;
}
void BST::emptyTree(node* treeNode) {
	if (treeNode) {
		emptyTree(treeNode->left);
		emptyTree(treeNode->right);
		delete treeNode;
	}
	return;
}
void BST::empty() {
	if (!root) { cout << "Tree is Empty"; return; }
	root = NULL;
	//emptyTree(root);
	return;
}
BST::~BST() {
	emptyTree(root);
}
void BST::displayNodeInDescending(node* treeNode) {
	if (treeNode) {
		displayNodeInDescending(treeNode->right);
		cout << treeNode->data << " ";
		displayNodeInDescending(treeNode->left);
	}
	return;
}
void BST::displayDescending() {
	if (!root) {
		cout << "Tree is Empty!!!\n";
		return;
	}
	displayNodeInDescending(root);
	cout << endl;
}
void BST::displayLessThan(int& num, node* treeNode) {
	if (treeNode) {
		displayLessThan(num, treeNode->right);
		if (treeNode->data < num) {
			cout << treeNode->data << " ";
		}
		displayLessThan(num, treeNode->left);
	}
	return;
}
void BST::displayLessThan(int num) {
	if (!root) {
		cout << "The Tree is Empty\n";
	}
	displayLessThan(num, root);
}
bool BST::is_BST(node* temp) {
	if (!temp) {
		return true;
	}
	if (temp->left) {
		if (temp->left->data >= temp->data) {
			return false;
		}
	}
	if (temp->right) {
		if (temp->right->data <= temp->data) {
			return false;
		}
	}
	return is_BST(temp->left) && is_BST(temp->right);
}
BST& BST::operator=(BST& tree) {
	if (!isEmpty()) {
		empty();
	}
	fill(tree.root);
	return *this;
}
void BST::fill(node* temp) {
	if (temp) {
		insert(temp->data);
		fill(temp->left);
		fill(temp->right);
	}
}
BST::BST(BST& tree) {
	fill(tree.root);
}
void BST::writeFile(string filePath) {
	ofstream file;
	file.open(filePath, ios::ate);
	if (!file.is_open()) {
		cout << "Unable to Open File. Try to Re-Enter Correct Path\n";
		return;
	}
	if (!root) {
		cout << "Tree is Empty. Nothing to Write in File\n";
		return;
	}
	int maxNodes = 0;
	for (int i = 0; i < findLevel(); i++) {
		maxNodes += pow(2, i);
	}
	int* arr = new int[maxNodes+1];
	for (int i = 1; i < maxNodes + 1; i++) {
		arr[i] = -897564231;
	}
	arr[1] = root->data;
	fillArray(root, arr);
	for (int i = 1; i < maxNodes + 1; i++) {
		file << arr[i] << '\n';
	}
	file.close();
	delete arr;
	return;
}
void BST::writeFile(ofstream& file, node* treeNode) {
	if (treeNode) {
		file << treeNode->data << '\n';
		writeFile(file, treeNode->left);
		writeFile(file, treeNode->right);
	}
	return;
}
void BST::fillArray(node* treeNode, int*& arr) {
	if (treeNode) {
		int count = 1;
		while (true) {
			if (arr[count] == treeNode->data) {
				break;
			}
			count++;
		}
		if (treeNode->left) {
			arr[2 * count] = treeNode->left->data;
		}
		if (treeNode->right) {
			arr[2 * count + 1] = treeNode->right->data;
		}
		fillArray(treeNode->left, arr);
		fillArray(treeNode->right, arr);
	}
	return;
}
int BST::findHeight(node* treeNode) {
	if (!treeNode) {
		return -1;
	}
	return max(findHeight(treeNode->left), findHeight(treeNode->right)) + 1;
}
int BST::findLevel() {
	return findHeight(root) + 1;
}
void BST::readFile(string filePath) {
	ifstream file;
	file.open(filePath, ios::in);
	if (!file.is_open()) {
		cout << "Unable to Open File. Try to Re-Enter Correct Path\n";
		return;
	}
	if (root) {
		empty();
	}
	int count;
	int temp;
	for (count = 0; !file.eof(); count++) { file >> temp; }
	file.close();
	file.open(filePath);
	int* arr = new int[count];
	for (int i = 1; i < count; i++) {
		file >> arr[i];
	}
	root = new node;
	root->data = arr[1];
	root->left = root->right = NULL;

	fillTree(root, arr, count);
	file.close();
}
void BST::fillTree(node* treeNode, int*& arr, int& counter) {
	if (treeNode) {
		int count = 1;
		while (count<counter) {
			if (treeNode->data == arr[count]) { break; }
			count++;
		}
		if (arr[2 * count] != -897564231 && 2 * count < counter) {
			treeNode->left = new node;
			treeNode->left->data = arr[2*count];
			treeNode->left->left = treeNode->left->right = NULL;
		}
		else {
			treeNode->left = NULL;
		}
		if (arr[2 * count + 1] != -897564231 && 2*count+1 < counter) {
			treeNode->right = new node;
			treeNode->right->data = arr[2 * count + 1];
			treeNode->right->left = treeNode->right->right = NULL;
		}
		else {
			treeNode->right = NULL;
		}
		fillTree(treeNode->left, arr, counter);
		fillTree(treeNode->right, arr, counter);
	}
	return;
}