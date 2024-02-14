#include "common.h"
#include "DictionaryManagerBase.h"
#include <Word.h>

void CYXDictionaryManagerBase::AddNewWord( std::shared_ptr<class CYXWord> new_word )
{
	kWordArchive.try_emplace( new_word->GetId(), new_word );
}

void CYXDictionaryManagerBase::DeleteWord( WordID word_id )
{
	kWordArchive.erase( word_id );
}

std::vector<WordID> CYXDictionaryManagerBase::SearchWords( std::string word_name )
{
	std::vector<WordID> Ids{};

	for ( auto& [key, value] : kWordArchive )
	{
		if ( value->GetWord() == word_name )
			Ids.push_back( key );
	}

	return Ids;
}

std::shared_ptr<class CYXWord> CYXDictionaryManagerBase::GetWord( WordID word_id )
{
	if ( not kWordArchive.contains( word_id ) )
		return nullptr;
	return kWordArchive[word_id];
}
