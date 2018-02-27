#pragma once

#ifndef JOBINFO_H
#define JOBINFO_H

#include <string>

class JobInfo {
public:
	JobInfo(std::string jobName, int neededTimeHours, int deadLine, int periodDays);

	//getters
	inline std::string GetJobName() const { return m_jobName; }
	inline int GetNeededTimeUnits() const { return m_neededTimeUnits; }
	inline int GetDeadline() const { return m_deadline; }
	inline int GetPeriodUnits() const { return m_periodUnits; }

private:
	std::string m_jobName;
	int m_neededTimeUnits;
	int m_deadline;
	int m_periodUnits;

};
#endif // !JOBINFO_H
