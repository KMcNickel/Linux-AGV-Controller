#ifndef JOB_MANAGER_H_
#define JOB_MANAGER_H_

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
#include "global_defines.h"

class JobManager
{
    public:
        typedef void (*jobTask)(void * handle);

        struct job_t
        {
            jobTask task;
            void * data;
            std::chrono::milliseconds period;
            bool repeat;
            std::chrono::time_point<DEFAULT_CLOCK> lastRun;
        };
        
        job_t * addOneShotJob(jobTask task, void * handle, int periodMs);
        job_t * addRepeatingJob(jobTask task, void * handle, int periodMs);
        void removeJob(job_t * job);
        void runJobImmediately(job_t * job);

        void checkJobs();

    private:
        std::list<job_t> activeJobs;

        void runJob(job_t * job);
};

#endif