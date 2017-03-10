void histogram()
{
  TFile  f("histos.root","new");
  TH1F * h1 = new TH1F("hgaus","histo from a gaussian",100,-3,-3);
  h1->FillRandom("gaus",10000);
  h1->Write();
  h1->Draw();
}
