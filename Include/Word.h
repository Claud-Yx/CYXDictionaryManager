#pragma once

#include "common.h"
#include <string>
#include <queue>

class CYXWord
{
protected:
	CYXWord() = delete;
	CYXWord(ELanguageType language_type, EWordType word_type)
		: _language_type{ language_type }, _word_type{ word_type }, _id{ kId++ } {}

// Getter/Setter
public:
	inline const ELanguageType& GetLaunguageType() const
	{
		return _language_type;
	}

	inline const EWordType& GetWordType() const
	{
		return _word_type;
	}

	inline const std::string& GetWord() const
	{
		return _word;
	}

	inline const WordID GetId() const
	{
		return _id;
	}

	inline std::string& GetWordRef()
	{
		return _word;
	}

	inline void SetWord( std::string&& new_word )
	{
		_word = std::move(new_word);
	}

protected:
	const ELanguageType _language_type{};
	const EWordType _word_type{};
	const WordID _id;
	std::string _word{};

private:
	static WordID kId;
	inline static std::queue<WordID> kBlankIdQueue{};
};

