#pragma once

#ifndef JOBSCHEDULER_H
#define JOBSCHEDULER_H

#include "JobInfo.h"
#include "LeastCommonMultiple.h"
#include <vector>
#include <memory>
#include <iostream>

class JobScheduler {

public:
	JobScheduler() {};
	JobScheduler(std::vector<JobInfo> &initialSchedule);
	int GetPeriodLCM();
	bool Scheduability();
	void Schedule();

private:
	std::shared_ptr<std::vector<JobInfo>> m_jobs;	
};

#endif // !JOBSCHEDULER_H
