#include <iostream>
#include "TRandom3.h"
#include "TH1F.h"
#include "TFile.h"

using namespace std;

int main()
{
    cout << "hello world ......" << endl;
    TFile *file = new TFile("myroot.root","recreate");
    gRandom->SetSeed(0);

    TH1F *h1 = new TH1F("h1","hehe",100,-5,5);
    h1->FillRandom("gaus",10000);
    //h1->Draw();
    file->cd();
    h1->Write();
    return 0;
}
