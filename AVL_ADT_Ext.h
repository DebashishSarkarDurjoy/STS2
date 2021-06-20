#ifndef AVL_ADT_EXT_H_
#define AVL_ADT_EXT_H_
//Provided code. You may use, modify or delete it
template<class TYPE, class KTYPE>
class AVLTreeExt : public AvlTree<TYPE, KTYPE> {
	//Add your private numbers

  void  _traversalD  (void (*process)(TYPE dataProc),
                                         NODE<TYPE>    *root);

   NODE<TYPE> *_insertLN          (NODE<TYPE>  *root,
                                   NODE<TYPE>  *newPtr,
                                 bool&       taller);
public:

  void  AVL_TraverseD(void (*process)(TYPE dataProc));
  bool  AVL_InsertLN (TYPE dataIn);

};

template <class TYPE, class KTYPE>
void  AVLTreeExt<TYPE, KTYPE>
  ::  AVL_TraverseD (void (*process)(TYPE dataProc))
{
//	Statements
	_traversalD (process, this->tree);
	return;
}	// end AVL_Traverse

template <class TYPE, class KTYPE>
void  AVLTreeExt<TYPE, KTYPE>
  ::  _traversalD (void(*process)(TYPE dataproc),
                  NODE<TYPE> *root)
{
//	Statements
	if (root)
	   {
//	    process     (root->data);
	    _traversalD  (process, root->right);
	    process     (root->data);
	    _traversalD  (process, root->left);
	   } //  if
	return;
}	//  _traversal

template <class TYPE, class KTYPE>
bool   AVLTreeExt<TYPE, KTYPE> :: AVL_InsertLN (TYPE dataIn)
{
//	Local Definitions
	NODE<TYPE>  *newPtr;
	bool         taller;

//	Statements
	if (!(newPtr = new NODE<TYPE>))
	   return false;
	newPtr->bal    = EH;
	newPtr->right  = NULL;
	newPtr->left   = NULL;
	newPtr->data   = dataIn;

	this->tree = _insertLN(this->tree, newPtr, taller);
	this->count++;
	return true;
}	//  Avl_Insert

template <class TYPE, class KTYPE>
NODE<TYPE>*  AVLTreeExt<TYPE,  KTYPE>
         ::  _insertLN (NODE<TYPE>  *root,
                      NODE<TYPE>  *newPtr,
                      bool&        taller)
{
//	Statements
	if (!root)
	{
	    root    = newPtr;
	    taller  = true;
	    return  root;
	} //  if NULL tree

	if (newPtr->data.name.last_name < root->data.name.last_name)
	   {
	    root->left = _insertLN(root->left,
	                         newPtr,
	                         taller);
	    if (taller)
	       //  Left subtree is taller
	       switch (root->bal)
	          {
	           case LH: // Was left high--rotate
	                    root = this->leftBalance (root, taller);
	                    break;

	           case EH: // Was balanced--now LH
	                    root->bal = LH;
	                    break;

	           case RH: // Was right high--now EH
	                    root->bal = EH;
	                    taller    = false;
	                    break;
	          } // switch
	   } //  new < node
	else
	   //  new data >= root data
	   {
	    root->right = _insertLN (root->right,
	                           newPtr,
	                           taller);
	    if (taller)
	       // Right subtree is taller
	       switch (root->bal)
	           {
	            case LH: // Was left high--now EH
	                     root->bal = EH;
	                     taller    = false;
	                     break;

	            case EH: // Was balanced--now RH
	                     root->bal = RH;
	                     break;

	            case RH: // Was right high--rotate
	                     root = this->rightBalance (root, taller);
	                     break;
	           } //  switch
	   } //  else new data >= root data
	return root;
}	//  _insert


#endif /* AVL_ADT_EXT_H_ */
