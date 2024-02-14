#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using WordID = uint32;
using Channel = uint64;

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
	Example,	// This must be a sentence.
	Length = Example
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

// Reference Word Type
enum class EReferenceType
{
	None,
	Synonym,
	Antonym,
	Example	// This must be a sentence.
};

// Word Transformation Type
enum class EFormType
{
	None,
	PastTense,
	PastParticiple,
	PresentTense,
	PresentParticiple,
	Singular,
	Plural,
	Feminine,
	Masculine,
	Neuter
};

// Error Code
enum class EErrorCode : uint8
{
	Succeed,
	Null,
	OutOfBorder,
	NoMatch,
	Invalid,
};


const char* GetErrorMessage( EErrorCode error_code )
{
	const char* error_message{};

	switch ( error_code )
	{
	case EErrorCode::Succeed:
		error_message = "ErrorCode::Succeed -> No Errors";
		break;
	case EErrorCode::Null:
		error_message = "ErrorCode::Null -> The value is null pointer";
		break;
	case EErrorCode::OutOfBorder:
		error_message = "ErrorCode::OutOfBorder -> The value is out of border";
		break;
	case EErrorCode::NoMatch:
		error_message = "ErrorCode::NoMatch -> The value doesn't match the other";
		break;
	case EErrorCode::Invalid:
		error_message = "ErrorCode::Invalid -> The value is invalid.";
		break;
	}

	return error_message;
}