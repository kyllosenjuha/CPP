#include "GameBoardSize.h"
#include "MainApp.h"
#include "MainFrame.h"

MainApp::MainApp()
{
     //ctor
}

MainApp::~MainApp()
{
    //dtor
}

bool MainApp::OnInit()                     // Luodaan pelilauta ikkuna
{

    MainApp::wxCmdLineParser(argc, argv);  // Command line parametri (pelilaudan koko)
    MainFrame *MainWin;


    MainWin = new MainFrame(_T("Game of Life"), wxPoint(0, 0), wxSize((CELLSIZE_PX*GetBoardSize()),
            (CELLSIZE_PX*GetBoardSize()+BUTTONSIZE_PX+TITLEBAR_HEIGHT_PX)));

    MainWin->SetMinSize(wxSize((CELLSIZE_PX*GetBoardSize()+2),
            (CELLSIZE_PX*GetBoardSize()+BUTTONSIZE_PX+TITLEBAR_HEIGHT_PX)));

    MainWin->Fit();
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
