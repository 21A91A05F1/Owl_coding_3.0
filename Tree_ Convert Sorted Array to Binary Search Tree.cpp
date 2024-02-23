/*
To convert the given sorted array into binary search tree.
Bst properties: 
-> The elements which are left to any root of a subtree will be smaller than the root node of that particular root.and vice versa.
Approach:
consider the middle most element and make that element as root node and make a recursive call on left of the array. so that make the middle as 
root of the tree.
*/
TNode* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	TNode* root = newNode(arr[mid]);

	/* Recursively construct the left subtree
	and make it left child of root */
	root->left = sortedArrayToBST(arr, start, mid - 1);

	/* Recursively construct the right subtree
	and make it right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}



