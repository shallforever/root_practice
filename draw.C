#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"

void draw()
{
  TFile * f = TFile::Open("./store.root");
  TTree * data = (TTree *) f->Get("t");
  TCanvas * ca1 = new TCanvas();
  // ca1->Divide(2,2);
  //ca1->cd(1);
  data->Draw("s0");
  //ca1->Update();
  data->Draw("b0");
}
