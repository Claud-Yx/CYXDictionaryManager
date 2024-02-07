#pragma once

#include "Common.h"
#include <vector>
#include <string>
#include <memory>

class CYXDictionaryManagerBase
{
private:
	CYXDictionaryManagerBase();

public:
	static CYXDictionaryManagerBase& Get()
	{
		static CYXDictionaryManagerBase kInst;
		if (kInst.kLanguageType == ELanguageType::None)
		{
			kInst.SetLanguageType(kLanguageType);
		}
	}

// Interface Function Section
protected:
	virtual void AddNewWord(std::shared_ptr<class CYXWordBase> new_word);
	virtual void ModifyWord(std::string word_name);
	virtual void DeleteWord(std::string word_name);
	virtual void SearchWord(std::string word_name);

private:
	// Occur changing const variation. ==== !!
	static void SetLanguageType(ELanguageType new_language_type)
	{
		const int constVar = 10;

		if (kLanguageType == ELanguageType::None)
		{
			auto& language_type = const_cast<ELanguageType&>(kLanguageType);
			language_type = new_language_type;
		}
	}

protected:
	const static ELanguageType kLanguageType{};
	std::vector<std::shared_ptr<class CYXWordBase>> _word_list{};
};

