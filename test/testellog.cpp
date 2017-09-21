#include <iostream>

#include "../ellog.h"

// There are two ways to share repository
// one way is:
// SHARE_EASYLOGGINGPP(sharedLoggingRepository())

// Other way is
// INITIALIZE_NULL_EASYLOGGINGPP
// and in main function:
// int main(int argc, char** argv) {
//     el::Helpers::setStorage(sharedLoggingRepository());
//     ...
//     START_EASYLOGGINGPP(argc, argv);
//     ...
// }

INITIALIZE_NULL_EASYLOGGINGPP

int main() {
	mim::ellog elg("test");
	elg->info("This is after reconfiguration from main");
	return 0;
}
