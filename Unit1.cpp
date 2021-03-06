//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString nazwapliku="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Otworz1Click(TObject *Sender)
{

                if(OpenDialog1->Execute()){
                try     {
                        Tresc->Lines->LoadFromFile(OpenDialog1->FileName);
                        nazwapliku=OpenDialog1->FileName;
                        }
                catch(...) {
                        ShowMessage("B��d otwarcia pliku !");
                        }
                }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
           if(SaveDialog1->Execute()){
                try     {
                        Tresc->Lines->SaveToFile(SaveDialog1->FileName);
                        nazwapliku=SaveDialog1->FileName;
                        }
                catch(...) {
                        ShowMessage("B��d zapisu pliku !");
                        }
                }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if(nazwapliku!=""){
        Tresc->Lines->SaveToFile(nazwapliku);
        }
        else{
                Form1->Zapiszjako1Click(MainMenu1);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        if(Application->MessageBoxA("Czy na pewno utworzyc nowy plik?","Potwierdz",
        MB_YESNOCANCEL|MB_ICONQUESTION)==IDYES ) {
         Tresc->Lines->Clear();
         nazwapliku="";
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrescKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Shift.Contains(ssCtrl)){
         if((Key=='s')||(Key=='S')){
          Form1->   Zapisz1Click(MainMenu1);
         }
         else if((Key=='n')||(Key=='N')){
          Form1->   Otworz1Click(MainMenu1);
         }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{
        if(Application->MessageBoxA("Czy na zakonczyc program?","Potwierdz",
        MB_YESNO|MB_ICONQUESTION)==IDYES ) {
         Application->Terminate();
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
          if(Application->MessageBoxA("Czy na zakonczyc program?","Potwierdz",
        MB_YESNO|MB_ICONQUESTION)==IDNO ) {
         Action=caNone;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wytnij1Click(TObject *Sender)
{
        Tresc->CutToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WklejCtrlC1Click(TObject *Sender)
{
        Tresc->CopyToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WklejCtrlV1Click(TObject *Sender)
{
        Tresc->PasteFromClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
        if(Zawijaniewierszy1->Checked==true)
        {
                Zawijaniewierszy1->Checked=false;
                Tresc->WordWrap=false;
                Tresc->ScrollBars=ssBoth;
        }
        else{
         Zawijaniewierszy1->Checked=true;
         Tresc->WordWrap=true;
         Tresc->ScrollBars=ssVertical;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Trzcionka1Click(TObject *Sender)
{
        if(FontDialog1->Execute()){
        Tresc->Font->Name=FontDialog1->Font->Name;
        Tresc->Font->Color=FontDialog1->Font->Color;
        Tresc->Font->Size=FontDialog1->Font->Size;
        Tresc->Font->Style=FontDialog1->Font->Style;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
        Form2->ShowModal();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Blog1Click(TObject *Sender)
{
        ShellExecute(NULL,"open","https://aternos.org/server/",NULL,NULL  ,SW_SHOWNORMAL);     
}
//---------------------------------------------------------------------------
