#include "GameOfLife.h"
#define BUTTON_ID_START 6000
#define CELLSIZE_PX 30
#define MAX_BOARDSIZE 30


bool MainApp::OnInit()                     // Luodaan pelilauta ikkuna
{

    MainApp::wxCmdLineParser(argc, argv);  // Command line parametri (pelilaudan koko)
    MainFrame *MainWin;

    MainWin = new MainFrame(_T("Game of Life"), wxPoint(1, 1), wxSize((CELLSIZE_PX*GetBoardSize()+20), (CELLSIZE_PX*GetBoardSize()+95)));

    MainWin->Show(TRUE);   // Nauta window
    SetTopWindow(MainWin); // Asetetaan paaikkunaksi
    return TRUE;
}

int MainApp::OnExit() {
    return 0;
}

    // Event koodit

    BEGIN_EVENT_TABLE ( MainFrame, wxFrame )
        EVT_TIMER( 8003, MainFrame::OnRecTimer)   // Pelilaudan automaattinen paivitys
    END_EVENT_TABLE()

// Luodaan paaikkuna, Start-, NextState ja Reset -napit ja tehdaan alkualustukset

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize
    &size): wxFrame((wxFrame*)NULL,  - 1, title, pos, size)
    {

    StartSignal = false;            // Start napin signaali
    NextStateSignal = false;        // NextStaten napin signaali
    locked = false;                 // Kun = true, niin pelilautaa ei voi enää muokata
    interval = 500;                  // Automaattinen pelilaudan paivitysnonpeus millisekuntena
    totalsum = 0;                    // Solua ymparoivien mustien(alive) kavereiden maara


    // Luodaan pelilaudan automaattinen paivitys

    recTimer = new wxTimer(this, 8003);
    recTimer->Start(interval);

    // Luodaan control napit, pelilaudan napit se pelilaudan nykyinen ja seuraava tila

    CreateControlButtons();

    CreateGameBoard_UI();

    CreateGameBoardStates();

    // Kytketaan napin painaisu event oikeisiin paikkoihin

    Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::ClickButtonEvent));
    Centre();  // Kaynnistaan paaikkuna keskelle nayttoruutua
}

// Klikataan solua/nappia -metodi, luodaan pelin alkutilanne

void MainFrame::ClickButtonEvent(wxCommandEvent& event ) // wxCommandEvent tapahtuu, kun klikataan nappia / solua
{

    if(event.GetId() != 8000 && event.GetId() != 8001 && event.GetId() != 8002 && event.GetId() != 8003) {

        if(locked == false)
            ClickBoardCells(event.GetId());

        } else if(event.GetId() == 8000) {
            ClickStartButton();

        } else if(event.GetId() == 8001) {
            ClickNextStateButton();

        } else if(event.GetId() == 8002) {
            ClickResetButton();

        }
}

// Pelilaudan automaattinen paivitys, kun StartSignal = true;

void MainFrame::OnRecTimer(wxTimerEvent& event) {

    if(event.GetId() == 8003 && StartSignal == true) {

        CalcNextState();
        UpdateUI();
    }
}

// Command line argumenttien luku ohjelmaa kaynnistaessa.

void MainApp::wxCmdLineParser(int argc, char **argv)
{
    int n = 0; // <-- initialize your variables!

    n = atoi(argv[1]); // <-- [1] instead of [0]! and parse the string...

    if(n >= 5 && n <= MAX_BOARDSIZE && argc == 2) {
        SetBoardSize(n);
        } else {
            Exit();
        }
}

// Lasketaan seuraava tila

void MainFrame::CalcNextState() {

    for(int k=1; k <= GetBoardSize(); k++)
    {
        for(int m=1; m <= GetBoardSize(); m++)
        {
        totalsum = 0;
        totalsum =   GameBoardStatesCurrent[k-1][m-1] +
                     GameBoardStatesCurrent[k-1][m] +
                     GameBoardStatesCurrent[k-1][m+1] +
                     GameBoardStatesCurrent[k][m+1] +
                     GameBoardStatesCurrent[k+1][m+1] +
                     GameBoardStatesCurrent[k+1][m] +
                     GameBoardStatesCurrent[k+1][m-1] +
                     GameBoardStatesCurrent[k][m-1];

    if (GameBoardStatesCurrent[k][m] == 1) {
        if(totalsum <= 1 || totalsum >= 4)
            GameBoardStatesNext[k][m] = 0;
        else if(totalsum == 2 || totalsum == 3)
            GameBoardStatesNext[k][m] = 1;

    } else if (GameBoardStatesCurrent[k][m] == 0) {
        if(totalsum == 3)
            GameBoardStatesNext[k][m] = 1;
    }

        }
    }

}

