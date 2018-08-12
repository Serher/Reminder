//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>


#include "MyUtils.h"
#include "trayicon.h"
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Pan1;
    TLabeledEdit *LE1;
    TLabeledEdit *LE2;
    TLabeledEdit *LE3;
    TButton *Button1;
    TLabel *Label1;
    TLabel *Label2;
    TListBox *LB1;
    TTimer *Timer1;
    TTrayIcon *TI1;
    TPopupMenu *PopupMenu1;
    TMenuItem *Ht1;
    TMenuItem *N1;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall TI1Restore(TObject *Sender);
    void __fastcall TI1Minimize(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall Ht1Click(TObject *Sender);
    void __fastcall LB1DblClick(TObject *Sender);
    void __fastcall LE1DblClick(TObject *Sender);
    void __fastcall LE2DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    int nIDToDelete;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------


void SaveLog(AnsiString sMess);

#endif
