

#include "PCSTree.h"
#include "PCSNode.h"

namespace Azul
{
	// constructor
	PCSNode::PCSNode()
		:pParent(nullptr),
		pChild(nullptr),
		pNextSibling(nullptr),
		pPrevSibling(nullptr),
		pForward(nullptr),
		pReverse(nullptr)
	{
		memset(&this->pName[0], 0x0, PCSNode::NAME_SIZE);
	}

	// copy constructor
	PCSNode::PCSNode(const PCSNode &in)
	{
		this->pChild = in.pChild;
		this->pNextSibling = in.pNextSibling;
		this->pPrevSibling = in.pPrevSibling;
		this->pParent = in.pParent;
		this->pForward = in.pForward;
		this->pReverse = in.pReverse;

		SetName(in.pName);
	}

	// Specialize Constructor
	PCSNode::PCSNode(PCSNode* const pInParent, PCSNode* const pInChild, PCSNode* const pInNextSibling, PCSNode* const pInPrevSibling, const char* const pInName)
		:pParent(pInParent),
		pChild(pInChild),
		pNextSibling(pInNextSibling),
		pPrevSibling(pInPrevSibling)
	{
		SetName(pInName);
	}

	PCSNode::PCSNode(const char *const pInName)
		:pParent(nullptr),
		pChild(nullptr),
		pNextSibling(nullptr),
		pPrevSibling(nullptr),
		pForward(nullptr),
		pReverse(nullptr)
	{
		SetName(pInName);
	}


	// destructor
	PCSNode::~PCSNode()
	{
		// implement later
	}

	// assignment operator
	PCSNode &PCSNode::operator = (const PCSNode &in)
	{
		// Check for self-assignment
		if (this == &in) {
			return *this;
		}



		// Not a deep copy right now
		this->pChild = in.pChild;
		this->pNextSibling = in.pNextSibling;
		this->pPrevSibling = in.pPrevSibling;
		this->pParent = in.pParent;
		this->pForward = in.pForward;
		this->pReverse = in.pReverse;

		SetName(in.pName);
		return *this;
	}

	void PCSNode::SetParent(PCSNode* const pIn)
	{
		this->pParent = pIn;
	}

	void PCSNode::SetChild(PCSNode* const pIn)
	{
		this->pChild = pIn;
	}

	void PCSNode::SetNextSibling(PCSNode* const pIn)
	{
		this->pNextSibling = pIn;
	}

	void PCSNode::SetPrevSibling(PCSNode* const pIn)
	{
		this->pPrevSibling = pIn;
	}

	void PCSNode::SetForward(PCSNode* const pIn)
	{
		this->pForward = pIn;
	}

	void PCSNode::SetReverse(PCSNode* const pIn)
	{
		this->pReverse = pIn;
	}

	PCSNode* PCSNode::GetParent(void) const
	{
		return this->pParent;
	}

	PCSNode* PCSNode::GetChild(void) const
	{
		return this->pChild;
	}

	PCSNode* PCSNode::GetNextSibling(void) const
	{
		return this->pNextSibling;
	}

	PCSNode* PCSNode::GetPrevSibling(void) const
	{
		return this->pPrevSibling;
	}

	PCSNode* PCSNode::GetForward(void) const
	{
		return this->pForward;
	}

	PCSNode* PCSNode::GetReverse(void) const
	{
		return this->pReverse;
	}

	PCSNode::Code PCSNode::SetName(const char* const pInName)
	{
		if (pInName == nullptr)
		{
			return Code::FAIL_NULL_PTR;
		}
		size_t stringLength = strlen(pInName);
		if (stringLength > PCSNode::NAME_SIZE - 1)
		{
			stringLength = PCSNode::NAME_SIZE - 1;
		}

		memset(this->pName, 0x0, PCSNode::NAME_SIZE);
		memcpy(this->pName, pInName, stringLength);


		return Code::SUCCESS;
	}

	PCSNode::Code PCSNode::GetName(char* const pOutBuffer, unsigned int sizeOutBuffer) const {

		// TODO: Fail return not initialized code

		if (pOutBuffer == nullptr) 
		{
			return Code::FAIL_NULL_PTR;
		}

		memcpy(pOutBuffer, this->pName, sizeOutBuffer);
		if (strlen(this->pName) > sizeOutBuffer)
		{
			pOutBuffer[sizeOutBuffer - 1] = '\0';
		}


		return Code::SUCCESS;
	}

	void PCSNode::PrintNode() const
	{
		Trace::out("%s", this->pName);
	}

	void PCSNode::PrintChildren() const
	{
		const PCSNode* pCurr = this->pChild;

		while (pCurr != nullptr)
		{
			Trace::out("Child: %s", pCurr->pName);
			pCurr = pCurr->GetNextSibling();
		}

	}

	void PCSNode::PrintSiblings() const
	{
		const PCSNode* pCurr = this;

		while (pCurr != nullptr)
		{
			Trace::out("Sibling: %s", pCurr->pName);
			pCurr = pCurr->GetNextSibling();
		}
	}

	int PCSNode::GetNumSiblings() const
	{
		const PCSNode* pCurr = this;
		int count = 0;

		// Need to reset to beginning if not first child
		if (this->pPrevSibling != nullptr)
		{
			pCurr = this->GetParent()->GetChild();
		}

		while (pCurr != nullptr)
		{
			count++;
			pCurr = pCurr->GetNextSibling();
		}
		return count;
	}

	int PCSNode::GetNumChildren() const
	{
		const PCSNode* pCurr = this->pChild;
		int count = 0;

		while (pCurr != nullptr)
		{
			count++;
			pCurr = pCurr->GetNextSibling();
		}

		return count;
	}
}

// ---  End of File ---
