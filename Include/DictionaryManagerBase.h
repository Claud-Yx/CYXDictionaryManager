#pragma once

#include "common.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class CYXDictionaryManagerBase
{
protected:
	CYXDictionaryManagerBase() = delete;
	CYXDictionaryManagerBase( ELanguageType language_type ) :
		_language_type{ language_type } {}

// Interface Function Section
public:
	virtual void AddNewWord(std::shared_ptr<class CYXWord> new_word);
	virtual void DeleteWord(WordID word_id);
	virtual std::vector<WordID> SearchWords(std::string word_name);

	static std::shared_ptr<class CYXWord> GetWord(WordID word_id);

// Word Archive Section
protected
	 :
	const ELanguageType _language_type{};

private:
	inline static std::unordered_map<WordID, std::shared_ptr<class CYXWord>> kWordArchive{};
};

using DictionaryManager = CYXDictionaryManagerBase;