//-----------------------------------------------------------------------------
// Copyright 2024, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeReverseIterator.h"

namespace Azul
{
	PCSTreeReverseIterator::PCSTreeReverseIterator(PCSNode *rootNode)
		:root(rootNode)
	{

		// This will set current as last in list
		PCSNode* pCurr = rootNode;
		while (pCurr->GetForward() != nullptr)
		{
			pCurr = pCurr->GetForward();
		}
		this->current = pCurr;
		this->lastNode = pCurr;
	}

	PCSNode *PCSTreeReverseIterator::First()
	{
		this->current = this->lastNode;
		return this->lastNode;
	}

	PCSNode *PCSTreeReverseIterator::Next()
	{
		if (current->GetReverse() != nullptr)
		{
			this->current = this->current->GetReverse();
			return this->current;
		}
		else
		{
			current = nullptr;
			return nullptr;
		}
	}

	bool PCSTreeReverseIterator::IsDone()
	{
		return this->current == nullptr;
	}

	PCSNode *PCSTreeReverseIterator::Current()
	{
		return this->current;
	}

}

// ---  End of File ---
