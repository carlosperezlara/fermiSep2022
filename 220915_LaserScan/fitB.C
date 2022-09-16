int fitB(int run=10928, double xmin=-1,double xmax=-1) {
    TFile *file = new TFile( Form("/home/daq/ScopeData/LecroyTimingDAQ/run_scope%d.root",run) );
    TTree *tree = (TTree*) file->Get("pulse");
    tree->Draw("amp[1]:amp[3]","","colz");
    new TCanvas();
    tree->Draw("amp[1]>>h","");
    TH1F *hist = (TH1F*) file->Get("h");
    if( (xmin<0)&&(xmax<0) ) {
        xmin = hist->GetXaxis()->GetBinLowEdge(1);
        xmax = hist->GetXaxis()->GetBinLowEdge( hist->GetXaxis()->GetNbins() );
    }
    hist->Fit("gaus","R","",xmin,xmax);
    return 0;
}
