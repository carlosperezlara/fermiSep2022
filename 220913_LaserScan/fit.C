int fit(int run=10928, float xmin=63, float xmax=65) {
    TFile *file = new TFile( Form("/home/daq/ScopeData/LecroyTimingDAQ/run_scope%d.root",run) );
    TTree *tree = (TTree*) file->Get("pulse");
    //tree->Print();
    tree->Draw("1e9*(LP2_20[0] - LP2_20[5])>>h(800,62.6,64.4)","");
    TH1F *hist = (TH1F*) file->Get("h");
    /*
    TF1 *fitH = new TF1("fitH","[0]*TMath::Gaus(x,[1],[2])",62.6,63.4);
    fitH->SetParameter(1,hist->GetMean());
    fitH->SetParLimits(1,xmin,xmax);
    fitH->SetParameter(2,hist->GetMean());
    fitH->SetParLimits(2,0.05,0.3);
    //hist->Dump();
    cout << xmin << " " << xmax << endl;
    hist->Fit(fitH,"R","",xmin,xmax);
    hist->Fit(fitH,"R","",xmin,xmax);
    */
    hist->Fit("gaus","R","",xmin,xmax);
    return 0;
}
