int fitB(int run=10928) {
    TFile *file = new TFile( Form("/home/daq/ScopeData/LecroyTimingDAQ/run_scope%d.root",run) );
    TTree *tree = (TTree*) file->Get("pulse");
    tree->Draw("amp[1]:amp[3]","","colz");
    new TCanvas();
    tree->Draw("amp[1]>>h","");
    TH2F *hist = (TH2F*) file->Get("h");
    hist->Fit("gaus");
    return 0;
}
