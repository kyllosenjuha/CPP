#ifndef MAINAPP_H
#define MAINAPP_H

#include <wx/wx.h>


class MainApp: public wxApp, public GameBoardSize // MainApp on ohjelman luokka
    {
    // MainApp on paaikkunan container
    public:
      MainApp();
      ~MainApp();

      virtual bool OnInit();
      virtual int OnExit();
      virtual void wxCmdLineParser(int argc, char **argv); // Command line argumenttien poiminta talteen asetuksiksi
    };

#endif // MAINAPP_H