// Paivitetaan UI

void MainFrame::UpdateUI() {

    for(int i=0; i<GetBoardSize(); i++) {
        for(int j=0; j<GetBoardSize(); j++) {

            GameBoardStatesCurrent[i+1][j+1] = GameBoardStatesNext[i+1][j+1];
                if (GameBoardStatesCurrent[i+1][j+1] == 0) {
                    GameBoard_UI[i][j].SetBackgroundColour(*wxWHITE);
            } else if(GameBoardStatesCurrent[i+1][j+1] == 1) {
                    GameBoard_UI[i][j].SetBackgroundColour(*wxBLACK);
            }
        }
    }
}

void MainFrame::ClickBoardCells(int Cell_ID) {

    for(int i=0; i<GetBoardSize(); i++) {
        for(int j=0; j<GetBoardSize(); j++) {
            if(clickCell_UI[i][j] && Cell_ID == BUTTON_ID_START+i*GetBoardSize()+j)

            {
            clickCell_UI[i][j] = false;
            GameBoard_UI[i][j].SetBackgroundColour(*wxWHITE);
            GameBoardStatesCurrent[i+1][j+1] = 0;

            }
            else if (!clickCell_UI[i][j] && Cell_ID == BUTTON_ID_START+i*GetBoardSize()+j) {

            clickCell_UI[i][j] = true;
            GameBoard_UI[i][j].SetBackgroundColour(*wxBLACK);
            GameBoardStatesCurrent[i+1][j+1] = 1;

                }
            }
        }
}

void MainFrame::ClickStartButton() {

    if(clickControl_Button[0]) {
        clickControl_Button[0] = false;
        clickControl_Button[1] = false;
        Start->SetBackgroundColour(*wxRED);
        Start->SetLabel("Start");
        NextState->SetBackgroundColour(*wxRED);
        StartSignal = false;
        NextStateSignal = false;
    }

    else if(!clickControl_Button[0]) {
        locked = true;
        clickControl_Button[0] = true;
        clickControl_Button[1] = false;
        Start->SetBackgroundColour(*wxGREEN);
        Start->SetLabel("Stop");
        NextState->SetBackgroundColour(*wxRED);
        StartSignal = true;
        NextStateSignal = false;
    }

}

void MainFrame::ClickNextStateButton() {

        if(clickControl_Button[1]) {
            clickControl_Button[0] = false;
            clickControl_Button[1] = false;
            Start->SetBackgroundColour(*wxRED);
            Start->SetLabel("Start");
            NextState->SetBackgroundColour(*wxRED);
            StartSignal = false;
            NextStateSignal = false;
        }

        else if(!clickControl_Button[1]) {

            locked = true;
            clickControl_Button[0] = false;
            clickControl_Button[1] = false;
            Start->SetBackgroundColour(*wxRED);
            Start->SetLabel("Start");
            NextState->SetBackgroundColour(*wxGREEN);
            StartSignal = false;
            NextStateSignal = true;

            CalcNextState();
            UpdateUI();
        }
}

void MainFrame::ClickResetButton() {

        locked = false;
        clickControl_Button[0] = false;
        clickControl_Button[1] = false;

        for(int k=0; k<GetBoardSize(); k++)
        {
            for(int m=0; m<GetBoardSize(); m++)
            {
                clickCell_UI[k][m] = false;
            }
        }

        Start->SetBackgroundColour(*wxRED);
        Start->SetLabel("Start");
        NextState->SetBackgroundColour(*wxRED);
        StartSignal = false;
        NextStateSignal = false;

        for(int i=1; i<=GetBoardSize(); i++)
        {
            for(int j=1; j<=GetBoardSize(); j++) {
                GameBoardStatesNext[i][j] = 0;
            }
        }

        UpdateUI();
}

