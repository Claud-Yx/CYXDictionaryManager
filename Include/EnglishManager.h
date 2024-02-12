#pragma once

#include "DictionaryManagerBase.h"

class CYXEnglishManager :
    public CYXDictionaryManagerBase
{
protected:
	CYXEnglishManager() :
		CYXDictionaryManagerBase{ ELanguageType::English } {}

public:
	static CYXEnglishManager& Get()
	{
		static CYXEnglishManager kInst;
		return kInst;
	}
};

