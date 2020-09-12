/*
 * ScreenDisplay.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_

#include "ServerManager.h"
#include <string.h>

namespace npl {

class ScreenDisplay {

public:
	ScreenDisplay();
	int getOrder(string somestr);
	void printMenu();
	virtual ~ScreenDisplay();
};

} /* namespace npl */

#endif /* MANAGEMENT_H_ */
