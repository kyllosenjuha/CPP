
// ----------------------------------------------------//
// GameOfLife projektiin tarvittava .h header tiedosto //
// ----------------------------------------------------//

#include <wx/wx.h>

class GameBoardClass
{
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

int GameBoardClass::BoardSize = 0;

class MainApp: public wxApp, public GameBoardClass // MainApp on ohjelman luokka
    {
    // MainApp on paaikkunan container
    public:

      virtual bool OnInit();
      virtual int OnExit();
      virtual void wxCmdLineParser(int argc, char **argv); // Command line argumenttien poiminta talteen asetuksiksi

    };

class MainFrame: public wxFrame, public GameBoardClass // MainFrame on paaikkunan luokka
{
    // Sisaltyy paaikkunaan
    private:
      bool StartSignal = false;            // Start napin signaali
      bool NextStateSignal = false;        // NextStaten napin signaali
      bool locked = false;                 // Kun = true, niin pelilautaa ei voi enää muokata
      int interval = 500;                  // Automaattinen pelilaudan paivitysnonpeus millisekuntena
      int totalsum = 0;                    // Solua ymparoivien mustien(alive) kavereiden maara

      bool **clickCell_UI;
      bool *clickControl_Button;

      wxButton *Start;                     // Luodaan Start nappi
      wxButton *NextState;                 // Luodaan NextState nappi
      wxButton *Reset;                     // Luodaan Reset nappi
      wxButton **GameBoard_UI;             // Luodaan pelilaudan napit (pelilauta/ruudukko)
      int **GameBoardStatesCurrent;        // Pelilaudan nykyinen tila
      int **GameBoardStatesNext;           // Pelilaudan seuraava tila

      wxTimer *recTimer;                   // Tarvitaan pelilaudan automaattisessa paivityksessa

    public:

      MainFrame( const wxString &title, const wxPoint &pos, const wxSize &size );
      ~MainFrame() { FreeMemory(); };

      void ClickButtonEvent(wxCommandEvent& event );  // Klikataan pelilaudan soluja tai Start/NextState -nappija
      void OnRecTimer(wxTimerEvent& event);    // Tarvitaan pelilaudan automaattisessa paivityksessa
      void CalcNextState();
      void UpdateUI();

      void ClickBoardCells(int Cell_ID);
      void ClickStartButton();
      void ClickNextStateButton();
      void ClickResetButton();
      void CreateControlButtons();
      void CreateGameBoard_UI();
      void CreateGameBoardStates();
      void FreeMemory();

      DECLARE_EVENT_TABLE()
};

