#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"

void draw_scatter_plot()
{
  TFile * f = TFile::Open("./store.root");
  TTree * data = (TTree *) f->Get("t");
  TCanvas * ca1 = new TCanvas();
  TCanvas * ca2 = new TCanvas();
  TCanvas * ca3 = new TCanvas();
  TCanvas * ca4 = new TCanvas();
  TCanvas * ca5 = new TCanvas();
  ca1->Divide(2,2);
  ca2->Divide(2,2);
  ca3->Divide(2,2);
  ca4->Divide(2,2);
  ca5->Divide(2,2);
  ca1->cd(1);
  data->Draw("s0:b0");
  ca1->cd(2);
  data->Draw("s1:b1");
  ca1->cd(3);
  data->Draw("s2:b2");
  ca1->cd(4);
  data->Draw("s3:b3");
  ca2->cd(1);
  data->Draw("s4:b4");
  ca2->cd(2);
  data->Draw("s5:b5");
  ca2->cd(3);
  data->Draw("s6:b6");
  ca2->cd(4);
  data->Draw("s7:b7");
  ca3->cd(1);
  data->Draw("s8:b8");
  ca3->cd(2);
  data->Draw("s9:b9");
  ca3->cd(3);
  data->Draw("s10:b10");
  ca3->cd(4);
  data->Draw("s11:b11");
  ca4->cd(1);
  data->Draw("s12:b12");
  ca4->cd(2);
  data->Draw("s13:b13");
  ca4->cd(3);
  data->Draw("s14:b14");
  ca4->cd(4);
  data->Draw("s15:b15");
  ca5->cd(1);
  data->Draw("s16:b16");
  ca5->cd(2);
  data->Draw("s17:b17");
  ca5->cd(3);
  data->Draw("s18:b18");
  ca5->cd(4);
  data->Draw("s19:b19");
}
