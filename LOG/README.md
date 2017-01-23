#### log for c++

how to use
```cpp
	#define SAVELOG  // if you want to save the log info to the file log.txt
	#include "log.hpp" //include log.hpp file


	int main()
	{
		LOGGER log;
		log.LOG();
		log.LOG("%s", "Hello world!");
		log.LOG();
		return 0;
	}
```