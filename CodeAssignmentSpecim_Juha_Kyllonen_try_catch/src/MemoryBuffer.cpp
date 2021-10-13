#include "MemoryBuffer.h"

MemoryBuffer::MemoryBuffer()
{
    //ctor
}

MemoryBuffer::~MemoryBuffer()
{
    //dtor
}

std::mutex MemoryBuffer::memory_buffer_mutex;
std::vector<std::vector<unsigned short>> MemoryBuffer::MemoryBuffer_2D;
std::vector<unsigned short> MemoryBuffer::DataFromBuffer;
std::vector<std::vector<int>> MemoryBuffer::widthAndHeightBuffer_2D;
std::vector<int> MemoryBuffer::widthAndHeightFromBuffer;
int MemoryBuffer::fillCount {};
int MemoryBuffer::emptyCount = MAX_MEMORYBUFFER_DEPTH;
int MemoryBuffer::ProducerCount {};
int MemoryBuffer::ConsumerCount {};
bool MemoryBuffer::ConsumerExecutedAtLeastOnce {false};
