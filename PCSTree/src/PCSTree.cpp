//-----------------------------------------------------------------------------
// Copyright 2024, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"
#include <PCSTreeForwardIterator.h>
#include <PCSTreeReverseIterator.h>

namespace Azul
{

	// constructor
	PCSTree::PCSTree()
		:pRoot(nullptr)
	{
		this->mInfo.currNumLevels = 0;
		this->mInfo.currNumNodes = 0;
		this->mInfo.maxNumLevels = 0;
		this->mInfo.maxNumNodes = 0;
	};

	// destructor
	PCSTree::~PCSTree()
	{
		//
	};

	// get Root
	PCSNode* PCSTree::GetRoot() const
	{
		return this->pRoot;
	}

	// insert
	void PCSTree::Insert(PCSNode* const pInNode, PCSNode* const pParent)
	{
		// Increment node number stats
		this->mInfo.currNumNodes++;
		if (this->mInfo.maxNumNodes < this->mInfo.currNumNodes)
		{
			this->mInfo.maxNumNodes = this->mInfo.currNumNodes;
		}

		// Case where first on list
		if (pParent == nullptr)
		{
			this->pRoot = pInNode;
			this->mInfo.currNumLevels++;

			if (this->mInfo.maxNumLevels < this->mInfo.currNumLevels)
			{
				this->mInfo.maxNumLevels = this->mInfo.currNumLevels;
			}
			
			pInNode->SetForward(nullptr);
			pInNode->SetReverse(nullptr);
			return;
		}

		PCSNode* formerFront = pParent->GetChild();


		pParent->SetChild(pInNode);
		pInNode->SetParent(pParent);

		// Add to front
		pInNode->SetNextSibling(formerFront);
		pInNode->SetPrevSibling(nullptr);
		pInNode->SetChild(nullptr);

		if (formerFront != nullptr)
		{
			formerFront->SetPrevSibling(pInNode);
		}

		setForwardReverse(pInNode);
		UpdateLevelStats();
	}


	void PCSTree::setForwardReverse(PCSNode* pNode)
	{
		assert(pNode != nullptr);

		// Set the forward pointer
		PCSNode* forward = findNextNode(pNode);
		pNode->SetForward(forward);
		

		// Set the reverse pointer
		PCSNode* reverse = findPrevNode(pNode);
		pNode->SetReverse(reverse);


		// Update neighboring nodes
		if (forward != nullptr)
		{
			forward->SetReverse(pNode);
		}
		if (reverse != nullptr)
		{
			reverse->SetForward(pNode);
		}
	}


	PCSNode* PCSTree::findNextNode(PCSNode* pNode)
	{

		// First check if there's a child
		if (pNode->GetChild() != nullptr)
		{
			return pNode->GetChild();
		}

		// Set to next sibling, if no next, keep checking up the tree if there are siblings
		PCSNode* current = pNode;
		while (current != nullptr)
		{
			if (current->GetNextSibling() != nullptr)
			{
				return current->GetNextSibling();
			}
			current = current->GetParent();
		}

		return nullptr; // No next node found
	}

	PCSNode* PCSTree::findPrevNode(PCSNode* pNode)
	{
		// Root should never be passed to this method
		assert(pNode->GetParent() != nullptr);

		// If the node has a previous sibling, find the rightmost node in that subtree
		if (pNode->GetPrevSibling() != nullptr)
		{
			PCSNode* reverseNode = pNode->GetPrevSibling();

			// Find the rightmost descendant of the previous sibling
			while (reverseNode->GetChild() != nullptr)
			{
				reverseNode = reverseNode->GetChild();
				while (reverseNode->GetNextSibling() != nullptr)
				{
					reverseNode = reverseNode->GetNextSibling();
				}
			}
			return reverseNode;
		}

		// If no previous sibling, the reverse node is the parent
		return pNode->GetParent();
	}

