#include "TROOT"
#include "TFile"
#include "TTree"

void test_read()
{
  TFile * f = new TFile("tree1.root");
  TTree * t1 = (TTree *)f->Get("t1");
  Float_t px1,px2,py1,py2,pz1,pz2;
  Double_t random1,random2;
  Int_t ev;
  t1->SetBranchAddress("px",&px1);
  t1->SetBranchAddress("py",&py1);
  t1->SetBranchAddress("pz",&pz1);
  t1->SetBranchAddress("random",&random1);
  t1->SetBranchAddress("ev",&ev);
  TFile * f2 = new TFile("f2.root","RECREATE");
  TTree * t2 = new TTree("t2","t2");
  t2->Branch("px2",&px2,"px2/F");
  t2->Branch("py2",&py2,"py2/F");
  t2->Branch("pz2",&pz2,"pz2/F");
  t2->Branch("random2",&random2,"random2/D");
  Long64_t n = t1->GetEntries();
  for(Long64_t i = 0;i < n;i++)
    {
      t1->GetEntry(i);
      px2 = px1;
      py2 = py1;
      pz2 = pz1;
      random2 = random1;
      t2->Fill();
    }
  f2->Write();
  t1->Print();
  t2->Print();
  t1->Show(1);
  t2->Show(1);
}
