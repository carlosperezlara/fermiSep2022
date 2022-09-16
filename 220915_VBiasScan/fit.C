int fit(int run=10928, float xmin=-1, float xmax=-1) {
    TFile *file = new TFile( Form("/home/daq/ScopeData/LecroyTimingDAQ/run_scope%d.root",run) );
    TTree *tree = (TTree*) file->Get("pulse");
    //tree->Print();
    tree->Draw("1e9*(LP2_20[0] - LP2_20[5])>>h(800,62.6,64.4)","");
    TH1F *hist = (TH1F*) file->Get("h");
    if( (xmin<0)&&(xmax<0) ) {
        xmin = hist->GetXaxis()->GetBinLowEdge(1);
        xmax = hist->GetXaxis()->GetBinLowEdge( hist->GetXaxis()->GetNbins() );
    }
    hist->Fit("gaus","R","",xmin,xmax);
    return 0;
}
