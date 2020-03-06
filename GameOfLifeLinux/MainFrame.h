#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>

class MainFrame: public wxFrame, public GameBoardSize // MainFrame on paaikkunan luokka
{
    // Sisaltyy paaikkunaan
    private:

      bool StartSignal;                    // Start napin signaali
      bool NextStateSignal;                // NextStaten napin signaali
      bool locked;                         // Kun = true, niin pelilautaa ei voi enaa muokata
      int interval;                        // Automaattinen pelilaudan paivitysnonpeus millisekuntena
      int totalsum;                        // Solua ymparoivien mustien(alive) kavereiden maara

      bool **clickCell_UI;                 // Pelilaudan nappien klikkaukset
      bool *clickControl_Button;           // Control nappien klikkaukset, Start ja Next.

      wxButton *Start;                     // Luodaan Start nappi
      wxButton *NextState;                 // Luodaan NextState nappi
      wxButton *Reset;                     // Luodaan Reset nappi
      wxButton **GameBoard_UI;             // Luodaan pelilaudan napit (pelilauta/ruudukko)
      int **GameBoardStatesCurrent;        // Pelilaudan nykyinen tila
      int **GameBoardStatesNext;           // Pelilaudan seuraava tila

      wxTimer *recTimer;                   // Tarvitaan pelilaudan automaattisessa paivityksessa
      void FreeMemory();

    public:

      MainFrame( const wxString &title, const wxPoint &pos, const wxSize &size );
      ~MainFrame() { FreeMemory(); };

      void ClickButtonEvent(wxCommandEvent& event );  // Klikataan pelilaudan soluja tai Start/NextState -nappija
      void OnRecTimer(wxTimerEvent& event);           // Tarvitaan pelilaudan automaattisessa paivityksessa
      void CalcNextState();
      void UpdateUI();

      void ClickBoardCells(int Cell_ID);
      void ClickStartButton();
      void ClickNextStateButton();
      void ClickResetButton();
      void CreateControlButtons();
      void CreateGameBoard_UI();
      void CreateGameBoardStates();

      DECLARE_EVENT_TABLE()
};

#endif // MAINFRAME_H
