#include "stdafx.h"
#include <iostream>
#include "JobScheduler.h"
#include "LeastCommonMultiple.h"


int main()
{
	JobInfo item1("stocking", 3, 7, 20);
	JobInfo item2("finishing", 2, 4, 5);
	JobInfo item3("finishing", 2, 8, 10);

	std::vector<JobInfo> itemList = { item1, item2, item3 };

	JobScheduler jobSchedulerTest(itemList);

	int result = jobSchedulerTest.GetPeriodLCM();
	std::cout << "the result is " << result << std::endl;

	int isScheduable = jobSchedulerTest.Scheduability();
	std::cout << isScheduable << std::endl;

	jobSchedulerTest.Schedule();

    return 0;
}
