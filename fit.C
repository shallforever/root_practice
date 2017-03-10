#include <unistd.h>

void fit()
{
  TFile * data = TFile::Open("./store.root");
  TFile * f = new TFile("graph.root","RECREATE");
  TTree * sig = (TTree *) data->Get("t");
  Int_t n = sig->GetEntries();
  Double_t * s = new Double_t [n];
  Double_t * b = new Double_t [n];
  Float_t ss,bb;
  TString sstr[20] = {"s0","s1","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","s12","s13","s14","s15","s16","s17","s18","s19"};
  TString bstr[20] = {"b0","b1","b2","b3","b4","b5","b6","b7","b8","b9","b10","b11","b12","b13","b14","b15","b16","b17","b18","b19"};
  //TCanvas * c[20];
  TGraphQQ * gr[20];
  for(Int_t j = 0;j < 20;j++)
    {
      //c[j] = new TCanvas();
      sig->SetBranchAddress(sstr[j],&ss);
      sig->SetBranchAddress(bstr[j],&bb);
      for(Int_t i = 0;i < n;i++)
	{
	  //c[i] = new TCanvas();
	  sig->GetEntry(i);
	  s[i] = (Double_t)ss;
	  b[i] = (Double_t)bb;
	}
      gr[j] = new TGraphQQ(n,s,n,b);
      std::cout<<gr[j]->GetCorrelationFactor()<<endl;
      //c[j]->Show();
      //c[j]->Update();
      gr[j]->Draw();
      //sleep(5);
      std::cout<<endl;
      gr[j]->SetName(sstr[j] + bstr[j]);
      gr[j]->Write();
      //sleep(1);
      //delete gr;
    }
  //f->Write();
  //Int_t in;
  //std::cin>>in;
  delete [] s;
  delete [] b;
  /*  for(Int_t i = 19;i >= 0;i--)
    {
      //delete c[i];
      delete gr[i];
      }*/
}
