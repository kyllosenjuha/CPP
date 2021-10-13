#include "ProCon.h"
#include <iostream>  //There are for example cout and endl functions.

ProCon::ProCon()
{
    //ctor
}

ProCon::~ProCon()
{
    //dtor
}

void ProCon::producer(unsigned short* dataPtr, int width, int height)
{
    while(true)
    {
        std::lock_guard<std::mutex> guard(memory_buffer_mutex);

        if(fillCount < MAX_MEMORYBUFFER_DEPTH)
        {
            try
            {
                MemoryBuffer_2D.push_back(std::vector<unsigned short>());
                widthAndHeightBuffer_2D.push_back(std::vector<int>());
            }
            catch(std::bad_alloc& ba)
            {
                std::cerr << "producer, MemoryBuffer_2D or widthAndHeightBuffer_2D, bad_alloc caught:\n" << ba.what() << '\n';
                exit(0);
            }

            for(int index {}; index < width*height; ++index)
            {
                try
                {
                    MemoryBuffer_2D[fillCount].push_back(*(dataPtr+index));
                }
                catch(std::bad_alloc& ba)
                {
                    std::cerr << "producer, MemoryBuffer_2D bad_alloc caught:\n" << ba.what() << '\n';
                    exit(0);
                }
            }

            try
            {
                widthAndHeightBuffer_2D[fillCount].push_back(width);
                widthAndHeightBuffer_2D[fillCount].push_back(height);
            }
            catch(std::bad_alloc& ba)
            {
                std::cerr << "producer, widthAndHeightBuffer_2D bad_alloc caught:\n" << ba.what() << '\n';
                exit(0);
            }

        fillCount++;
        emptyCount--;
        ProducerCount++;

        std::cout << "Thread of producer: fillCount = " << fillCount << ", emptyCount = " << emptyCount;
        std::cout << ", (w, h) = (" << widthAndHeightBuffer_2D[fillCount-1][0] << ", " << widthAndHeightBuffer_2D[fillCount-1][1] << ")" << std::endl;

        return;
        }
    }
}



void ProCon::consumer()
{
    while(true)
    {
        std::lock_guard<std::mutex> guard(memory_buffer_mutex);

        if(emptyCount < MAX_MEMORYBUFFER_DEPTH)
        {
            DataFromBuffer.clear();
            widthAndHeightFromBuffer.clear();

            for(const auto x : MemoryBuffer_2D[0])
            {
                try
                {
                    DataFromBuffer.push_back(x);
                }
                catch(std::bad_alloc& ba)
                {
                    std::cerr << "consumer, DataFromBuffer bad_alloc caught:\n" << ba.what() << '\n';
                    exit(0);
                }
            }

            for(const auto x : widthAndHeightBuffer_2D[0])
            {
                try
                {
                    widthAndHeightFromBuffer.push_back(x);
                }
                catch(std::bad_alloc& ba)
                {
                    std::cerr << "consumer, widthAndHeightFromBuffer bad_alloc caught:\n" << ba.what() << '\n';
                    exit(0);
                }
            }

            MemoryBuffer_2D.erase(MemoryBuffer_2D.begin());
            widthAndHeightBuffer_2D.erase(widthAndHeightBuffer_2D.begin());

            emptyCount++;
            fillCount--;
            ConsumerCount++;
            ConsumerExecutedAtLeastOnce=true;

            std::cout << "Thread of consumer: fillCount = " << fillCount << ", emptyCount = " << emptyCount;
            std::cout << ", (w, h) = (" << widthAndHeightFromBuffer[0] << ", " << widthAndHeightFromBuffer[1] << ")" << std::endl;

            return;
        }
    }
}

