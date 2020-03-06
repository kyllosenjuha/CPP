#ifndef GAMEBOARDSIZE_H
#define GAMEBOARDSIZE_H


class GameBoardSize
{
    public:
        GameBoardSize();
        virtual ~GameBoardSize();

    public:

        int GetBoardSize()
        {
            return BoardSize;
        }

        void SetBoardSize(int newVal)
        {
            BoardSize = newVal;
        }

    private:

        static int BoardSize;

};


#endif // GAMEBOARDSIZE_H
