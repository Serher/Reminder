//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    nIDToDelete = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    FileFuncs ff;
    LB1->Items->LoadFromFile(ff.GetCurDir() + "RemAlarms.txt");
    TI1->Visible = true;
}
//---------------------------------------------------------------------------




AnsiString DateTimeForCompare(AnsiString sEntry) // [17.08.2017][23:39] : wqrqwrweqr
{
    StringsContainer strCont;
    strCont.BreakString(sEntry, " :");
    AnsiString str = strCont.Vector[0]; // [17.08.2017][23:39]

    strCont.BreakString(str, "]"); // [17.08.2017 || [23:39
    AnsiString sTime = strCont.Vector[1]+"]";  // [23:39]

    str = strCont.Vector[0].Delete(1, 1); // 17.08.2017
    strCont.BreakString(str, ".");
    str = "["+strCont.Vector[2]+"."+strCont.Vector[1]+"."+strCont.Vector[0]+"]"; // [2017.08.17]

return str+sTime;  // [2017.08.17][23:39]
}
//---------------------------------------------------------------------------
void ShowAlarm(AnsiString sEntry) // [17.08.2017][23:39] : wqrqwrweqr
{
    Form2->sEntry = sEntry;

    AnsiString str, sMessage, sDate, sTime;
    StringsContainer strCont;

    strCont.BreakString(sEntry, " : ");
    sMessage = strCont.Vector[1]; // wqrqwrweqr

    str = strCont.Vector[0];  // [17.08.2017][23:39]
    strCont.BreakString(str, "]"); // [17.08.2017 || [23:39
    sDate = strCont.Vector[0].Delete(1, 1); // 17.08.2017
    sTime = strCont.Vector[1].Delete(1, 1); // 23:39

    Form2->Edit1->Text = sDate;
    Form2->Edit2->Text = sTime;
    Form2->Label3->Caption = sMessage;

    Form2->Left = 0;
    Form2->Top = 0;


    Form2->Visible = true;
    Form1->TI1->Restore();
    Form1->Visible = false;
    Form2->SetFocus();
}

//---------------------------------------------------------------------------
void SaveLog(AnsiString sMess)
{
    sMess = "[" + Now().DateTimeString() + "] " + sMess + "\n";

    FileFuncs ff;
    AnsiString sFileName = ff.GetCurDir()+ "Log.txt";
    std::ofstream F;
    F.open(sFileName.c_str(), std::ios_base::app);
    if(F)
    {
        F<<sMess.c_str();
        F.close();
    }
}
//---------------------------------------------------------------------------










//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    LE1->Text = Now().DateString();
    StringsContainer strCont;
    strCont.BreakString(Now().TimeString(), ":");
    if(strCont.Vector[0].Length() == 1)
        strCont.Vector[0] = "0"+strCont.Vector[0];
    LE2->Text = strCont.Vector[0] + ":" + strCont.Vector[1]; // Чтобы отделить секунды

    //Form2->Form = Form1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(LE3->Text == "")
        return;
    
    AnsiString sAction =  " ДОБАВЛЕНО: ";

    if(nIDToDelete>-1)
    {
        sAction = " ИЗМЕНЕНИЕ: ";
        LB1->Items->Delete(LB1->ItemIndex);
        nIDToDelete =-1;
    }
    LB1->Items->Add("["+LE1->Text+"]["+LE2->Text+"] : "+LE3->Text);
    SaveLog(sAction + "\"["+LE1->Text+"]["+LE2->Text+"] : "+LE3->Text + "\"");
    LE3->Text = "";

    FileFuncs ff;
    LB1->Items->SaveToFile(ff.GetCurDir() + "RemAlarms.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    AnsiString str;
    StringsContainer strCont;
    // Date
    strCont.BreakString(Now().DateString(), ".");
    AnsiString sCurrentDate = strCont.Vector[2]+"."+strCont.Vector[1]+"."+strCont.Vector[0];
    // Time
    strCont.BreakString(Now().TimeString(), ":");
    if(strCont.Vector[0].Length() == 1)
        strCont.Vector[0] = "0"+strCont.Vector[0];
    AnsiString sCurrentTime = strCont.Vector[0]+ ":"+strCont.Vector[1];                         

    AnsiString sCurrent = "["+sCurrentDate+"]["+sCurrentTime+"]";  //[2017.08.17][22:00]
    for(int i=0; i<LB1->Items->Count; i++)
    {
        str = DateTimeForCompare(LB1->Items->Strings[i]);
        if(str <= sCurrent)
            ShowAlarm(LB1->Items->Strings[i]);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TI1Restore(TObject *Sender)
{
    Form1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TI1Minimize(TObject *Sender)
{
    Form1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)// Delete Entry
{
    if(LB1->ItemIndex>-1)
    {
        SaveLog(" УДАЛЕНО: \"" + LB1->Items->Strings[LB1->ItemIndex] + "\"");
        LB1->Items->Delete(LB1->ItemIndex);
        FileFuncs ff;
        LB1->Items->SaveToFile(ff.GetCurDir() + "RemAlarms.txt");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ht1Click(TObject *Sender)
{
    if(LB1->ItemIndex>-1)
    {
        nIDToDelete = LB1->ItemIndex;
        AnsiString str = LB1->Items->Strings[nIDToDelete];
        StringsContainer strCont;
        // Отделяем сообщение
        strCont.BreakString(str, " : ");
        LE3->Text = strCont.Vector[1];
        // Дата и время
        strCont.BreakString(strCont.Vector[0], "][");
        LE1->Text = strCont.Vector[0].Delete(1, 1);
        LE2->Text = strCont.Vector[1].SubString(0, strCont.Vector[1].Length()-1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LB1DblClick(TObject *Sender)
{
    Ht1Click(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LE1DblClick(TObject *Sender)
{
    LE1->Text = Now().DateString();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LE2DblClick(TObject *Sender)
{
    StringsContainer strCont;
    strCont.BreakString(Now().TimeString(), ":");
    if(strCont.Vector[0].Length() == 1)
        strCont.Vector[0] = "0"+strCont.Vector[0];
    LE2->Text = strCont.Vector[0] + ":" + strCont.Vector[1]; // Чтобы отделить секунды
}
//---------------------------------------------------------------------------

