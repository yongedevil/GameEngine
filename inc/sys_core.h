#ifndef _SYS_CORE_H
#define _SYS_CORE_H

#include "system.h"
#include "comp_transform.h"

namespace GameEngine
{
	class SysCore : public System
	{
	private:

	public:
		SysCore();
		~SysCore();

		void startup();
		void update(float dt);
		void shutdown();



	};
}


#endif