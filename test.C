void test()
{
  TFile * file = new TFile("test.root","RECREATE");
  TTree * Tes = new TTree("Tes","test TTree");
  TRandom ran;
  Double_t random,px,py,pz;
  UShort_t i;
  Tes->Branch("px",&px,"px/D");
  Tes->Branch("py",&py,"py/D");
  Tes->Branch("pz",&pz,"pz/D");
  Tes->Branch("random",&random,"random/D");
  Tes->Branch("i",&i,"i/s");
  //Tes->SetCircular(20000);
  for(i = 0;i <= 60000;i++)
  {
    random = ran.Rndm();
    ran.Rannor(px,py);
    pz = px * px + py * py;
    Tes->Fill();
  }
  file->Write();
}
