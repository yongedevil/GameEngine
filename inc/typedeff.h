#ifndef TYPEDEFF_H
#define TYPEDEFF_H

namespace GameEngine
{
	enum eComponentTypes
	{
		eCT_BASE = 0,
		//add component types here

		eCT_NUMTYPES
	};
	typedef unsigned long ComponentID;

	typedef unsigned long EntityID;

	enum eSystemTypes
	{
		eST_BASE = 0,
		//add system types here
		eST_NUMTYPES
	};
	typedef unsigned long SystemID;
}

#endif