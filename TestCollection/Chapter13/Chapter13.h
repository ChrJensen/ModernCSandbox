#pragma once

#ifdef CHAPTER13_EXPORTS
#define DllExport   __declspec( dllexport )
#else
#define DllExport   __declspec(dllimport)
#endif // CHAPTER1_EXPORTS

namespace Chapter13NS
{
	class DllExport Chapter13
	{
	public:
		Chapter13();
		~Chapter13();
		void  HandleSection13_1();
		void  HandleSection13_2();
		void  HandleSection13_3();

	};
}