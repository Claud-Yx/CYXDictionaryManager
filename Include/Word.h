#pragma once

#include "common.h"
#include <string>
#include <queue>
#include <vector>
#include <memory>
#include <unordered_map>

class CYXWord
{
// Using Statements
public:
	using ReferenceMap = std::unordered_multimap<EReferenceType, WordID>;
	using MeaningMap = std::unordered_multimap<ELanguageType, WordID>;

private:
	static WordID kId;
	inline static std::queue<WordID> kBlankIdQueue{};

protected:
	CYXWord() = delete;
	CYXWord( ELanguageType language_type, EWordType word_type )
		: _language_type{ language_type }, _word_type{ word_type } 
	{
		auto& id = const_cast<WordID&>(_id);

		if ( kBlankIdQueue.empty() )
			id = kId++;
		else
		{
			auto blank_id = kBlankIdQueue.front();
			kBlankIdQueue.pop();
			id = blank_id;
		}
	}
	
// Generator
public:
	static std::shared_ptr<CYXWord> Generate( ELanguageType language_type, EWordType word_type, std::string word );

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

// Reference Section
public:
	// If return value is nullptr, it's failure.
	// Or if return values are same, it's failure, too.
	std::pair<ReferenceMap::iterator, ReferenceMap::iterator> GetReferenceRange( EReferenceType type, Channel channel );
	
	// Return added channel number
	Channel AddChannel();

	EErrorCode AddReference( Channel channel, EReferenceType type, WordID word_id);
	EErrorCode AddMeaning( Channel channel, WordID word_id );

// Main Attribute Section
protected:
	const ELanguageType _language_type;
	const EWordType _word_type;
	const WordID _id{};

	std::string _word{};
	std::unordered_multimap<EFormType, std::string> _forms{};

private:
	// _reference_word_ids[Channel][ReferenceType] -> WordIDs
	std::vector<ReferenceMap> _reference_word_ids{};
	std::vector<MeaningMap> _meaning_ids{};
};