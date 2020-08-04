#include "urlreader.h"
int main()
{
	std::vector<std::string> libraryUrls;
	ReadLibraryUrl(libraryUrls );
	for (auto i : libraryUrls)
	{
		std::cout << i << std::endl;
	}
}