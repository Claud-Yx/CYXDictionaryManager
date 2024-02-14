#include "common.h"
#include "Word.h"
#include <DictionaryManagerBase.h>

WordID CYXWord::kId{};

std::shared_ptr<CYXWord> CYXWord::Generate( ELanguageType language_type, EWordType word_type, std::string word )
{
	auto new_word = std::make_shared<CYXWord>( language_type, word_type );
	new_word->SetWord( move(word) );

	return new_word;
}

std::pair<CYXWord::ReferenceMap::iterator, CYXWord::ReferenceMap::iterator> CYXWord::GetReferenceRange( EReferenceType type, Channel channel )
{
	std::pair<CYXWord::ReferenceMap::iterator, CYXWord::ReferenceMap::iterator> range{};
	
	if ( _reference_word_ids.size() > channel )
		range = _reference_word_ids[channel].equal_range( type );

	return range;
}

Channel CYXWord::AddChannel()
{
	_reference_word_ids.push_back( {} );
	_meaning_ids.push_back( {} );

	return _reference_word_ids.size() - 1;
}

EErrorCode CYXWord::AddReference( Channel channel, EReferenceType type, WordID word_id )
{
	if ( _reference_word_ids.size() <= channel )
		return EErrorCode::OutOfBorder;

	_reference_word_ids[channel].insert( { type, word_id } );

	return EErrorCode::Succeed;
}

EErrorCode CYXWord::AddMeaning( Channel channel, WordID word_id )
{
	auto word = DictionaryManager::GetWord( word_id );
	
	if ( not word )
		return EErrorCode::Null;
	else if ( _meaning_ids.size() <= channel )
		return EErrorCode::OutOfBorder;
	else if ( word->GetLaunguageType() == GetLaunguageType() )
		return EErrorCode::Invalid;

	_meaning_ids[channel].insert( { word->GetLaunguageType(), word_id } );

	return EErrorCode::Succeed;
}