	// Remove
	void PCSTree::RemoveLeaf(PCSNode* const pInNode)
	{
		if (pInNode == nullptr)
		{
			return;
		}

		this->mInfo.currNumNodes--;


		PCSNode* parent = pInNode->GetParent();
		PCSNode* previousSib = pInNode->GetPrevSibling();
		PCSNode* nextSib = pInNode->GetNextSibling();
		PCSNode* reverseNode = pInNode->GetReverse();
		PCSNode* forwardNode = pInNode->GetForward();

		// Case where root
		pInNode->SetParent(nullptr);
		if (pInNode == this->pRoot)
		{
			this->pRoot->SetChild(nullptr);
			this->pRoot = nullptr;
		}

		// Only child
		else if (previousSib == nullptr && nextSib == nullptr)
		{
			parent->SetChild(nullptr);
		}

		// Last sibling
		else if (previousSib != nullptr && nextSib == nullptr)
		{
			previousSib->SetNextSibling(nullptr);
		}

		// First child
		else if (previousSib == nullptr && nextSib != nullptr)
		{
			nextSib->SetPrevSibling(nullptr);
			parent->SetChild(nextSib);
		}
		// Middle child
		else if (previousSib != nullptr && nextSib != nullptr)
		{
			previousSib->SetNextSibling(nextSib);
			nextSib->SetPrevSibling(previousSib);
		}

		if (reverseNode != nullptr)
		{
			reverseNode->SetForward(forwardNode);
		}

		if (forwardNode != nullptr)
		{
			forwardNode->SetReverse(reverseNode);
		}

		pInNode->SetForward(nullptr);
		pInNode->SetReverse(nullptr);

		// Reset 
		pInNode->SetNextSibling(nullptr);
		pInNode->SetPrevSibling(nullptr);
		pInNode->SetParent(nullptr);
	}

	void PCSTree::RemoveSubtree(PCSNode* const pInNode)
	{
		if (pInNode == nullptr) return;

		if (pInNode->GetChild() != nullptr)
		{
			RemoveSubtree(pInNode->GetChild());
		}
		if (pInNode->GetNextSibling() != nullptr)
		{
			RemoveSubtree(pInNode->GetNextSibling());
		}

		RemoveLeaf(pInNode);
	}

	// Remove
	void PCSTree::Remove(PCSNode* const pInNode)
	{
		PCSNode* pChild = pInNode->GetChild();
		if (pChild == nullptr)
		{
			RemoveLeaf(pInNode);
			UpdateLevelStats();
			return;
		}
		else
		{
			RemoveSubtree(pChild);
			RemoveLeaf(pInNode);
			UpdateLevelStats();
		}
	}

	// get tree info
	void PCSTree::GetInfo(Info& info)
	{
		info.currNumLevels = this->mInfo.currNumLevels;
		info.currNumNodes = this->mInfo.currNumNodes;
		info.maxNumLevels = this->mInfo.maxNumLevels;
		info.maxNumNodes = this->mInfo.maxNumNodes;
	}

	void PCSTree::Print() const
	{
		PCSTreeForwardIterator it(this->pRoot);
		int count = 0;
		Trace::out("\nForward Print:\n");
		while (!it.IsDone())
		{
			it.Current()->PrintNode();
			it.Next();

			count++;
			if (count % 4 == 0)
			{
				Trace::out("\n");
			}

			if (it.Current() != nullptr)
			{
				Trace::out(" --> ");
			}
		}
		Trace::out("\n");
	}

	void PCSTree::ReversePrint() const
	{
		PCSTreeReverseIterator it(pRoot);
		int count = 0;
		Trace::out("\nReverse Print:\n");
		while (!it.IsDone())
		{
			it.Current()->PrintNode();
			it.Next();

			count++;
			if (count % 4 == 0)
			{
				Trace::out("\n");
			}

			if (it.Current() != nullptr)
			{
				Trace::out(" --> ");
			}
		}
		Trace::out("\n");
	}

	int PCSTree::CountLevels(PCSNode* node)
	{
		int count = 0;

		while (node != nullptr)
		{
			node = node->GetParent();
			if (node != nullptr)
			{

			}

			count++;
		}
		return count;
	}

	void PCSTree::GetLevelRecursive(PCSNode* node, int& levelCount)
	{
		if (node == nullptr) return;

		if (node->GetChild() != nullptr)
		{
			GetLevelRecursive(node->GetChild(), levelCount);
		}
		if (node->GetNextSibling() != nullptr)
		{
			GetLevelRecursive(node->GetNextSibling(), levelCount);
		}

		int currentLevel = CountLevels(node);
		if (currentLevel > levelCount)
		{
			levelCount = currentLevel;
		}

	}

	void PCSTree::UpdateLevelStats()
	{
		if (this->pRoot == nullptr)
		{
			this->mInfo.currNumLevels = 0;
			return;
		}

		int levelCount = 0;
		GetLevelRecursive(this->pRoot, levelCount);
		this->mInfo.currNumLevels = levelCount;

		if (levelCount > this->mInfo.maxNumLevels)
		{
			this->mInfo.maxNumLevels = levelCount;
		}

	}

}

// ---  End of File ---
