#include "stdafx.h"
#include "JobScheduler.h"

JobScheduler::JobScheduler(std::vector<JobInfo> &initialSchedule) : m_jobs(new std::vector<JobInfo>)
{
	for (auto item : initialSchedule)
	{
		m_jobs->push_back(item);
	}
	
}

int JobScheduler::GetPeriodLCM()
{
	std::vector<int> tempPeriodsVector;
	
	for (int i = 0; i != m_jobs->size(); ++i)
	{
		tempPeriodsVector.push_back(m_jobs->at(i).GetPeriodUnits());
	}
	
	LeastCommonMultiple lcm(tempPeriodsVector);
	int result = lcm.GetLcmForVector();

	return result;
}

bool JobScheduler::Scheduability()
{
	bool isJobScheduable = false;
	double condition = 0;

	for (int i = 0; i != m_jobs->size(); ++i)
	{
		condition += (m_jobs->at(i).GetNeededTimeUnits() / (double)m_jobs->at(i).GetPeriodUnits());
	}

	if (condition <= 1)
		isJobScheduable = true;

	return isJobScheduable;
}

void JobScheduler::Schedule()
{
	//closest deadline i.e. the distance to the earliest deadline
	int earliestDeadline;
	//closest deadline index
	int earliestDeadlineIndex;
	//the table of Scheduling
	std::vector<int> schedulingTable(m_jobs->size());
	//table holds the remaining execution time for each process
	std::vector<int> remainingCapacity(m_jobs->size());
	//table holds the number between current time and next deadline for each process
	std::vector<int> nextDeadline(m_jobs->size());
	//must update variable below to when we reach a new period and to reset our capacity and start new period
	std::vector<int> processOnlineNewPeriod;

	//variable initialization
	for (int i = 0; i != m_jobs->size(); ++i)
	{
		nextDeadline.at(i) = m_jobs->at(i).GetDeadline();
		remainingCapacity.at(i) = m_jobs->at(i).GetNeededTimeUnits();
		processOnlineNewPeriod.push_back(0);
	}

	//NOTE: MIGHT WANT TO CHECK TO MKE SURE JOB IS DO ABLE BY CALLING THE SCHEDUABILITY FUNCTION 1ST

	//get periods LCM for scheduling loop
	std::vector<int> tempProcessesLcmVector;
	for (int i = 0; i != m_jobs->size(); ++i)
	{
		tempProcessesLcmVector.push_back(m_jobs->at(i).GetPeriodUnits());
	}
	LeastCommonMultiple LcmForPeriodUnits(tempProcessesLcmVector);

	int periodUnitsLcm = LcmForPeriodUnits.GetLcmForVector();

	//scheduling loop which has a time frame equal to the LCM for all jobs
	for (int i = 0; i != periodUnitsLcm; ++i)
	{
		//getting the earliest deadline
		earliestDeadline = periodUnitsLcm;
		earliestDeadlineIndex = -1;

		//this loop will look at each job and determine which one should be scheduled next
		for (int j = 0; j != m_jobs->size(); ++j)
		{
			//check if there is still capaicty to execute for the job at the given index
			if (remainingCapacity.at(j) > 0)
			{
				//if the earliest deadline is greater then we must change
				if (earliestDeadline > nextDeadline.at(j))
				{
					earliestDeadline = nextDeadline.at(j);
					earliestDeadlineIndex = j;
				}
			}
		}

		//execute earliest deadline process
		std::cout << earliestDeadlineIndex << std::endl;
		std::cout << "(" << i << "," << i + 1 << ")" << earliestDeadlineIndex << std::endl;

		//after we execute we must decrement capacity b/c we just decrement 1 unit
		if (earliestDeadlineIndex != -1)
		{
			remainingCapacity.at(earliestDeadlineIndex)--;
		}		

		for (int j = 0; j != m_jobs->size(); ++j)
		{
			if (processOnlineNewPeriod.at(j) == (m_jobs->at(j).GetPeriodUnits() - 1))
			{
				//MAKE A METHOD FOR THIS
				//we we have exceeed the deadline
				if (remainingCapacity.at(j) > 0)
				{
					std::cout << "process " << j << "'s deadline has been exceeded" << std::endl;
				}

				nextDeadline.at(j) = m_jobs->at(j).GetDeadline();
				//reset capacity
				remainingCapacity.at(j) = m_jobs->at(j).GetNeededTimeUnits();
				processOnlineNewPeriod.at(j) = 0;
			}
			else
			{
				if (nextDeadline.at(j) > 0)
				{
					//decrement b/c deadline is closer
					nextDeadline.at(j)--;
				}

				processOnlineNewPeriod.at(j)++;
			}
		}

	}//end scheduling for loop
}
