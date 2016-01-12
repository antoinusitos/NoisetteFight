#include "stdafx.h"
#include "Combo.h"


Combo::Combo()
{
	combos = new std::vector<Hit*>();

}


Combo::~Combo()
{
	delete(combos);
}