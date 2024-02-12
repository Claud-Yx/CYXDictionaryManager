#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using WordID = uint64;

// Language Type
enum class ELanguageType : uint8
{
	None,
	English,
	Korean,
	Spanish,
	Length = Spanish
};

// Word Type
enum class EWordType : uint8
{
	None,
	Word,
	Idiom,
	ExampleSentence,
	Length = ExampleSentence
};

// Part of Speech
enum class EPartOfSpeech 
{
	None,
	Noun,
	Pronoun,
	Verb,
	Adjective,
	Adverb,
	Determiner,
	Preposition,
	Conjunction,
	Interjection,
	Numeral,
	Postposition
};
using EPOS = EPartOfSpeech;

