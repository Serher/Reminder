//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "MyUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
    TForm1 *Form1 = dynamic_cast<TForm1 *>(Form);
    if(Form1)
    {
        int nID = Form1->LB1->Items->IndexOf(sEntry);
        SaveLog(" ÏÐÈÍßÒÎ: \"" + Form1->LB1->Items->Strings[nID] + "\"");

        Form1->LB1->Items->Delete(nID);
        FileFuncs ff;
        Form1->LB1->Items->SaveToFile(ff.GetCurDir() + "RemAlarms.txt");
        Form2->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Form = Form1;    
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
    FileFuncs ff;
    TForm1 *Form1 = dynamic_cast<TForm1 *>(Form);
    if(Form1)
    {
        //Óäàëåíèå
        Form1->LB1->Items->Delete(Form1->LB1->Items->IndexOf(sEntry));

        // Äîáàâëåíèå
        Form1->LB1->Items->Add("["+Edit1->Text+"]["+Edit2->Text+"] : "+Label3->Caption);
        SaveLog(" ÏÅÐÅÍÎÑ: \"["+Edit1->Text+"]["+Edit2->Text+"] : "+Label3->Caption + "\"");

        Form1->LB1->Items->SaveToFile(ff.GetCurDir() + "RemAlarms.txt");

        Form2->Visible = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label3DblClick(TObject *Sender)
{
    AnsiString sMess = Label3->Caption;
    StringsContainer strCont;
    strCont.BreakString(sMess, " ");
    CopyTextToClipboard(strCont.Vector[0]);
}
//---------------------------------------------------------------------------

