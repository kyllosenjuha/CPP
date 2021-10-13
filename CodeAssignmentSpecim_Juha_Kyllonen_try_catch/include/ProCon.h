#ifndef PROCON_H
#define PROCON_H

#include "MemoryBuffer.h"

class ProCon : public MemoryBuffer
{
    public:
        ProCon();
        virtual ~ProCon();

        static void producer(unsigned short* dataPtr, int width, int height);
        static void consumer();

    protected:

    private:
};

#endif // PROCON_H
