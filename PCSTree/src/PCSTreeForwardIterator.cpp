//-----------------------------------------------------------------------------
// Copyright 2024, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeForwardIterator.h"

namespace Azul
{
	PCSTreeForwardIterator::PCSTreeForwardIterator(PCSNode *rootNode)
		:root(rootNode), current(rootNode) {}


	PCSNode *PCSTreeForwardIterator::First()
	{
		this->current = this->root;
		return this->root;
	}

	PCSNode *PCSTreeForwardIterator::Next()
	{
		if (current->GetForward() != nullptr)
		{
			current = current->GetForward();
			return current;
		}
		else
		{
			current = nullptr;
			return nullptr;
		}
	}

	bool PCSTreeForwardIterator::IsDone()
	{
		return this->current == nullptr;
	}

	PCSNode *PCSTreeForwardIterator::Current()
	{
		return this->current;
	}

	bool PCSTreeForwardIterator::IsWithinSubtree(PCSNode* subtreeRoot)
	{
		PCSNode* node = this->current;
		while (node != nullptr)
		{
			if (node == subtreeRoot)
			{
				return true;
			}
			node = node->GetParent();
		}
		return false;
	}

}

// ---  End of File ---
