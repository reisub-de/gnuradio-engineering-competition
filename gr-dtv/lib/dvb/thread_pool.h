#include <deque>  
#include <string>  
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

namespace gr {
  namespace dtv {
    class ThreadPool
    {
    public:
        ThreadPool(int threadNum = 8);
        ~ThreadPool();

    public:
        size_t addTask(Task *task);
        void   stop();
        int    size();
        Task*  take();

    private:
        int createThreads();
        static void* threadFunc(void * threadData);

    private:
        ThreadPool& operator=(const ThreadPool&);
        ThreadPool(const ThreadPool&);

    private:
        volatile  bool              isRunning_;
        int                         threadsNum_;
        pthread_t*                  threads_;

        std::deque<Task*>           taskQueue_;
        pthread_mutex_t             mutex_;
        pthread_cond_t              condition_;
    };
  } // namespace dtv
} // namespace gr