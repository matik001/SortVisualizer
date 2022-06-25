#ifndef SORTVISUALIZER_DISPATCHER_H
#define SORTVISUALIZER_DISPATCHER_H
#include <queue>
#include <functional>
#include <mutex>

class Dispatcher {
    std::queue< std::function<void()> > _queue;
public:
    std::mutex mutex;
    void execute(std::function<void()> func);
    void update();
};


#endif //SORTVISUALIZER_DISPATCHER_H
