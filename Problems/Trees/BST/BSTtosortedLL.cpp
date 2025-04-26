/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
class pairx
{
	public:
	  Node<int>* head;
	  Node<int>* tail;
	  pairx()
	    {
			head=NULL;
			tail=NULL;
		}
};
pairx HelperConst(BinaryTreeNode<int>* root)
{
 
  if (root == NULL) {
    pairx p;
    p.head = NULL;
    p.tail = NULL;
    return p;
	}
        pairx  p1=HelperConst(root->left);
        pairx p2=HelperConst(root->right);
	Node<int>* node=new Node<int>(root->data);
       if(p1.head == NULL)
	    {
			p1.head=node;
			p1.tail=node;
		}
		else
		{
			p1.tail->next=node;
			p1.tail=node;
		}
		p1.tail->next=p2.head;
		if(p2.head)
	    	p1.tail=p2.tail;
		
       /* pairx x;
		x.head=p1.head;
		x.tail=p1.tail;
		return x;*/
        return p1;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
     //  return HelperConst(root).head;
        
        pairx p=HelperConst(root);
	return p.head;

}