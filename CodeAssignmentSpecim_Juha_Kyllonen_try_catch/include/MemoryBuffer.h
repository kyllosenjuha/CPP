#ifndef MEMORYBUFFER_H
#define MEMORYBUFFER_H

#include <vector>   //Now I can use vector container
#include <thread>   //Now I can make concurrent processes, using threads
#include <mutex>    //This library is also needed with concurrent processes, using mutex and lock_guard
#include <exception>

#include "Constants.h"

class MemoryBuffer
{
    public:
        MemoryBuffer();
        virtual ~MemoryBuffer();
        std::vector<unsigned short> get_DataFromBuffer() const {return DataFromBuffer;};
        std::vector<int> get_widthAndHeightFromBuffer() const {return widthAndHeightFromBuffer;};
        int get_ProducerCount() const {return ProducerCount;};
        int get_ConsumerCount() const {return ConsumerCount;};
        bool get_ConsumerExecutedAtLeastOnce() const {return ConsumerExecutedAtLeastOnce;};

    private:
        static std::mutex memory_buffer_mutex;
        static std::vector<std::vector<unsigned short>> MemoryBuffer_2D;
        static std::vector<unsigned short> DataFromBuffer;
        static std::vector<std::vector<int>> widthAndHeightBuffer_2D;
        static std::vector<int> widthAndHeightFromBuffer;
        static int fillCount;
        static int emptyCount;
        static int ProducerCount;
        static int ConsumerCount;
        static bool ConsumerExecutedAtLeastOnce;

        friend class ProCon;
};

#endif // MEMORYBUFFER_H
