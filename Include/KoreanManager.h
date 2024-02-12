#pragma once

#include "DictionaryManagerBase.h"

class CYXKoreanManager :
    public CYXDictionaryManagerBase
{
protected:
	CYXKoreanManager() :
		CYXDictionaryManagerBase{ ELanguageType::Korean } {}

public:
	static CYXKoreanManager& Get()
	{
		static CYXKoreanManager kInst;
		return kInst;
	}
};

