#pragma once

#ifdef CHAPTER1_EXPORTS
#define DllExport   __declspec( dllexport )
#else
#define DllExport   __declspec(dllimport)
#endif // CHAPTER1_EXPORTS

namespace Chapter1NS 
{
	 class DllExport Chapter1
	{
	public:
		Chapter1();
		~Chapter1();
		void  HandleSection1_1();
		void HandleSection1_2();

	};
}

