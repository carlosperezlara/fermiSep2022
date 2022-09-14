int fit(int run=10888, float xmin=10.3, float xmax=10.6) {
    TFile *file = new TFile( Form("/home/daq/ScopeData/LecroyTimingDAQ/run_scope%d.root",run) );
    TTree *tree = (TTree*) file->Get("pulse");
    //tree->Print();
    tree->Draw("1e9*(LP2_20[0] - LP2_20[2])>>h(800,10,11)","");
    TH1F *hist = (TH1F*) file->Get("h");
    //hist->Dump();
    cout << xmin << " " << xmax << endl;
    hist->Fit("gaus","R","",xmin,xmax);
    return 0;
}