void MainFrame::CreateControlButtons() {

    // Luodaan Start nappi ja maaritetaan alkuasetukset.

    Start = new wxButton(this, 8000, _T("Start"),
            wxPoint(0 , 0), wxSize(50, 50), 0);

    Start->SetBackgroundColour(*wxRED);
    Start->SetForegroundColour(*wxBLACK);

    // Luodaan NextState nappi ja maaritetaan alkuasetukset.

    NextState = new wxButton(this, 8001, _T("Next"),
            wxPoint(50, 0), wxSize(50, 50), 0);

    NextState->SetBackgroundColour(*wxRED);
    NextState->SetForegroundColour(*wxBLACK);

    // Luodaan Reset nappi ja maaritetaan alkuasetukset.

    Reset = new wxButton(this, 8002, _T("Reset"),
            wxPoint(100 , 0), wxSize(50, 50), 0);

    Reset->SetBackgroundColour(*wxGREEN);
    Reset->SetForegroundColour(*wxBLACK);

    // Luodaan Start ja NextState nappien klikkauksien tilat

    clickControl_Button = new bool[2];
    clickControl_Button[0] = false;
    clickControl_Button[1] = false;

}

void MainFrame::CreateGameBoard_UI() {


    // Luodaan pelilauta painonapit ja maaritetaan alkuasetukset

    GameBoard_UI = new wxButton* [GetBoardSize()];

    for(int i=0; i<GetBoardSize(); i++) {
        GameBoard_UI[i] = new wxButton[GetBoardSize()];
    }

    for(int i=0; i<GetBoardSize(); i++) {
        for(int j=0; j<GetBoardSize(); j++) {
        GameBoard_UI[i][j].Create(this, BUTTON_ID_START+i*(GetBoardSize())+j , _T(""),
        wxPoint(j*CELLSIZE_PX, i*CELLSIZE_PX+50), wxSize(CELLSIZE_PX, CELLSIZE_PX), 0);
        }
    }

    // Alustetaan UI valkeilla(dead) soluilla

    for(int i=0; i<GetBoardSize(); i++) {
        for(int j=0; j<GetBoardSize(); j++) {
        GameBoard_UI[i][j].SetBackgroundColour(*wxWHITE);
        }
    }

    // Luodaan pelilaudan nappien klikkauksien tilat

    clickCell_UI = new bool* [GetBoardSize()];

    for(int i=0; i<GetBoardSize(); i++) {
        clickCell_UI[i] = new bool[GetBoardSize()];
    }

    for(int k=0; k<GetBoardSize(); k++) {
        for(int m=0; m<GetBoardSize(); m++) {
            clickCell_UI[k][m] = false;
        }
    }
}

void MainFrame::CreateGameBoardStates() {

    // Luodaan pelilaudan nykyinen ja seuraava tila

    GameBoardStatesCurrent = new int* [GetBoardSize()+2];
    GameBoardStatesNext = new int* [GetBoardSize()+2];

    for(int i=0; i<GetBoardSize()+2; i++) {
        GameBoardStatesCurrent[i] = new int[GetBoardSize()+2];
        GameBoardStatesNext[i] = new int[GetBoardSize()+2];
        }

    // Alustetaan koko pelilauta nollilla.

    for(int i=0; i<GetBoardSize()+2; i++) {
        for(int j=0; j<GetBoardSize()+2; j++) {
        GameBoardStatesCurrent[i][j] = 0;
        }
    }

    // Alustetaan päivitetty pelilauta nollilla.

    for(int i=0; i<GetBoardSize()+2; i++) {
        for(int j=0; j<GetBoardSize()+2; j++) {
        GameBoardStatesNext[i][j] = 0;
        }
    }
}

void MainFrame::FreeMemory() {

    for(int k=0; k<GetBoardSize(); k++)
    {
        delete[] clickCell_UI[k];
        delete[] GameBoard_UI[k];
    }

    delete[] clickCell_UI;
    delete[] GameBoard_UI;
    delete[] clickControl_Button;

    for(int n=0; n<GetBoardSize()+2; n++)
    {
        delete[] GameBoardStatesCurrent[n];
        delete[] GameBoardStatesNext[n];

    }

    delete[] GameBoardStatesCurrent;
    delete[] GameBoardStatesNext;

    delete Start;
    delete NextState;
    delete Reset;
    delete recTimer;
}
