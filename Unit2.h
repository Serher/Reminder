//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label3;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TEdit *Edit1;
    TEdit *Edit2;
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall Label3DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);


    AnsiString sEntry;
    TForm *Form;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
