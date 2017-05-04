double f(double x,double y)
{
  return y - 2 * x / y;
}

void euler()
{
  int min = 0;
  int max = 2;
  double h = 0.0001;
  int n = int((max - min) / h) + 1;
  double * x = new double [n];
  double * y = new double [n];
  double * z = new double [n];
  y[0] = 1;
  x[0] = min;
  z[0] = 0;
  for(int i = 0;i < n - 1;i++)
    {
      x[i + 1] = x[i] + h;
      y[i + 1] = y[i] + h * f(x[i],y[i]);    //euler method
      y[i + 1] = y[i] + 0.5 * h * (f(x[i],y[i]) + f(x[i + 1],y[i + 1]));   //improved euler method
      //x[i + 1] = x[i] + h;
      z[i + 1] = sqrt(2 * x[i + 1] + 1) - y[i + 1];
    }
  TGraph * gra = new TGraph(n,x,y);
  TGraph * gra2 = new TGraph(n,x,z);
  gra->Draw();
  TCanvas * c2 = new TCanvas("c2","");
  gra2->Draw();
  cout<<h<<"\t"<<y[int(1 / h)]<<"\t"<<z[int(1 / h)]<<endl;
}
