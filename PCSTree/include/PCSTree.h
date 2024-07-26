//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------- 

#ifndef PCSTREE_H
#define PCSTREE_H

namespace Azul
{

	// forward declare
	class PCSNode;

	// PCSTree class 
	class PCSTree
	{
	public:
		// Simple data structure
		struct Info
		{
			int currNumNodes;
			int maxNumNodes;
			int currNumLevels;
			int maxNumLevels;
		};

	public:
		// constructor
		PCSTree();

		// copy constructor 
		PCSTree(const PCSTree &in) = delete;

		// assignment operator
		PCSTree &operator = (const PCSTree &in) = delete;

		// destructor
		~PCSTree();

		// get Root
		PCSNode *GetRoot() const;

		// insert
		void Insert(PCSNode *const pInNode, PCSNode *const pParent);

		void setForwardReverse(PCSNode* pInNode);

		PCSNode* findNextNode(PCSNode* pNode);

		PCSNode* findPrevNode(PCSNode* pNode);

		void RemoveLeaf(PCSNode* const pInNode);

		void RemoveSubtree(PCSNode* const pInNode);


		// remove
		void Remove(PCSNode *const pInNode);

		// get info
		void GetInfo(Info &info);
		void Print() const;
		void ReversePrint() const;
		int CountLevels(PCSNode* node);
		void GetLevelRecursive(PCSNode* node, int& levelCount);
		void UpdateLevelStats();

	private:

		// Data
		Info	mInfo;
		PCSNode *pRoot;

	};

}

#endif

// ---  End of File ---
