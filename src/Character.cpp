#include "Character.h"

bool Character::isHighSurrogate(char ch)
{
	return ch >= MIN_HIGH_SURROGATE && ch < (MAX_HIGH_SURROGATE + 1);
}