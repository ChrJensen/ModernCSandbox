#pragma once
#ifdef CHAPTER2_EXPORTS
#define DllExport2   __declspec( dllexport )
#else
#define DllExport2   __declspec(dllimport)
#endif // CHAPTER2_EXPORTS
namespace Chapter2NS 
{
	class DllExport2 Chapter2
	{
	public:
		Chapter2();
		~Chapter2();
		void HandleSection2_1();
		void HandleSection2_4();
		void HandleSection2_5();
	};
}

