#include "Header.h"

int main() {
	int option;
	do {
		cout << "Select Question to Run: \n";
		cout << "1. Q1\n2. Q2\nEnter Option: ";
		cin >> option;
	} while (option < 1 || option>2);
	if (option == 1) {
		cout << "-------------- BST TREE IMPLEMENTATION --------------\n";
		int num = 0;
		bool flag = true;
		BST tree;
		while (flag) {
			do {
				cout << "Select Option: \n";
				cout << "1. Insert\n2. Remove\n3. Retrieve\n4. Size\n5. Is Empty\n6. Print Inorder\n7. Print Preorder\n8. Print Postorder\n9. Print Descending\n10. Print Less Than\n11. Empty Tree\n12.isBST\n13.Tree Levels\n14. EXIT\nEnter Option: ";
				cin >> option;
			} while (option < 1 || option>14);
			switch (option) {
			case 1:
				cout << "Enter Number: ";
				cin >> num;
				tree.insert(num);
				break;
			case 2:
				cout << "Enter Number: ";
				cin >> num;
				tree.remove(num);
				cout << endl;
				break;
			case 3:
				cout << "Enter Num: ";
				cin >> num;
				cout << num << " is in the tree: " << boolalpha << tree.retrieve(num) << endl;
				break;
			case 4:
				cout << "Size: " << tree.size() << endl;
				break;
			case 5:
				cout << "Tree is Empty: " << boolalpha << tree.isEmpty() << endl;
				break;
			case 6:
				tree.displayInOrder();
				break;
			case 7:
				tree.displayPreOrder();
				break;
			case 8:
				tree.displayPostOrder();
				break;
			case 9:
				tree.displayDescending();
				break;
			case 10:
				cout << "Enter Num: ";
				cin >> num;
				tree.displayLessThan(num);
				break;
			case 11:
				tree.empty();
				break;
			case 12:
				cout << "The Tree is BST: " << boolalpha << tree.isBST() << endl;
				break;
			case 13:
				cout << "The Tree has " << tree.findLevel() << " Levels\n";
				break;
			case 14:
				flag = false;
				break;
			}
			if (!flag) { break; }
		}
	}
	else {
		cout << "-------------- FILE READ WRITE BST TREE  --------------\n";
		int num = 0;
		bool flag = true;
		BST tree;
		while (flag) {
			do {
				cout << "Select Option: \n";
				cout << "1. Insert\n2. Remove\n3. Retrieve\n4. Size\n5. Is Empty\n6. Print Inorder\n7. Print Preorder\n8. Print Postorder\n9. Print Descending\n10. Print Less Than\n11. Empty Tree\n12. isBST\n13. Tree Levels\n14. Write to File\n15. Read From File\n16. EXIT\nEnter Option: ";
				cin >> option;
			} while (option < 1 || option>16);
			switch (option) {
			case 1:
				cout << "Enter Number: ";
				cin >> num;
				tree.insert(num);
				break;
			case 2:
				cout << "Enter Number: ";
				cin >> num;
				tree.remove(num);
				cout << endl;
				break;
			case 3:
				cout << "Enter Num: ";
				cin >> num;
				cout << num << " is in the tree: " << boolalpha << tree.retrieve(num) << endl;
				break;
			case 4:
				cout << "Size: " << tree.size() << endl;
				break;
			case 5:
				cout << "Tree is Empty: " << boolalpha << tree.isEmpty() << endl;
				break;
			case 6:
				tree.displayInOrder();
				break;
			case 7:
				tree.displayPreOrder();
				break;
			case 8:
				tree.displayPostOrder();
				break;
			case 9:
				tree.displayDescending();
				break;
			case 10:
				cout << "Enter Num: ";
				cin >> num;
				tree.displayLessThan(num);
				break;
			case 11:
				tree.empty();
				break;
			case 12:
				cout << "The Tree is BST: " << boolalpha << tree.isBST() << endl;
				break;
			case 13:
				cout << "The Tree has " << tree.findLevel() << " Levels\n";
				break;
			case 14:
				cout << "Writing Data to /'./Text.txt/' ...\n";
				tree.writeFile("./Text.txt");
				break;
			case 15:
				cout << "Reading Data From /'./Text.txt/' ...\n";
				tree.readFile("./Text.txt");
				break;
			case 16:
				flag = false;
				break;
			}
			if (!flag) { break; }
		}
	}
	return 0;
}
