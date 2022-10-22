#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <csignal>
#include <iostream>
#include <mosquitto.h>
#include <list>

#include <linux/can.h>

#include "spdlog/spdlog.h"
#include "include/global_defines.h"
#include "include/job_manager.h"

JobManager::job_t * JobManager::addOneShotJob(jobTask task, void * handle, int periodMs)
{
    job_t newJob;

    newJob.task = task;
    newJob.data = handle;
    newJob.period;
    newJob.repeat = false;
    newJob.lastRun = DEFAULT_CLOCK::now();

    activeJobs.push_back(newJob);

    return &(activeJobs.back());
}

JobManager::job_t * JobManager::addRepeatingJob(jobTask task, void * handle, int periodMs)
{
    job_t newJob;
    
    newJob.task = task;
    newJob.data = handle;
    newJob.period;
    newJob.repeat = true;
    newJob.lastRun = DEFAULT_CLOCK::now();

    activeJobs.push_back(newJob);

    return &(activeJobs.back());
}

void JobManager::removeJob(job_t * job)
{
    activeJobs.remove(*job);
}

void JobManager::runJobImmediately(job_t * job)
{
    runJob(job);
}

void JobManager::checkJobs()
{
    std::chrono::time_point<DEFAULT_CLOCK> now = DEFAULT_CLOCK::now();

    std::for_each(activeJobs.begin(), activeJobs.end(), [this, now](job_t job)
    {
        if(job.period.count() == 0 || now - job.lastRun > job.period)
            runJob(&job);
    });
}

void JobManager::runJob(job_t * job)
{
    if(job->task != NULL)
        job->task(job->data);

    if(!job->repeat)
        activeJobs.remove(*job);
    else
        job->lastRun = DEFAULT_CLOCK::now();
}