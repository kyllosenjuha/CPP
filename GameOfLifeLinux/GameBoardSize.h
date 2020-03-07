#ifndef GAMEBOARDSIZE_H
#define GAMEBOARDSIZE_H


class GameBoardSize
{
    public:
        GameBoardSize();
        virtual ~GameBoardSize();

        int GetBoardSize()
        {
            return BoardSize;
        }

        void SetBoardSize(int newVal)
        {
            BoardSize = newVal;
        }

    protected:
        const int BUTTON_ID_START = 6000;
        const int CELLSIZE_PX = 30;
        const int BUTTONSIZE_PX = 50;
        const int TITLEBAR_SIZE_PX = 30;
        const int MAX_BOARDSIZE = 30;

    private:

        static int BoardSize;

};

#endif // GAMEBOARDSIZE_H
