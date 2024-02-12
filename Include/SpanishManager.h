#pragma once

#include "DictionaryManagerBase.h"

class CYXSpanishManager :
    public CYXDictionaryManagerBase
{
protected:
	CYXSpanishManager() :
		CYXDictionaryManagerBase{ ELanguageType::Spanish } {}

public:
	static CYXSpanishManager& Get()
	{
		static CYXSpanishManager kInst;
		return kInst;
	}
};

