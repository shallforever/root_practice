void graph()
{
  Int_t n = 50;
  Double_t x[n],y[n];
  for(Int_t i = 0;i < n;i++)
    {
      x[i] = i * 0.1;
      y[i] = 10 * sin(x[i] + 0.2);
    }
  TGraph * gr1 = new TGraph(n,x,y);
  TCanvas * c1 = new TCanvas("c1","Graph Draw Options",200,10,600,400);
  gr1->Draw("AC**");
  TCanvas * c2 = new TCanvas("c2","Graph Draw Options",200,10,600,400);
  TGraph * gr2 = new TGraph(n,x,y);
  gr2->SetFillColor(40);
  gr2->Draw("AB");
  TCanvas * c3 = new TCanvas("c3","Graph Draw Options",200,10,600,400);
  TGraph * gr3 = new TGraph(n,x,y);
  gr3->SetFillColor(45);
  gr3->Draw("AF");
}
