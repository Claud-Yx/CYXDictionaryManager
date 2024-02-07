#pragma once

#include "Common.h"

class CYXWordBase
{
protected:
	CYXWordBase() = delete;
	CYXWordBase(ELanguageType language_type)
		: _language_type{ language_type } {}

protected:
	const ELanguageType _language_type{};

};

