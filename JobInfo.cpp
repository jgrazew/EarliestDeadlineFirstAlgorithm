#include "stdafx.h"
#include "JobInfo.h"

JobInfo::JobInfo(std::string jobName, int neededTimeUnits, int deadline, int periodUnits) : m_jobName(jobName), m_neededTimeUnits(neededTimeUnits), m_deadline(deadline), m_periodUnits(periodUnits) { }
